//
//  PLVSocketEventDefine.h
//  PLVBusinessSDK
//
//  Created by ftao on 10/11/2017.
//  Copyright © 2017 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 1. 注明 NSDictionary、NSNumber 的表示该字段(参数)的值为 字典或 number 类型；未注明的为默认 String 类型
 2. 注明 optional 的为可选项，即可能不存在此字段；未注明的一般都为存在
 3. 如果注释或字段和实际数据存在出入，欢迎大家通过Github或技术支持进行反馈。
 */

#pragma mark - 聊天室事件键集合

/*!
 @constant    PLVSocketIOChatRoomUserKey
 @abstract    聊天室用户信息
 */
extern NSString *const PLVSocketIOChatRoomUserKey; /* NSDictionary */
    extern NSString *const PLVSocketIOChatRoomUserClientIpKey; /* 用户IP */
    extern NSString *const PLVSocketIOChatRoomUserNickKey; /* 用户昵称 */
    extern NSString *const PLVSocketIOChatRoomUserPicKey; /* 用户头像，地址需要转换，返回的地址一般未带协议 */
    extern NSString *const PLVSocketIOChatRoomUserRoomIdKey; /* 房间号 */
    extern NSString *const PLVSocketIOChatRoomUserUidKey; /* socket 分配的id */
    extern NSString *const PLVSocketIOChatRoomUserUserIdKey; /* 用户唯一标识 */
    extern NSString *const PLVSocketIOChatRoomUserUserTypeKey; /* 用户类型，目前有teacher(老师)、assistant(助教)、manager(管理员)、slice(云课堂学员) */
    extern NSString *const PLVSocketIOChatRoomUserActorKey; /* optional, 头衔 */
    extern NSString *const PLVSocketIOChatRoomUserCanAnswerKey; /* optional, 是否有回答提问的权限 */

#pragma mark 聊天室基本消息

/*!
 @constant    PLVSocketIOChatRoom_LOGIN_EVENT
 @abstract    登录消息，登录房间的时候服务器会广播这一消息
 */
extern NSString *const PLVSocketIOChatRoom_LOGIN_EVENT;
    extern NSString *const PLVSocketIOChatRoom_LOGIN_onlineUserNumber; /* NSNumber, 当前房间总在线人数 */
    extern NSString *const PLVSocketIOChatRoom_LOGIN_userKey; /* NSDictionary，等同 PLVSocketIOChatRoomUserKey */

/*!
 @constant    PLVSocketIOChatRoom_LOGOUT_EVENT
 @abstract    退出消息，断开连接服务器广播的消息
 */
extern NSString *const PLVSocketIOChatRoom_LOGOUT_EVENT;
    extern NSString *const PLVSocketIOChatRoom_LOGOUT_onlineUserNumber; /* NSNumber, 当前在线总人数 */
    extern NSString *const PLVSocketIOChatRoom_LOGOUT_uid; /* 离开人的uid */

/*!
 @constant    PLVSocketIOChatRoom_RELOGIN_EVENT
 @abstract    当前用户id在别处重新登录
 */
extern NSString *const PLVSocketIOChatRoom_RELOGIN_EVENT;
    extern NSString *const PLVSocketIOChatRoom_RELOGIN_channelId;

/*!
 @constant    PLVSocketIOChatRoom_SET_NICK_EVENT
 @abstract    昵称设置，设置的昵称存在时间为5个小时
 */
extern NSString *const PLVSocketIOChatRoom_SET_NICK_EVENT;
    extern NSString *const PLVSocketIOChatRoom_SET_NICK_message; /* 消息内容 */
    extern NSString *const PLVSocketIOChatRoom_SET_NICK_status; /* 设置状态 */
    extern NSString *const PLVSocketIOChatRoom_SET_NICK_nick; /* 设置昵称 */
    extern NSString *const PLVSocketIOChatRoom_SET_NICK_userId; /* 用户Id */

/*!
 @constant    PLVSocketIOChatRoom_GONGGAO_EVENT
 @abstract    公告消息，如有公告，登录房间的时候服务器会广播这一消息，公告即为管理员的发言信息
 */
extern NSString *const PLVSocketIOChatRoom_GONGGAO_EVENT;
    extern NSString *const PLVSocketIOChatRoom_GONGGAO_content; /* 公告内容 */

/*!
 @constant    PLVSocketIOChatRoom_BULLETIN_EVENT
 @abstract    公告消息，PLV 后台聊天室管理中，发布公告的内容
 */
