//
//  PLVLiveVideoAPI.h
//  PLVLiveScenesSDK
//
//  Created by zykhbl on 2018/7/27.
//  Copyright © 2018年 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLVLiveDefine.h"
#import "PLVLiveVideoChannelMenuInfo.h"
#import "PLVPlaybackListModel.h"
#import "PLVCommodityModel.h"
#import "PLVChannelInfoModel.h"
#import "PLVViewLogCustomParam.h"
#import "PLVLivePlaybackSectionModel.h"
#import "PLVChannelPlaybackInfoModel.h"


extern NSString *const PLVApichatDomain;

NS_ASSUME_NONNULL_BEGIN

@interface PLVLiveVideoAPI : NSObject

/**
 设置私有的聊天室域名
 
 @param domainName 外部设置的私有域名，如果为空或没有设置，怎使用默认的域名
 */
 + (void)setPrivateApichatDomainName:(NSString *)domainName;

#pragma mark - 登录校验

/**
 登录校验
 两种校验类型：1.直播相关参数校验 2.回放相关参数校验（vid为nil时进行直播相关参数校验，非空时进行回放相关参数校验）
 1.直播相关参数校验：channelId、appId、userId、appSecret
 2.回放相关参数校验：①vid、appId、channelId、userId；②vid、appId（channelId为0时，版本兼容）
 v1.0.0 版本之后请使用新接口 '+verifyLivePermissionWithChannelId:userId:appId:appSecret:completion:failure:' 和 '+verifyVodPermissionWithVid:userId:appId:appSecret:completion:failure:' 进行直播和回放的登录校验
 @param channelId 直播频道号
 @param vid 回放点播视频vid
 @param appId 云直播账号 应用Id
 @param userId 云直播账号 用户Id
 @param appSecret 云直播账号 应用密钥
 */
+ (void)verifyPermissionWithChannelId:(NSUInteger)channelId vid:(NSString *)vid appId:(NSString *)appId userId:(NSString *)userId appSecret:(NSString *)appSecret completion:(void (^)(NSDictionary *))completion failure:(void (^)(NSError *))failure DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用verifyPermissionWithChannelId:vid:appId:userId:completion:failure:");
/**
 登录校验
 两种校验类型：1.直播相关参数校验 2.回放相关参数校验（vid为nil时进行直播相关参数校验，非空时进行回放相关参数校验）
 1.直播相关参数校验：channelId、appId、userId
 2.回放相关参数校验：①vid、appId、channelId、userId；②vid、appId（channelId为0时，版本兼容）
 v1.0.0 版本之后请使用新接口 '+verifyLivePermissionWithChannelId:userId:appId:appSecret:completion:failure:' 和 '+verifyVodPermissionWithVid:userId:appId:appSecret:completion:failure:' 进行直播和回放的登录校验
 @param channelId 直播频道号
 @param vid 回放点播视频vid
 @param appId 云直播账号 应用Id
 @param userId 云直播账号 用户Id
 */
+ (void)verifyPermissionWithChannelId:(NSUInteger)channelId vid:(NSString *)vid appId:(NSString *)appId userId:(NSString *)userId completion:(void (^)(NSDictionary *))completion failure:(void (^)(NSError *))failure;

/**
 直播登录校验 API（v1.0.0版本+）
 直播相关参数校验：channelId、userId、appId、appSecret
 @param channelId 频道号
 @param userId 用户Id
 @param appId 应用Id
 @param appSecret 应用密钥
 */
+ (void)verifyLivePermissionWithChannelId:(NSUInteger)channelId
                                   userId:(NSString *)userId
                                    appId:(NSString *)appId
                                appSecret:(NSString *)appSecret
                               completion:(void (^)(NSDictionary *data))completion
                                  failure:(void (^)(NSError *error))failure DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用verifyLivePermissionWithChannelId:userId:appId:completion:failure:");

/**
 直播登录校验 API（v1.0.0版本+）
 直播相关参数校验：channelId、userId、appId
 @param channelId 频道号
 @param userId 用户Id
 @param appId 应用Id */
+ (void)verifyLivePermissionWithChannelId:(NSUInteger)channelId
                                   userId:(NSString *)userId
                                    appId:(NSString *)appId
                               completion:(void (^)(NSDictionary *data))completion
                                  failure:(void (^)(NSError *error))failure;

/**
 回放登录校验 API（v1.0.0版本+）
 回放相关参数校验：channelId、vid、userId、appId、appSecret
 @param channelId 频道号
 @param vid 回放点播视频vid
 @param userId 用户Id
 @param appId 应用Id
 @param appSecret 应用密钥
 */
