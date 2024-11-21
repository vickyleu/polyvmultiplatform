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
//    id(libs.plugins.kotlin.cocoapods.get().pluginId)
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
            }
        }
        it.compilations.getByName("main"){
            val polyv by cinterops.creating{
                defFile("src/nativeInterop/cinterop/polyv.def")
                includeDirs(projectDir.resolve("src/nativeInterop/cinterop/polyv"))
                packageName = "what.the.fuck.polyv"
            }
        }

    }

    /*listOf(
        iosX64(),
        iosArm64(),
        iosSimulatorArm64()
    ).forEach {
        it.binaries.framework {
            baseName = "live"
            isStatic = true
            xcFramework.add(this)
        }
//        it.compilations.getByName("main") {
//            val polyv by cinterops.creating {
//                // Path to .def file
//                defFile("src/nativeInterop/cinterop/polyv.def")
//                packageName = "what.the.fuck.polyv"
//                compilerOpts("-framework", "polyv") //, "-F/Users/user/Projects/MyFramework/ios/SDK"
//                compilerOpts("-framework", "SDWebImage") //, "-F/Users/user/Projects/MyFramework/ios/SDK"
//
//                val list = listOf(projectDir.resolve("src/nativeInterop/cinterop/ios/PLVLiveCloudClassScene"),
//                    projectDir.resolve("src/nativeInterop/cinterop/ios/PLVLiveCommonModule"),
//                    projectDir.resolve("src/nativeInterop/cinterop/ios/Headers"),
//                    project.layout.buildDirectory.get().asFile.resolve("cocoapods/synthetic/ios/Pods/SDWebImage/SDWebImage/Core/")
//                )
//                val allHeaderDirs = list.flatMap { dir ->
//                    dir.walk()
//                        .filter { it.isDirectory && !it.name.equals("Resource", ignoreCase = true) } // 排除 Resource 目录
//                        .map { it.absolutePath } // 获取所有子目录
//                }
//                includeDirs(*allHeaderDirs.toTypedArray())
//
//                val headerFiles = listOf(
//                    projectDir.resolve("src/nativeInterop/cinterop/ios/PLVLiveCloudClassScene"),
//                    projectDir.resolve("src/nativeInterop/cinterop/ios/PLVLiveCommonModule"),
//                    projectDir.resolve("src/nativeInterop/cinterop/ios/Headers")
//                ).flatMap { dir ->
//                    dir.walk()
//                        .filter { it.isFile && it.extension == "h" }
//                        .toList()
//                }
//                // 添加头文件目录
//                headers(*headerFiles.toTypedArray())
//
//            }
//
//        }
//        it.binaries.all {
//            // Tell the linker where the framework is located.
//            linkerOpts("-framework", "polyv") //, "-F/Users/user/Projects/MyFramework/ios/SDK"
//            linkerOpts("-framework", "SDWebImage") //, "-F/Users/user/Projects/MyFramework/ios/SDK"
//        }
    }*/

   /* cocoapods {
        summary = "Compose for iOS"
        homepage = ""
        ios.deploymentTarget = "12.0"
        version = "1.0.0"

        specRepos {
            this.url("https://github.com/aliyun/aliyun-specs.git")
        }
        framework {
            baseName = "POLY"
            isStatic = true
            optimized = true
            debuggable = false
        }
        val parent = project.projectDir.parentFile as File
        val path = parent.resolve("polyv")
        val path2 = file("src/nativeInterop/cinterop/ios")
//        val path = file("src/nativeInterop/cinterop/ios")

//        pod("SDWebImage"){
//            version = "5.20.0"
//            linkOnly=true
//        }



//        // TODO 出现TXLiteAVSDK_TRTC冲突时,请到百家云或者保利威的podspec文件中修改版本号
//        pod("PLVLiveScenesSDK") {
//            packageName = "what.the.fuck.polyv"
//            version="1.19.1"
//        }
        pod("polyv") {
            packageName = "what.the.fuck.polyv"
            moduleName = "polyv"
//            this.useInteropBindingFrom("PLVLiveScenesSDK")
            source =
                CocoapodsExtension.CocoapodsDependency.PodLocation.Path(path)
        }

        val frameworkLinkDir = path2.resolve("framework")
        if (!frameworkLinkDir.exists()) {
            val defDir = project.layout.buildDirectory.get().asFile.resolve("cocoapods/framework/")
            val absolute = defDir.absolutePath
//            val relative = defDir.relativeTo(project.projectDir.resolve("src/nativeInterop/cinterop/ios"))
//            println("relative::${relative.path}")
            ProcessBuilder().directory(project.projectDir.resolve("src/nativeInterop/cinterop/ios"))
                .command(
                    "ln",
                    "-sf",
                    "${absolute}/",
                    "./framework"
                ).start().apply {
                waitFor()
            }.inputStream.bufferedReader().readText()
        }
        extraSpecAttributes["vendored_frameworks"] =
            "'live.framework'" //导入系统库
    }*/
    /*targets.withType<KotlinNativeTarget> {
        val platform = when (this.name) {
            "iosX64", "iosSimulatorArm64" -> "iphonesimulator"
            "iosArm64" -> "iphoneos"
            else -> error("Unsupported target ${this.name}")
        }

    }*/

    /*tasks.withType<DefFileTask>().configureEach {
        this.pod.get().source
    }*/

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

/*val frameworkSourcePath = "src/nativeInterop/cinterop/ios/framework" // 你的 framework 源目录
val frameworkTargetBasePath = "src/nativeInterop/cinterop/ios" // 你的 framework 源目录
tasks.register("copyFrameworks") {
    kotlin.targets.withType<KotlinNativeTarget>().forEach { target ->
        val platform = when (target.konanTarget.family) {
            org.jetbrains.kotlin.konan.target.Family.IOS -> when (target.konanTarget) {
                org.jetbrains.kotlin.konan.target.KonanTarget.IOS_ARM64 -> "iphoneos"
                org.jetbrains.kotlin.konan.target.KonanTarget.IOS_X64,
                org.jetbrains.kotlin.konan.target.KonanTarget.IOS_SIMULATOR_ARM64 -> "iphonesimulator"
                else -> error("Unsupported target ${target.konanTarget.name}")
            }
            else -> error("Target is not iOS")
        }
        val arch = when (target.konanTarget) {
            org.jetbrains.kotlin.konan.target.KonanTarget.IOS_ARM64 -> "arm64"
            org.jetbrains.kotlin.konan.target.KonanTarget.IOS_X64 -> "x86_64"
            org.jetbrains.kotlin.konan.target.KonanTarget.IOS_SIMULATOR_ARM64 -> "arm64e"
            else -> error("Unsupported architecture ${target.konanTarget.name}")
        }
        val sourceDir = file("$frameworkSourcePath/live.framework")
        val targetDir = file("$frameworkTargetBasePath/$arch/live.framework")
        println("taskName:>>>>:targetDir>>>:${targetDir.absolutePath}")
        doLast {
            if (sourceDir.exists()) {
                targetDir.parentFile.mkdirs()
                sourceDir.copyRecursively(targetDir, overwrite = true)
                println("Framework for $arch ($platform) copied to ${targetDir.absolutePath}")
            } else {
                println("Source framework not found in $frameworkSourcePath for $arch ($platform)")
            }
        }

    }

}*/

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
