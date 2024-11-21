//
//  PLVPlaybackMessageManager.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2022/6/6.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PLVPlaybackMessage;

NS_ASSUME_NONNULL_BEGIN

@protocol PLVPlaybackMessageManagerDelegate;

/// 聊天重放消息管理器
@interface PLVPlaybackMessageManager : NSObject

#pragma mark 可配置属性

@property (nonatomic, weak) id<PLVPlaybackMessageManagerDelegate> delegate;
/// 预加载消息最大数目，默认200
@property (nonatomic, assign) NSUInteger maxPreloadCount;

#pragma mark 只读属性

/// 频道号
@property (nonatomic, copy, readonly) NSString *channelId;
/// 回放场次id
@property (nonatomic, copy, readonly) NSString *sessionId;
/// 回放视频id
@property (nonatomic, copy, readonly) NSString *videoId;

#pragma mark 方法

/// 初始化方法
/// @param channelId 频道号
/// @param sessionId 当场回放的场次id
/// @param videoId 当前回放的视频id
- (instancetype)initWithChannelId:(NSString *)channelId sessionId:(NSString *)sessionId videoId:(NSString *)videoId;

/// 从预加载数组中获取指定时间区间内的消息
/// 注意，预加载数组只保存当前播放节点至未来kPreloadTime的时间段内，数量不超过maxPreloadCount条数的消息
- (NSArray <PLVPlaybackMessage *>*)playbackMessagInPreloadMessagesFrom:(NSTimeInterval)startTime to:(NSTimeInterval)endTime;

/// 获取指定时间之前的消息
- (void)loadMorePlaybackMessagBefore:(NSTimeInterval)playbackTime;

@end

@protocol PLVPlaybackMessageManagerDelegate <NSObject>

/// 首次获取回放数据的分段信息后触发
/// @param success YES-已获取到回放数据分段信息 NO-获取数据失败或获取到的数据为空
- (void)loadMessageInfoSuccess:(BOOL)success playbackMessageManager:(PLVPlaybackMessageManager *)manager;

/// 定时获取当前视频播放时间节点
- (NSTimeInterval)currentPlaybackTimeForPlaybackMessageManager:(PLVPlaybackMessageManager *)manager;

/// 方法 '-loadMorePlaybackMessagBefore:' 触发，返回获取到的消息数组
- (void)loadMoreHistoryMessagesSuccess:(NSArray <PLVPlaybackMessage *>*)playbackMessags playbackMessageManager:(PLVPlaybackMessageManager *)manager;

@end

NS_ASSUME_NONNULL_END
