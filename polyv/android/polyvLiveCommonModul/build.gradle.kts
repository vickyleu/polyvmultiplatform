plugins {
    id(libs.plugins.kotlin.kapt.get().pluginId)
    id(libs.plugins.kotlin.android.get().pluginId)
    id(libs.plugins.android.library.get().pluginId)
}

android {
    compileSdk = libs.versions.android.compileSdk.get().toInt()
    namespace = "com.easefun.polyv.livecommon"
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
        implementation("com.google.android.material:material:1.12.0")
//    implementation 'com.android.support:design:28.0.0'
        //noinspection UseTomlInstead
        implementation("androidx.gridlayout:gridlayout:1.1.0-beta01")

        //glide
        //noinspection UseTomlInstead
        api("com.github.bumptech.glide:okhttp3-integration:4.16.0") {
//        exclude group:'com.github.bumptech.glide',module:'glide'
        }

        //noinspection UseTomlInstead
        api("net.polyv.android:polyvSDKLiveScenes:1.19.0") {
            exclude(group = "com.tencent.liteav")
        }
        //noinspection UseTomlInstead
        kapt("com.github.bumptech.glide:compiler:4.16.0")
        //noinspection UseTomlInstead
        api("pl.droidsonroids.gif:android-gif-drawable:1.2.28")
        //noinspection UseTomlInstead
        implementation("androidx.constraintlayout:constraintlayout:2.1.4")
        //noinspection UseTomlInstead
        api("androidx.room:room-runtime:2.7.0-alpha08")
        //noinspection UseTomlInstead
        kapt("androidx.room:room-compiler:2.7.0-alpha08")
        //noinspection UseTomlInstead
        api("androidx.room:room-rxjava2:2.7.0-alpha08")
        //svga动画特效库
        //noinspection UseTomlInstead
        api("com.github.yyued:SVGAPlayer-Android:2.6.1")

        //下拉刷新&上拉加载更多控件
        //noinspection UseTomlInstead
        api("me.dkzwm.widget.srl:core:1.7.1.6.androidx")
        //noinspection UseTomlInstead
        api("me.dkzwm.widget.srl:ext-util:1.7.1.6.androidx")
        //noinspection UseTomlInstead
        api("me.dkzwm.widget.srl:ext-material:1.7.1.6.androidx")
        //noinspection UseTomlInstead
        api("me.dkzwm.widget.srl:ext-classics:1.7.1.6.androidx")
        //noinspection UseTomlInstead
        api("com.google.android.flexbox:flexbox:3.0.0")
        api("androidx.swiperefreshlayout:swiperefreshlayout:1.1.0")
    }
}
