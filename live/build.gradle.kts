@file:OptIn(ExperimentalKotlinGradlePluginApi::class)

import org.jetbrains.kotlin.gradle.ExperimentalKotlinGradlePluginApi
import org.jetbrains.kotlin.gradle.plugin.cocoapods.CocoapodsExtension
import org.jetbrains.kotlin.gradle.targets.native.tasks.PodInstallSyntheticTask
import org.jetbrains.kotlin.gradle.targets.native.tasks.PodInstallTask
import org.jetbrains.kotlin.gradle.tasks.DefFileTask

plugins {
//    alias(libs.plugins.kotlin.multiplatform)
//    alias(libs.plugins.kotlin.cocoapods)
//    alias(libs.plugins.android.library)
    id(libs.plugins.kotlinMultiplatform.get().pluginId)
    id(libs.plugins.android.library.get().pluginId)
}

afterEvaluate{
    afterEvaluate{
       /* tasks.withType<DefFileTask>().configureEach {
            val task = this
            val podName = task.pod.get().moduleName
            val taskName = "generateDef${podName}"

            task.inputs.file(tasks.named("xcodeVersion").get().outputs.files.singleFile)
            task.dependsOn("xcodeVersion")

            tasks.named("podGenIos").get().inputs.file(task.outputs.files.singleFile)
            tasks.named("podGenIos").get().dependsOn(task)

//            doFirst {
//                tasks.named(taskName) {
//                    inputs.file(tasks.named("xcodeVersion").get().outputs.files.singleFile)
//                    dependsOn("xcodeVersion")
//                }
//                tasks.named("podGenIos") {
//                    inputs.file(tasks.named(taskName).get().outputs.files.singleFile)
//                    dependsOn(taskName)
//                }
//            }
        }
        tasks.withType<PodSetupBuildTask>().configureEach {
            val task = this
            val podName = task.pod.get().moduleName
            println("task.name::${task.name}  podName:$podName")
            val arch = task.name.split(podName).last()

            val relatedTasks = tasks.matching { it.name.startsWith("cinterop${podName}") }.asIterable().toList()
            println("arch:$arch task:${task.name}  tasks======>${relatedTasks.joinToString { it.name }}")
            relatedTasks.forEach {relatedTask->
                val taskName = relatedTask.name.split(podName).last()
                when(arch){
                    "Iphonesimulator"->{
                        if (taskName.contains("IosSimulatorArm64")||taskName.contains("IosSimulatorArm64")) {
//                            task.mustRunAfter(relatedTask)
                        }
                    }
                    "Iphoneos"->{
                        if (taskName.contains("IosArm64")) {
//                            task.mustRunAfter(relatedTask)
                        }
                    }
                }
            }
        }*/
       /* tasks.named("generateDefPolyv") {
            inputs.file(tasks.named("generateDefPLVLiveScenesSDK").get().outputs.files.singleFile)
            dependsOn("generateDefPLVLiveScenesSDK")
        }*/
//        tasks.named("publish") {
//            dependsOn(":polyvLiveCommonModul:publish", ":polyvLiveCloudClassScene:publish") // 指定依赖子模块的发布任务
//        }
//
//
//
//        tasks.withType<AbstractPublishToMaven>().configureEach {
//            println("commonizeNativeDistribution afterEvaluate====>>${this}")
//            mustRunAfter(":polyvLiveCommonModul:publish", ":polyvLiveCloudClassScene:publish")
//        }

        /*tasks.findByName("generateDefPolyv")?.apply {
            println("${rootProject.project("polyvLiveCloudClassScene").tasks.map { it.name }}")


            inputs.file(rootProject.project("polyvLiveCloudClassScene").tasks.named("compileReleaseJavaWithJavac").get().outputs.files.singleFile)
//            inputs.file(rootProject.tasks.named(":polyvLiveCloudClassScene:packageReleaseResources").get().outputs.files.singleFile)
//            inputs.file(rootProject.tasks.named(":polyvLiveCloudClassScene:generateReleaseResValues").get().outputs.files.singleFile)
//            inputs.file(rootProject.tasks.named(":polyvLiveCloudClassScene:processReleaseManifest").get().outputs.files.singleFile)
//            inputs.file(rootProject.tasks.named(":polyvLiveCloudClassScene:syncReleaseLibJars").get().outputs.files.singleFile)
//            inputs.file(rootProject.tasks.named(":polyvLiveCloudClassScene:compileReleaseJavaWithJavac").get().outputs.files.singleFile)
//            inputs.file(rootProject.tasks.named(":polyvLiveCloudClassScene:packageReleaseResources").get().outputs.files.singleFile)
        }*/
//        tasks.withType<PodInstallSyntheticTask>().configureEach {
//            val podInstallSyntheticIos = this
//            tasks.findByName("generateDefPolyv")?.apply {
//                val generateDefPolyv = this
//                generateDefPolyv.inputs.file(podInstallSyntheticIos.outputs.files.singleFile)
//                generateDefPolyv.mustRunAfter(podInstallSyntheticIos)
//            }
//        }
//        tasks.findByName("xcodeVersion")?.apply {
//            val xcodeVersion = this
//            tasks.findByName("generateDefPolyv")?.apply {
//                val generateDefPolyv = this
//                generateDefPolyv.inputs.file(xcodeVersion.outputs.files.singleFile)
//                generateDefPolyv.mustRunAfter(xcodeVersion)
//            }
//        }
//        tasks.findByName("podGenIos")?.apply {
//            val podGenIos = this
//            tasks.findByName("generateDefPolyv")?.apply {
//                val generateDefPolyv = this
//                generateDefPolyv.inputs.file(podGenIos.outputs.files.singleFile)
//                generateDefPolyv.mustRunAfter(podGenIos)
//            }
//        }

    }
}



