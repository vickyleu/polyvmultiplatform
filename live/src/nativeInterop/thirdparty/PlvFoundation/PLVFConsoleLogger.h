//
//  PLVFConsoleLogger.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2020/2/20.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PLVFConsoleLogType) {
    PLVFConsoleLogTypeERROR     = 1 << 0,
    PLVFConsoleLogTypeWARN      = 1 << 1,
    PLVFConsoleLogTypeDEBUG     = 1 << 2,
    PLVFConsoleLogTypeINFO      = 1 << 3
};

typedef NS_ENUM(NSUInteger, PLVFConsoleLogLevel) {
    ///关闭所有打印
    PLVFConsoleLogLevelOFF      = 0,
    ///只允许打印ERROR级别打印
    PLVFConsoleLogLevelERROR    = PLVFConsoleLogTypeERROR,
    ///允许打印ERROR、WARN级别打印
    PLVFConsoleLogLevelWARN     = PLVFConsoleLogTypeERROR  | PLVFConsoleLogTypeWARN,
    ///允许打印INFO、DEBUG级别打印
    PLVFConsoleLogLevelDEBUG    = PLVFConsoleLogTypeINFO   | PLVFConsoleLogTypeDEBUG,
    ///只允许打印INFO级别打印
    PLVFConsoleLogLevelINFO     = PLVFConsoleLogTypeINFO,
    ///允许所有级别打印
    PLVFConsoleLogLevelALL      = 0xF
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFConsoleLogger : NSObject
///打印等级
@property (nonatomic, assign) PLVFConsoleLogLevel logLevel;

+ (instancetype)defaultLogger;

- (void)logWithModule:(NSString * _Nullable)module type:(PLVFConsoleLogType)type print:(BOOL)print format:(NSString *)frmt, ...;

- (void)logWithModule:(NSString * _Nullable)module type:(PLVFConsoleLogType)type format:(NSString *)frmt, ...;

- (void)logWithKey:(NSString * _Nullable)key info:(NSString * _Nullable)info;

@end

#define PLVFLOG_ERROR( frmt, ...) PLVFLOG( nil, PLVFConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVFLOG_WARN( frmt, ...) PLVFLOG( nil, PLVFConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVFLOG_DEBUG( frmt, ...) PLVFLOG( nil, PLVFConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVFLOG_INFO( frmt, ...) PLVFLOG( nil, PLVFConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVF_NORMAL_LOG_ERROR( module, frmt, ...) PLVFLOG( module, PLVFConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVF_NORMAL_LOG_WARN( module, frmt, ...) PLVFLOG( module, PLVFConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVF_NORMAL_LOG_DEBUG( module, frmt, ...) PLVFLOG( module, PLVFConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVF_NORMAL_LOG_INFO( module, frmt, ...) PLVFLOG( module, PLVFConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVFLOG(module, logType, frmt, ...) \
{ \
    [[PLVFConsoleLogger defaultLogger] logWithModule : module \
                                        type : logType \
                                          format : (frmt), ## __VA_ARGS__]; \
}

NS_ASSUME_NONNULL_END
