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
    spec.ios.vendored_frameworks = 'polyv/polyv.xcframework'

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
    # 添加额外的设置项
    spec.static_framework = false
end