+ (void)verifyVodPermissionWithChannelId:(NSUInteger)channelId
                                     vid:(NSString *)vid
                                  userId:(NSString *)userId
                                   appId:(NSString *)appId
                               appSecret:(NSString *)appSecret
                              completion:(void (^)(NSDictionary *data))completion
                                 failure:(void (^)(NSError *error))failure DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用verifyVodPermissionWithChannelId:vid:userId:appId:completion:failure:");

/**
 回放登录校验 API（v1.0.0版本+）
 回放相关参数校验：channelId、vid、userId、appId
 @param vid 回放点播视频vid
 @param userId 用户Id
 @param appId 应用Id
 */
+ (void)verifyVodPermissionWithChannelId:(NSUInteger)channelId
                                     vid:(NSString *)vid
                                  userId:(NSString *)userId
                                   appId:(NSString *)appId
                              completion:(void (^)(NSDictionary *data))completion
                                 failure:(void (^)(NSError *error))failure;

/// 推流登录，获取推流的频道信息
/// @param channelId 频道号
/// @param password 频道密码
/// @param channelType 频道类型，目前只支持（‘ppt’-三分屏/‘alone’-纯视频）两种频道类型
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)loadPushInfoWithChannelId:(NSString *)channelId
                         password:(NSString *)password
                      channelType:(PLVChannelType)channelType
                       completion:(void (^)(NSDictionary *data, NSString *rtmpUrl))completion
                          failure:(void (^)(NSError *error))failure;

#pragma mark - 获取频道类型 & 直播状态

/**
 校验后，根据channelId获取该频道的类型（普通直播，云课堂），和是否正在直播（废弃从0.13.1）
 @param channelId 频道号
 */
+ (void)liveStatus:(NSString *)channelId completion:(void (^)(BOOL, NSString *))completion failure:(void (^)(NSError *error))failure;

/// 获取频道的直播类型、直播流状态（v2）
///
/// @param channelId 频道号ID
/// @param completion 请求完成Block (channelType:频道类型 streamState:当前直播流状态)
/// @param failure 请求失败Block
+ (void)liveStatus2:(NSString *)channelId completion:(void (^)(PLVChannelType channelType, PLVChannelLiveStreamState streamState))completion failure:(void (^)(NSError *error))failure;

/// 获取频道的直播类型、直播流状态（v3）
///
/// @param channelId 频道号ID
/// @param appId 云直播账号 应用Id
/// @param appSecret 云直播账号 应用密钥
/// @param completion 请求完成Block (channelType:频道类型 streamState:当前直播流状态)
/// @param failure 请求失败Block
+ (void)liveStatus2:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret completion:(void (^)(PLVChannelType channelType, PLVChannelLiveStreamState streamState))completion failure:(void (^)(NSError *error))failure;

/**
 登录界面，校验后，根据vodId获取该频道的类型（普通直播，云课堂）
 
 @param vodId 回放视频ID
 */
+ (void)getVodType:(NSString *)vodId completion:(void (^)(PLVChannelType channelType))completion failure:(void (^)(NSError *error))failure;

/**
 登录界面，校验后，根据文件Id获取该频道的类型（普通直播，云课堂）
 
 @param channelId 直播频道号
 @param fileId 文件Id
 @param appId 云直播账号 应用Id
 @param appSecret 云直播账号 应用密钥
 */
+ (void)getLiveRecordTypeWithChannelId:(NSString *)channelId fileId:(NSString *)fileId appId:(NSString *)appId appSecret:(NSString *)appSecret completion:(void (^)(PLVChannelType))completion failure:(void (^)(NSError *error))failure;

/**
 获取频道菜单列表
 
 @param channelId 频道号
 */
+ (void)getChannelMenuInfos:(NSString *)channelId completion:(void(^)(PLVLiveVideoChannelMenuInfo *channelMenuInfo))completion failure:(void (^)(NSError *error))failure;

/**
 修改频道名
 
 @param channelName 频道名称
 @param channelId 频道号
 */
+ (void)updateChannelName:(NSString *)channelName channelId:(NSString *)channelId completion:(void (^)(void))completion failure:(void (^)(NSError *error))failure;


#pragma mark - 文档

/**
  根据频道号 channelId 获取 文档列表数据
 @note 用于 手机开播（三分屏）场景
 @param channelId 频道号
 */
+ (void)requestDocumentListWithChannelId:(NSString *)channelId completion:(void (^)(NSArray<NSDictionary *> *responseArray))completion failure:(void (^)(NSError *error))failure;

