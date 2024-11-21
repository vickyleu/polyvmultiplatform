//
//  PLVBRTCStatistics.h
//  PLVBusinessSDK
//
//  Created by MissYasiky on 2023/4/25.
//  Copyright © 2023 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 网络和性能的汇总统计指标
 */
@interface PLVBRTCStatistics : NSObject

/// 上行丢包率，单位 (%)
@property(nonatomic, assign) NSInteger upLoss;

/// 下行丢包率，单位 (%)
@property(nonatomic, assign) NSInteger downLoss;

///从终端到服务器的往返延时，单位 ms
/// 如果 rtt < 50ms，意味着较低的音视频通话延迟；如果 rtt > 200ms，则意味着较高的音视频通话延迟
@property(nonatomic, assign) NSInteger rtt;

@end

NS_ASSUME_NONNULL_END