extern NSString *const PLVSocketIOChatRoom_BULLETIN_EVENT;
    extern NSString *const PLVSocketIOChatRoom_BULLETIN_RemoveBulletin; /* 移除公告 */
    extern NSString *const PLVSocketIOChatRoom_BULLETIN_content; /* 公告内容 */

/*!
 @constant    PLVSocketIOChatRoom_SPEAK_EVENT
 @abstract    发言,接收别人的发言消息(不包括自己)
 */
extern NSString *const PLVSocketIOChatRoom_SPEAK_EVENT;
    extern NSString *const PLVSocketIOChatRoom_SPEAK_id; /* 消息唯一标志 */
    extern NSString *const PLVSocketIOChatRoom_SPEAK_time; /* NSNumber,时间戳 */
    extern NSString *const PLVSocketIOChatRoom_SPEAK_userKey; /* NSDictionary，等同 PLVSocketIOChatRoomUserKey，发言人 */
    extern NSString *const PLVSocketIOChatRoom_SPEAK_values; /* NSArray, 消息内容 */

/*!
 @constant    PLVSocketIOChatRoom_EMOTION_EVENT
 @abstract    图片表情,接收别人的图片表情消息(不包括自己)
 */
extern NSString *const PLVSocketIOChatRoom_EMOTION_EVENT;
    extern NSString *const PLVSocketIOChatRoom_EMOTION_id; /* 图片表情id */
    extern NSString *const PLVSocketIOChatRoom_EMOTION_messageId; /* 消息id*/
    extern NSString *const PLVSocketIOChatRoom_EMOTION_source; /* 是否为特殊身份聊天 */

#pragma mark 聊天室赞赏消息

/*!
 @constant    PLVSocketIOChatRoom_FLOWERS_EVENT
 @abstract    送花事件
 */
extern NSString *const PLVSocketIOChatRoom_FLOWERS_EVENT;
    extern NSString *const PLVSocketIOChatRoom_FLOWERS_nick; /* 送花人昵称 */
    extern NSString *const PLVSocketIOChatRoom_FLOWERS_uimg; /* 送花人头像 */

/*!
 @constant    PLVSocketIOChatRoom_LIKES_EVENT
 @abstract    点赞事件
 */
extern NSString *const PLVSocketIOChatRoom_LIKES_EVENT;
    extern NSString *const PLVSocketIOChatRoom_LIKES_count; /* NSNumber, 当前点赞总数，若发生消息的时候没传此属性，则不返回这个属性 */
    extern NSString *const PLVSocketIOChatRoom_LIKES_nick; /* 点赞人昵称 */

/*!
 @constant    PLVSocketIOChatRoom_REWARD_EVENT
 @abstract    打赏事件，目前需要通过HTTP接口进行支付后，由后台通知服务器
 */
extern NSString *const PLVSocketIOChatRoom_REWARD_EVENT;
    extern NSString *const PLVSocketIOChatRoom_REWARD_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOChatRoom_REWARD_contentKey; /* NSDictionary, 打赏的内容 */
        extern NSString *const PLVSocketIOChatRoom_REWARD_content_gimg; /* 礼物的图片，若为空，则代表现金打赏 */
        extern NSString *const PLVSocketIOChatRoom_REWARD_content_rewardContent; /* 礼物的名称,若gimg为空,此字段为打赏的金额 */
        extern NSString *const PLVSocketIOChatRoom_REWARD_content_uimg; /* 打赏人的头像 */
        extern NSString *const PLVSocketIOChatRoom_REWARD_content_unick; /* 打赏人的昵称 */

/*!
 @constant    PLVSocketIOChatRoom_REDPAPER_EVENT
 @abstract    发红包，和打赏的情况类似，也是通过HTTP接口支付后由后台通知服务器
 */
extern NSString *const PLVSocketIOChatRoom_REDPAPER_EVENT;
    extern NSString *const PLVSocketIOChatRoom_REDPAPER_msgSource; /* 消息类型 */
    extern NSString *const PLVSocketIOChatRoom_REDPAPER_totalAmount; /* 红包总金额 */
    extern NSString *const PLVSocketIOChatRoom_REDPAPER_number; /* 红包个数 */
    extern NSString *const PLVSocketIOChatRoom_REDPAPER_content; /* 祝福语 */
    extern NSString *const PLVSocketIOChatRoom_REDPAPER_redpackId; /* 红包ID */
    extern NSString *const PLVSocketIOChatRoom_REDPAPER_redCacheId; /* 红包缓存ID */
    extern NSString *const PLVSocketIOChatRoom_REDPAPER_userKey; /* NSDictionary, 发红包用户 */
        extern NSString *const PLVSocketIOChatRoom_REDPAPER_user_roomId; /* 房间号 */
        extern NSString *const PLVSocketIOChatRoom_REDPAPER_user_openId; /* 微信用户openId */
        extern NSString *const PLVSocketIOChatRoom_REDPAPER_user_nick; /* 用户昵称 */
        extern NSString *const PLVSocketIOChatRoom_REDPAPER_user_pic; /* 用户头像 */
        extern NSString *const PLVSocketIOChatRoom_REDPAPER_user_userId; /* optional, 用户Id */