/// 获取文档列表数据
/// @note 用于 互动学堂 场景
/// @param lessonId 课节ID
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)requestDocumentListWithLessonId:(NSString *)lessonId completion:(void (^)(NSArray<NSDictionary *> *responseArray))completion failure:(void (^)(NSError *error))failure DEPRECATED_MSG_ATTRIBUTE("Please use 'requestDocumentListWithLessonId:courseCode:teacher:completion:failure:' instead");

/// 获取文档列表数据
/// @note 用于 互动学堂 场景
/// @param lessonId 课节ID
/// @param courseCode 课程号
/// @param teacher 是否为讲师
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)requestDocumentListWithLessonId:(NSString *)lessonId
                             courseCode:(NSString * _Nullable)courseCode teacher:(BOOL)teacher
                             completion:(void (^)(NSArray<NSDictionary *> *responseArray))completion
                                failure:(void (^)(NSError *error))failure;

/**
  根据频道号 channelId、文件ID fileId 删除某个文档
 
 @param channelId 频道号
 @param fileId 文件ID
 */
+ (void)deleteDocumentWithChannelId:(NSString * _Nullable)channelId fileId:(NSString *)fileId completion:(void (^)(void))completion failure:(void (^)(NSError *error))failure;

/**
  获取 PPT 文档转码结果
 @note 用于 手机开播（三分屏）场景
 @param channelId 频道号
 @param fileId 文件ID
 */ 
+ (void)getDocumentConvertStatusWithChannelId:(NSString *)channelId fileId:(NSString *)fileId completion:(void (^)(NSArray <NSDictionary *> *responseArray))completion failure:(void (^)(NSError *error))failure;

/// 获取 PPT 文档转码结果
/// @note 用于 互动学堂 场景
/// @param lessonId 课程号
/// @param fileId 文件ID
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)getDocumentConvertStatusWithLessonId:(NSString *)lessonId fileId:(NSString *)fileId completion:(void (^)(NSArray <NSDictionary *> *responseArray))completion failure:(void (^)(NSError *error))failure DEPRECATED_MSG_ATTRIBUTE("Please use 'getDocumentConvertStatusWithLessonId:fileId:courseCode:teacher:completion:failure:' instead");

/// 获取 PPT 文档转码结果
/// @note 用于 互动学堂 场景
/// @param lessonId 课程号
/// @param fileId 文件ID
/// @param courseCode 课程号
/// @param teacher 是否为讲师
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)getDocumentConvertStatusWithLessonId:(NSString *)lessonId
                                      fileId:(NSString *)fileId
                                  courseCode:(NSString * _Nullable)courseCode
                                     teacher:(BOOL)teacher
                                  completion:(void (^)(NSArray <NSDictionary *> *responseArray))completion failure:(void (^)(NSError *error))failure;

#pragma mark - 聊天室相关

/**
 获取 chatToken

 @param channelId 频道号
 @param userId 聊天室用户ID
 @param role 聊天室用户角色
 @Param groupId 聊天室分组Id
 */
+ (void)getChatTokenWithChannelId:(NSString *)channelId
                           userId:(NSString *)userId
                             role:(NSString *)role
                          groupId:(NSString * _Nullable)groupId
                       completion:(void (^)(NSDictionary *))completion
                          failure:(void (^)(NSError *error))failure;

/**
 获取 chatToken，分组Id默认为空

 @param channelId 频道号
 @param userId 聊天室用户ID
 @param role 聊天室用户角色
 */
+ (void)getChatTokenWithChannelId:(NSString *)channelId
                           userId:(NSString *)userId
                             role:(NSString *)role
                       completion:(void (^)(NSDictionary *))completion
                          failure:(void (^)(NSError *error))failure;

/**
 获取 chatToken，身份默认为 viewer

 @param channelId 频道号
 @param userId 聊天室用户ID
 */
+ (void)getChatTokenWithChannelId:(NSString *)channelId userId:(NSString *)userId completion:(void (^)(NSDictionary *data))completion failure:(void (^)(NSError *error))failure;

/**
 加载聊天室开关信息
 
 @param roomId 频道号
 */
+ (void)loadChatroomFunctionSwitchWithRoomId:(NSUInteger)roomId completion:(void (^)(NSDictionary *switchInfo))completion failure:(void (^ _Nullable)(NSError *error))failure;

