@file:OptIn(ExperimentalKotlinGradlePluginApi::class)

import org.jetbrains.kotlin.gradle.ExperimentalKotlinGradlePluginApi
import org.jetbrains.kotlin.gradle.plugin.cocoapods.CocoapodsExtension
import org.jetbrains.kotlin.gradle.plugin.mpp.KotlinNativeTarget

plugins {
//    alias(libs.plugins.kotlin.multiplatform)
//    alias(libs.plugins.kotlin.cocoapods)
//    alias(libs.plugins.android.library)
    id(libs.plugins.kotlinMultiplatform.get().pluginId)
    id(libs.plugins.kotlin.cocoapods.get().pluginId)
    id(libs.plugins.android.library.get().pluginId)
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
        /*it.compilations.getByName("main") {
            val polyv by cinterops.creating {
                // Path to .def file
                defFile("src/nativeInterop/cinterop/polyv.def")
                packageName = "what.the.fuck.polyv"

//                includeDirs(project.layout.buildDirectory.get().asFile.resolve("cocoapods/synthetic/ios/Pods/SDWebImage/SDWebImage/Core/"))
                compilerOpts("-framework", "SDWebImage") //, "-F/Users/user/Projects/MyFramework/ios/SDK"

                val headerFiles = listOf(
                    projectDir.resolve("src/nativeInterop/cinterop/ios/PLVLiveCloudClassScene"),
                    projectDir.resolve("src/nativeInterop/cinterop/ios/PLVLiveCommonModule")
                ).flatMap { dir ->
                    dir.walk()
                        .filter { it.isFile && it.extension == "h" }
                        .toList()
                }
//                .filter {
//                    it.name.contains("PLVLCCloudClassViewController")||
//                    it.name.contains("PLVMultiLanguageManager") ||
//                    it.name.contains("PLVMultiLanguageModeZH") ||
//                    it.name.contains("PLVRoomLoginClient")
//                }
                // 添加头文件目录
                headers(*headerFiles.toTypedArray())

            }
        }
        it.binaries.all {
            // Tell the linker where the framework is located.
            linkerOpts("-framework", "SDWebImage") //, "-F/Users/user/Projects/MyFramework/ios/SDK"
        }*/
    }

    cocoapods {
        summary = "Compose for iOS"
        homepage = ""
        ios.deploymentTarget = "12.0"
        version = "1.0.0"

        specRepos {
            this.url("https://github.com/aliyun/aliyun-specs.git")
        }
        framework {
            baseName = "live"
            isStatic = true
            optimized = true
            debuggable = false
        }
        val path = file("src/nativeInterop/cinterop/ios")
        pod("SDWebImage")
        /*pod("PLVLiveScenesSDK") {
            packageName = "what.the.fuck.polyv"
            version="1.19.1"
        }*/
        pod("PLVImagePickerController","0.1.3")
        pod("MJRefresh","~> 3.7.7")
        pod("Protobuf"){
            version="3.22.4"
        }
        pod("SVGAPlayer"){
            version="~> 2.3"
            // 添加 GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 定义
            this.extraOpts+= listOf("-compiler-option", "-DGPB_USE_PROTOBUF_FRAMEWORK_IMPORTS")
            this.useInteropBindingFrom("Protobuf")
        }

        pod("TXLiteAVSDK_TRTC")
        // TODO 出现TXLiteAVSDK_TRTC冲突时,请到百家云或者保利威的podspec文件中修改版本号
        pod("polyv") {
            packageName = "what.the.fuck.polyv"
//            this.useInteropBindingFrom("SDWebImage")
//            this.useInteropBindingFrom("PLVLiveScenesSDK")
//            this.useInteropBindingFrom("PLVImagePickerController")
            source =
                CocoapodsExtension.CocoapodsDependency.PodLocation.Path(path)
        }
        val frameworkLinkDir = path.resolve("framework")
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
            "'src/nativeInterop/cinterop/ios/framework/live.framework'" //导入系统库
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
