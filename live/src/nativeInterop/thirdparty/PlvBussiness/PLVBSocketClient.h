//
//  PLVBSocketClient.h
//  PLVBusinessSDK
//
//  Created by MissYasiky on 2020/12/10.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVBSocketClientConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/// socket 连接状态枚举
typedef NS_ENUM(NSUInteger, PLVBSocketConnectStatus) {
    PLVBSocketConnectStatusUnconnect    = 0,
    PLVBSocketConnectStatusConnected    = 1,
    PLVBSocketConnectStatusError        = 2,
    PLVBSocketConnectStatusReconnect    = 3,
    PLVBSocketConnectStatusDisconnect   = 4
};

/// socket 登录失败错误码
typedef NS_ENUM(NSInteger, PLVBSocketErrorCode) {
    PLVBSocketErrorCodeAckError     = -100,
    PLVBSocketErrorCodeTokenExpired = -101,
    PLVBSocketErrorCodeLoginRefuse  = -102,
    PLVBSocketErrorCodeRelogin      = -103,
    PLVBSocketErrorCodeKick         = -104
};

@class PLVBSocketClient;

/*
 PLVBSocketClient的协议
 */
@protocol PLVBSocketClientProtocol <NSObject>

/// socket 状态变更回调
/// @param connectStatus 连接状态枚举值
- (void)socketClient:(PLVBSocketClient *)socketClient didConnectStatusChange:(PLVBSocketConnectStatus)connectStatus;

/// socket 登录成功回调
/// @param ackArray 登录成功返回ACK
- (void)socketClient:(PLVBSocketClient *)socketClient didLoginSuccess:(NSArray <NSString *> *)ackArray;

/// socket 登录失败回调
/// @param error 登录失败错误
- (void)socketClient:(PLVBSocketClient *)socketClient didLoginFailure:(NSError *)error;

/// message 事件回调
/// @param subEvent 返回的EVENT类型
/// @param jsonString 返回的数据json原格式
/// @param object 返回数据转换成的OC格式，为NSArray或NSDictionary
- (void)socketClient:(PLVBSocketClient *)socketClient
   didReceiveMessage:(NSString *)subEvent
                json:(NSString *)jsonString
          jsonObject:(id)object;

/// 其他自定义监听事件回调
/// @param event 监听事件类型
/// @param subEvent 返回的EVENT类型
/// @param jsonString 返回的数据json原格式
/// @param object 返回数据转换成的OC格式，为NSArray或NSDictionary
- (void)socketClient:(PLVBSocketClient *)socketClient
     didReceiveEvent:(NSString *)event
            subEvent:(NSString * _Nullable)subEvent
                json:(NSString *)jsonString
          jsonObject:(id)object;

@end

/*
 socket模块终端类
 与第三方socketSDK对接，负责socket模块的功能逻辑
 */
@interface PLVBSocketClient : NSObject

/// PLVBSocketClient的消息监听类，不可为空
@property (nonatomic, weak) id<PLVBSocketClientProtocol> delegate;

/// PLVBSocketClient的配置类，不可为空
@property (nonatomic, strong, readonly) PLVBSocketClientConfiguration *configuration;

/// socket 的连接状态
@property (nonatomic, assign, readonly) PLVBSocketConnectStatus status;

/// 是否登录成功
@property (nonatomic, assign, readonly) BOOL login;

/// socket ID
@property (nonatomic, strong, readonly) NSString *socketId;

/// 唯一合法初始化方法
+ (instancetype)clientWithConfiguration:(PLVBSocketClientConfiguration *)configuration;

/// 登入方法，获取房间和 token 之后调用该接口进行 socket 连接
/// @param roomId 房间号
/// @param token socket连接token
/// @return 成功-YES 失败-NO
- (BOOL)loginWithRoomId:(NSString *)roomId token:(NSString *)token;

/// 登出方法，包括断开连接、释放资源、状态位清零一系列操作
- (void)logout;

/// 动态添加socket监听事件，注意每个相同事件只能添加一次
/// 目前只在【互动模块】需要使用
/// @param event 事件名称
- (void)addObserveSocketEvent:(NSString *)event;

- (BOOL)emitEvent:(NSString *)event
          content:(id)content
          timeout:(double)timeout
         callback:(void (^ _Nullable )(NSArray *ackArray))callback;

@end

NS_ASSUME_NONNULL_END