#pragma mark 聊天室管理及控制

/*!
 @constant    PLVSocketIOChatRoom_REMOVE_CONTENT_EVENT
 @abstract    删除某条聊天记录，目前需要通过HTTP接口调用
 */
extern NSString *const PLVSocketIOChatRoom_REMOVE_CONTENT_EVENT;
    extern NSString *const PLVSocketIOChatRoom_REMOVE_CONTENT_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOChatRoom_REMOVE_CONTENT_id; /* 删除内容对应的id */
    extern NSString *const PLVSocketIOChatRoom_REMOVE_CONTENT_content; /* optional, 删除的内容 */

/*!
 @constant    PLVSocketIOChatRoom_REMOVE_HISTORY_EVENT
 @abstract    清空聊天记录
 */
extern NSString *const PLVSocketIOChatRoom_REMOVE_HISTORY_EVENT;

/*!
 @constant    PLVSocketIOChatRoom_CLOSEROOM_EVENT
 @abstract    关闭聊天室
 */
extern NSString *const PLVSocketIOChatRoom_CLOSEROOM_EVENT;
    extern NSString *const PLVSocketIOChatRoom_CLOSEROOM_valueKey; /* NSDictionary */
        extern NSString *const PLVSocketIOChatRoom_CLOSEROOM_value_roomId; /* NSNumber, 房间号 */
        extern NSString *const PLVSocketIOChatRoom_CLOSEROOM_value_closed; /* NSNumber(BOOL)，true为关闭；false为开启 */

/*!
 @constant    PLVSocketIOChatRoom_CLOSE_DANMU_EVENT
 @abstract    关闭弹幕
 */
extern NSString *const PLVSocketIOChatRoom_CLOSE_DANMU_EVENT;
    extern NSString *const PLVSocketIOChatRoom_CLOSE_DANMU_isClose; /* NSNumber(BOOL)，true为关；false为开启 */


/*!
 @constant    PLVSocketIOChatRoom_BANIP_EVENT
 @abstract    禁言事件
 */
extern NSString *const PLVSocketIOChatRoom_BANIP_EVENT;
    extern NSString *const PLVSocketIOChatRoom_BANIP_userIds; /* NSArray<NSDictionary，内容可使用PLVSocketIOChatRoomUserKey内Key值>, 被禁用户 */

/*!
 @constant    PLVSocketIOChatRoom_UNSHIELD_EVENT
 @abstract    解禁言事件
 */
extern NSString *const PLVSocketIOChatRoom_UNSHIELD_EVENT;
    extern NSString *const PLVSocketIOChatRoom_UNSHIELD_userIds; /* NSArray<NSDictionary，内容可使用PLVSocketIOChatRoomUserKey内Key值>, 解禁用户 */

/*!
 @constant    PLVSocketIOChatRoom_KICK_EVENT
 @abstract    踢人事件
 */
extern NSString *const PLVSocketIOChatRoom_KICK_EVENT;
    extern NSString *const PLVSocketIOChatRoom_KICK_userKey; /* NSDictionary，等同 PLVSocketIOChatRoomUserKey，被踢用户对象 */


/*!
 @constant    PLVSocketIOChatRoom_DEBUG_EVENT
 @abstract    调试模式，调试模式的开关在助教页面
 */
extern NSString *const PLVSocketIOChatRoom_DEBUG_EVENT;
    extern NSString *const PLVSocketIOChatRoom_DEBUG_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOChatRoom_DEBUG_isdebug; /* NSNumber(BOOL)，true为开启调试模式；false为关闭 */

/*!
 @constant    PLVSocketIOChatRoom_CHATROOM_CONTROL_EVENT
 @abstract    聊天室管理操作事件（关闭欢迎语、关闭点赞语）
 */
extern NSString *const PLVSocketIOChatRoom_CHATROOM_CONTROL_EVENT;
    extern NSString *const PLVSocketIOChatRoom_CHATROOM_CONTROL_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOChatRoom_CHATROOM_CONTROL_type; /* 控制类型：closeWelcome(关闭欢迎语)、closeLikes(关闭点赞语)等 */
    extern NSString *const PLVSocketIOChatRoom_CHATROOM_CONTROL_value; /* NSNumber(BOOL)，YES 为开启；NO 为关闭 */

