//
//  PLVDocumentUploadModel.h
//  PLVCloudClassStreamerSDK
//
//  Created by MissYasiky on 2020/4/3.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 文件上传状态
typedef NS_ENUM(NSInteger, PLVDocumentUploadStatus) {
    PLVDocumentUploadStatusUploading = 0, // 上传中（初始状态）
    PLVDocumentUploadStatusFailure, // 上传失败
    PLVDocumentUploadStatusSuccess, // 上传成功（等待转码）
    PLVDocumentUploadStatusConvertFailure, // 转码失败
};

typedef void (^PLVSUploadProgressBlock) (float progress);

/// 文档上传数据模型
@interface PLVDocumentUploadModel : NSObject

/// 文件Id
@property (nonatomic, copy) NSString *fileId;

/// 文件名
@property (nonatomic, copy) NSString *fileName;

/// 文件路径
@property (nonatomic, copy) NSString *filePath;

/// 文件转换类型：“common” 普通ppt ， “animate”动画PPT
@property (nonatomic, copy) NSString *convertType;

/// 文件上传进度
@property (nonatomic, assign) float progress;

/// 文件上传状态
@property (nonatomic, assign) PLVDocumentUploadStatus status;

/// 视频上传进度回调 block（该 block 运行在主线程，用于更新 UI）
@property (nonatomic, copy) PLVSUploadProgressBlock _Nullable uploadProgress;

/// 设置 PLVDocumentUploadStatus 状态
/// @param statusString 状态字符串
- (void)setupUploadStatusWithStatusStirng:(NSString *)statusString;

@end

NS_ASSUME_NONNULL_END
