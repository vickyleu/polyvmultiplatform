//
//  PLVFChatErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFChatErrorCode){
    /* http 接口请求错误 */
    // 获取聊天历史记录接口
    PLVFChatErrorCodeHistory_ParameterError = 101,
    PLVFChatErrorCodeHistory_DataError = 103,
    
    // 获取聊天室在线成员列表接口
    PLVFChatErrorCodeOnlineUsers_ParameterError = 104,
    PLVFChatErrorCodeOnlineUsers_DataError = 106,

    // 禁言设置
    PLVFChatErrorCodeCloseChatroom_ParameterError = 107,
    PLVFChatErrorCodeCloseChatroom_CodeError = 108,
    PLVFChatErrorCodeCloseChatroom_DataError = 109,

    // 获取聊天室功能开关
    PLVFChatErrorCodeGetSwitch_ParameterError = 110,
    PLVFChatErrorCodeGetSwitch_CodeError = 111,
    PLVFChatErrorCodeGetSwitch_DataError = 112,

    // 获取图片上传 token
    PLVFChatErrorCodeImageUploadToken_ParameterError = 113,
    PLVFChatErrorCodeImageUploadToken_CodeError = 114,
    PLVFChatErrorCodeImageUploadToken_DataError = 115,
    
    // 图片上传
    PLVFChatErrorCodeImageUpload_ParameterError = 116,
    PLVFChatErrorCodeImageUpload_Failure = 117,
    
    // 上报某段时间内的点赞数接口
    PLVFChatErrorCodeLike_ParameterError = 119,
    PLVFChatErrorCodeLike_CodeError = 120,
    PLVFChatErrorCodeLike_DataError = 121,
    
    /// 因为在1.5.2 中错误码冲突，所以重新定义了图片表情的错误码。仅在1.5.2版本是123、124、125
    // 获取图片表情列表接口
    PLVFChatErrorCodeEmotionImages_ParameterError = 122,
    PLVFChatErrorCodeEmotionImages_CodeError = 123,
    PLVFChatErrorCodeEmotionImages_DataError = 124,
    
    // 获取聊天室被踢出的用户列表接口
    PLVFChatErrorCodeKickedUsers_ParameterError = 125,
    PLVFChatErrorCodeKickedUsers_CodeError = 126,
    PLVFChatErrorCodeKickedUsers_DataError = 127,
    
    // 获取聊天室提醒消息历史记录
    PLVFChatErrorCodeRemindHistory_ParameterError = 128,
    PLVFChatErrorCodeRemindHistory_CodeError = 129,
    PLVFChatErrorCodeRemindHistory_DataError = 130,
    
    // 获取聊天室最新红包
    PLVFChatErrorCodeNewestRedpack_ParameterError = 131,
    PLVFChatErrorCodeNewestRedpack_CodeError = 132,
    PLVFChatErrorCodeNewestRedpack_DataError = 133,
    
    // 判断聊天室观众是否已抢红包
    PLVFChatErrorCodeRedpackReceiveCache_ParameterError = 134,
    PLVFChatErrorCodeRedpackReceiveCache_CodeError = 135,
    PLVFChatErrorCodeRedpackReceiveCache_DataError = 136,
    
    // 获取聊天室提问消息历史记录
    PLVFChatErrorCodeQuestionHistory_ParameterError = 137,
    PLVFChatErrorCodeQuestionHistory_DataError = 138,
    PLVFChatErrorCodeQuestionHistory_GetTokenError = 139,

    /* socket 信令问题 */
    // socket 未连接
    PLVFChatErrorCodeNotConnect = 403,
    // 账号已在别处登录
    PLVFChatErrorCodeRelogin = 404,
    // 未被授权观看本直播（被踢出直播间）
    PLVFChatErrorCodeUserBeKicked = 405,
    // socket 未登录
    PLVFChatErrorCodeNotLogin = 406,
    // 超出最大同时在线人数
    PLVFChatErrorCodeRestrict = 407,
    
    /* 发言问题 */
    // 发言失败，因为房间已被关闭
    PLVFChatErrorCodeRoomBeClosed = 503,
    // 发言失败，因为已被禁言
    PLVFChatErrorCodeUserBeBaned = 504,
    // 发言失败，因为含有违规词
    PLVFChatErrorCodeSendMessageError = 505,
    
    /* 发图片问题 */
    // 图片审核失败
    PLVFChatErrorCodeImageReviewFailure = 605,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFChatErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFChatErrorCode)error;

+ (NSString *)errorDescription:(PLVFChatErrorCode)error;

@end

NS_ASSUME_NONNULL_END
