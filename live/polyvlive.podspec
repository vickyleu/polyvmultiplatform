Pod::Spec.new do |spec|
    spec.name                     = 'polyvlive'
    spec.version                  = '1.0.0'
    spec.homepage                 = ''
    spec.source                   = { :http=> ''}
    spec.authors                  = ''
    spec.license                  = ''
    spec.summary                  = 'Compose for iOS'
    spec.vendored_frameworks      = '../../../buildOut/KMMComposeDev/subprojects/polyvlive/cocoapods/framework/live.framework'
                
    spec.ios.deployment_target    = '14.0'
    spec.dependency 'MJRefresh', '~>3.7.7'
    spec.dependency 'PLVImagePickerController', '~> 0.1.2'
    spec.dependency 'PLVLiveScenesSDK', '~> 1.19.0'
    spec.dependency 'Protobuf', '3.22.4'
    spec.dependency 'SDWebImage'
    spec.dependency 'SVGAPlayer', '~> 2.3'
    spec.dependency 'polyv'
                
    if !Dir.exist?('../../../buildOut/KMMComposeDev/subprojects/polyvlive/cocoapods/framework/live.framework') || Dir.empty?('../../../buildOut/KMMComposeDev/subprojects/polyvlive/cocoapods/framework/live.framework')
        raise "

        Kotlin framework 'live' doesn't exist yet, so a proper Xcode project can't be generated.
        'pod install' should be executed after running ':generateDummyFramework' Gradle task:

            ./gradlew :polyvlive:generateDummyFramework

        Alternatively, proper pod installation is performed during Gradle sync in the IDE (if Podfile location is set)"
    end
                
    spec.xcconfig = {
        'ENABLE_USER_SCRIPT_SANDBOXING' => 'NO',
    }
                
    spec.pod_target_xcconfig = {
        'KOTLIN_PROJECT_PATH' => ':polyvlive',
        'PRODUCT_MODULE_NAME' => 'live',
    }
                
    spec.script_phases = [
        {
            :name => 'Build polyvlive',
            :execution_position => :before_compile,
            :shell_path => '/bin/sh',
            :script => <<-SCRIPT
                if [ "YES" = "$OVERRIDE_KOTLIN_BUILD_IDE_SUPPORTED" ]; then
                  echo "Skipping Gradle build task invocation due to OVERRIDE_KOTLIN_BUILD_IDE_SUPPORTED environment variable set to \"YES\""
                  exit 0
                fi
                set -ev
                REPO_ROOT="$PODS_TARGET_SRCROOT"
                "$REPO_ROOT/../../KMMComposeDev/gradlew" -p "$REPO_ROOT" $KOTLIN_PROJECT_PATH:syncFramework \
                    -Pkotlin.native.cocoapods.platform=$PLATFORM_NAME \
                    -Pkotlin.native.cocoapods.archs="$ARCHS" \
                    -Pkotlin.native.cocoapods.configuration="$CONFIGURATION"
            SCRIPT
        }
    ]
    spec.libraries = ['c++', 'sqlite3','z']
end