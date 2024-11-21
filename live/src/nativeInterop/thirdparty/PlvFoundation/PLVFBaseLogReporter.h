//
//  PLVFBaseLogReporter.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/11/27.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PLVFLogModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PLVFLogProductType) {
    PLVProductTypeVod = 0,  /// 点播
    PLVProductTypeLive,     /// 云课堂观看
    PLVProductTypeStreamer, /// 手机开播
    PLVProductTypeHiClass   /// 互动学堂
};

/*
 日志上报的基类，基类内部只负责日志的http请求，其他逻辑由子类完成
 子类可调用父类的 '-sendRequest:successHandler:failureHandler:' 方法进行网络请求，该方法不可被覆写
 */
@interface PLVFBaseLogReporter : NSObject

/// 请求加密
///（目前仅PLVFELogReporter、PLVFTrackLogReporter、PLVFViewLogReporter、PLVFQosLogReporter支持）
@property (nonatomic, assign) BOOL requestXbody;

/// sha256签名（目前仅PLVFTrackLogReporter支持）
@property (nonatomic, assign) BOOL enableSha256;

/// 防重放（目前仅PLVFTrackLogReporter支持）
@property (nonatomic, assign) BOOL enableSignatureNonce;

// 子类化后，Elog、Qos、ViewLog 均会用到的产品类型枚举值
@property (nonatomic, assign) PLVFLogProductType productType;

@end

NS_ASSUME_NONNULL_END
