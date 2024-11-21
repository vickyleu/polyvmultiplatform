//
//  PLVFLinkErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFLinkErrorCode){
    /* http 接口请求错误 */
    /// notify stream 接口
    PLVFLinkErrorCodeNotifyStreamFailed_ParameterError = 101,
    PLVFLinkErrorCodeNotifyStreamFailed_DataError = 103,

    /// 获取连麦Token接口
    PLVFLinkErrorCodeMicAuthFailed_ParameterError = 104,
    PLVFLinkErrorCodeMicAuthFailed_CodeError = 105,
    PLVFLinkErrorCodeMicAuthFailed_DataError = 106,

    /// 获取连麦SessionID接口
    PLVFLinkErrorCodeChannelSessionIDFailed_ParameterError = 107,

    /// 获取推流频道信息接口
    PLVFLinkErrorCodeTeacherLoginFailed_ParameterError = 110,
    PLVFLinkErrorCodeTeacherLoginFailed_DataError = 112,

    /// 更新频道直播状态接口
    PLVFLinkErrorCodeLivestatusEndFailed_ParameterError = 116,
    PLVFLinkErrorCodeLivestatusEndFailed_CodeError = 117,
    PLVFLinkErrorCodeLivestatusEndFailed_DataError = 118,
    
    /// 混流配置接口
    PLVFLinkErrorCodeMixActionFailed_ParameterError = 119,
    PLVFLinkErrorCodeMixActionFailed_CodeError = 120,
    PLVFLinkErrorCodeMixActionFailed_DataError = 121,
    
    /// RTC错误
    PLVFLinkErrorCodeStreamPublishFailed = 401,
    PLVFLinkErrorCodeJoinChannelFailed = 402,
    PLVFLinkErrorCodeAddPublishStreamUrlFailed = 403,
    
    /// 系统错误
    PLVFLinkErrorCodeUnauthorized = 501,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFLinkErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFLinkErrorCode)error;

+ (NSString *)errorDescription:(PLVFLinkErrorCode)error;

@end

NS_ASSUME_NONNULL_END
