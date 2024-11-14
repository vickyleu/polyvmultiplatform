Pod::Spec.new do |spec|
    spec.name                     = 'live'
    spec.version                  = '1.0.0'
    spec.homepage                 = ''
    spec.source                   = { :http=> ''}
    spec.authors                  = ''
    spec.license                  = ''
    spec.summary                  = 'Compose for iOS'
                
    spec.libraries                = 'c++'
    spec.ios.deployment_target    = '12.0'
    spec.dependency 'MJRefresh', '~> 3.7.7'
    spec.dependency 'PLVImagePickerController', '0.1.3'
    spec.dependency 'Protobuf', '3.22.4'
    spec.dependency 'SDWebImage'
    spec.dependency 'SVGAPlayer', '~> 2.3'
    spec.dependency 'TXLiteAVSDK_TRTC'
    spec.dependency 'polyv'
                
                
    spec.xcconfig = {
        'ENABLE_USER_SCRIPT_SANDBOXING' => 'NO',
    }
                
    spec.pod_target_xcconfig = {
        'KOTLIN_PROJECT_PATH' => ':live',
        'PRODUCT_MODULE_NAME' => 'live',
    }
                
    spec.script_phases = [
        {
            :name => 'Build live',
            :execution_position => :before_compile,
            :shell_path => '/bin/sh',
            :script => <<-SCRIPT
                if [ "YES" = "$OVERRIDE_KOTLIN_BUILD_IDE_SUPPORTED" ]; then
                  echo "Skipping Gradle build task invocation due to OVERRIDE_KOTLIN_BUILD_IDE_SUPPORTED environment variable set to \"YES\""
                  exit 0
                fi
                set -ev
                REPO_ROOT="$PODS_TARGET_SRCROOT"
                "$REPO_ROOT/../gradlew" -p "$REPO_ROOT" $KOTLIN_PROJECT_PATH:syncFramework \
                    -Pkotlin.native.cocoapods.platform=$PLATFORM_NAME \
                    -Pkotlin.native.cocoapods.archs="$ARCHS" \
                    -Pkotlin.native.cocoapods.configuration="$CONFIGURATION"
            SCRIPT
        }
    ]
    spec.vendored_frameworks = 'src/nativeInterop/cinterop/ios/framework/live.framework'
end