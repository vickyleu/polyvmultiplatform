//
//  PLVFPlayErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFPlayErrorCode){
    /// 回放信息 接口
    PLVFPlayErrorCodeGetVideoInfo_ParameterError = 524,
    PLVFPlayErrorCodeGetVideoInfo_CodeError = 508,
    PLVFPlayErrorCodeGetVideoInfo_DataError = 509,
    PLVFPlayErrorCodeGetVideoInfo_FileUrlError = 510,
    PLVFPlayErrorCodeGetVideoInfo_RequestFailed = 511,

    /// 频道信息 接口
    PLVFPlayErrorCodeGetChannelInfo_ParameterError = 525,
    PLVFPlayErrorCodeGetChannelInfo_CodeError = 514,
    PLVFPlayErrorCodeGetChannelInfo_DataError = 513,
    PLVFPlayErrorCodeGetChannelInfo_RequestFailed = 512,
    
    /// 限制信息
    PLVFPlayErrorCodeChannelRestrict_PlayRestrict = 515,
    PLVFPlayErrorCodeChannelRestrict_RequestFailed = 516,

    /// 网络不佳
    PLVFPlayErrorCodeNetwork_NotGoodNetwork = 526,
    
    /// 直播流状态信息 接口
    PLVFPlayErrorCodeGetStreamState_ParameterError = 527,
    PLVFPlayErrorCodeGetStreamState_CodeError = 518,
    PLVFPlayErrorCodeGetStreamState_DataError = 517,
    PLVFPlayErrorCodeGetStreamState_RequestFailed = 519,
    
    /// SessionID 接口
    PLVFPlayErrorCodeGetSessionID_ParameterError = 528,
    PLVFPlayErrorCodeGetSessionID_RequestFailed = 523,
    
    /// 画中画
    PLVFPlayErrorCodePictureInPicture_OpenError = 529,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFPlayErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFPlayErrorCode)error;

+ (NSString *)errorDescription:(PLVFPlayErrorCode)error;

@end

NS_ASSUME_NONNULL_END
