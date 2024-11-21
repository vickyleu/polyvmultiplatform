//
//  PLVBroadcastSampleHandler.h
//  PLVScreenShareExtension
//
//  Created by Sakya on 2022/2/9.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <ReplayKit/ReplayKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 录屏结束的原因
typedef NS_ENUM(NSUInteger, PLVBroadcastSampleHandlerReason) {
    /// 主进程请求结束
    PLVBroadcastSampleHandlerReasonRequestedByMain,
    /// 链接断开，主进程退出
    PLVBroadcastSampleHandlerReasonDisconnected,
    /// 版本号与主进程SDK不符
    PLVBroadcastSampleHandlerReasonVersionMismatch
};

@protocol PLVBroadcastSampleHandlerDelegate;

/// 录屏广播的处理
///
/// @note 负责 录屏广播 的开始、暂停、恢复、完成及音视频数据的处理
@interface PLVBroadcastSampleHandler : NSObject

/// 代理
@property (nonatomic, weak) id <PLVBroadcastSampleHandlerDelegate> delegate;

@property (nonatomic, copy, readonly) NSString *appGroup;

+ (instancetype)broadcastSampleHandlerWithAppGroup:(NSString *)appGroup;

/// 开始录屏方法
///
/// 通过系统控制中心或者主程序开启录屏后，会回调 RPBroadcastSampleHandler.broadcastStartedWithSetupInfo，在 broadcastStartedWithSetupInfo 方法中调用
- (void)broadcastStarted;

/// 录屏暂停方法
///
/// 通过系统控制中心停止录屏时，会回调 RPBroadcastSampleHandler.broadcastPaused，在 broadcastPaused 方法中调用
- (void)broadcastPaused;

/// 录屏恢复方法
///
/// 通过系统控制中心停止录屏时，会回调 RPBroadcastSampleHandler.broadcastResumed，在 broadcastResumed 方法中调用
- (void)broadcastResumed;

/// 录屏完成方法
///
/// 通过系统控制中心停止录屏时，会回调 RPBroadcastSampleHandler.broadcastFinished，在 broadcastFinished 方法中调用
- (void)broadcastFinished;

/// 媒体数据（音视频）发送方法
///
/// 需要在 RPBroadcastSampleHandler 的实现类中的 processSampleBuffer: 方法中调用
///
/// @param sampleBuffer 系统回调的视频或音频帧
/// @param sampleBufferType 媒体输入类型
- (void)sendSampleBuffer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType API_AVAILABLE(ios(10.0));

@end

/// 录屏广播 处理器 的回调
@protocol PLVBroadcastSampleHandlerDelegate <NSObject>

/// SDK端 结束录屏的回调
/// @param sampleHandler 广播处理器
/// @param reason 结束录屏的原因
- (void)plvBroadcastSampleHandler:(PLVBroadcastSampleHandler *)sampleHandler broadcastFinished:(PLVBroadcastSampleHandlerReason)reason;

@end

NS_ASSUME_NONNULL_END
