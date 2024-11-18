Pod::Spec.new do |spec|
    spec.name                     = 'polyv'
    spec.version                  = '1.0.0'
    spec.homepage                 = 'https://your-homepage-url.com'  # 你可以填写项目的主页
    spec.source                   = { :git => 'https://github.com/vickyleu/polyvmultiplatform'}
    spec.authors                  = { 'Your Name' => 'your-email@example.com' }  # 替换为你的名字和邮箱
    spec.license                  = { :type => 'MIT', :file => 'LICENSE' }  # 设置合适的许可证
    spec.summary                  = 'Polyv SDK for iOS integration'
    spec.platform          = :ios
    spec.ios.deployment_target    = '12.0'
    spec.ios.vendored_frameworks = 'polyv.xcframework'
    spec.dependency 'PLVImagePickerController', '0.1.3'
    spec.dependency 'PLVLiveScenesSDK', '1.19.1'
    spec.dependency 'MJRefresh', '~> 3.7.7'
    spec.dependency 'SVGAPlayer', '~> 2.3'
    spec.dependency 'Protobuf', '3.22.4'
    spec.dependency 'SDWebImage'
    spec.dependency 'TXLiteAVSDK_TRTC'
    spec.pod_target_xcconfig = {
        'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES',
    }
    # 添加额外的设置项
    spec.frameworks               = 'UIKit', 'Foundation'
end
