plugins{
    alias(libs.plugins.jetbrainsCompose)
    alias(libs.plugins.android.library)
    alias(libs.plugins.compose.compiler)
    alias(libs.plugins.kotlinMultiplatform)
    alias(libs.plugins.kotlin.cocoapods)
}

kotlin{
    applyDefaultHierarchyTemplate()
    androidTarget{
        publishLibraryVariants("release")
    }
    iosX64()
    iosArm64()
    iosSimulatorArm64()

    cocoapods {
        summary = "Compose for iOS"
        homepage = ""
        ios.deploymentTarget = "14.0"
        version = "1.0.0"
    }

}