/**
 根据时间戳加载聊天室历史记录
 
 @param roomId 频道号
 @param index 如果目前展示的消息已经有time为timestamp，且有1条，index不用传或者传1。假如有两条，则index传2，三条传3，依此类推。
 @param size 每页长度
 @param timestamp 从该时间戳开始获取，不传表示获取最新的数据
 @param order 数据根据时间戳的顺序，YES表示从小到大，NO表示从大到小
 */
+ (void)requestChatRoomHistoryWithRoomId:(NSString *)roomId index:(NSUInteger)index size:(NSInteger)size timestamp:(NSString *)timestamp order:(BOOL)order completion:(void (^)(NSArray * _Nonnull))completion failure:(void (^)(NSError * _Nonnull))failure;

/**
 加载聊天室历史记录
 
 @param roomId 频道号
 @param startIndex 开始index
 @param endIndex 结束index
 */
+ (void)requestChatRoomHistoryWithRoomId:(NSString *)roomId startIndex:(NSUInteger)startIndex endIndex:(NSInteger)endIndex completion:(void (^)(NSArray *historyList))completion failure:(void (^)(NSError *error))failure;

/**
 获取聊天室在线人数列表接口 1
 
 @param roomId 频道号/房间号
 @param page 页码
 @param length 一页的数据条数
 @param streamer YES-当前用户为讲师和特殊身份,返回classStatus字段（非讲师身份不可为YES，会有性能问题）
 */
+ (void)requestChatRoomListUsersWithRoomId:(NSString *)roomId
                                      page:(NSUInteger)page
                                    length:(NSUInteger)length
                                  streamer:(BOOL)streamer
                                   success:(void (^)(NSDictionary *data))success
                                   failure:(void (^ _Nullable)(NSError *error))failure;

/**
 获取聊天室在线人数列表接口 2
 
 @param roomId 频道号/房间号
 @param page 页码
 @param length 一页的数据条数
 @param sessionId 场次ID，目前该参数只用于互动学堂场景
 @param streamer YES-当前用户为讲师和特殊身份,返回classStatus字段（非讲师身份不可为YES，会有性能问题） 
 */
+ (void)requestChatRoomListUsersWithRoomId:(NSString *)roomId
                                      page:(NSUInteger)page
                                    length:(NSUInteger)length
                                 sessionId:(NSString * _Nullable)sessionId
                                  streamer:(BOOL)streamer
                                   success:(void (^)(NSDictionary *))success
                                   failure:(void (^ _Nullable)(NSError *))failure;

/**
 获取聊天室具体房间号被踢出的用户列表
 @param roomId 频道号/房间号
 */
+ (void)requestChatRoomListKickedWithRoomId:(NSString *)roomId
                                    success:(void (^)(NSArray *responseArray))success
                                    failure:(void (^)(NSError *error))failure;

/**
 获取图片表情列表接口
 
 @param roomId 频道号/房间号
 @param accountId 账号Id
 @param page 页码
 @param size 一页的数据条数
 */
+ (void)requestEmotionImagesWithRoomId:(NSUInteger)roomId
                             accountId:(NSString *)accountId
                                  page:(NSUInteger)page
                                  size:(NSUInteger)size
                               success:(void (^)(NSDictionary *data))success
                               failure:(void (^ _Nullable)(NSError *error))failure;

/**
 点赞
 
 @param channelId 频道号
 @param viewerId 聊天室用户Id
 @param times 某段时间内新增点赞数
 */
+ (void)likeWithChannelId:(NSUInteger)channelId viewerId:(NSString *)viewerId times:(NSUInteger)times completion:(void (^)(void))completion failure:(void (^ _Nullable )(NSError *error))failure;

/**
 发送图片
 
 @param image 图片
 @param imageName 图片名字
 @param channelId 频道号
 */
+ (void)uploadImage:(UIImage *)image
          imageName:(NSString *)imageName
          channelId:(NSString *)channelId
           progress:(void (^)(float))progressBlock
            success:(void (^)(NSDictionary *tokenDict, NSString *key, NSString *imageName))successBlock
               fail:(void (^)(NSError *error))failBlock;

/**
 发送图片
 @note 使用该方法上传的图片，会压缩到小于2MB为止
 @param image 图片
 @param imageName 图片名字
 */
+ (void)uploadImage:(UIImage *)image
          imageName:(NSString *)imageName
           progress:(void (^)(float))progressBlock
            success:(void (^)(NSDictionary *tokenDict, NSString *key, NSString *imageName))successBlock
               fail:(void (^)(NSError *error))failBlock DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用uploadImage:imageName:channelId:progress:success:fail:");

/**
 发送图片
 @note 使用该方法上传的图片，不会再进行压缩
 @param imageData 图片数据
 @param imageName 图片名字
 @param channelId 频道号
 */
