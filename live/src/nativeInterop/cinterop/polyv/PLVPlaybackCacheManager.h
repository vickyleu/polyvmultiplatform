//
//  PLVPlaybackCacheManager.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/5/24.
//  Copyright © 2022 PLV. All rights reserved.
//
//  回放缓存管理器

#import <Foundation/Foundation.h>
#import "PLVPlaybackVideoInfoModel.h"
#import "PLVDownloadPlaybackTaskInfo.h"
#import "PLVLiveDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLVPlaybackCacheManager : NSObject

+ (PLVPlaybackVideoCacheState)stateOfPlaybackPlayerCacheState:(NSString *)fileId;

+ (void)asynGetPlaybackPlayerCacheState:(NSString *)fileId completion:(void (^)(PLVPlaybackVideoCacheState state))completion;

/// 添加 videoPoolId 至下载队列 (适用于回放列表、点播列表这两个有videoPoolId 的视频下载)
+ (void)enqueueDownloadQueueWithVideoPoolId:(NSString *)videoPoolId
                                  channelId:(NSString *)channelId
                                 completion:(void (^)(NSError *error))completion;

/// 添加 暂存视频的 fileId 至下载队列 （仅适用于暂存视频的下载）
+ (void)enqueueDownloadQueueWithRecordFileId:(NSString *)fileId
                                   channelId:(NSString *)channelId
                                  completion:(void (^)(NSError *error))completion;

/// 添加 PLVPlaybackVideoInfoModel 至下载队列
+ (void)enqueueDownloadQueueWithPlaybackPlayerModel:(PLVPlaybackVideoInfoModel *)playerModel
                                         completion:(void (^)(NSError *error))completion;

@end

@interface PLVPlaybackCacheManager (PlayerModelBuilder)

/// 通过本地/在线数据生成回放列表/点播列表中的视频信息模型 (将优先判断是否存在本地数据)
+ (void)playbackVideoInfoModelWithVid:(NSString *)vid
                            channelId:(NSString *)channelId
                             listType:(NSString *)listType
                           completion:(void (^)(PLVPlaybackVideoInfoModel *model, NSError *error))completion;

/// 通过在线数据生成回放列表/点播列表中的视频信息模型
+ (void)loadOnlinePlaybackVideoInfoModelWithVid:(NSString *)vid
                                      channelId:(NSString *)channelId
                                       listType:(NSString *)listType
                                     completion:(void (^)(PLVPlaybackVideoInfoModel *model, NSError *error))completion;

/// 通过本地/在线数据生成暂存列表中的视频信息模型 (将优先判断是否存在本地数据)
+ (void)recordPlaybackVideoInfoModelWithFileId:(NSString *)fileId
                                     channelId:(NSString *)channelId
                                    completion:(void (^)(PLVPlaybackVideoInfoModel *model, NSError *error))completion;

/// 通过在线数据生成暂存列表中的视频信息模型
+ (void)loadOnlineRecordPlaybackVideoInfoModelWithFileId:(NSString *)fileId
                                               channelId:(NSString *)channelId
                                              completion:(void (^)(PLVPlaybackVideoInfoModel *model, NSError *error))completion;


@end

@interface PLVPlaybackCacheManager (ModelAdapter)

/// 下载回放模型 -> 本地播放回放模型
+ (PLVPlaybackLocalVideoInfoModel *)toPlaybackPlayerModel:(PLVDownloadPlaybackTaskInfo *)taskInfo;

/// 在线播放回放模型 -> 下载回放模型
+ (PLVDownloadPlaybackTaskInfo *)toDownloadPlaybackTaskInfo:(PLVPlaybackVideoInfoModel *)model;

@end

NS_ASSUME_NONNULL_END
