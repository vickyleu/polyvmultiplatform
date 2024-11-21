//
//  PLVDownloadPathManager.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/5/23.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PLVDownloadPathManager;

/// 回调事件定义
/**
 用户Id改变事件回调

 @param manager 下载路径管理器
 @param viewerId 当前用户Id
 */
typedef void (^PLVDownloadViewerIdChangeBlock)(PLVDownloadPathManager * manager, NSString * viewerId);

/// 下载路径管理器（单例类）
@interface PLVDownloadPathManager : NSObject

#pragma mark - [ 属性 ]

#pragma mark 基础信息
/// 当前用户Id（可通过 setupDownloadViewerId: 配置）
@property (nonatomic, copy, readonly) NSString * viewerId;

/// 下载信息数据库的总目录
@property (nonatomic, copy, readonly) NSString * databaseHomePath;
/// 当前用户数据库文件的路径
@property (nonatomic, copy, readonly) NSString * databaseViewerFilePath;

/// 下载文件存放的总目录
@property (nonatomic, copy, readonly) NSString * fileCacheHomePath;
/// 下载文件存放的用户目录
@property (nonatomic, copy, readonly) NSString * fileCacheViewerPath;

#pragma mark 云课堂业务
/// 当前用户的云课堂回放路径
@property (nonatomic, copy, readonly) NSString * viewerPlaybackPath;

#pragma mark - [ 方法 ]

/// 获取单例类
+ (instancetype)shareManager;

/// 配置用户Id（不同用户的下载文件将分开存放管理；不配置该值，下载模块将无法使用；重复配置该Id，将切换数据库及下载文件路径）
- (void)setupDownloadViewerId:(NSString *)viewerId;

#pragma mark 云课堂业务
/// 某个回放相关文件路径
- (NSString *)playbackFileIdPath:(NSString *)fileId;
/// 某个回放的视频文件路径（读取后需按分辨率，找到对应文件）
- (NSString *)playbackFileIdVideoPath:(NSString *)fileId;
/// 某个回放的PPT文件路径
- (NSString *)playbackFileIdPPTPath:(NSString *)fileId;
/// 某个回放的Js文件路径
- (NSString *)playbackFileIdJsPath:(NSString *)fileId;

#pragma mark 辅助方法
/// 获取路径文件大小
- (unsigned long long)fileSizeForPath:(NSString *)path;
/// 检查路径已存在（若不存在，不会自动创建）
- (BOOL)checkPathExsit:(NSString *)path;
/// 确认文件夹已存在（若不存在，将自动创建文件夹）
- (void)ensureFolderExsit:(NSString *)folderPath;
/// 移除文件
- (NSError * _Nullable)removeFileWithPath:(NSString *)filePath;
/// 获取目标路径下，全部文件（不获取文件夹）
- (NSArray <NSString *> *)getAllFileAtFolderPath:(NSString *)folderPath;
/// 获取目标路径下，文件名包含特定字符的文件数组（不获取文件夹）
- (NSArray <NSString *> *)findFileAtFolderPath:(NSString *)folderPath stringInFileName:(NSString *)string;

#pragma mark 多接收方事件
/**
 添加一个Block接收 用户Id改变事件 （与上方属性Block事件，相互独立）
 
 @param block 事件回调
 @param blockKey 回调Key（不同调用方，以此字符串来区分注册）
 */
- (void)addViewerIdChangeBlock:(PLVDownloadViewerIdChangeBlock)block key:(NSString *)blockKey;

/**
 移除一个接收方 不再接收用户Id改变事件
 
 @param blockKey 接收方，在添加事件接收时所填Key
 */
- (void)removeViewerIdChangeWithKey:(NSString *)blockKey;

@end

NS_ASSUME_NONNULL_END
