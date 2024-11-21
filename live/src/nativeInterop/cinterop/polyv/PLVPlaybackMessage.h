//
//  PLVPlaybackMessage.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2022/6/6.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVPlaybackMsgUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLVPlaybackMessage : NSObject
// 视频时间戳，单位毫秒
@property (nonatomic, assign) NSTimeInterval playbackTime;
// 发送消息用户
@property (nonatomic, strong) PLVPlaybackMsgUser *user;
// 可能是PLVSpeakMessage、PLVQuoteMessage、PLVImageMessage、PLVImageEmotionMessage、PLVSpeakTopMessage
@property (nonatomic, strong) id message;

/// 解析后台接口返回数据
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/// message属性是否是PLVSpeakMessage、PLVQuoteMessage、PLVImageMessage、PLVImageEmotionMessage、PLVSpeakTopMessage五种消息类型之一
+ (BOOL)playbackMessageValid:(PLVPlaybackMessage *)playbackMessage;

@end

NS_ASSUME_NONNULL_END
