//
//  PLVSocketManager.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/12/13.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 用户类型枚举
/// 注意：需要与BusinessSDK的PLVBSocketUserType枚举对齐
typedef NS_ENUM(NSUInteger, PLVSocketUserType) {
    PLVSocketUserTypeUnknown   = 0,
    
    PLVSocketUserTypeStudent   = 1, // 普通观众
    PLVSocketUserTypeSlice     = 2, // 云课堂学员
    PLVSocketUserTypeViewer    = 3, // 客户端的参与者
    
    PLVSocketUserTypeGuest     = 4, // 嘉宾
    PLVSocketUserTypeTeacher   = 5, // 讲师
    PLVSocketUserTypeAssistant = 6, // 助教
    PLVSocketUserTypeManager   = 7,  // 管理员
    
    PLVSocketUserTypeSCStudent = 9   // 互动学堂学员
};

/// socket 连接状态枚举
/// /// 注意：需要与BusinessSDK的PLVBSocketConnectStatus枚举对齐
typedef NS_ENUM(NSUInteger, PLVSocketConnectStatus) {
    PLVSocketConnectStatusUnconnect    = 0,
    PLVSocketConnectStatusConnected    = 1,
    PLVSocketConnectStatusError        = 2,
    PLVSocketConnectStatusReconnect    = 3,
    PLVSocketConnectStatusDisconnect   = 4
};

/// socket 登录失败错误码
/// 注意：需要与BusinessSDK的PLVBSocketErrorCode枚举对齐
typedef NS_ENUM(NSInteger, PLVSocketLoginErrorCode) {
    PLVSocketLoginErrorCodeAckError     = -100,
    PLVSocketLoginErrorCodeTokenExpired = -101,
    PLVSocketLoginErrorCodeLoginRefuse  = -102,
    PLVSocketLoginErrorCodeRelogin      = -103,
    PLVSocketLoginErrorCodeKick         = -104
};

/// 'TEACHER_SET_PERMISSION' socket消息类型
typedef NS_ENUM(NSInteger, PLVSocketPermissionType) {
    PLVSocketPermissionTypeSpeaker, // 主讲
    PLVSocketPermissionTypePaint, // 画笔
    PLVSocketPermissionTypeCup, // 奖杯
    PLVSocketPermissionTypeRaiseHand, // 举手
    PLVSocketPermissionTypeCamera, // 摄像头
    PLVSocketPermissionTypeMicrophone, // 麦克风
    PLVSocketPermissionTypeScreenShare // 屏幕共享
};

/// PLVSocketManager的协议
/// @note 允许设置多个监听者
@protocol PLVSocketManagerProtocol <NSObject>

@optional

/// socket 启动失败回调（启动成功才可进行连接）
/// @param error 失败错误码
- (void)socketManager_didStartFailure:(NSError *)error;

/// socket 连接状态变更回调（连接成功才可进行登录）
/// @param connectStatus 连接状态枚举值
- (void)socketMananger_didConnectStatusChange:(PLVSocketConnectStatus)connectStatus;

/// socket 登录成功回调（登录成功才可收发消息）
/// @param ackString 登录成功返回ACK字符串
- (void)socketMananger_didLoginSuccess:(NSString *)ackString;

/// socket 登录失败回调（登录成功才可收发消息）
/// @param error 登录失败错误
- (void)socketMananger_didLoginFailure:(NSError *)error;

/// message 事件回调
/// @param subEvent 返回的EVENT类型
/// @param jsonString 返回的数据json原格式
/// @param object 返回数据转换成的OC格式，为NSArray或NSDictionary
- (void)socketMananger_didReceiveMessage:(NSString *)subEvent
                                    json:(NSString *)jsonString
                              jsonObject:(id)object;

/// 其他自定义监听事件回调
/// @param event 监听事件类型
/// @param subEvent 返回的EVENT类型
/// @param jsonString 返回的数据json原格式
/// @param object 返回数据转换成的OC格式，为NSArray或NSDictionary
- (void)socketMananger_didReceiveEvent:(NSString *)event
                              subEvent:(NSString *)subEvent
                                  json:(NSString *)jsonString
                            jsonObject:(id)object;

@end

#pragma mark -

/// socket 管理类
@interface PLVSocketManager : NSObject