#pragma mark 聊天室问答消息
/*!
 @constant    PLVSocketIOChatRoom_QUESTION_EVENT
 @abstract    老师在客户端发起问答，参考：https://dev.polyv.net/2016/08/clientchat/ 2.3问答功能
 */
extern NSString *const PLVSocketIOChatRoom_QUESTION_EVENT;
    extern NSString *const PLVSocketIOChatRoom_QUESTION_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOChatRoom_QUESTION_question; /* 问题选项(单选题/判断题) */

/*!
 @constant    PLVSocketIOChatRoom_CLOSE_QUESTION_EVENT
 @abstract    老师在客户端关闭问答
 */
extern NSString *const PLVSocketIOChatRoom_CLOSE_QUESTION_EVENT;
    extern NSString *const PLVSocketIOChatRoom_CLOSE_QUESTION_roomId; /* NSNumber, 房间号 */

/*!
 @constant    PLVSocketIOChatRoom_ANSWER_EVENT
 @abstract    学员在观看端回答老师的问答
 */
extern NSString *const PLVSocketIOChatRoom_ANSWER_EVENT;
    extern NSString *const PLVSocketIOChatRoom_ANSWER_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOChatRoom_ANSWER_answer; /* 学员选择的答案 */
    extern NSString *const PLVSocketIOChatRoom_ANSWER_nick; /* 回答问题学员昵称 */

#pragma mark 聊天室自定义消息

/*!
 @constant    PLVSocketIOChatRoom_CUSTOMER_MESSAGE_EVENT
 @abstract    自定义消息接收事件，目前只能通过后台管理员调用HTTP接口发送消息，可参考https://dev.polyv.net/2016/12/send-chat/
 */
extern NSString *const PLVSocketIOChatRoom_CUSTOMER_MESSAGE_EVENT;
    extern NSString *const PLVSocketIOChatRoom_CUSTOMER_MESSAGE_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOChatRoom_CUSTOMER_MESSAGE_image; /* 消息图片(根据发送的消息是否有图片决定) */
    extern NSString *const PLVSocketIOChatRoom_CUSTOMER_MESSAGE_content; /* 消息内容 */


#pragma mark 聊天室私聊消息

/*!
 @constant    PLVSocketIOChatRoom_S_QUESTION_EVENT
 @abstract    学生在观看端发起提问
 */
extern NSString *const PLVSocketIOChatRoom_S_QUESTION_EVENT;
extern NSString *const PLVSocketIOChatRoom_S_QUESTION_roomId; /* NSNumber, 房间号 */
extern NSString *const PLVSocketIOChatRoom_S_QUESTION_content; /* 提问内容 */
extern NSString *const PLVSocketIOChatRoom_S_QUESTION_userKey; /* NSDictionary，提问学生相关信息，可以参看 PLVSocketIOChatRoomUserKey 字典属性内容*/

/*!
 @constant    PLVSocketIOChatRoom_T_ANSWER_EVENT
 @abstract    老师回答学生的提问
 */
extern NSString *const PLVSocketIOChatRoom_T_ANSWER_EVENT;
extern NSString *const PLVSocketIOChatRoom_T_ANSWER_roomId; /* NSNumber, 房间号 */
extern NSString *const PLVSocketIOChatRoom_T_ANSWER_content; /* 回答内容 */
extern NSString *const PLVSocketIOChatRoom_T_ANSWER_sUserId; /* 提问学生userId */
extern NSString *const PLVSocketIOChatRoom_T_ANSWER_userKey; /* NSDictionary，讲师信息，可以参看 PLVSocketIOChatRoomUserKey 字典属性内容 */


#pragma mark 奖杯消息
/*!
 @constant    PLVSocketIOChatRoom_SEND_CUP_EVENT
 @abstract    奖杯事件
 */
extern NSString *const PLVSocketIOChatRoom_SEND_CUP_EVENT;

#pragma mark - 连麦事件键集合

/*!
 @constant    PLVSocketIOLinkMicUserkey
 @abstract    举手学员信息
 */
extern NSString *const PLVSocketIOLinkMicUserkey;
    extern NSString *const PLVSocketIOLinkMicUserNickkey; /* 用户昵称 */
    extern NSString *const PLVSocketIOLinkMicUserPickey; /* 用户头像 */
    extern NSString *const PLVSocketIOLinkMicUserUserIdkey; /* 用户userId */
    extern NSString *const PLVSocketIOLinkMicUserUserTypekey; /* 用户类型，默认为空，老师为teacher，ppt学员为slice */
    extern NSString *const PLVSocketIOLinkMicUserRoomIdkey; /* NSNumber, optional, 用户所在房间/频道号 */
    extern NSString *const PLVSocketIOLinkMicUserStatuskey; /* optional, 用户当前连麦状态 */
    extern NSString *const PLVSocketIOLinkMicUserUidkey; /* optional, 用户链接聊天室服务器uid，由服务器生成 */

