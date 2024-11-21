//
//  PLVFUploadErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFUploadErrorCode){
    /* http 接口请求错误 */
    /// 获取文档上传 token 接口
    PLVFUploadErrorCodeGetToken_ParameterError = 101,
    PLVFUploadErrorCodeGetToken_CodeError = 102,
    PLVFUploadErrorCodeGetToken_DataError = 103,
    
    /* 文档上传相关异常 */
    /// 拷贝文档到沙盒失败
    PLVFUploadErrorCodeDocumentCopyError = 401,
    /// 文档上传任务已存在（本地判断）
    PLVFUploadErrorCodeDocumentUploadingExist = 402,
    /// 文档已存在服务端（接口返回）
    PLVFUploadErrorCodeDocumentUploadedExist = 403,
    /// 阿里 OSS 上传失败
    PLVFUploadErrorCodeDocumentOSSTaskError = 404,
    /// 刷新 OSS Client STS token 接口失败
    PLVFUploadErrorCodeDocumentOSSTokenRefreshError = 405
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFUploadErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFUploadErrorCode)error;

+ (NSString *)errorDescription:(PLVFUploadErrorCode)error;

@end

NS_ASSUME_NONNULL_END
