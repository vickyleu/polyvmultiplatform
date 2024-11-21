//
//  PLVBRTCDefine.h
//  PLVBusinessSDK
//
//  Created by Lincal on 2021/4/13.
//  Copyright © 2021 PLV. All rights reserved.
//

#ifndef PLVBRTCDefine_h
#define PLVBRTCDefine_h

/// 流宽高比
typedef NS_ENUM(NSInteger, PLVBLinkMicStreamScale) {
    PLVBLinkMicStreamScale16_9 = 0,  // (画面横屏) 16:9
    PLVBLinkMicStreamScale4_3 = 1,   // (画面横屏) 4:3
    PLVBLinkMicStreamScale9_16 = 2,  // (画面竖屏) 9:16
    PLVBLinkMicStreamScale3_4 = 3,   // (画面竖屏) 3:4
};

/// 流清晰度
typedef NS_ENUM(NSInteger, PLVBLinkMicStreamQuality) {
    PLVBLinkMicStreamQuality180P = 0, // 180p（标清）
    PLVBLinkMicStreamQuality360P = 4, // 360p（高清）
    PLVBLinkMicStreamQuality720P = 8, // 720p（超清）
    PLVBLinkMicStreamQuality1080P = 12, // 1080p（超高清）
};

/// 网络状态（已废弃）
DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用PLVBRTCNetworkQuality")
typedef NS_ENUM(NSInteger, PLVBLinkMicNetworkQuality) {
    PLVBLinkMicNetworkQualityUnknown = 0,// 未知
    PLVBLinkMicNetworkQualityGood = 1,   // 好
    PLVBLinkMicNetworkQualityFine = 2,   // 良好
    PLVBLinkMicNetworkQualityBad = 3,    // 差
    PLVBLinkMicNetworkQualityDown = 4,   // 离线
};

/// 网络状态
typedef NS_ENUM(NSInteger, PLVBRTCNetworkQuality) {
    PLVBRTCNetworkQuality_Unknown = 0,  // 网络情况未知
    PLVBRTCNetworkQuality_Excellent = 1,    // 当前网络非常好
    PLVBRTCNetworkQuality_Good = 2,     // 当前网络比较好
    PLVBRTCNetworkQuality_Poor = 3,     // 当前网络一般
    PLVBRTCNetworkQuality_Bad = 4,      // 当前网络较差
    PLVBRTCNetworkQuality_VBad = 5,     // 当前网络很差
    PLVBRTCNetworkQuality_Down = 6,     // 当前网络不满足RTC的最低要求
};

/// RTC服务连接状态
typedef NS_ENUM(NSInteger, PLVBLinkMicConnectionStateType) {
    PLVBLinkMicConnectionStateDisconnected = 1, // 已断开
    PLVBLinkMicConnectionStateConnecting = 2,   // 连接中
    PLVBLinkMicConnectionStateConnected = 3,    // 已连接
    PLVBLinkMicConnectionStateReconnecting = 4, // 重连中
    PLVBLinkMicConnectionStateFailed = 5,       // 连接失败
};

/// 订阅流的媒体类型
typedef NS_OPTIONS(NSUInteger, PLVBRTCSubscribeStreamMediaType) {
    PLVBRTCSubscribeStreamMediaType_Audio = 1 << 0, // 音频流
    PLVBRTCSubscribeStreamMediaType_Video = 1 << 1, // 视频流
};

/// 流的源类型
///
/// @note 推荐使用此 流的源类型 枚举
typedef NS_OPTIONS(NSInteger, PLVBRTCStreamSourceType) {
    PLVBRTCStreamSourceType_Unknown = 0, // 未知的源类型
    PLVBRTCStreamSourceType_Camera =  1 << 0,  // 摄像头流
    PLVBRTCStreamSourceType_Screen =  1 << 1,  // 屏幕流
};

/// 订阅流的源类型
///
/// @note 此枚举仅作为过渡使用，建议后续使用 PLVBRTCStreamSourceType
typedef NS_OPTIONS(NSInteger, PLVBRTCSubscribeStreamSourceType) {
    PLVBRTCSubscribeStreamSourceType_Unknown = 0, // 未知的源类型
    PLVBRTCSubscribeStreamSourceType_Camera =  1 << 0,  // 摄像头流
    PLVBRTCSubscribeStreamSourceType_Screen =  1 << 1,  // 屏幕流
};

