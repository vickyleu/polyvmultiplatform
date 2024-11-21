//
//  PLVDownloadDatabaseManager+Playback.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/5/23.
//  Copyright © 2022 PLV. All rights reserved.
//

#import "PLVDownloadDatabaseManager.h"

#import "PLVDownloadPlaybackTaskInfo.h"

NS_ASSUME_NONNULL_BEGIN

/// 数据库管理器 [云课堂回放相关]（若需处理云课堂回放相关数据，直接引用该扩展即可）
@interface PLVDownloadDatabaseManager ()

#pragma mark - [ 属性 ]

#pragma mark 下载任务数组 [云课堂回放]
/// 所有的回放下载任务 数组
@property (nonatomic, strong, readonly) NSArray <PLVDownloadPlaybackTaskInfo *> * totalPlaybackTaskInfoArray;
/// 下载完成的回放下载 数组
@property (nonatomic, strong, readonly) NSArray <PLVDownloadPlaybackTaskInfo *> * completedPlaybackTaskInfoArray;
/// 下载未完成的回放下载 数组
@property (nonatomic, strong, readonly) NSArray <PLVDownloadPlaybackTaskInfo *> * unfinishedPlaybackTaskInfoArray;

#pragma mark - [ 方法 ]

#pragma mark 数据控制 [云课堂回放]
/**
 判断一个回放，是否已存在下载记录（不考虑下载状态）
 
 @param fileId 回放视频Id，fileId
 @return 检查结果（YES存在 / NO不存在）
 */
- (BOOL)checkPlaybackTaskInfoWithFileId:(NSString *)fileId;

/**
 判断一个回放，是否已存在下载记录（不考虑下载状态）
 
 @param fileId 回放视频Id，fileId
 @return 检查结果（taskInfo对象，存在 / nil，不存在；使用时，可通过判断该对象的state，来确认是否下载完成）
 */
- (PLVDownloadPlaybackTaskInfo *)checkAndGetPlaybackTaskInfoWithFileId:(NSString *)fileId;

/**
 判断一个回放，是否已存在下载记录（不考虑下载状态,只有回放列表、点播列表的TaskInfo才能通过videopoolId查找）
 
 @param videopoolId 回放视频Id，videopoolId
 @return 检查结果（taskInfo对象，存在 / nil，不存在；使用时，可通过判断该对象的state，来确认是否下载完成）
 */
- (PLVDownloadPlaybackTaskInfo *)checkAndGetPlaybackTaskInfoWithVideoPoolId:(NSString *)videopoolId;

/**
 添加一个回放下载任务（若任务已存在于数据库，将添加失败）
 
 @param taskInfo 回放下载任务信息模型
 @return 添加结果（YES成功 / NO失败）
 */
- (BOOL)addPlaybackTaskInfo:(PLVDownloadPlaybackTaskInfo *)taskInfo;

/**
 删除一个回放下载任务（若任务已不存在于数据库，将删除失败）
 
 @param taskInfo 回放下载任务信息模型
 @return 删除结果（YES成功 / NO失败）
 */
- (BOOL)deletePlaybackTaskInfo:(PLVDownloadPlaybackTaskInfo *)taskInfo;

@end

NS_ASSUME_NONNULL_END
