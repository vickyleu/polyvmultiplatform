//
//  PLVSpeakMessage.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/11/24.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVSpeakMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, copy) NSString *content;

@property (nonatomic, assign) NSTimeInterval time;

@property (nonatomic, assign) NSTimeInterval playbackTime;
/// 如果值为"extend"表示为：提醒消息
@property (nonatomic, copy) NSString * _Nullable source;
/// 消息是否超过约定长度
@property (nonatomic, assign) BOOL overLen;
/// 是否触发严禁词，且content中的严禁词已被**替换，默认为NO
@property (nonatomic, assign) BOOL prohibitWordReplaced;

@end

NS_ASSUME_NONNULL_END