/*!
 @constant    PLVSocketIOLinkMic_OPEN_MICROPHONE_EVENT
 @abstract    老师开启关闭连麦事件消息
 */
extern NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_EVENT;
    extern NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_type; /* 连麦类型：audio(语音通话)；video(视频通话) */
    extern NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_status; /* 状态：open(打开)、close(关闭) */
    extern NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_teacherId; /* optional, 教师id */
    extern NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_userId; /* optional, 用户id，存在此字段时非关闭所有连麦 */

/*!
 @constant    PLVSocketIOLinkMic_JOIN_REQUEST_key
 @abstract    举手事件
 */
extern NSString *const PLVSocketIOLinkMic_JOIN_REQUEST_key;
    extern NSString *const PLVSocketIOLinkMic_JOIN_REQUEST_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOLinkMic_JOIN_REQUEST_userKey; /* NSDictionary, 等同 PLVSocketIOLinkMicUserkey，学员信息 */

/*!
 @constant    PLVSocketIOLinkMic_JOIN_RESPONSE_key
 @abstract    老师同意通话事件
 */
extern NSString *const PLVSocketIOLinkMic_JOIN_RESPONSE_key;
    extern NSString *const PLVSocketIOLinkMic_JOIN_RESPONSE_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOLinkMic_JOIN_RESPONSE_userKey; /* NSDictionary, 等同 PLVSocketIOLinkMicUserkey，学员信息 */
    extern NSString *const PLVSocketIOLinkMic_JOIN_RESPONSE_value;

/*!
 @constant    PLVSocketIOLinkMic_JOIN_SUCCESS_key
 @abstract    加入连麦频道成功事件消息
 */
extern NSString *const PLVSocketIOLinkMic_JOIN_SUCCESS_key;
    extern NSString *const PLVSocketIOLinkMic_JOIN_SUCCESS_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOLinkMic_JOIN_SUCCESS_userKey; /* NSDictionary, 等同 PLVSocketIOLinkMicUserkey，学员信息 */
    extern NSString *const PLVSocketIOLinkMic_JOIN_SUCCESS_value;

/*!
 @constant    PLVSocketIOLinkMic_JOIN_ANSWERTTL_key
 @abstract    观众查询邀请连麦接受时限
 */
extern NSString *const PLVSocketIOLinkMic_JOIN_ANSWERTTL_key;

/*!
 @constant    PLVSocketIOLinkMic_JOIN_LEAVE_key
 @abstract    结束发言事件消息
 */
extern NSString *const PLVSocketIOLinkMic_JOIN_LEAVE_key;
    extern NSString *const PLVSocketIOLinkMic_JOIN_LEAVE_roomId; /* NSNumber, 房间号 */
    extern NSString *const PLVSocketIOLinkMic_JOIN_LEAVE_userKey; /* NSDictionary, 等同 PLVSocketIOLinkMicUserkey，学员信息 */

/*!
 @constant    PLVSocketLinkMicEventType_TEACHER_INFO_key
 @abstract    连麦讲师信息事件
 */
extern NSString *const PLVSocketLinkMicEventType_TEACHER_INFO_key;

/*!
 @constant    PLVSocketLinkMicEventType_MuteUserMedia_key
 @abstract    连麦讲师关闭连麦人的摄像头或麦克风
 */
extern NSString *const PLVSocketLinkMicEventType_MuteUserMedia_key;

/*!
 @constant    PLVSocketLinkMicEventType_SwitchView_key
 @abstract    连麦讲师切换连麦人的主副屏位置
 */
extern NSString *const PLVSocketLinkMicEventType_SwitchView_key;

/*!
 @constant    PLVSocketLinkMicEventType_TEACHER_SET_PERMISSION_key
 @abstract    讲师设置连麦者的权限
 */
extern NSString *const PLVSocketLinkMicEventType_TEACHER_SET_PERMISSION_key;

/*!
 @constant    PLVSocketLinkMicEventType_changeVideoAndPPTPosition_key
 @abstract    讲师主动切换PPT和播放器的位置
 */
extern NSString *const PLVSocketLinkMicEventType_changeVideoAndPPTPosition_key;

/*!
 @constant    PLVSocketLinkMicEventType_switchJoinVoice_key
 @abstract    允许某人上麦
 */
