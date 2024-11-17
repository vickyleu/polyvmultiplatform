plugins {
    id(libs.plugins.kotlin.android.get().pluginId)
    id(libs.plugins.android.library.get().pluginId)
}
kotlin{
    jvmToolchain(libs.versions.jvmTarget.get().toInt())
}
android {
    compileSdk = libs.versions.android.compileSdk.get().toInt()
    namespace = "com.easefun.polyv.livecloudclass"
    defaultConfig {
        minSdk = libs.versions.android.minSdk.get().toInt()
        renderscriptTargetApi = libs.versions.android.targetSdk.get().toInt()
        renderscriptSupportModeEnabled = true
    }
    lint {
        targetSdk = libs.versions.android.targetSdk.get().toInt()
        checkReleaseBuilds = false
        abortOnError = false
    }
    compileOptions {
        sourceCompatibility = JavaVersion.toVersion(libs.versions.jvmTarget.get())
        targetCompatibility = JavaVersion.toVersion(libs.versions.jvmTarget.get())
    }
    buildTypes {
        getByName("release") {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    packaging {
        resources.excludes.add("META-INF/polyv*")
        resources.excludes.add("META-INF/androidx/room")
        resources.excludes.add("META-INF/*.RSA")
        resources.excludes.add("META-INF/*.SF")
        resources.excludes.add("META-INF/*.DSA")
    }
    sourceSets {
        getByName("main") {
            java.srcDirs("src/main/java", "src/main/kotlin")
            res.srcDirs(
                listOf(
                    "src/main/res",
                    "src/main/res/layouts/chatroom",
                    "src/main/res/layouts/pagemenu",
                    "src/main/res/layouts/interact",
                    "src/main/res/layouts/linkmic",
                    "src/main/res/layouts/player",
                    "src/main/res/layouts/ppt",
                    "src/main/res/layouts/liveroom",
                    "src/main/res/layouts/previous",
                    "src/main/res/layouts/download"
                )
            )
        }
    }

    publishing {
        singleVariant("release") {
            withSourcesJar()
//            withJavadocJar()
        }
    }
    dependencies {
        //noinspection UseTomlInstead
        implementation("androidx.appcompat:appcompat:1.7.0")
        implementation("com.google.android.material:material:1.12.0")
        //noinspection UseTomlInstead
        implementation("androidx.constraintlayout:constraintlayout:2.1.4")
        compileOnly(projects.polyvLiveCommonModul)
    }
}
