//
//  PLVFDownloadErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFDownloadErrorCode){
    /// 视频信息相关
    PLVFDownloadErrorCodeGetVideoInfo_videoIdError = 622,
    PLVFDownloadErrorCodeGetVideoInfo_videoInfoError = 400,
    PLVFDownloadErrorCodeGetVideoInfo_videoUrlError = 402,
    
    /// 网络相关
    PLVFDownloadErrorCodeNetWork_noNetWork = 300,
    
    /// 下载文件相关
    PLVFDownloadErrorCodeDownloadFile_LocalExist = 626,
    PLVFDownloadErrorCodeDownloadFile_QueueExist = 627,
    PLVFDownloadErrorCodeDownloadFile_unZipFailed = 605,
    PLVFDownloadErrorCodeDownloadFile_writeDataFailed = 628,
    PLVFDownloadErrorCodeDownloadFile_notEnoughMemory = 607,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFDownloadErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFDownloadErrorCode)error;

+ (NSString *)errorDescription:(PLVFDownloadErrorCode)error;

@end

NS_ASSUME_NONNULL_END