extern NSString *const PLVSocketLinkMicEventType_switchJoinVoice_key;

#pragma mark - 电话入会事件键集合

/*!
 @constant    PLVSocketIOSipLinkMic_EVENT
 @abstract    电话入会事件
 */
extern NSString *const PLVSocketIOSipLinkMic_EVENT;
    extern NSString *const PLVSocketIOSipLinkMic_type;  /* NSString, 电话入会事件类型 */
    extern NSString *const PLVSocketIOSipLinkMic_message;  /* NSString, 相关信息说明 */
    extern   NSString *const PLVSocketIOSipLinkMic_name;  /* NSString, 用户昵称 */
    extern NSString *const PLVSocketIOSipLinkMic_phoneNumber;  /*  NSString, 电话号码 */
    extern NSString *const PLVSocketIOSipLinkMic_isAll; /* 状态, Y(操作所有)、N(操作指定用户) */
    extern NSString *const PLVSocketIOSipLinkMic_id;  /* NSString, 拨号id */
/*!
 @constant    PLVSocketIOSipLinkMic_call_key
 @abstract    呼叫
 */
extern NSString *const PLVSocketIOSipLinkMic_call_key;

/*!
 @constant    PLVSocketIOSipLinkMic_cancelCall_key
 @abstract    取消呼叫
 */
extern NSString *const PLVSocketIOSipLinkMic_cancelCall_key;

/*!
 @constant    PLVSocketIOSipLinkMic_recall_key
 @abstract    重新呼叫
 */
extern NSString *const PLVSocketIOSipLinkMic_recall_key;

/*!
 @constant    PLVSocketIOSipLinkMic_callTimeout_key
 @abstract    呼叫超时
 */
extern NSString *const PLVSocketIOSipLinkMic_callTimeout_key;

/*!
 @constant    PLVSocketIOSipLinkMic_callReject_key
 @abstract    拒绝呼叫
 */
extern NSString *const PLVSocketIOSipLinkMic_callReject_key;

/*!
 @constant    PLVSocketIOSipLinkMic_disconnectCall_key
 @abstract    断开呼叫
 */
extern NSString *const PLVSocketIOSipLinkMic_disconnectCall_key;

/*!
 @constant    PLVSocketIOSipLinkMic_callFail_key
 @abstract    呼叫失败
 */
extern NSString *const PLVSocketIOSipLinkMic_callFail_key;

/*!
 @constant    PLVSocketIOSipLinkMic_callSuccess_key
 @abstract    呼叫成功
 */
extern NSString *const PLVSocketIOSipLinkMic_callSuccess_key;

/*!
 @constant    PLVSocketIOSipLinkMic_hangUp_key
 @abstract    挂断
 */
extern NSString *const PLVSocketIOSipLinkMic_hangUp_key;

/*!
 @constant    PLVSocketIOSipLinkMic_callIn_key
 @abstract    呼入
 */
extern NSString *const PLVSocketIOSipLinkMic_callIn_key;

/*!
 @constant    PLVSocketIOSipLinkMic_mute_key
 @abstract    静音
 */
extern NSString *const PLVSocketIOSipLinkMic_mute_key;

/*!
 @constant    PLVSocketIOSipLinkMic_unMute_key
 @abstract    取消静音
 */
extern NSString *const PLVSocketIOSipLinkMic_unMute_key;


#pragma mark - 云课堂事件键集合

/*!
 @constant    PLVSocketIOPPT_onSliceID_key
 @abstract    登录Socket后服务器传值
 */
extern NSString *const PLVSocketIOPPT_onSliceID_key;
    extern NSString *const PLVSocketIOPPT_onSliceID_data; /* NSDictionary */

/*!
 @constant    PLVSocketIOPPT_onSliceOpen_key
 @abstract    客户端打开PPT操作事件
 */
extern NSString *const PLVSocketIOPPT_onSliceOpen_key;
    extern NSString *const PLVSocketIOPPT_onSliceOpen_data; /* NSDictionary */

/*!
 @constant    PLVSocketIOPPT_onSliceStart_key
 @abstract    客户端点击上课推流事件
 */
extern NSString *const PLVSocketIOPPT_onSliceStart_key;
    extern NSString *const PLVSocketIOPPT_onSliceStart_data; /* NSDictionary */
    extern NSString *const PLVSocketIOPPT_onSliceStart_isNoCount; /* BOOL, 合并ppt的数据用，也区分开新旧数据 */
    extern NSString *const PLVSocketIOPPT_onSliceStart_pushTime; /* NSNumber */
    extern NSString *const PLVSocketIOPPT_onSliceStart_timeStamp; /* NSNumber */

