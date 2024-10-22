Pod::Spec.new do |spec|
    spec.name                     = 'polyv'
    spec.version                  = '1.0.0'
    spec.homepage                 = 'https://your-homepage-url.com'  # 你可以填写项目的主页
    spec.source                   = { :path => './' }
    spec.authors                  = { 'Your Name' => 'your-email@example.com' }  # 替换为你的名字和邮箱
    spec.license                  = { :type => 'MIT', :file => 'LICENSE' }  # 设置合适的许可证
    spec.summary                  = 'Polyv SDK for iOS integration'

    spec.libraries                = 'c++'
    spec.ios.deployment_target    = '12.0'

    # 指定源文件路径
    spec.source_files             = 'PLVLiveCloudClassScene/**/*.{h,m,mm,swift}', 'PLVLiveCommonModule/**/*.{h,m,mm,swift}'  # 根据文件结构调整
    spec.public_header_files      = 'PLVLiveCloudClassScene/**/*.h', 'PLVLiveCommonModule/**/*.h'  # 根据文件结构调整
    spec.resources                = 'PLVLiveCloudClassScene/Resource/**/*'
    # 依赖项
    spec.dependency 'PLVImagePickerController', '~> 0.1.2'
    spec.dependency 'PLVLiveScenesSDK', '~> 1.19.0'
    spec.dependency 'MJRefresh', '~>3.7.7'
    spec.dependency 'SVGAPlayer', '~> 2.3'
    spec.dependency 'Protobuf', '3.22.4'
    spec.dependency 'SDWebImage'
    spec.dependency 'TXLiteAVSDK_TRTC'
    # 添加额外的设置项
    spec.frameworks               = 'UIKit', 'Foundation'
    spec.requires_arc             = true
    # 设为静态框架
    spec.static_framework = true
end