+ (void)uploadImageData:(NSData *)imageData
              imageName:(NSString *)imageName
              channelId:(NSString *)channelId
               progress:(void (^)(float))progressBlock
                success:(void (^)(NSDictionary *tokenDict, NSString *key, NSString *imageName))successBlock
                   fail:(void (^)(NSError *error))failBlock;

/**
 发送图片
 @note 使用该方法上传的图片，不会再进行压缩
 @param imageData 图片数据
 @param imageName 图片名字
 */
+ (void)uploadImageData:(NSData *)imageData
              imageName:(NSString *)imageName
               progress:(void (^)(float))progressBlock
                success:(void (^)(NSDictionary *tokenDict, NSString *key, NSString *imageName))successBlock
                   fail:(void (^)(NSError *error))failBlock DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用uploadImageData:imageName:channelId:progress:success:fail:");

/**
 增加播放热度
 
 @param channelId 频道号
 @param times 新增 socket login 次数（收到自己的 login 消息一次 times +1）
 */
+ (void)increaseViewerWithChannelId:(NSString *)channelId times:(NSUInteger)times completion:(void (^)(NSInteger))completion failure:(void (^)(NSError *error))failure;

/// 获取当前观看次数
/// @param channelId 频道号
+ (void)requestPageViewWithChannelId:(NSString *)channelId completion:(void (^)(NSDictionary *data))completion failure:(void (^)(NSError *error))failure;

/// 加载聊天室提醒消息历史记录
/// @param roomId 频道号
/// @param startIndex 开始index
/// @param endIndex 结束index
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)requestChatRoomRemindHistoryWithRoomId:(NSString *)roomId startIndex:(NSUInteger)startIndex endIndex:(NSInteger)endIndex completion:(void (^)(NSArray *historyList))completion failure:(void (^)(NSError *error))failure;

/// 获取最新红包
/// @param channelId 频道号
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)requestNewestRedpackWithChannelId:(NSString *)channelId completion:(void (^)(NSDictionary *data))completion failure:(void (^_Nullable)(NSError *error))failure;

/// 判断观众是否已抢红包
/// @param channelId 频道号
/// @param viewerId 观众viewerId
/// @param redpackId 红包ID
/// @param redCacheId 红包CacheID
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)requestRedpackReceiveCacheWithChannelId:(NSString *)channelId
                                       viewerId:(NSString *)viewerId
                                      redpackId:(NSString *)redpackId
                                     redCacheId:(NSString *)redCacheId
                                     completion:(void (^)(NSDictionary *data))completion
                                        failure:(void (^_Nullable)(NSError *error))failure;

/// 加载聊天室提问消息历史记录
/// @param roomId 频道号
/// @param page 页码
/// @param pageSize 每页的size
/// @param completion 成功回调
/// @param failure 失败回调
+ (void)requestChatRoomQuestionHistoryWithRoomId:(NSString *)roomId page:(NSUInteger)page pageSize:(NSInteger)pageSize completion:(void (^)(NSDictionary *data))completion failure:(void (^)(NSError * _Nonnull))failure;

#pragma mark - 连麦相关

/**
 普通直播，获取推流端是旧的推流端（主讲人走CDN视频，连麦走RTC音频），还是新的推流端（主讲人走RTC视频，连麦走RTC）
 
 @param channelId 频道号
 */
+ (void)rtcEnabled:(NSUInteger)channelId completion:(void (^)(BOOL))completion failure:(void (^)(NSError *))failure;

/**
 检测当前连麦状态
 
 @param roomId 频道号
 */
+ (void)requestLinkMicStatusWithRoomId:(NSUInteger)roomId completion:(void (^)(NSString *, NSString *))completion failure:(void (^)(NSError *))failure;

/**
 获取当前连麦列表
 
 @param roomId 频道号
 @param sessionId 当前直播的sessionId
 */
+ (void)requestLinkMicOnlineListWithRoomId:(NSString *)roomId sessionId:(NSString *)sessionId completion:(void (^)(NSDictionary *))completion failure:(void (^)(NSError *))failure;

/**
 获取当前连麦列表
 
 @param roomId 频道号
 @param sessionId 当前直播的sessionId
 @param getSubRooms 是否获取转播子频道信息，默认为NO
 */
+ (void)requestLinkMicOnlineListWithRoomId:(NSString *)roomId
                                 sessionId:(NSString *)sessionId
                               getSubRooms:(BOOL)getSubRooms
                                completion:(void (^)(NSDictionary *))completion
                                   failure:(void (^)(NSError *))failure;

