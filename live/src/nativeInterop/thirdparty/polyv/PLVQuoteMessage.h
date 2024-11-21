//
//  PLVQuoteMessage.h
//  PLVLiveScenesDemo
//
//  Created by MissYasiky on 2020/11/25.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVQuoteMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, copy) NSString *content;

@property (nonatomic, copy) NSString *quoteMsgId;

@property (nonatomic, copy) NSString *quoteUserId;

@property (nonatomic, copy) NSString *quoteUserName;

@property (nonatomic, copy) NSString * _Nullable quoteContent;

@property (nonatomic, copy) NSString * _Nullable quoteImageUrl;

@property (nonatomic, assign) CGSize quoteImageSize;

@property (nonatomic, assign)NSTimeInterval time;

@property (nonatomic, assign) NSTimeInterval playbackTime;
/// 消息是否超过约定长度
@property (nonatomic, assign) BOOL overLen;
/// 是否触发严禁词，且content中的严禁词已被**替换，默认为NO
@property (nonatomic, assign) BOOL prohibitWordReplaced;

@end

NS_ASSUME_NONNULL_END
