//
//  PLVLinkMicGetTokenModel.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2020/12/24.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PLVLiveDefine.h"

NS_ASSUME_NONNULL_BEGIN

/// 更新连麦Token时所需的数据模型
@interface PLVLinkMicGetTokenModel : NSObject

#pragma mark 必需配置项
/// 频道号
@property (nonatomic, copy) NSString * channelId;

/// 连麦用户ID
@property (nonatomic, copy) NSString * userId;

/// 频道类型
@property (nonatomic, assign) PLVChannelType channelType;

/// 用户类型字符串
/// 讲师：teacher 嘉宾：guest 观众：audience
/// 特邀观众：invited 主持人：host 参会者：attendee
/// 互动学堂讲师：teacher 互动学堂观看端：SCStudent
@property (nonatomic, copy) NSString * userType;

/// 用户聊天室ID
@property (nonatomic, copy) NSString * viewerId;

/// 用户昵称
@property (nonatomic, copy) NSString * nickname;

/// 场次ID
@property (nonatomic, copy) NSString * sessionId;

/// 课节ID
@property (nonatomic, copy) NSString * _Nullable lessonId;

/// 课程码
@property (nonatomic, copy) NSString * _Nullable courseCode;

/// 分组ID
@property (nonatomic, copy) NSString * _Nullable groupId;

@end

NS_ASSUME_NONNULL_END