/**
 连麦id和聊天室用户id关联
 
 @param channelId 频道号
 @param viewerId 聊天室的用户Id
 @param linkMicId 连麦id
 */
+ (void)requestViewerIdLinkMicIdRelate:(NSString *)channelId viewerId:(NSString *)viewerId linkMicId:(NSString *)linkMicId completion:(nullable void (^)(void))completion failure:(nullable void (^)(NSError *))failure;

/**
 强制下麦
 
 @param channelId 频道号
 @param userId 连麦用户ID
 @param linkMicId 连麦id
 */
+ (void)requestLinkMicRemoveUser:(NSString *)channelId userId:(NSString *)userId linkMicId:(NSString *)linkMicId completion:(void (^)(BOOL))completion failure:(void (^)(NSError *))failure;

#pragma mark - SIP相关
/**
 获取SIP入会信息
 @param channelId 频道号
 */
+ (void)requestSIPInfoWithChannelId:(NSString *)channelId completion:(void (^)(NSDictionary *data))completion failure:(void (^)(NSError * error))failure;

/**
 获取当前拨号情况列表
 @param channelId 频道号
 */
+ (void)requestSIPDialLinesListWithChannelId:(NSString *)channelId completion:(void (^)(NSDictionary *data))completion failure:(void (^)(NSError *error))failure;

#pragma mark - 抽奖

/**
 发送中奖信息（自 v0.11.1 失效）
 
 @param data 中奖信息
 */
+ (void)postLotteryWithData:(NSDictionary *)data completion:(void (^)(void))completion failure:(void (^)(NSError *error))failure;

/**
 发送中奖信息（自 v0.11.1 生效）
 
 @param data 中奖信息
 */
+ (void)newPostLotteryWithData:(NSDictionary *)data completion:(void (^)(void))completion failure:(void (^)(NSError *error))failure;

/**
 放弃领奖
 
 @param channelId 频道号
 @param userId 聊天室用户ID
 */
+ (void)giveUpReceiveWithChannelId:(NSString *)channelId userId:(NSString *)userId completion:(void (^)(NSString *))completion failure:(void (^)(NSError *error))failure;

#pragma mark - 礼物打赏

/**
  获取该频道打赏设置
  
  @param channelId 频道号
  */
+ (void)requestRewardWithChannelId:(NSString *)channelId completion:(void (^)(NSDictionary*))completion failure:(void (^)(NSError * _Nonnull))failure;

/**
  获取该频道积分打赏设置
  
  @param channelId 频道号
  */
 + (void)requestPointSettingWithChannelId:(NSUInteger)channelId completion:(nullable void (^)(NSDictionary *))completion failure:(nullable void (^)(NSError *))failure;

 /**
 获取观众的积分信息
  
 @param viewerId 聊天室用户Id
 @param nickName 观众的用户昵称
 @param channelId 频道号
 */
 + (void)requestViewerPointWithViewerId:(NSString *)viewerId nickName:(NSString *)nickName channelId:(NSUInteger)channelId completion:(nullable void (^)(NSString *))completion failure:(nullable void (^)(NSError *))failure;

 /**
 观众打赏积分道具
  
 @param viewerId 聊天室用户Id
 @param nickName 观众的昵称
 @param avatar 观众的头像地址
 @param goodId 商品id
 @param goodNum 商品数量
 @param channelId 频道号
 */
 + (void)requestViewerRewardPointWithViewerId:(NSString *)viewerId nickName:(NSString *)nickName avatar:(NSString *)avatar goodId:(NSInteger)goodId goodNum:(NSInteger)goodNum channelId:(NSUInteger)channelId completion:(nullable void (^)(NSString *))completion failure:(nullable void (^)(NSError *))failure;

/**
观众打赏免费道具
 
@param viewerId 聊天室用户Id
@param nickName 观众的昵称
@param avatar 观众的头像地址
@param goodId 商品id
@param goodNum 商品数量
@param channelId 频道号
@param sessionId 场次号
*/
+ (void)requestViewerFreeDonateRewardWithViewerId:(NSString *)viewerId nickName:(NSString *)nickName avatar:(NSString *)avatar goodId:(NSInteger)goodId goodNum:(NSInteger)goodNum channelId:(NSUInteger)channelId sessionId:(NSString *)sessionId completion:(nullable void (^)(void))completion failure:(nullable void (^)(NSError *))failure;

