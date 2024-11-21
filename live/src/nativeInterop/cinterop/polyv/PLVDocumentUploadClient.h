//
//  PLVDocumentUploadClient.h
//  PLVCloudClassStreamerSDK
//
//  Created by MissYasiky on 2020/4/3.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVDocumentUploadModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PLVDocumentUploadErrorDelegate <NSObject>

- (void)uploadError:(NSError *)error;

@end

@protocol PLVDocumentUploadResultDelegate <NSObject>

/// 初次上传上传启动成功回调
- (void)uploadStartWithModel:(PLVDocumentUploadModel *)model;

/// 上传中断重新上传启动成功/失败回调
- (void)uploadRestartSuccess:(BOOL)success model:(PLVDocumentUploadModel *)model;

/// 失败重试重新上传启动成功/失败回调
- (void)uploadRetrySuccess:(BOOL)success model:(PLVDocumentUploadModel *)model;

/// 上传成功/失败时回调
- (void)uploadSuccess:(BOOL)success model:(PLVDocumentUploadModel *)model;

/// 清理所有上传中断任务时回调
- (void)updateUploadData;

@end

/// 文档上传管理器
@interface PLVDocumentUploadClient : NSObject

/// 上传过程错误情况回调
@property (nonatomic, weak) id<PLVDocumentUploadErrorDelegate> errorDelegate;

/// 上传结果回调，用于刷新页面，回调方法在主线程执行
@property (nonatomic, weak) id<PLVDocumentUploadResultDelegate> resultDelegate;

/// 用户是否【支持动效转码】
@property (nonatomic, assign, readonly) BOOL pptAnimationEnabled;

/// 上传任务队列（包含上传中、上传失败）
@property (nonatomic, copy, readonly) NSMutableArray <PLVDocumentUploadModel *> *uploadArray;

/// 上传中任务队列
@property (nonatomic, copy, readonly) NSMutableArray <PLVDocumentUploadModel *> *uploadingArray;

#pragma mark 初始化

+ (instancetype)sharedClient;

/// 初始化上传管理器，登录时调用
/// @note 用于 手机开播（三分屏）场景
/// @param channelId  登录频道号
/// @param pptAnimationEnabled 是否支持动效转码
- (void)setupWithChannelId:(NSString *)channelId pptAnimationEnable:(BOOL)pptAnimationEnabled;

/// 初始化上传管理器，登录时调用
/// @note 用于 互动学堂场景
/// @param channelId  登录频道号
/// @param lessionId  课节Id
/// @param pptAnimationEnabled 是否支持动效转码
- (void)setupWithChannelId:(NSString *)channelId lessionId:(NSString *)lessionId pptAnimationEnable:(BOOL)pptAnimationEnabled;

/// 初始化上传管理器，登录时调用
/// @note 用于 互动学堂场景
/// @param channelId  登录频道号
/// @param lessionId  课节Id
/// @param courseCode  课程号
/// @param pptAnimationEnabled 是否支持动效转码
/// @param teacher 是否为讲师
- (void)setupWithChannelId:(NSString *)channelId
                 lessionId:(NSString *)lessionId
                courseCode:(NSString * _Nullable)courseCode
        pptAnimationEnable:(BOOL)pptAnimationEnabled
                   teacher:(BOOL)teacher;

#pragma mark 通用方法

/// 新增文档上传
/// @param fileURL 待上传文档 URL
/// @param convertType 转码类型
- (void)uploadDocumentWithFileURL:(NSURL *)fileURL convertType:(NSString *)convertType;

/// 移除上传任务
/// @param fileId 上传任务的 fileId
- (void)removeUploadWithFileId:(NSString *)fileId;

/// 删除沙盒文档
/// @param fileName 文件名称
- (void)deleteFileWithFileName:(NSString *)fileName;

/// 中断之后，恢复所有上传中任务
- (void)continueAllUpload;

/// 中断之后，移除所有上传中任务
- (void)clearAllUpload;

/// 停止所有上传任务
- (void)stopAllUpload;

#pragma mark 手机开播（三分屏）场景
/// 失败重试
/// @note 用于 手机开播（三分屏）场景
/// @param fileId 失败任务的 fileId
- (void)retryUploadWithFileId:(NSString *)fileId;

#pragma mark 互动学堂 场景
/// 失败重试
/// @note 用于 互动学堂 场景 (支持重启APP后重试)
/// @param model 文档模型
- (void)retryUploadWithModel:(PLVDocumentUploadModel *)model;

/// 重新上传 转码失败文档
/// @note 用于 互动学堂 场景（支持重启APP后重试）
/// @param model 文档模型
- (void)retryUploadConvertFailureDocumentWithModel:(PLVDocumentUploadModel *)model;

@end

NS_ASSUME_NONNULL_END
