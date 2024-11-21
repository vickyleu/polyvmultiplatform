//
//  PLVBSocketClientConfiguration.h
//  PLVBusinessSDK
//
//  Created by MissYasiky on 2020/12/10.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PLVBSocketUserType) {
    PLVBSocketUserTypeUnknown   = 0,
    
    PLVBSocketUserTypeStudent   = 1, // 普通观众
    PLVBSocketUserTypeSlice     = 2, // 云课堂学员
    PLVBSocketUserTypeViewer    = 3, // 客户端的参与者
    
    PLVBSocketUserTypeGuest     = 4, // 嘉宾
    PLVBSocketUserTypeTeacher   = 5, // 讲师
    PLVBSocketUserTypeAssistant = 6, // 助教
    PLVBSocketUserTypeManager   = 7, // 管理员
    
    PLVBSocketUserTypeSCStudent = 9  // 互动学堂学员
};

@class PLVBSocketAccount, PLVBSocketUser;

/*
 PLVBSocketClient的配置类
 在socket连接之前进行配置，配置之后将不可更改
 */
@interface PLVBSocketClientConfiguration : NSObject

/// 登录Socket的PLV用户账号信息，用于获取chatToken
@property (nonatomic, strong, readonly) PLVBSocketAccount *account;

/// 登录Socket的用户信息
@property (nonatomic, strong, readonly) PLVBSocketUser *user;

/// socket监听事件名数组（可为空），无需设置message，属于默认监听事件
@property (nonatomic, strong, readonly) NSSet <NSString *> * _Nullable listeningEvents;

/// 域名
/// 默认为 https://chat.polyv.net
@property (nonatomic, strong, readonly) NSString *domain;

/// 是否开启奖杯功能
/// 默认为NO，不开启
@property (nonatomic, assign) BOOL getCup;

/// sessionId，互动学堂场景登录时该属性必须设置
@property (nonatomic, strong) NSString *sessionId;

/// 配置account的便捷方法，必须调用，参数不可为nil
- (void)setAccountWithChannelId:(NSString *)channelId
                         userId:(NSString *)userId;

/// 配置user的便捷方法，必须调用，参数为nil时使用默认值
- (void)setUserWithViewerId:(NSString * _Nullable)viewerId
                 viewerName:(NSString * _Nullable)viewerName
                  avatarUrl:(NSString * _Nullable)avatarUrl
                 extraParam:(NSDictionary * _Nullable)extraParam
                      actor:(NSString * _Nullable)actor
                   userType:(PLVBSocketUserType)userType;

/// 配置监听事件名数组，可不调用，不调用时不额外监听事件
- (void)configureListeningEvents:(NSSet<NSString *> *)listeningEvents;

/// 配置域名，可不调用，不调用时使用默认域名
- (void)configureDomain:(NSString *)domain;

@end

@interface PLVBSocketAccount : NSObject

/// 账号ID
@property (nonatomic, strong, readonly) NSString *userId;

/// 频道号
@property (nonatomic, strong, readonly) NSString *channelId;

@end

@interface PLVBSocketUser : NSObject

/// 聊天室用户类型
/// 必须设置用户类型，否则为PLVBSocketUserTypeUnknown
@property (nonatomic, assign, readonly) PLVBSocketUserType userType;

/// 聊天室用户类型字符串，socket登录时需要用到
@property (nonatomic, strong, readonly) NSString *userTypeString;

/// 聊天室用户连麦ID
/// userType为PLVBSocketUserTypeViewer\PLVBSocketUserTypeTeacher\PLVBSocketUserTypeSCStudent时，连麦ID与viewerId一致；
/// 否则，userType为根据时间戳生成的32位整数字符串
@property (nonatomic, strong, readonly) NSString *linkMicId;

/// 聊天室用户ID
/// 默认自动根据时间戳生成32位整数字符串
@property (nonatomic, strong, readonly) NSString *viewerId;

/// 聊天室用户昵称
/// 默认自动生成5位随机数字符串
@property (nonatomic, strong, readonly) NSString *viewerName;

/// 聊天室用户头像url
/// 默认根据userType使用占位头像url
@property (nonatomic, strong, readonly) NSString *avatarUrl;

/// 聊天室用户自定义头衔（可为空）
@property (nonatomic, strong, readonly) NSString * _Nullable actor;

/// 聊天室自定义参数param4
@property (nonatomic, copy, readonly) NSString * _Nullable liveParam4;

/// 聊天室自定义参数param5
@property (nonatomic, copy, readonly) NSString * _Nullable liveParam5;
/// 返回对应userType枚举值的用户类型字符串，userType不符合要求时返回空字符串
/// english为YES时返回英文字符串，为NO时返回中文字符串
+ (NSString *)userTypeStringWithUserType:(PLVBSocketUserType)userType english:(BOOL)english;

@end

NS_ASSUME_NONNULL_END
