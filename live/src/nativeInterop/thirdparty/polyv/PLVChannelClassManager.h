//
//  PLVChannelClassManager.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2021/8/9.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PLVLiveDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PLVChannelClassManagerDelegate;

/// 频道上下课状态管理器
@interface PLVChannelClassManager : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// delegate
@property (nonatomic, weak) id <PLVChannelClassManagerDelegate> delegate;

#pragma mark 状态
/// 当前频道的 ‘直播流状态’
///
/// @note 枚举类型详见 PLVLiveDefine.h
@property (nonatomic, assign, readonly) PLVChannelLiveStreamState currentStreamState;

#pragma mark 数据
/// 场次Id
@property (nonatomic, copy, readonly) NSString * sessionId;

/// 获取到的 开始推流时间戳 (单位毫秒；非 PLVChannelLiveStreamState_Live 状态下，可能获取到上一场次数值)
@property (nonatomic, assign, readonly) NSTimeInterval pushtimeTimestamp;

/// 获取到的 已推流时长 (单位毫秒；非 PLVChannelLiveStreamState_Live 状态下，可能获取到上一场次数值)
@property (nonatomic, assign, readonly) NSTimeInterval pushDuration;

/// 当前 已推流时长 (单位秒，带小数，可精确至毫秒；非 PLVChannelLiveStreamState_Live 状态下，不建议参考此数值)
@property (nonatomic, assign, readonly) NSTimeInterval currentPushDuration;


#pragma mark - [ 方法 ]

/// 创建道上下课状态管理器
/// 
/// @param channelId 频道号ID
- (instancetype)initWithChannelId:(NSString *)channelId;

/// 开始监听 ‘流状态’ 变化
///
/// @note 开始监听后，将定时触发 ‘流状态请求成功Block’ 或 ‘流状态请求失败Block’；
///       随着 PLVChannelClassManager对象 被释放，内部计时器将自行释放，无需要求必须调用 [stopObserveStreamState] 方法；
///
/// @param stream 流名
/// @param completion 流状态请求成功Block
/// @param failure 流状态请求失败Block
- (void)startObserveStreamStateWithStream:(NSString *)stream completion:(void (^)(PLVChannelLiveStreamState streamState,BOOL streamStateDidChanged))completion failure:(void (^)(NSError * _Nonnull error))failure;

/// 停止监听 ‘流状态’ 变化
///
/// @note 随着 PLVChannelClassManager对象 被释放，内部计时器将自行释放，无需要求必须调用 [stopObserveStreamState] 方法；
///       若是不希望释放 PLVChannelClassManager对象，而又不再需要监听 ‘流状态’ 变化，则可使用该方法；
- (void)stopObserveStreamState;

@end


#pragma mark - [ 代理方法 ]
/// PLVChannelClassManager 的 Delegate
@protocol PLVChannelClassManagerDelegate <NSObject>

@optional
/// 当前 ’已推流时长‘ 定时回调
///
/// @note 基于 ’获取到的 开始推流时间戳‘ 计算所得；
///       每1秒回调通知一次最新值；
///
/// @param manager 频道上下课状态管理器
/// @param currentPushDuration 当前 已推流时长 (单位秒，带小数，可精确至毫秒)
- (void)plvChannelClassManager:(PLVChannelClassManager *)manager currentPushDuration:(NSTimeInterval)currentPushDuration;

@end

NS_ASSUME_NONNULL_END
