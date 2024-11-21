//
//  PLVBPublicStreamVOLCPlayer.h
//  PLVBusinessSDK
//
//  Created by juno on 2022/9/13.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVBPublicStreamPlayerDelegate;

/// 火山RTC用于订阅播放公共流的播放器
@interface PLVBPublicStreamVOLCPlayer : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// 代理
@property (nonatomic, weak) id <PLVBPublicStreamPlayerDelegate> delegate;

#pragma mark - [ 方法 ]

/// 更新公共流信息
- (void)updatePublicStreamInfoWithStr:(NSString *)publicStreamInfoStr;

/// 创建 RTC引擎
- (void)createRTCEngine;

/// 设置负责承载播放器画面的父视图
/// @param displaySuperview 承载播放器画面的父视图，为空则不渲染stream
/// @return  0成功、!0失败
- (int)setupDisplaySuperview:(UIView *_Nullable)displaySuperview;

/// 播放;return 0成功、!0失败
- (int)play;

/// 停止;return 0成功、!0失败
- (int)stop;

/// 销毁 RTC引擎
- (void)destroyRTCEngine;

@end

#pragma mark - [ 代理方法 ]
/// PLVBPublicStreamVOLCPlayer 的 Delegate
@protocol PLVBPublicStreamPlayerDelegate <NSObject>

@optional

/// 公共流拉流质量统计回调
/// @param streamPlayer 公共流播放器
/// @param videoLossRate 视频丢包率。统计周期内的音频下行丢包率，取值范围为 [0, 1]
/// @param audioLossRate 音频丢包率。统计周期内的音频下行丢包率，取值范围为 [0, 1]
- (void)plvbPublicStreamPlayer:(PLVBPublicStreamVOLCPlayer * _Nonnull)streamPlayer videoLossRate:(float)videoLossRate audioLossRate:(float)audioLossRate;

@end

NS_ASSUME_NONNULL_END
