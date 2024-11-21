//
//  PLVPublicStreamPlayer.h
//  PLVLiveScenesSDK
//
//  Created by juno on 2022/9/13.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>
#import "PLVPublicStreamGetInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 网络质量（公共流播放器）
typedef NS_ENUM(NSInteger, PLVPublicStreamPlayerNetworkQuality) {
    PLVPublicStreamPlayerNetworkQuality_NoConnection = 0,   // 无网络
    PLVPublicStreamPlayerNetworkQuality_Good = 1,           // 良好
    PLVPublicStreamPlayerNetworkQuality_Middle = 2,         // 一般
    PLVPublicStreamPlayerNetworkQuality_Poor = 3            // 较差
};

@protocol PLVPublicStreamPlayerDelegate;

/// 公共流播放器
@interface PLVPublicStreamPlayer : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
@property (nonatomic, weak) id <PLVPublicStreamPlayerDelegate> delegate;

#pragma mark 数据
/// 是否正在播放
@property (nonatomic, assign, readonly) BOOL streamPlaying;

#pragma mark - [ 方法 ]

/// 配置播放器
/// @param model 配置播放器所需的数据模型
- (void)setupPlayerWith:(PLVPublicStreamGetInfoModel *)model;

/// 设置负责承载播放器画面的父视图
- (void)setupDisplaySuperview:(UIView *)displaySuperview;

/// 重新加载播放器
- (void)reloadStreamPlayer;

/// 播放
- (void)play;

/// 停止播放器
- (void)stop;

/// 暂停播放器
- (void)pause;

/// 恢复播放器
- (void)resume;

/// 清理播放器
- (void)clearPlayer;

@end

/// 播放器代理
@protocol PLVPublicStreamPlayerDelegate <NSObject>

@optional

/// 公共流播放器播放状态改变
/// @param streamPlayer 公共流播放器
/// @param playing 是否正在播放
- (void)plvPublicStreamPlayer:(PLVPublicStreamPlayer *)streamPlayer streamPlayerPlayingStateDidChange:(BOOL)playing;

/// 公共流播放器 公共流网络质量检测回调
///
/// @note 仅在 公共流观看 时会触发该回调(即 [publicStreamWatching]为YES时)；
///
/// @param streamPlayer 公共流播放器
/// @param netWorkQuality 网络质量
- (void)plvPublicStreamPlayer:(PLVPublicStreamPlayer *)streamPlayer publicStreamNetworkQuality:(PLVPublicStreamPlayerNetworkQuality)netWorkQuality;

@end

NS_ASSUME_NONNULL_END