/*!
 @constant    PLVSocketIOPPT_onSliceDraw_key
 @abstract    画笔格式事件
 */
extern NSString *const PLVSocketIOPPT_onSliceDraw_key;
    extern NSString *const PLVSocketIOPPT_onSliceDraw_data; /* NSDictionary */

/*!
 @constant    PLVSocketIOPPT_onSliceControl_key
 @abstract    PPT控制命令
 */
extern NSString *const PLVSocketIOPPT_onSliceControl_key;
    extern NSString *const PLVSocketIOPPT_onSliceControl_data;  /* NSDictionary */

#pragma mark - 图文直播事件键集合

/*!
 @constant    PLVSocketIOTuwen_Create_key
 @abstract    聊天室消息，收到新的图文触发
 */
extern NSString *const PLVSocketIOTuwen_Create_key;
    extern NSString *const PLVSocketIOTuwen_Create_data; /* NSDictionary */

/*!
 @constant    PLVSocketIOTuwen_Delete_key
 @abstract    聊天室消息，删除图文
 */
extern NSString *const PLVSocketIOTuwen_Delete_key;
    extern NSString *const PLVSocketIOTuwen_Delete_data; /* NSDictionary */

/*!
 @constant    PLVSocketIOTuwen_Settop_key
 @abstract    聊天室消息，置顶图文
 */
extern NSString *const PLVSocketIOTuwen_Settop_key;
    extern NSString *const PLVSocketIOTuwen_Settop_data; /* NSDictionary */

/*!
 @constant    PLVSocketIOTuwen_Edit_key
 @abstract    聊天室消息，编辑现有图文
 */
extern NSString *const PLVSocketIOTuwen_Edit_key;
    extern NSString *const PLVSocketIOTuwen_Edit_data; /* NSDictionary */

#pragma mark - 问答功能事件键集合

/*!
 @constant    PLVSocketIOQA_LAUNCH_QUESTION_EVENT
 @abstract    发出问答事件
 */
extern NSString *const PLVSocketIOQA_LAUNCH_QUESTION_EVENT;
    extern NSString *const PLVSocketIOQA_LAUNCH_QUESTION_content; //发出问答内容

/*!
 @constant    PLVSocketIOQA_LAUNCH_ANSWER_EVENT
 @abstract    回复问答事件
 */
extern NSString *const PLVSocketIOQA_LAUNCH_ANSWER_EVENT;
    extern NSString *const PLVSocketIOQA_LAUNCH_ANSWER_content; //回复问答内容
    extern NSString *const PLVSocketIOQA_LAUNCH_ANSWER_id;
    extern NSString *const PLVSocketIOQA_LAUNCH_ANSWER_user;/* NSDictionary */
    extern NSString *const PLVSocketIOQA_LAUNCH_ANSWER_sessionId;
    extern NSString *const PLVSocketIOQA_LAUNCH_ANSWER_roomId;
    extern NSString *const PLVSocketIOQA_LAUNCH_ANSWER_questionerId;
    extern NSString *const PLVSocketIOQA_LAUNCH_ANSWER_questionId;

/*!
 @constant    PLVSocketIOQA_DELETE_ANSWER_EVENT
 @abstract    删除问答事件
 */
extern NSString *const PLVSocketIOQA_DELETE_ANSWER_EVENT;
    extern NSString *const PLVSocketIOQA_DELETE_ANSWER_id;
    extern NSString *const PLVSocketIOQA_DELETE_ANSWER_questionId;
    extern NSString *const PLVSocketIOQA_DELETE_ANSWER_roomId;
    extern NSString *const PLVSocketIOQA_DELETE_ANSWER_sessionId;

#pragma mark - 互动课堂事件键集合

/*!
 @constant    PLVSocketIOClass_onClassStart_key
 @abstract    开始上课事件
 */
extern NSString *const PLVSocketIOClass_onClassStart_key;
    extern NSString *const PLVSocketIOClass_onClassStart_roomId;
    extern NSString *const PLVSocketIOClass_onClassStart_sessionId;
    extern NSString *const PLVSocketIOClass_onClassStart_timeStamp; /* NSNumber */
    extern NSString *const PLVSocketIOClass_onClassStart_isNoCount; /* BOOL */
    extern NSString *const PLVSocketIOClass_onClassStart_data; /* NSDictionary */
    extern NSString *const PLVSocketIOClass_onClassStart_pushtime; /* NSNumber */
    extern NSString *const PLVSocketIOClass_onClassStart_teacherId;

/*!
 @constant    PLVSocketIOClass_onClassEnd_key
 @abstract    结束上课事件
 */
