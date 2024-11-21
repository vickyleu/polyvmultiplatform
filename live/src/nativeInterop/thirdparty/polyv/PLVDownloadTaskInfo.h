//
//  PLVDownloadTaskInfo.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/5/23.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVLiveDefine.h"
#import <PLVFoundationSDK/PLVFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class PLVDownloadTaskInfo;

/// 下载状态定义对应文本
NS_INLINE NSString * _Nonnull NSStringFromPLVDownloadState(PLVDownloadState state) {
    NSString * string;
    switch (state) {
        case PLVDownloadStateDefault:{string = PLVFDLocalizableString(@"默认"); }break;
            
        case PLVDownloadStatePreparing:{string = PLVFDLocalizableString(@"准备中"); }break;
        case PLVDownloadStatePrepared:{string = PLVFDLocalizableString(@"已准备"); }break;
            
        case PLVDownloadStateWaiting:{string = PLVFDLocalizableString(@"等待中"); }break;
        case PLVDownloadStateDownloading:{string = PLVFDLocalizableString(@"下载中"); }break;
            
        case PLVDownloadStateUnzipping:{string = PLVFDLocalizableString(@"正在解压"); }break;
        case PLVDownloadStateUnzipped:{string = PLVFDLocalizableString(@"解压结束"); }break;

        case PLVDownloadStateStopped:{string = PLVFDLocalizableString(@"已停止"); }break;
        case PLVDownloadStateSuccess:{string = PLVFDLocalizableString(@"下载成功"); }break;
        case PLVDownloadStateFailed:{string = PLVFDLocalizableString(@"下载失败"); }break;
            
        default:{string = PLVFDLocalizableString(@"未知"); }break;
    }
    return string;
}

/// 下载事件定义
/**
 下载文件解压进度改变事件

 @param taskInfo 对应的下载信息模型
 @param entryNumber 已解压文件大小
 @param total 总解压文件大小
 */
typedef void (^PLVDownloadUnzipProgressChangeBlock)(PLVDownloadTaskInfo * _Nullable taskInfo, long entryNumber, long total);

/**
 下载文件解压完成事件

 @param taskInfo 对应的下载信息模型
 @param succeeded 是否解压成功
 @param error 解压错误（若成功则为nil）
 */
typedef void (^PLVDownloadUnzipCompletedBlock)(PLVDownloadTaskInfo * _Nullable taskInfo, BOOL succeeded, NSError * _Nullable error);

/**
 下载进度改变事件

 @param taskInfo 对应的下载信息模型
 @param receivedSize 已接收文件大小（单位，bytes）
 @param expectedSize 总接收文件大小（单位，bytes）
 @param progress 下载百分比
 @param speedValue 下载速度值（单位，KB/s）
 */
typedef void (^PLVDownloadProgressChangeBlock)(PLVDownloadTaskInfo * _Nullable taskInfo, unsigned long long receivedSize, unsigned long long expectedSize, float progress, float speedValue);

/**
 下载状态改变事件

 @param taskInfo 对应的下载信息模型
 @param state 当期改变到的状态
 */
typedef void (^PLVDownloadStateChangeBlock)(PLVDownloadTaskInfo * _Nullable taskInfo, PLVDownloadState state);

/**
 下载完成事件

 @param taskInfo 对应的下载信息模型
 @param error 下载错误（若成功则为nil）
 */
typedef void (^PLVDownloadCompletedBlock)(PLVDownloadTaskInfo * _Nullable taskInfo, NSError * _Nullable error);

/// 下载任务信息模型，描述一个下载任务
@interface PLVDownloadTaskInfo : NSObject

#pragma mark - [ 属性 ]

#pragma mark 基础信息
/// 下载任务的Id（自动根据url链接生成Id；若需自定义Id，可使用customModel自定义模型）
@property (nonatomic, copy, readonly) NSString *taskInfoId;
@property (nonatomic, copy) NSString *fileId;
/// 任务下载链接
@property (nonatomic, copy) NSString *url;
/// 文件保存路径
@property (nonatomic, copy, readonly) NSString *filePath;
/// 文件名
@property (nonatomic, copy, readonly) NSString *fileName;
/// 当前下载状态
@property (nonatomic, assign, readonly) PLVDownloadState state;

