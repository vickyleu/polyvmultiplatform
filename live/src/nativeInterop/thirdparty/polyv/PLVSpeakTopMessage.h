//
//  PLVSpeakTopMessage.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2024/7/2.
//  Copyright © 2024 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVSpeakTopMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

/// 上墙内容
@property (nonatomic, copy) NSString *content;

@property (nonatomic, assign) NSTimeInterval time;

@property (nonatomic, assign) NSTimeInterval relativeTime;

/// 上墙用户昵称
@property (nonatomic, copy) NSString *nick;

/// 上墙用户头像
@property (nonatomic, copy) NSString *pic;

/// 操作上墙的头衔
@property (nonatomic, copy) NSString *topActor;

/// top 上墙 cancelTop下墙
@property (nonatomic, copy) NSString *action;

/// 解析数据
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