/// 获取卡片推送相关信息
/// @param channelId 频道id
/// @param cardPushId 商品推送id
+ (void)requestCardPushInfoWithChannelId:(NSString *)channelId cardPushId:(NSString *)cardPushId completion:(void (^)(NSDictionary *cardDict))completion failure:(nullable void (^)(NSError *))failure;

#pragma mark - 直播回放
/**
 获取视频弹幕信息
 */
+ (void)loadDanmuWithVid:(NSString *)vid time:(NSString *)time msgId:(NSUInteger)msgId limit:(NSUInteger)limit completion:(void (^)(NSArray *danmuArr, NSError *error))completion;

/**
 新增回放弹幕
 */
+ (void)addDanmuWithVid:(NSString *)vid msg:(NSString *)msg time:(NSString *)time sessionId:(NSString *)sessionId msgType:(NSString *)msgType user:(NSString *)user completion:(void (^)(NSDictionary *respondDict, NSError *error))completion;

/// 查询频道回放功能开关
/// @param channelId 频道号
/// @param appId 用户appId
/// @param appSecret 用户appSecret
/// @param completion 请求完成块
+ (void)requestPlaybackEnableWithChannelId:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret completion:(void (^)(BOOL enable , NSError * _Nullable error))completion;

/// 查询回放视频的视频列表信息（区分是否是接收转播的频道）
/// @param channelId 频道号
/// @param listType playback-回放列表，vod-点播列表; 默认普通直播场景为vod，三分屏为playback
/// @param page 页数，默认每页显示12条数据
/// @param pageSize 每页显示的数据条数，0为默认值
/// @param appId 用户appId
/// @param appSecret 用户appSecret
/// @param completion 请求完成块
+ (void)requestPlaybackListWithChannelId:(NSString *)channelId listType:(NSString *)listType page:(NSUInteger)page pageSize:(NSUInteger)pageSize appId:(NSString *)appId appSecret:(NSString *)appSecret completion:(void (^)(PLVPlaybackListModel * _Nullable model, NSError * _Nullable error))completion;

/// 查询回放视频的视频列表信息
/// @param channelId 频道号
/// @param listType playback-回放列表，vod-点播列表; 默认普通直播场景为vod，三分屏为playback
/// @param page 页数，默认每页显示12条数据
/// @param pageSize 每页显示的数据条数，0为默认值
/// @param appId 用户appId
/// @param appSecret 用户appSecret
/// @param completion 请求完成块
+ (void)requestPlaybackList:(NSString *)channelId listType:(NSString *)listType page:(NSUInteger)page pageSize:(NSUInteger)pageSize appId:(NSString *)appId appSecret:(NSString *)appSecret completion:(void (^)(PLVPlaybackListModel * _Nullable model, NSError * _Nullable error))completion DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用requestPlaybackListWithChannelId:listType:page:pageSize:appId:appSecret:completion:");

/// 查询章节功能开关
/// @param channelId 频道号
/// @param completion 请求完成块
+ (void)requestLivePlaybackSectionEnableWithChannelId:(NSString *)channelId completion:(void (^)(BOOL enable))completion failure:(void (^)( NSError * _Nullable error))failure DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用requestChannelPlaybackSettingWithChannelId:appId:completion:failure:");

/// 获取回放章节列表 （v2）
/// @param channelId 频道号
/// @param videoId 直播系统生成的回放id
/// @param appId 用户appId
/// @param appSecret 用户appSecret
/// @param completion 请求完成块
+ (void)requestLivePlaybackSectionListWithChannelId:(NSString *)channelId videoId:(NSString *)videoId appId:(NSString *)appId appSecret:(NSString *)appSecret completion:(void (^)(NSArray<PLVLivePlaybackSectionModel *> *sectionList, NSError * _Nullable error))completion;

/// 获取回放章节列表
/// @param channelId 频道号
/// @param videoId 直播系统生成的回放id
/// @param completion 请求完成块
+ (void)requestLivePlaybackSectionListWithChannelId:(NSString *)channelId videoId:(NSString *)videoId completion:(void (^)(NSArray<PLVLivePlaybackSectionModel *> *sectionList, NSError * _Nullable error))completion;

/// 查询回放功能设置
/// @param channelId 频道号
/// @param appId 用户appId
/// @param vid 视频vid
/// @param playbackType 回放类型
/// @param completion 请求完成块，回放设置可为空
+ (void)requestChannelPlaybackInfoWithChannelId:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret vid:(NSString * _Nullable)vid playbackType:(NSString * _Nullable)playbackType completion:(void (^)(PLVChannelPlaybackInfoModel * _Nullable channelPlaybackInfo))completion failure:(void (^)( NSError * _Nullable error))failure;

