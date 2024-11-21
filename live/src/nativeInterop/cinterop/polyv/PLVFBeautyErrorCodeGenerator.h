//
//  PLVFBeautyErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by junotang on 2022/6/5.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFBeautyErrorCode){
    /* http 接口请求错误 */
    /// 美颜设置接口
    PLVFBeautyErrorCodeBeautySetting_ParameterError = 101,
    PLVFBeautyErrorCodeBeautySetting_CodeError = 102,
    PLVFBeautyErrorCodeBeautySetting_DataError = 103,
    /// 美颜资源接口
    PLVFBeautyErrorCodeBeautyResource_ParameterError = 104,
    PLVFBeautyErrorCodeBeautyResource_CodeError = 105,
    PLVFBeautyErrorCodeBeautyResource_DataError = 106,
    /// 美颜资源处理错误
    PLVFBeautyErrorCodeResourceHandle_UnzipError = 401,
    /// 美颜sdk错误
    PLVFBeautyErrorCodeBeautySDK_ProcessError = 501,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFBeautyErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFBeautyErrorCode)error;

+ (NSString *)errorDescription:(PLVFBeautyErrorCode)error;

@end

NS_ASSUME_NONNULL_END
