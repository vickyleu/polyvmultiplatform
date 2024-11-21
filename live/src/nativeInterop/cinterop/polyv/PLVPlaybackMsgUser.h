//
//  PLVPlaybackMsgUser.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2022/6/6.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVPlaybackMsgUser : NSObject
/// 用户头衔
@property (nonatomic, copy) NSString *actor;
/// 用户角色字符串
@property (nonatomic, copy) NSString *role;
/// 用户Id
@property (nonatomic, copy) NSString *userId;
/// 用户昵称
@property (nonatomic, copy) NSString *userName;
/// 用户头像地址
@property (nonatomic, copy) NSString *avatarUrl;

/// 解析后台接口返回数据
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
