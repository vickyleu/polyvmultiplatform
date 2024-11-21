//
//  PLVConfig.h
//  PLVFoundationSDK
//
//  Created by zykhbl on 2018/9/6.
//  Copyright © 2018年 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PLVLogLevel) {
    PLVLogLevelNoLog = 0,
    PLVLogLevelDebug = 1,
    PLVLogLevelInfo  = 2,
    PLVLogLevelError = 3
};

@protocol PLVConfig <NSObject>

/// 播放器名字
@property (nonatomic, strong) NSString *playerName;
/// 播放器版本
@property (nonatomic, strong) NSString *playerVersion;

/// PLV 云直播账号ID
@property (nonatomic, strong) NSString *userId;
/// PLV 云直播应用ID
@property (nonatomic, strong) NSString *appId;
/// PLV 云直播应用密匙
@property (nonatomic, strong) NSString *appSecret;
/// 日志级别
@property (nonatomic, assign) PLVLogLevel logLevel;

/* 以下单例属性可能会被废弃 */

/// userAgent
@property (nonatomic, strong) NSString *userAgent;

/// 播放器Id
@property (nonatomic, strong) NSString *playerId;

/// 单例方法
+ (instancetype)sharedInstance;

/// 设置播放器版本信息
+ (void)setPlayerVersion:(NSString *)playerVersion;

/// 设置PLV Live SDK LOG等级
+ (void)setLogLevel:(PLVLogLevel)logLevel;

+ (NSString *)playerVersion;

+ (NSString *)playerName;

+ (NSString *)userAgent;

+ (PLVLogLevel)logLevel;

+ (NSString *)createPlayerId;

@end
