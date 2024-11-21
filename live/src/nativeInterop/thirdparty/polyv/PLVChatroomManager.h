//
//  PLVChatroomManager.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/11/24.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSpeakMessage.h"
#import "PLVQuoteMessage.h"
#import "PLVImageMessage.h"
#import "PLVCustomMessage.h"
#import "PLVImageEmotionMessage.h"

NS_ASSUME_NONNULL_BEGIN

/* PLVChatroomManager的协议 */
@protocol PLVChatroomManagerProtocol <NSObject>

@optional

/// 发送消息包含严禁词时触发
/// @param message 后端返回的message提示文本
/// @param word 触发的严禁词
/// @note 该回调会在全局队列中执行
- (void)chatroomManager_receiveWarning:(NSString *)message prohibitWord:(NSString *)word;

/// 发送图片违规时触发
/// @param msgId 后端返回的消息ID
/// @note 该回调会在全局队列中执行
- (void)chatroomManager_receiveImageWarningWithMsgId:(NSString *)msgId;

/// 发送图片失败时触发
/// @param message 图片消息数据模型
- (void)chatroomManager_sendImageMessageFaild:(PLVImageMessage *)message;

/// 发送图片成功时（收到socket消息回调）触发
/// @param message 图片消息数据模型(已更新了数据模型中的msgId字段)
- (void)chatroomManager_sendImageMessageSuccess:(PLVImageMessage *)message;

/// 图片消息中的图片上传进度发生变化时触发
/// @param message 图片消息模型
/// @param progress 图片上传进度（大于0小于等于1）
- (void)chatroomManager_sendImageMessage:(PLVImageMessage *)message updateProgress:(CGFloat)progress;

@end

/* 负责聊天室socket消息的发送 */
@interface PLVChatroomManager : NSObject
/// 委托代理
@property (nonatomic, weak) id<PLVChatroomManagerProtocol> delegate;
/// 当前场次ID，需在Demo层进行设置，并监听数据变化实时更新
@property (nonatomic, copy) NSString * _Nullable sessionId;
/// 当前登录用户是否是特殊身份（譬如讲师），默认为NO，为YES时字段banned永远为NO
@property (nonatomic, assign) BOOL specialRole;
/// socket处于已连接且登录成功的状态时为YES，默认为NO
@property (nonatomic, assign, readonly) BOOL online;
/// 聊天室是否被关闭，默认为NO
@property (nonatomic, assign, readonly) BOOL closeRoom;
/// 当前登录用户是否被禁言，默认为NO
@property (nonatomic, assign, readonly) BOOL banned;

/// 单例方法
+ (instancetype)sharedManager;

/// 发送提问消息
/// @param content 提问的文本内容
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendQuesstionMessage:(NSString *)content;

/// 发送自定义消息
/// @param message 自定义消息数据模型
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendCustonMessage:(PLVCustomMessage *)message;

/// 发送自定义消息
/// @param message 自定义消息数据模型
/// @param joinHistoryList 是否加入历史聊天记录，加入为YES，不加入为NO
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendCustonMessage:(PLVCustomMessage *)message
          joinHistoryList:(BOOL)joinHistoryList;

/// 发送文本消息，默认不需要回调msgId
/// @param message 文本消息数据模型
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendSpeakMessage:(PLVSpeakMessage *)message;

/// 发送文本消息，发送成功执行callback
/// @param message 文本消息数据模型
/// @param callback 回调
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendSpeakMessage:(PLVSpeakMessage *)message
                callback:(void (^ _Nullable)(NSString *msgId))callback;

/// 发送回复消息
/// @param message 回复消息数据模型
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendQuoteMessage:(PLVQuoteMessage *)message;

/// 发送回复消息，发送成功执行callback
/// @param message 回复消息数据模型
/// @param callback 回调
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendQuoteMessage:(PLVQuoteMessage *)message
                callback:(void (^ _Nullable)(NSString *msgId))callback;

/// 发送图片消息
/// 发送结果通过delegate通知
/// @param message 图片消息数据模型
/// @note 如果使用message.processImageData进行上传，数据不允许大于2mb
- (void)sendImageMessage:(PLVImageMessage *)message;

/// 发送图片表情消息
/// @param message 图片表情消息数据模型 根据sendState状态判断发送结果
- (BOOL)sendImageEmotionMessage:(PLVImageEmotionMessage *)message;

/// 发送点赞，新增点赞次数为1
/// 调用该方法之后，内部会进行数据累计，每5s发送一次socket消息，以及发送一次http统计
- (void)sendLikeEvent;

/// 发送点赞
/// 调用该方法之后，内部会进行数据累计，每5s发送一次socket消息，以及发送一次http统计
/// @param count 新增点赞次数
- (void)sendLikeEvent:(NSInteger)count;

/// 发送禁言消息，讲师端专用接口
/// @param banned YES-禁言 NO-取消禁言
/// @param userId 被禁言/取消禁言的用户ID
- (BOOL)sendBandMessage:(BOOL)banned bannedUserId:(NSString *)userId;

/// 发送踢人消息，讲师端专用接口
/// @param userId 被踢出的用户ID
- (BOOL)sendKickMessageWithUserId:(NSString *)userId;

/// 发送取消踢出(移入)消息，讲师端专用接口
/// @param userId 被移入的用户ID
- (BOOL)sendUnkickMessageWithUserId:(NSString *)userId;

/// 发送全体禁言、解禁消息，讲师端专用接口
/// @param closeRoom YES:全体禁言；NO：全体解禁
- (BOOL)sendCloseRoom:(BOOL)closeRoom;

/// 发送回复消息，发送成功执行callback
/// @param nickname 修改后昵称
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendChangeNickname:(NSString *)nickname;

/// 发送上墙/下墙消息
/// @param msgId 需要上墙消息的id，下墙不需要
/// @param toTop YES:上墙；NO：下墙
/// @return 发送结果，成功为YES，失败为NO
- (BOOL)sendPinMessageWithMsgId:(NSString *_Nullable)msgId toTop:(BOOL)toTop;

/// 开启管理器
/// @param delegate 用于设置代理，监听socket消息等
- (void)setupWithDelegate:(id<PLVChatroomManagerProtocol>)delegate channelId:(NSString *)channelId;

/// 消息overLen字段为YES时，使用该方法获取超长消息
/// @return YES-消息发出；NO-消息未发出，即callback不会执行
- (BOOL)overLengthSpeakMessageWithMsgId:(NSString *)msgId callback:(void (^)(NSString * _Nullable content))callback;

/// 退出前调用，用于资源释放、状态位清零
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