kotlin {
    compilerOptions {
        freeCompilerArgs = listOf(
            "-Xexpect-actual-classes", // remove warnings for expect classes
            "-Xskip-prerelease-check",
            "-opt-in=kotlinx.cinterop.BetaInteropApi",
            "-opt-in=kotlinx.cinterop.ExperimentalForeignApi",
            "-opt-in=kotlinx.cinterop.ExperimentalForeignApi",
            "-opt-in=org.jetbrains.compose.resources.InternalResourceApi",
        )
    }
    jvmToolchain {
        languageVersion.set(JavaLanguageVersion.of(libs.versions.jvmTarget.get()))
    }


    applyDefaultHierarchyTemplate()

    androidTarget {
        publishLibraryVariants("release")
    }
    listOf(
        iosX64(),
        iosArm64(),
        iosSimulatorArm64()
    ).forEach {
        it.binaries {
            framework {
                isStatic = false
                baseName = "live"
                transitiveExport=true
                export("org.uooc.live:live")
            }
        }
        it.compilations.getByName("main"){
            val PLVBusinessSDK by cinterops.creating{
                defFile("src/nativeInterop/cinterop/PLVBusinessSDK.def")
                includeDirs(projectDir.resolve("src/nativeInterop/thirdparty/PlvBussiness"))
                packageName = "what.the.fuck.polyv"
            }
            val PLVFoundationSDK by cinterops.creating{
                defFile("src/nativeInterop/cinterop/PLVFoundationSDK.def")
                includeDirs(projectDir.resolve("src/nativeInterop/thirdparty/PlvFoundation"))
                packageName = "what.the.fuck.polyv"
            }

            val polyv by cinterops.creating{
                defFile("src/nativeInterop/cinterop/polyv.def")
                includeDirs(projectDir.resolve("src/nativeInterop/thirdparty/polyv"))
                packageName = "what.the.fuck.polyv"
            }

        }
    }
    sourceSets {
        commonMain.dependencies {
            implementation(project.dependencies.platform(libs.coil.bom))
            implementation(libs.coil.core)
        }
        androidMain.dependencies {
            compileOnly(projects.polyvLiveCommonModul)
            compileOnly(projects.polyvLiveCloudClassScene) {
                exclude("com.google.android", "flexbox")
            }
        }
    }
}
android {
    namespace = "org.uooc.plv"
    compileSdk = libs.versions.android.compileSdk.get().toInt()
    sourceSets["main"].java.srcDirs("src/androidMain/java", "src/androidMain/kotlin")
    sourceSets["main"].res.srcDirs("src/androidMain/res")
    defaultConfig {
        minSdk = libs.versions.android.minSdk.get().toInt()
    }
    lint {
        targetSdk = libs.versions.android.targetSdk.get().toInt()
        abortOnError = false
        checkReleaseBuilds = false
    }
    packaging {
        resources.excludes.add("META-INF/polyv*")
        resources.excludes.add("META-INF/androidx/room")
        resources.excludes.add("META-INF/*.RSA")
        resources.excludes.add("META-INF/*.SF")
        resources.excludes.add("META-INF/*.DSA")
        resources.excludes.add("META-INF/*.LIST")
    }
    publishing {
        singleVariant("release") {
            withSourcesJar()
            withJavadocJar()
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.toVersion(libs.versions.jvmTarget.get())
        targetCompatibility = JavaVersion.toVersion(libs.versions.jvmTarget.get())
    }
}