#pragma mark 过程信息
/// 下载速度值（单位，KB/s）
@property (nonatomic, assign, readonly) float speedValue;
/// 下载速度（附带单位字符串，bytes/s、KB/s、MB/s、GB/s）
@property (nonatomic, copy, readonly) NSString *speed;
/// 下载进度值（范围，0~1）
@property (nonatomic, assign, readonly) float progress;

#pragma mark 过程详细信息
/// 已下载数据大小数值（单位，bytes）
@property (nonatomic, assign, readonly) unsigned long long totalBytesWritten;
/// 已下载数据大小（附带单位字符串，bytes、KB、MB、GB）
@property (nonatomic, copy, readonly) NSString * totalBytesWrittenString;
/// 任务总数据大小数值（单位，bytes；可赋值，但最终以请求结果返回值为准；提前赋值的目的，是任务未开始下载时，任务总大小也不为0）
@property (nonatomic, assign) unsigned long long totalBytesExpectedToWrite;
/// 任务总数据大小（附带单位字符串，bytes、KB、MB、GB）
@property (nonatomic, copy, readonly) NSString * totalBytesExpectedToWriteString;

#pragma mark 结果信息
/// 下载错误（若下载成功，则为nil)
@property (nonatomic, strong, readonly, nullable) NSError *error;

#pragma mark 自定义信息
/// 自定义模型（该模型中可定义所需的属性；遵循协议实现方法后，数据将一并被入库保存）
@property (nonatomic, strong) NSObject * customModel;

#pragma mark 辅助属性
/// 是否提前获取文件大小（适用于添加下载任务时，不知文件大小的场景；YES - 添加任务后即使任务未开始，也可获取到文件大小；默认NO）
@property (nonatomic, assign) BOOL preGetFileSize;

@property (nonatomic, assign) BOOL deleteZipFileWhenUnzip;// 解压完成后是否删除zip文件

#pragma mark 事件
/**
 以下事件，若在TableViewCell中使用，可通过Cell自持有TaskInfoId值，回调时判断与回调携带的TaskInfoId是否匹配，来保证Cell复用不受影响
 */
/// 下载文件解压进度改变事件
@property (nonatomic, strong) PLVDownloadUnzipProgressChangeBlock downloadUnzipProgressChangeBlock;
/// 下载文件解压完成事件
@property (nonatomic, strong) PLVDownloadUnzipCompletedBlock downloadUnzipCompletedBlock;
/// 下载进度改变事件
@property (nonatomic, strong) PLVDownloadProgressChangeBlock downloadProgressChangeBlock;
/// 下载状态改变事件
@property (nonatomic, strong) PLVDownloadStateChangeBlock downloadStateChangeBlock;
/// 下载完成事件
@property (nonatomic, strong) PLVDownloadCompletedBlock downloadCompletedBlock;

#pragma mark - [ 方法 ]

#pragma mark 多接收方事件
/**
 一般场景可通过上方Block事件满足，不必使用以下多接收方事件进行事件接收
 */

/**
 添加一个Block接收 下载状态改变事件 （与上方属性Block事件，相互独立）
 
 @param block 事件回调
 @param blockKey 回调Key（不同调用方，以此字符串来区分注册）
 */
- (void)addDownloadStateChangeBlock:(PLVDownloadStateChangeBlock)block key:(NSString *)blockKey;

/**
 移除一个接收方 不再接收下载状态改变事件

 @param blockKey 接收方，在添加事件接收时所填Key
 */
- (void)removeDownloadStateChangeBlockWithKey:(NSString *)blockKey;

/**
 添加一个Block接收 下载完成事件 （与上方属性Block事件，相互独立）
 
 @param block 事件回调
 @param blockKey 回调Key（不同调用方，以此字符串来区分注册）
 */
- (void)addDownloadCompletedBlock:(PLVDownloadCompletedBlock)block key:(NSString *)blockKey;

/**
 移除一个接收方 不再接收下载完成事件
 
 @param blockKey 接收方，在添加事件接收时所填Key
 */
- (void)removeDownloadCompletedBlockWithKey:(NSString *)blockKey;

@end

NS_ASSUME_NONNULL_END
