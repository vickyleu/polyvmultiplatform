//
//  PLVNetworkAccessibility.h
//  PLVLiveScenesDemo
//
//  Created by lijingtong on 2021/6/21.
//  Copyright © 2021 PLV. All rights reserved.
// 网络权限工具
// 可用于检测系统为iOS10+的国行iPhone是否开启网络权限

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const PLVNetworkAccessibilityChangedNotification;

typedef NS_ENUM(NSUInteger, PLVNetworkAccessibleState) {
    PLVNetworkAccessibleStateChecking,
    PLVNetworkAccessibleStateUnknown,
    /// 网络已授权
    PLVNetworkAccessibleStateAccessible,
    /// 网络未授权
    PLVNetworkAccessibleStateRestricted,
};

typedef void (^NetworkAccessibleStateNotifier)(PLVNetworkAccessibleState state);

@interface PLVNetworkAccessibility : NSObject

/// 开启 PLVNetworkAccessibility
/// @note 仅支持iOS10.0+
+ (void)start;

/// 停止 PLVNetworkAccessibility
/// @note 仅支持iOS10.0+
+ (void)stop;

/// 当判断网络状态为 ZYNetworkRestricted 时，提示用户开启网络权限
/// @note 仅支持iOS10.0+
+ (void)setAlertEnable:(BOOL)setAlertEnable;

/// 通过 block 方式监控网络权限变化。
/// @note 仅支持iOS10.0+
/// @param block block
+ (void)setStateDidUpdateNotifier:(void (^)(PLVNetworkAccessibleState))block;

/// 返回的是最近一次的网络状态检查结果，若距离上一次检测结果短时间内网络授权状态发生变化，该值可能会不准确。
/// @note 仅支持iOS10.0+
+ (PLVNetworkAccessibleState)currentState;

@end

NS_ASSUME_NONNULL_END
