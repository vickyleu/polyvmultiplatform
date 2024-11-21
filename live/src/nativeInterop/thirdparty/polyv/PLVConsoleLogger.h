//
//  PLVConsoleLogger.h
//  PLVCloudClassStreamerSDK
//
//  Created by MissYasiky on 2020/2/20.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <PLVFoundationSDK/PLVFoundationSDK.h>
///业务模块枚举
/// @note 每个模块对应一个字符，如：‘PLVConsoleLogModuleTypeJSBridge’对应‘PLVS-JS’
typedef NS_ENUM(NSUInteger, PLVConsoleLogModuleType) {
    PLVConsoleLogModuleTypeJSBridge     = 0, ///JS交互模块
    PLVConsoleLogModuleTypeSocket       = 1, ///Socket模块
    PLVConsoleLogModuleTypePPT          = 2, ///PPT模块
    PLVConsoleLogModuleTypeInteract     = 3, ///Interact模块
    PLVConsoleLogModuleTypePlayer       = 4, ///Player模块
    PLVConsoleLogModuleTypeLinkMic      = 5, ///LinkMic模块
    PLVConsoleLogModuleTypeRoom         = 6, ///Room模块
    PLVConsoleLogModuleTypeChatRoom     = 7, ///ChatRoom模块
    PLVConsoleLogModuleTypeStreamer     = 8, ///Streamer模块
    PLVConsoleLogModuleTypeBeauty       = 9, ///美颜模块
    PLVConsoleLogModuleTypeDownload     = 10,///download模块
    PLVConsoleLogModuleTypeNetwork      = 11,///网络模块
    PLVConsoleLogModuleTypeLogan        = 12,///Logan模块
    PLVConsoleLogModuleTypeVerbose      = 13 ///系统打印
};

NS_ASSUME_NONNULL_BEGIN

/// 控制台Log打印
///
/// @note 控制台Log等级打印、全局开关在此类中实现。
@interface PLVConsoleLogger : PLVFConsoleLogger

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeJSBridge 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeJSBridgeLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeSocket 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeSocketLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypePPT 的日志，默认为 NO
@property (nonatomic, assign) BOOL closePPTLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeInteract 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeInteractLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypePlayer 的日志，默认为 NO
@property (nonatomic, assign) BOOL closePlayerLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeLinkMic 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeLinkMicLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeRoom 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeRoomLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeChatRoom 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeChatRoomLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeStreamer 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeStreamerLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeDownload 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeDownloadLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeNetwork 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeNetworkLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeLogan 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeLoganLog;

/// 如果为 YES，关闭 PLVConsoleLogModuleTypeVerbose 的日志，默认为 NO
@property (nonatomic, assign) BOOL closeVerboseLog;

/// 自定义Log打印的前缀，默认为PLVS，如：设置logPrefix = @"XX"
/// 则‘PLVConsoleLogModuleTypeJSBridge’对应的前缀为‘XX-JS’
@property (nonatomic, copy) NSString *logPrefix;

/// 单例
+ (instancetype)defaultLogger;


/// 打印Log
/// @param moduleType 模块类型
/// @param type 打印类型
/// @param frmt 参数
- (void)logWithModuleType:(PLVConsoleLogModuleType)moduleType type:(PLVFConsoleLogType)type format:(NSString *)frmt, ...;

- (void)logInfoWithKey:(NSString * _Nullable)key info:(NSString * _Nullable)info;

@end

///打印error Log
/// @param moduleType 模块类型
/// @param frmt 参数
#define PLV_LOG_ERROR( moduleType, frmt, ...) PLVLOG( moduleType, PLVFConsoleLogTypeERROR ,frmt , ## __VA_ARGS__)
///打印warn Log
/// @param moduleType 模块类型
/// @param frmt 参数
#define PLV_LOG_WARN( moduleType, frmt, ...)  PLVLOG( moduleType, PLVFConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
///打印debug Log
/// @param moduleType 模块类型
/// @param frmt 参数
#define PLV_LOG_DEBUG( moduleType, frmt, ...) PLVLOG( moduleType, PLVFConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
///打印info Log
/// @param moduleType 模块类型
/// @param frmt 参数
#define PLV_LOG_INFO( moduleType, frmt, ...)  PLVLOG( moduleType, PLVFConsoleLogTypeINFO ,frmt , ## __VA_ARGS__)

#define PLVLOG(moduleType, logType, frmt, ...) \
{ \
    [[PLVConsoleLogger defaultLogger] logWithModuleType : moduleType \
                                                    type : logType \
                                                    format : (frmt), ## __VA_ARGS__]; \
}

#define PLV_KEY_INFO(key, info) PLVKEYINFO(key, info)

#define PLVKEYINFO(key, infoString) \
{ \
    [[PLVConsoleLogger defaultLogger] logInfoWithKey : key \
                                                info : infoString]; \
}

NS_ASSUME_NONNULL_END