#pragma mark - Readwrite Property

/// 是否允许使用分房间功能，优先级高于后台的配置
/// 默认为NO，不允许
@property (nonatomic, assign) BOOL allowChildRoom;

/// 是否开启奖杯功能，默认关闭
@property (nonatomic, assign) BOOL getCup;

/// 配置私有域名
/// 如果与默认域名相同，会自行忽略，为空使用默认域名
@property (nonatomic, strong) NSString * _Nullable chatDomain;

/// 可用于增加socket监听事件，为空则只监听默认事件
@property (nonatomic, strong) NSSet <NSString *> * _Nullable listeningEvents;

/// 聊天室消息阈值开关，默认为关
@property (nonatomic, assign) BOOL chatMessageOnceControlEnabled;

/// 聊天室阈值大小，默认为10
@property (nonatomic, assign) NSInteger chatMessageMaxLengthOnce;

#pragma mark 互动学堂独有属性

/// 是否是互动学堂等vclass域名的场景，默认为 NO
@property (nonatomic, assign) BOOL vclassDomain;
/// 课程码，学生端使用课程码登录时该属性必须设置
@property (nonatomic, strong) NSString * _Nullable courseCode;
/// 课节ID，学生端使用课节ID登录时该属性必须设置
@property (nonatomic, strong) NSString * _Nullable lessonId;

#pragma mark - Readonly Property

/// socket 的连接状态
@property (nonatomic, assign, readonly) PLVSocketConnectStatus status;

/// 是否登录成功
@property (nonatomic, assign, readonly) BOOL login;

///后端是否开启分房间功能
///需要childRoomEnable为YES且allowChildRoom也为YES，才会真正开启分房间功能
@property (nonatomic, assign, readonly) BOOL childRoomEnable;

/// 房间号
@property (nonatomic, strong, readonly) NSString *roomId;

/// 登录成功后返回的 ack 字符串
@property (nonatomic, copy, readonly) NSString *loginSuccessAckString;

/// socket ID
@property (nonatomic, strong, readonly) NSString *socketId;

/// 聊天室用户类型
@property (nonatomic, assign, readonly) PLVSocketUserType userType;

/// 聊天室用户类型字符串
@property (nonatomic, strong, readonly) NSString *userTypeString;

/// 聊天室用户连麦ID
@property (nonatomic, strong, readonly) NSString *linkMicId;

/// 聊天室用户ID
@property (nonatomic, strong, readonly) NSString *viewerId;

/// 聊天室用户昵称
@property (nonatomic, strong, readonly) NSString *viewerName;

/// 聊天室用户头像url
@property (nonatomic, strong, readonly) NSString *avatarUrl;

/// 聊天室用户自定义头衔（可为空）
@property (nonatomic, strong, readonly) NSString * _Nullable actor;

/// 聊天室用户自定义参数4（可为空）
@property (nonatomic, strong, readonly) NSString * _Nullable liveParam4;

@property (nonatomic, strong, readonly) NSString * _Nullable chatToken;

#pragma mark - API

/// 单例方法
+ (instancetype)sharedManager;

/// 登录方法，调用该方法后，自动开始获取chatToken，连接socket
/// @param channelId 频道号
/// @param viewerId 聊天室用户ID（可用于区分用户的唯一ID）
/// @param viewerName 聊天室用户昵称
/// @param avatarUrl 聊天室用户头像url
/// @param actor 聊天室用户自定义头衔（可为空）
/// @param userType 聊天室用户类型枚举值
/// @return YES-正常登录，NO-检查参数是否有问题或者SDK是否尚未初始化
- (BOOL)loginWithChannelId:(NSString *)channelId
                  viewerId:(NSString *)viewerId
                viewerName:(NSString *)viewerName
                 avatarUrl:(NSString *)avatarUrl
                     actor:(NSString * _Nullable)actor
                  userType:(PLVSocketUserType)userType;

/// socket 连接成功之后发送 login 消息进行登录
/// @note 这个方法仅适用于 socket 连接且登录成功之后调用
- (BOOL)emitLoginEvent;

