//
//  PLVFTrackLogReporter.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2023/5/16.
//  Copyright © 2023 PLV. All rights reserved.
//

#import <PLVFoundationSDK/PLVFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class PLVFTrackLogModel, PLVETrackDataParamModel;

@interface PLVFTrackLogReporter : PLVFLogReporter

/// productType 为 PLVProductTypeLive 时的登录接口
- (void)registerWithChannelId:(NSString *)channelId userId:(NSString *)userId;

/// 登出接口
- (void)unregister;

/// 配置viewerId、viewerName、用户角色
- (void)setupViewerId:(NSString *)viewerId viewerName:(NSString *)viewerName role:(NSString *)role;

/// 配置场次ID
- (void)setupSessionId:(NSString *)sessionId;

/// 生成模版数据模型，模型中已包含通用的基础信息
- (PLVFTrackLogModel *)generateTemplateModel;

- (PLVETrackDataParamModel *)generateDataParamModel;

@end

NS_ASSUME_NONNULL_END