/// 查询回放功能设置
/// @param channelId 频道号
/// @param completion 请求完成块，回放设置可为空
+ (void)requestChannelPlaybackInfoWithChannelId:(NSString *)channelId completion:(void (^)(PLVChannelPlaybackInfoModel * _Nullable channelPlaybackInfo))completion failure:(void (^)( NSError * _Nullable error))failure DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用requestChannelPlaybackSettingWithChannelId:appId:completion:failure:");

/// 获取录制文件章节列表 (v2)
/// @param channelId 频道号
/// @param fileId 录制文件id
/// @param appId 用户appId
/// @param appSecret 用户appSecret
/// @param completion 请求完成块
+ (void)requestLiveRecordSectionListWithChannelId:(NSString *)channelId fileId:(NSString *)fileId appId:(NSString *)appId appSecret:(NSString *)appSecret completion:(void (^)(NSArray<PLVLivePlaybackSectionModel *> *sectionList, NSError * _Nullable error))completion;

/// 获取录制文件章节列表
/// @param channelId 频道号
/// @param fileId 录制文件id
/// @param completion 请求完成块
+ (void)requestLiveRecordSectionListWithChannelId:(NSString *)channelId fileId:(NSString *)fileId completion:(void (^)(NSArray<PLVLivePlaybackSectionModel *> *sectionList, NSError * _Nullable error))completion;

#pragma mark - 跑马灯

/**
 加载自定义跑马灯

 @param url 自定义跑马灯地址
 @param channelId 直播频道号
 @param userId 云直播账号 用户ID
 @param code 自定义跑马灯附带参数
 @param completion 加载成功
 @param failure 加载失败
 */
+ (void)loadCustomMarquee:(NSURL *)url withChannelId:(NSUInteger)channelId userId:(NSString *)userId code:(NSString *)code completion:(void (^)(BOOL valid, NSDictionary *marqueeDict))completion failure:(void (^)(NSError *error))failure;

#pragma mark - 商品

/**
 获取商品列表
 
 @param channelId 频道号
 @param rank 排序号 （加载序号以前的商品）
 @param count 获取列表数据大小，默认10条，最大20
 @param completion 加载成功（返回商品列表顺序与后台显示顺序一致）
 @param failure 加载失败
 */
+ (void)loadCommodityList:(NSUInteger)channelId rank:(NSUInteger)rank count:(NSUInteger)count completion:(void (^)(NSUInteger total, NSArray<PLVCommodityModel *> *commoditys))completion failure:(void (^)(NSError *error))failure;

#pragma mark - 海报

/// 获取邀请海报设置
/// @param channelId 频道号
/// @param success 请求成功
/// @param failure 请求失败
+ (void)requestInvitePosterWithChannelId:(NSString *)channelId success:(void (^) (NSDictionary *respondDict))success failure:(void (^)(NSError * error))failure;

#pragma mark - 推流
/// 更新频道直播状态至结束接口
///
/// @param channelId 频道号
/// @param stream 流名
/// @param success 请求成功
/// @param failure 请求失败
+ (void)requestChannelLivestatusEndWithChannelId:(NSString *)channelId stream:(NSString *)stream success:(void (^)(NSString *))success failure:(void (^)(NSError * error))failure;

#pragma mark - 分组

/// 获取分组列表
/// @param channelId 频道号
/// @param appId appId
/// @param channelToken api频道token
/// @param success 请求成功
/// @param failure 请求失败
+ (void)requestGroupListWithChannelId:(NSString *)channelId
                                appId:(NSString *)appId
                         channelToken:(NSString *)channelToken
                              success:(void (^)(NSArray<NSDictionary *> *groupArray))success
                              failure:(void (^ _Nullable)(NSError * error))failure;

#pragma mark 观看页用户列表
/// 获取观看页用户列表
/// @param roomId 频道号
/// @param success 请求成功
/// @param failure 请求失
+ (void)requestViewerListWithRoomId:(NSString *)roomId
                            success:(void (^)(NSDictionary *viewerListDict))success
                            failure:(void (^ _Nullable)(NSError * error))failure;
/// 获取观看页分组用户列表
/// @param roomId 频道号
/// @param groupId 分组
/// @param success 请求成功
/// @param failure 请求失
+ (void)requestViewerListWithRoomId:(NSString *)roomId
                            groupId:(NSString *)groupId
                            success:(void (^)(NSDictionary *viewerListDict))success
                            failure:(void (^ _Nullable)(NSError * error))failure;

@end

NS_ASSUME_NONNULL_END
