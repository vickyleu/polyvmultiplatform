//
//  PLVBRTCVideoEncoderConfiguration.h
//  PLVBusinessSDK
//
//  Created by Lincal on 2021/6/8.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PLVBRTCDefine.h"
#import "PLVBRTCConstants.h"

NS_ASSUME_NONNULL_BEGIN

/// 视频编码参数模型
@interface PLVBRTCVideoEncoderConfiguration : NSObject

/// 视频分辨率
///
/// @note 默认值:PLVBRTCVideoResolution320x180
@property (nonatomic, assign) CGSize videoResolution;

/// 视频码率
///
/// @note 默认值:280
@property (nonatomic, assign) NSInteger videoBitrate;

/// 视频采集帧率
///
/// @note 默认值:15
@property (nonatomic, assign) NSInteger videoFrameRate;

/// 视频输出方向模式
///
/// @note 方向模式影响最终的分辨率，示例如下
///       PLVBRTCVideoOutputOrientationMode_Landscape + PLVBRTCVideoResolution_640_360 = 640 × 360
///       PLVBRTCVideoOutputOrientationMode_Portrait + PLVBRTCVideoResolution_640_360 = 360 × 640
///       默认值:PLVBRTCVideoOutputOrientationMode_Landscape
@property (nonatomic, assign) PLVBRTCVideoOutputOrientationMode videoOutputOrientationMode;

/// 视频流 镜像类型
///
/// @note 部分RTC类型下，不支持后置摄像头镜像；
///
/// @note 此属性仅影响远端观看的镜像效果；默认值:PLVBRTCVideoMirrorMode_Disabled
@property (nonatomic, assign) PLVBRTCVideoMirrorMode videoMirrorMode;

/// 视频流画质偏好
@property (nonatomic, assign) PLVBRTCVideoQosPreference videoQosPreference;

@end

NS_ASSUME_NONNULL_END