/// 流的订阅方式
typedef NS_OPTIONS(NSInteger, PLVBRTCSubscribeStreamSubscribeMode) {
    PLVBRTCSubscribeStreamSubscribeMode_ScreenFirst_Mix = 0, // 屏幕流优先的混合流订阅方式
    PLVBRTCSubscribeStreamSubscribeMode_Camera = 1, // 仅订阅摄像头流方式
    PLVBRTCSubscribeStreamSubscribeMode_Screen = 2, // 仅订阅屏幕流方式
};

/// 用户角色
typedef NS_ENUM(NSInteger, PLVBLinkMicRoleType) {
    PLVBLinkMicRoleBroadcaster = 1, // 主播
    PLVBLinkMicRoleAudience = 2,    // 观众
};

/// RTC类型
typedef NS_ENUM(NSInteger, PLVBLinkMicRTCType) {
    PLVBLinkMicRTCType_AG = 1, // AG
    PLVBLinkMicRTCType_UC = 2, // UC
    PLVBLinkMicRTCType_ZE = 3, // ZE
    PLVBLinkMicRTCType_TX = 4, // TX
    PLVBLinkMicRTCType_BD = 5, // BD
};

/// 视频画面 填充模式
typedef NS_ENUM(NSInteger, PLVBRTCVideoViewFillMode) {
    PLVBRTCVideoViewFillMode_Fill = 0, // 等比缩放，无黑边，被裁剪（视频填满画布，超出载体画布的部分，将被裁剪，画面显示可能不完整）
    PLVBRTCVideoViewFillMode_Fit = 2,  // 等比缩放，有黑边，不裁剪（视频长边，优先填充至画布边界；视频短边，因等比缩放而未填充的区域，将填充黑色）
};

/// 视频画面 镜像类型
typedef NS_ENUM(NSUInteger, PLVBRTCVideoMirrorMode) {
    PLVBRTCVideoMirrorMode_Auto = 0,     // 自动镜像 (前置摄像头镜像，后置摄像头不镜像)
    PLVBRTCVideoMirrorMode_Enabled = 1,  // 开启镜像 (前后置摄像头，画面均镜像)
    PLVBRTCVideoMirrorMode_Disabled = 2, // 不开启镜像 (前后置摄像头，画面均不镜像)
};

/// 视频输出方向模式
typedef NS_ENUM(NSInteger, PLVBRTCVideoOutputOrientationMode) {
    PLVBRTCVideoOutputOrientationMode_Landscape = 0,  /// 视频 横屏输出 模式
    PLVBRTCVideoOutputOrientationMode_Portrait  = 1,  /// 视频 竖屏输出 模式
};

/// 屏幕采集结束的原因
typedef NS_ENUM(NSInteger, PLVBRTCScreenCaptureFinishedReason) {
    PLVBRTCScreenCaptureFinishedReason_Engine = 0,     // 用户触发 通过在App内部调用SDK的API方法触发
    PLVBRTCScreenCaptureFinishedReason_Extension = 1,  // 用户触发 通过extension模块或者控制中心结束录制
};

/// 画质偏好
/// 在弱网络环境下有两种调控模式：“优先保证画面清晰”或“优先保证画面流畅”，两种模式均会优先保障声音数据的传输。
typedef NS_ENUM(NSInteger, PLVBRTCVideoQosPreference) {
    /// 清晰优先（默认值）：即当前网络不足以传输既清晰又流畅的画面时，优先保证画面的清晰度，代价就是画面会比较卡顿。
    PLVBRTCVideoQosPreferenceClear = 0,

    /// 流畅优先：即当前网络不足以传输既清晰又流畅的画面时，优先保证画面的流畅性，代价就是画面会比较模糊且伴随有较多的马赛克。
    PLVBRTCVideoQosPreferenceSmooth = 1
};

/// 降噪
typedef NS_ENUM(NSInteger, PLVBLinkMicNoiseCancellationLevel) {
    /// 适用于微弱降噪
    PLVBLinkMicNoiseCancellationLevelSoft = 1,
    
    /// 适用于抑制嘈杂非平稳噪声
    PLVBLinkMicNoiseCancellationLevelAggressive = 2,
};

#endif /* PLVBRTCDefine_h */
