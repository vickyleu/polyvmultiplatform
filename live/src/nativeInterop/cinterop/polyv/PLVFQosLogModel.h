//
//  PLVFQosLogModel.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/24.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <PLVFoundationSDK/PLVFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

/*
 QosLog 数据模型
 */
@interface PLVFQosLogModel : PLVFLogModel

/// 点播独有属性
/// 视频ID，点播独有属性
@property (nonatomic, copy) NSString *vid;
/// 使用的CDN域名，点播独有属性
@property (nonatomic, copy) NSString *domain;
/// 当前页面地址，点播独有属性
@property (nonatomic, copy) NSString *href;

/// 直播独有属性
/// 频道ID，直播独有属性
@property (nonatomic, copy) NSString *cid;
///客户端标识和版本，格式为“ios-{$版本号}”，直播独有属性
@property (nonatomic, copy) NSString *client;

/// 用户ID，即视频是属于那个用户的
@property (nonatomic, copy) NSString *uid;

/// 播放器为每次播放产生的唯一ID
@property (nonatomic, copy) NSString *pid;

/// 缓冲或加载视频所需的时间，单位为毫秒
@property (nonatomic, copy) NSString *time;

/// 播放流程请参与耗时统计的业务所需的总时间，单位为毫秒
@property (nonatomic, copy) NSString *time_business;

/// 播放器起播所需的时间，单位为毫秒
@property (nonatomic, copy) NSString *time_player;

/// 此HTTP请求类型标识，type=loading、buffer、error、adplay、aderror、end、forbidden（end、forbidden为点播专有）
@property (nonatomic, copy) NSString *type;

/// 播放场次标识
@property (nonatomic, copy) NSString *session_id;

/// 自定义参数1，需要自行 UrlSafeBase64编码或SM2加密
@property (nonatomic, copy) NSString *param1;

/// 自定义参数2，需要自行 UrlSafeBase64编码或SM2加密
@property (nonatomic, copy) NSString *param2;

/// 自定义参数3，需要URLEncode
@property (nonatomic, copy) NSString *param3;

/// 自定义参数4，需要自行 UrlSafeBase64编码或SM2加密
@property (nonatomic, copy) NSString *param4;

/// 自定义参数5，需要自行 UrlSafeBase64编码或SM2加密
@property (nonatomic, copy) NSString *param5;

/// 直播 type = error、aderror  时独有属性
/// 自定义参数1，需要URLEncode
@property (nonatomic, copy) NSString *uri;
/// 服务器响应的状态码，需要URLEncode
@property (nonatomic, copy) NSString *status;
/// 错误代码，需要URLEncode
@property (nonatomic, copy) NSString *errorcode;
/// 错误内容描述，需要URLEncode
@property (nonatomic, copy) NSString *errormsg;

/// 直播 type = adplay 时独有属性
/// 广告的url，，需要URLEncode
@property (nonatomic, copy) NSString *url;
/// 加载广告资源需要耗费的时间，单位：毫秒
@property (nonatomic, strong) NSNumber *load_time;
/// 广告的观看时长，单位：秒
@property (nonatomic, strong) NSNumber *play_time;

/// 点播 type =  error、forbidden 时独有属性
/// 请求资源的URI，需要URLEncode
@property (nonatomic, copy) NSString *request_uri;
/// 服务器响应的状态码
@property (nonatomic, copy) NSString *response_code;



@end

NS_ASSUME_NONNULL_END
