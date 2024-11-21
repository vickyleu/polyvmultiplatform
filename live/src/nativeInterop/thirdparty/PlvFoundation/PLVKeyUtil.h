//
//  PLVKeyUtil.h
//  PLVFoundationSDK
//
//  Created by Dhan on 2022/9/14.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Key工具类常量

extern NSString *const ALI_DNS_AUTH_KEY;

extern NSString *const ALI_DNS_AUTH_IV;

extern NSString *const LINK_MIC_AUTH_KEY;

extern NSString *const LINK_MIC_AUTH_IV;

extern NSString *const UTILS_AUTH_KEY;

extern NSString *const UTILS_AUTH_IV;

extern NSString *const CHANNEL_INFO_AUTH_KEY;

extern NSString *const CHANNEL_INFO_AUTH_IV;

extern NSString *const API_UTILS_AUTH_KEY;

extern NSString *const API_UTILS_AUTH_IV;

extern NSString *const API_UTILS_AUTH_PUBLIC_KEY;

extern NSString *const API_UTILS_AUTH_PRIVATE_KEY;

extern NSString *const API_LOG_UTILS_KEY;

#pragma mark - Key工具类

@interface PLVKeyUtil : NSObject

/**
工具类初始化方法
 */
+ (void)setUp;

+ (NSString *)getAliKey;

+ (NSString *)getAliIv;

+ (NSString *)getLinkMicKey;

+ (NSString *)getLinkMicIv;

+ (NSString *)getUtilsKey;

+ (NSString *)getUtilsIv;

+ (NSString *)getChannelInfoKey;

+ (NSString *)getChannelInfoIv;

+ (NSString *)getApiUtilsKey;

+ (NSString *)getApiUtilsIv;

+ (NSString *)getApiUtilsPublicKey;

+ (NSString *)getApiUtilsPrivateKey;

+ (NSString *)getApiLogUtilsKey;

@end

NS_ASSUME_NONNULL_END
