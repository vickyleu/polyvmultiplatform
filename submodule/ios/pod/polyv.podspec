Pod::Spec.new do |spec|
    spec.name                     = 'polyv'
    spec.version                  = '1.0.0'
    spec.homepage                 = 'https://your-homepage-url.com'  # 你可以填写项目的主页
    spec.source                   = { :git => 'https://github.com/vickyleu/polyvmultiplatform' }
    spec.authors                  = { 'Your Name' => 'your-email@example.com' }  # 替换为你的名字和邮箱
    spec.license                  = { :type => 'MIT', :file => 'LICENSE' }  # 设置合适的许可证
    spec.summary                  = 'Polyv SDK for iOS integration'

  # PHPicker 需 iOS 14+；如果必须兼容更低，用 weak_frameworks
  spec.ios.deployment_target = '12.0'      # 或 12.0 + spec.weak_frameworks = 'PhotosUI'

  spec.source_files        = ['PLVLiveCloudClassScene/**/*.{h,m,mm,swift}',
                              'PLVLiveCommonModule/**/*.{h,m,mm,swift}',
                              'PLVLiveStreamerScene/**/*.{h,m,mm,swift}',
                              'PLVStreamerAloneScene/**/*.{h,m,mm,swift}']

  spec.public_header_files = ['PLVLiveCloudClassScene/**/*.h',
                              'PLVLiveCommonModule/**/*.h',
                              'PLVLiveStreamerScene/**/*.h',
                              'PLVStreamerAloneScene/**/*.h']

  spec.resource_bundles = {
    'Resources' => ['PLVLiveCloudClassScene/**/*.bundle',
                    'PLVLiveCommonModule/**/*.bundle',
                    'PLVLiveStreamerScene/**/*.bundle',
                    'PLVStreamerAloneScene/**/*.bundle']
  }

  # 依赖

    # 保利威 多场景 SDK
    spec.dependency  'PLVLiveScenesSDK', '1.29.0'
    # 保利威 手机开播场景 需依赖的库
    spec.dependency  'PLVBytedEffectSDK', '4.4.2'
    spec.dependency  'PLVBeautyEffect','1.3.0'
    spec.dependency  'PLVBusinessSDK', '1.29.0'
    # 保利威 SM2加密 需依赖的库
    spec.dependency  'PLVLOpenSSL', '~> 1.1.12100'
    spec.dependency  'PLVFoundationSDK', '1.29.0'
    spec.dependency   'PLVImagePickerController', '~> 0.1.5' # 仅手机开播场景需要
    # 保利威 UI源码 需依赖的库
    spec.dependency  'SDWebImage', '4.4.0'
    spec.dependency  'MJRefresh', '~> 3.5.0'
    spec.dependency  'SVGAPlayer', '~> 2.3'
    spec.dependency  'Protobuf', '3.22.4'



  # 系统框架 & 库（解决 PHPicker、音视频、C++/SQLite 等符号）
  spec.frameworks = [
    'UIKit','Foundation', # //'PhotosUI',         # PHPicker*
    'AVFoundation','CoreMedia','CoreVideo',
    'VideoToolbox','AudioToolbox','CoreGraphics',
    'SystemConfiguration','CFNetwork','WebKit'
  ]
  spec.libraries  = 'c++','z','resolv','sqlite3'

  # 低版本兼容可改成弱链接 PhotosUI
  spec.weak_frameworks = 'PhotosUI'

  spec.pod_target_xcconfig = {
    'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES',
    'OTHER_LDFLAGS' => '$(inherited) -ObjC'
  }
  spec.static_framework = false
end
