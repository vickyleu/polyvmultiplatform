//
//  PLVFELogReporter.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/5.
//  Copyright © 2019 PLV. All rights reserved.
//

#import "PLVFoundationSDK.h"
#import "PLVFLogReporter.h"

@class PLVFELogModel;

NS_ASSUME_NONNULL_BEGIN

/*
 Elog日志上报器，唯一需要获取用户账号信息的日志上报器，支持批量日志上报
 */
@interface PLVFELogReporter : PLVFLogReporter

/// productType 为 PLVProductTypeVod 的登录接口
- (void)registerWithUserId:(NSString *)userId secretkey:(NSString *)secretkey DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用registerWithUserId:");

/// productType 为 PLVProductTypeVod 的登录接口 (v2)
- (void)registerWithUserId:(NSString *)userId;

/// productType 为 PLVProductTypeLive 观看直播时的登录接口
- (void)registerWithChannelId:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret userId:(NSString *)userId DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用registerWithChannelId:userId:");

/// productType 为 PLVProductTypeLive 观看直播时的登录接口（v2）
- (void)registerWithChannelId:(NSString *)channelId userId:(NSString *)userId;

/// productType 为 PLVProductTypeLive 观看回放时的登录接口
- (void)registerWithChannelId:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret userId:(NSString *)userId vId:(NSString *)vid DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用registerWithChannelId:userId:vId:");

/// productType 为 PLVProductTypeLive 观看回放时的登录接口（v2）
- (void)registerWithChannelId:(NSString *)channelId userId:(NSString *)userId vId:(NSString *)vid;

/// productType 为 PLVProductTypeStreamer、PLVProductTypeHiClass 时的登录接口
- (void)registerWithChannelId:(NSString *)channelId;

/// 登出接口
- (void)unregister;

/// 生成模版数据模型，模型中已包含通用的基础信息
- (PLVFELogModel *)generateTemplateModel;

@end

NS_ASSUME_NONNULL_END
