//
//  PLVLiveVideoConfig.h
//  PLVLiveScenesSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "../../../../../fakePod/Pods/PLVFoundationSDK/Frameworks/MiniFramework/PLVFoundationSDK.framework/Headers/PLVFoundationSDK.h"

@class PLVClientPushStreamTemplateAudioParams;
@class PLVClientPushStreamTemplateVideoParams;

/**
 直播 SDK 配置文件
 */
@interface PLVLiveVideoConfig : NSObject<PLVConfig>

/// 是否已配置有效userId、appId、appSecret，默认为NO，有效指非空字符串
@property (nonatomic, assign, readonly) BOOL configAccount;
/// 可配置chatApi私有域名
@property (nonatomic, strong, readonly) NSString *chatApiDomain;
/// 推流参数
@property (nonatomic, copy, readonly) NSDictionary *clientParams;
/// 推流模板开关
@property (nonatomic, assign, readonly) BOOL clientPushStreamTemplateEnabled;
/// 推流音频模版
@property (nonatomic, copy, readonly) PLVClientPushStreamTemplateAudioParams *audioParams;
/// 推流视频模版
@property (nonatomic, copy, readonly) NSArray<PLVClientPushStreamTemplateVideoParams *> *videoParams;
/// 推流视频模版讲师默认清晰度
@property (nonatomic, strong, readonly) NSString *teacherDefaultQualityLevel;
/// 推流视频模版嘉宾默认清晰度
@property (nonatomic, strong, readonly) NSString *guestDefaultQualityLevel;

/// 直播 观众连麦时设置第一画面时推流视频清晰度 N、360p、720p、1080p
@property (nonatomic, copy, readonly) NSString *audienceFirstScreenQualityLevel;

/// 弹出相册或相机时不能横竖屏切换
@property (nonatomic, assign) BOOL unableRotate;
/// 互动页面此时是否不能横竖屏切换
@property (nonatomic, assign) BOOL triviaCardUnableRotate;
/// 是否启用 HttpDNS，默认开启
@property (nonatomic, assign) BOOL enableHttpDNS;
/// 是否启用 IPV6，如果启用，将自动选择IP，取消HttpDNS
@property (nonatomic, assign) BOOL enableIPV6;
/// 接口签名是否启用 sha256 加密，默认 NO
@property (nonatomic, assign) BOOL enableSha256;
/// 接口是否启用防重放，默认 NO
@property (nonatomic, assign) BOOL enableSignatureNonce;
/// 接口是否启用响应加密，默认 NO
@property (nonatomic, assign) BOOL enableResponseEncrypt;
/// 接口是否启用请求加密，默认 NO
@property (nonatomic, assign) BOOL enableRequestEncrypt;
/// 接口是否启用安全接口，默认 NO
@property (nonatomic, assign) BOOL enableSecureApi;
/// 接口是否启用资源鉴权，默认 NO
@property (nonatomic, assign) BOOL enableResourceAuth;

/// 是否禁用日志本地记录功能，默认 NO
@property (nonatomic, assign) BOOL localLogDisable;

/// 是否禁用日志上报功能，默认 NO
/// @note 应在configWithUserId之前调用，否则仍会检查是否上报
@property (nonatomic, assign) BOOL localLogUploadDisable;

+ (instancetype)sharedInstance;

/// 配置账号信息
/// PLV 后台，云直播->开发设置->身份认证：userId、AppID、AppSecret参数
/// @param userId 用户ID
/// @param appId 应用ID
/// @param appSecret 应用密钥
- (BOOL)configWithUserId:(NSString *)userId appId:(NSString *)appId appSecret:(NSString *)appSecret;

/**
 私有域名配置
 */
+ (void)setPrivateDomainWithData:(NSDictionary *)data;


@end

@interface  PLVClientPushStreamTemplateAudioParams: NSObject

/// 音频采样率
@property (nonatomic, assign, readonly) NSInteger audioSamplerate;
/// 音频声道
@property (nonatomic, assign, readonly) NSInteger audioChannels;
/// 音频码率
@property (nonatomic, assign, readonly) NSInteger audioBitrate;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface  PLVClientPushStreamTemplateVideoParams: NSObject

/// 推流质量等级，唯一标识
@property (nonatomic, copy, readonly) NSString * qualityLevel;
/// 推流质量名称
@property (nonatomic, copy, readonly) NSString * qualityName;
/// 推流质量名称（英文名字段）
@property (nonatomic, copy, readonly) NSString * qualityEnName;
/// 视频分辨率
@property (nonatomic, assign, readonly) CGSize videoResolution;
/// 视频码率
@property (nonatomic, assign, readonly) NSInteger videoBitrate;
/// 视频采集帧率
@property (nonatomic, assign, readonly) NSInteger videoFrameRate;
/// 视频关键帧帧率
@property (nonatomic, assign, readonly) NSInteger videoGop;
/// 屏幕共享分辨率
@property (nonatomic, assign, readonly) CGSize screenResolution;
/// 屏幕共享码率
@property (nonatomic, assign, readonly) NSInteger screenBitrate;
/// 屏幕共享采集帧率
@property (nonatomic, assign, readonly) NSInteger screenFrameRate;
/// 屏幕共享关键帧帧率
@property (nonatomic, assign, readonly) NSInteger screenGop;
/// 是否支持此配置参数
@property (nonatomic, assign, readonly) BOOL isSupportVideoParams;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
