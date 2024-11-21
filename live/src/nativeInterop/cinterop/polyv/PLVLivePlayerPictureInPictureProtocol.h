//
//  PLVLivePlayerPictureInPictureProtocol.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2024/3/13.
//  Copyright © 2024 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PLVLivePlayerPictureInPictureDelegate;

@protocol PLVLivePlayerPictureInPictureProtocol <NSObject>

/// 播放器画中画代理
@property (nonatomic, weak) id <PLVLivePlayerPictureInPictureDelegate> pictureInPictureDelegate;

/// 是否允许在切换到后台时自动启动画中画，默认NO，PLVLivePictureInPictureMode_IJKPlayer模式有效
@property (nonatomic, assign) BOOL canAutoStartPictureInPicture;

/// 开启画中画功能
/// @param originView 画中画播放器的起始视图，PLVLivePictureInPictureMode_IJKPlayer模式下 可为空
- (void)startPictureInPictureFromOriginView:(UIView *)originView;

/// 关闭画中画功能
- (void)stopPictureInPicture;

@end

/// 画中画代理
@protocol PLVLivePlayerPictureInPictureDelegate <NSObject>

@optional

/// 画中画即将开始
/// @param livePlayer 播放器
- (void)plvLivePlayerPictureInPictureWillStart:(PLVPlayer<PLVLivePlayerPictureInPictureProtocol> *)livePlayer;

/// 画中画已经开始
/// @param livePlayer 播放器
- (void)plvLivePlayerPictureInPictureDidStart:(PLVPlayer<PLVLivePlayerPictureInPictureProtocol> *)livePlayer;

/// 画中画开启失败
/// @param livePlayer 播放器
/// @param error 失败错误原因
- (void)plvLivePlayer:(PLVPlayer<PLVLivePlayerPictureInPictureProtocol> *)livePlayer pictureInPictureFailedToStartWithError:(NSError *)error;

/// 画中画即将停止
/// @param livePlayer 播放器
- (void)plvLivePlayerPictureInPictureWillStop:(PLVPlayer<PLVLivePlayerPictureInPictureProtocol> *)livePlayer;

/// 画中画已经停止
/// @param livePlayer 播放器
- (void)plvLivePlayerPictureInPictureDidStop:(PLVPlayer<PLVLivePlayerPictureInPictureProtocol> *)livePlayer;

/// 画中画播放器播放状态改变
/// @param livePlayer 播放器
/// @param playing 是否正在播放
- (void)plvLivePlayer:(PLVPlayer<PLVLivePlayerPictureInPictureProtocol> *)livePlayer pictureInPicturePlayerPlayingStateDidChange:(BOOL)playing;

/// 画中画播放器播放状态改变
///
/// @note iOS15系统上生效
///
/// @param livePlayer 播放器
/// @param playing 是否正在播放
/// @param systemInterrupts 是否系统中断
- (void)plvLivePlayer:(PLVPlayer<PLVLivePlayerPictureInPictureProtocol> *)livePlayer pictureInPicturePlayerPlayingStateDidChange:(BOOL)playing systemInterrupts:(BOOL)systemInterrupts;

@end

NS_ASSUME_NONNULL_END