extern NSString *const PLVSocketIOClass_onClassEnd_key;
    extern NSString *const PLVSocketIOClass_onClassEnd_roomId;
    extern NSString *const PLVSocketIOClass_onClassEnd_timeStamp; /* NSNumber */

/*!
 @constant    PLVSocketIOClass_onClassControl_key
 @abstract    课堂控制事件
 */
extern NSString *const PLVSocketIOClass_onClassControl_key;
    extern NSString *const PLVSocketIOClass_onClassControl_roomId;
    extern NSString *const PLVSocketIOClass_onClassControl_timeStamp; /* NSNumber */
    extern NSString *const PLVSocketIOClass_onClassControl_type; /* muteAllAudio(全员静音)、muteAllVideo(全员下麦)、muteUserAudio(静音某个学员)、muteUserVideo(下麦某个学员) */
    extern NSString *const PLVSocketIOClass_onClassControl_isMuted; /* BOOL: true(静音/下麦)、false(恢复静音/上麦) */
    extern NSString *const PLVSocketIOClass_onClassControl_userId; /* Optional, 学员id */

#pragma mark - H5互动消息事件键集合

#pragma mark 答题卡事件键集合
/*!
 @constant    PLVSocketInteraction_onTriviaCard_key
 @abstract    答题卡事件
 */
extern NSString *const PLVSocketInteraction_onTriviaCard_key;
    extern NSString *const PLVSocketInteraction_onTriviaCard_questionContent;
    extern NSString *const PLVSocketInteraction_onTriviaCard_questionResult;
    extern NSString *const PLVSocketIOClass_onTriviaCard_stop;
    extern NSString *const PLVSocketInteraction_onTriviaCard_about;

#pragma mark 问卷事件键集合
/*!
 @constant    PLVSocketInteraction_onQuestionnaire_key
 @abstract    问卷事件
 */
extern NSString *const PLVSocketInteraction_onQuestionnaire_key;
    extern NSString *const PLVSocketInteraction_onQuestionnaire_start;
    extern NSString *const PLVSocketInteraction_onQuestionnaire_stop;
    extern NSString *const PLVSocketInteraction_onQuestionnaire_sendResult;
    extern NSString *const PLVSocketInteraction_onQuestionnaire_achievement;
    extern NSString *const PLVSocketInteraction_onQuestionnaire_about;

#pragma mark 抽奖事件键集合
/*!
 @constant    PLVSocketInteraction_onLottery_key
 @abstract    抽奖事件
 */
extern NSString *const PLVSocketInteraction_onLottery_key;
    extern NSString *const PLVSocketInteraction_onLottery_start;
    extern NSString *const PLVSocketInteraction_onLottery_stop;
    extern NSString *const PLVSocketInteraction_onLottery;
    extern NSString *const PLVSocketInteraction_onLottery_winner;
    extern NSString *const PLVSocketInteraction_onLottery_about;

#pragma mark 签到事件键集合
/*!
 @constant    PLVSocketInteraction_onSignIn_key
 @abstract    签到事件
 */
extern NSString *const PLVSocketInteraction_onSignIn_key;
    extern NSString *const PLVSocketInteraction_onSignIn_start;
    extern NSString *const PLVSocketInteraction_onSignIn_stop;
    extern NSString *const PLVSocketInteraction_onSignIn_about;

#pragma mark 中奖消息记录事件键集合
/*!
 @constant    PLVSocketInteraction_lotteryWinRecord_key
 @abstract    签到事件
 */
extern NSString *const PLVSocketInteraction_lotteryWinRecord_key;
    extern NSString *const PLVSocketInteraction_lotteryWinRecord_about;

#pragma mark 卡片推送事件键集合
/*!
 @constant    PLVSocketCardPush_newsPush_key
 @abstract    营销 - 卡片推送事件
 */
extern NSString *const PLVSocketCardPush_newsPush_key;
    extern NSString *const PLVSocketCardPush_newsPush_EVENT;
    extern NSString *const PLVSocketCardPush_newsPush_roomId;
    extern NSString *const PLVSocketCardPush_newsPush_entrance;
    extern NSString *const PLVSocketCardPush_newsPush_lookTime;
    extern NSString *const PLVSocketCardPush_newsPush_time;

/*!
 @constant    PLVSocketProduct_product_key
 @abstract    营销 - 热卖商品推送事件
 */
extern NSString *const PLVSocketProduct_product_key;
    extern NSString *const PLVSocketProduct_productClick_EVENT;
    extern NSString *const PLVSocketProduct_productClick_nickName;
    extern NSString *const PLVSocketProduct_productClick_type;
    extern NSString *const PLVSocketProduct_productClick_positionName;
