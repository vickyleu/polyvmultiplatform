//
//  PLVRedpackMessage.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2023/1/5.
//  Copyright © 2023 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PLVRedpackMessageType) {
    PLVRedpackMessageTypeUnknown = 0,       // 未知红包类型
    PLVRedpackMessageTypeAliPassword // 支付宝口令红包
};

// 红包状态
typedef NS_ENUM(NSInteger, PLVRedpackState) {
    PLVRedpackStateUnknow = 0,
    PLVRedpackStateExpired, // 已过期
    PLVRedpackStateNoneRedpack, // 已派完
    PLVRedpackStateReceive, // 已领取
    PLVRedpackStateSuccess  // 可领取
};

@interface PLVRedpackMessage : NSObject
// 消息ID
@property (nonatomic, copy) NSString * _Nullable msgId;
// 红包ID
@property (nonatomic, copy) NSString * _Nullable redpackId;
// 红包存量ID
@property (nonatomic, copy) NSString * _Nullable redCacheId;
// 红包祝福语
@property (nonatomic, copy) NSString *content;
// 红包消息时间戳
@property (nonatomic, assign) NSTimeInterval time;
// 红包类型
@property (nonatomic, assign) PLVRedpackMessageType type;
// 红包状态
@property (nonatomic, assign) PLVRedpackState state;
// 红包数量
@property (nonatomic, assign) NSInteger number;
// 红包总金额
@property (nonatomic, assign) float totalAmount;
// 红包类型type字符串
@property (nonatomic, copy, readonly) NSString *typeString;

@end

NS_ASSUME_NONNULL_END