/// 登录方法，调用该方法后，可传递自定义参数并自动开始获取chatToken，连接socket
/// @param channelId 频道号
/// @param viewerId 聊天室用户ID（可用于区分用户的唯一ID）
/// @param viewerName 聊天室用户昵称
/// @param avatarUrl 聊天室用户头像url
/// @param extraParam 聊天室自定义参数字典（可为空）
/// @param actor 聊天室用户自定义头衔（可为空）
/// @param userType 聊天室用户类型枚举值
/// @return YES-正常登录，NO-检查参数是否有问题或者SDK是否尚未初始化
- (BOOL)loginWithChannelId:(NSString *)channelId
                  viewerId:(NSString *)viewerId
                viewerName:(NSString *)viewerName
                 avatarUrl:(NSString *)avatarUrl
                extraParam:(NSDictionary * _Nullable)extraParam
                     actor:(NSString * _Nullable)actor
                  userType:(PLVSocketUserType)userType;

/// 登出时调用
- (void)logout;

/// 动态添加socket监听事件，注意每个相同事件只能添加一次
/// 目前只在【互动模块】需要使用
/// @param event 事件名称
- (void)addObserveSocketEvent:(NSString *)event;

#pragma mark Multicast

/// 增加PLVSocketManagerProtocol协议的监听者
/// @param delegate 待增加的监听者
/// @param delegateQueue 执行回调的队列
- (void)addDelegate:(id<PLVSocketManagerProtocol>)delegate delegateQueue:(dispatch_queue_t)delegateQueue;

/// 移除PLVSocketManagerProtocol协议的监听者
/// @param delegate 待移除的监听者
- (void)removeDelegate:(id<PLVSocketManagerProtocol>)delegate;

/// 移除PLVSocketManagerProtocol协议的所有监听者
- (void)removeAllDelegates;

#pragma mark Message Emit

/// 提交 socket "message" 事件消息
/// @param content 消息内容，NSString 或 NSDictionary 类型
/// @return 成功-YES 失败-NO
- (BOOL)emitMessage:(id)content;

/// 提交 socket "message" 事件消息
/// @param content 消息内容，NSString 或 NSDictionary 类型
/// @param timeout 回调超时等待，默认 0
/// @param callback 回调
/// @return 成功-YES 失败-NO
- (BOOL)emitMessage:(id)content
            timeout:(double)timeout
           callback:(void (^)(NSArray *ackArray))callback;

/// 提交 socket 特定事件消息
/// @param event 事件名
/// @param content 消息内容，NSString 或 NSDictionary 类型
/// @return 成功-YES 失败-NO
- (BOOL)emitEvent:(NSString *)event
          content:(id)content;

/// 提交 socket 特定事件消息
/// @param event 事件名
/// @param content 消息内容，NSString 或 NSDictionary 类型
/// @param timeout 回调超时等待，默认 0
/// @param callback 回调
/// @return 成功-YES 失败-NO
- (BOOL)emitEvent:(NSString *)event
          content:(id)content
          timeout:(double)timeout
         callback:(void (^)(NSArray *ackArray))callback;

/// 发送'TEACHER_SET_PERMISSION' socket消息
/// @param userId 用户Id
/// @param type 权限类型
/// @param status YES:授予权限，NO:移除权限
/// @return 成功-YES 失败-NO
- (BOOL)emitPermissionMessageWithUserId:(NSString *)userId
                                   type:(PLVSocketPermissionType)type
                                 status:(BOOL)status;

/// 发送'TEACHER_SET_PERMISSION' socket消息
/// @param userId 用户Id
/// @param type 权限类型
/// @param status YES:授予权限，NO:移除权限
/// @param timeout 回调超时等待，默认 0
/// @param callback 回调
/// @return 成功-YES 失败-NO
- (BOOL)emitPermissionMessageWithUserId:(NSString *)userId
                                   type:(PLVSocketPermissionType)type
                                 status:(BOOL)status
                              timeout:(double)timeout
                               callback:(void (^ _Nullable )(NSArray *ackArray))callback;

/// 发送'TEACHER_SET_PERMISSION' socket消息挂断全部用户的连麦
/// @param timeout 回调超时等待，默认 0
/// @param callback 回调
/// @return 成功-YES 失败-NO
- (BOOL)emitPermissionMessageForCloseAllLinkMicWithTimeout:(double)timeout
                                                  callback:(void (^ _Nullable)(NSArray * _Nonnull))callback;

@end

NS_ASSUME_NONNULL_END
