//
//  PLVRTCStreamerMixUser.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2021/6/5.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 混流用户 画面填充模式
typedef NS_ENUM(NSInteger, PLVRTCStreamerMixUserRenderMode) {
    PLVRTCStreamerMixUserRenderMode_Fill = 0,         // 等比缩放，并裁剪 (画面填满画布，超出部分进行裁剪)
    PLVRTCStreamerMixUserRenderMode_Fit = 1,          // 等比缩放，不裁剪 (画面保留完整)
    PLVRTCStreamerMixUserRenderMode_FitBlackBase = 2, // 等比缩放，不裁剪 且 背景为黑色 (画面保留完整，未填充区域将为黑色底色)
};

/// 混流用户 混流媒体类型
typedef NS_ENUM(NSInteger, PLVRTCStreamerMixUserInputType) {
    PLVRTCStreamerMixUserInputType_AudioVideo = 0,  // 混入音视频
    PLVRTCStreamerMixUserInputType_Video = 1,       // 只混入视频
    PLVRTCStreamerMixUserInputType_Audio = 2,       // 只混入音频
};

/// 混流用户 流类型
typedef NS_ENUM(NSInteger, PLVRTCStreamerMixUserStreamType) {
    PLVRTCStreamerMixUserStreamType_Camera,  // 摄像头流
    PLVRTCStreamerMixUserStreamType_Screen,  // 屏幕流
};

/// 混流用户模型
@interface PLVRTCStreamerMixUser : NSObject

#pragma mark - 可配置项
/// 当前混流用户 RTCId
@property (nonatomic, copy) NSString * userRTCId;

/// 当前混流用户 画面填充模式
@property (nonatomic, assign) PLVRTCStreamerMixUserRenderMode renderMode;

/// 当前混流用户 混流媒体类型
@property (nonatomic, assign) PLVRTCStreamerMixUserInputType inputType;

/// 当前混流用户 流的类型
@property (nonatomic, assign) PLVRTCStreamerMixUserStreamType streamType;

@end

NS_ASSUME_NONNULL_END
