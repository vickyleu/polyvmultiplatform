//
//  PLVDownloadManager.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/5/23.
//  Copyright © 2022 PLV. All rights reserved.
//
// 下载管理器

#import <Foundation/Foundation.h>
#import "PLVDownloadTaskInfo.h"

NS_ASSUME_NONNULL_BEGIN

/// 下载管理器（单例类）
@interface PLVDownloadManager : NSObject

#pragma mark - [ 属性 ]

#pragma mark 可配置项
/// 最高下载并发数（默认，3个；可设置此值，自定义最大下载并发数）
@property (nonatomic, assign) NSInteger maxConcurrentDownloads;
/// 当前下载的并发数（已入队列的任务数）
@property (nonatomic, assign, readonly) NSUInteger currentQueueCount;
/// 当前下载的并发执行数（正在下载的任务数）
@property (nonatomic, assign, readonly) NSUInteger currentDownloadCount;

#pragma mark 账号信息
/// 用户唯一标识，用于登录socket、发送日志
@property (nonatomic, copy) NSString *viewerId;
/// 用户昵称，用于登录socket、发送日志
@property (nonatomic, copy) NSString *viewerName;
/// 用户头像地址，用于登录socket
@property (nonatomic, copy) NSString *viewerAvatar;

#pragma mark - [ 方法 ]

/// 获取单例
+ (instancetype)shareManager;

#pragma mark 任务控制
/// 添加一个下载任务（不会自动开始下载）
- (void)addDownloadTaskWith:(PLVDownloadTaskInfo *)taskInfo;
/// 删除一个下载任务（将删除对应下载文件）
- (void)deleteDownloadTaskWith:(PLVDownloadTaskInfo *)taskInfo;

#pragma mark 下载控制
/// 指定一个下载任务，开始下载
- (void)startDownloadWith:(PLVDownloadTaskInfo *)taskInfo;
/// 指定一个下载任务，暂停下载
- (void)stopDownloadWith:(PLVDownloadTaskInfo *)taskInfo;

@end

NS_ASSUME_NONNULL_END
