//
//  PLVFTrackLogModel.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2023/5/16.
//  Copyright © 2023 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFLogModel.h"

NS_ASSUME_NONNULL_BEGIN

@class PLVETrackDataParamModel;

/*
 track 日志数据模型
 */
@interface PLVFTrackLogModel : PLVFLogModel

/// 固定N/A
@property (nonatomic, copy) NSString *project_id;

/// 产品线名称：研讨会-seminar 、高互动-hi-class、云直播-live、点播-vod
@property (nonatomic, copy) NSString *project_name;

/// 固定N/A
@property (nonatomic, copy) NSString *app_id;

/// 应用名称
@property (nonatomic, copy) NSString *app_name;

/// 应用版本号
@property (nonatomic, copy) NSString *app_version;

/// SDK 类型：h5、ios、android
@property (nonatomic, copy) NSString *sdk_type;

/// SDK 版本号
@property (nonatomic, copy) NSString *sdk_version;

/// @note 不可为空，固定 N/A
@property (nonatomic, copy) NSString *session_uuid;

/// 设备 UUID
@property (nonatomic, copy) NSString *device_uuid;

/// 设备类型-标识：phone、pad、tv
@property (nonatomic, copy) NSString *device_class;

/// 设备品牌，默认 Apple
@property (nonatomic, copy) NSString *device_brand;

/// 设备机型
@property (nonatomic, copy) NSString *device_model;

/// 操作系统
@property (nonatomic, copy) NSString *os;

/// 操作系统版本
@property (nonatomic, copy) NSString *os_version;

/// @note 不可为空，从http请求头获取
@property (nonatomic, copy) NSString *ua;

/// 终端时间
/// @note 不可为空，单位秒
@property (nonatomic, copy) NSString *local_ts;

/// 用户昵称
@property (nonatomic, copy) NSString *nickname;

/// 用户 ID
@property (nonatomic, copy) NSString *logon_id;

/// 用户登录类型
/// @note 不可为空，固定 N/A
@property (nonatomic, copy) NSString *logon_type;

/// @note 不可为空，代码级日志-debug、端到端日志-perf、行为日志-event
@property (nonatomic, copy) NSString *data_type;

/// @note 不参与上报
@property (nonatomic, strong) PLVETrackDataParamModel * _Nullable data_paramElement;

/// @note 不可为空
@property (nonatomic, strong) NSArray <PLVETrackDataParamModel *> *data_param;

@end

/*
 PLVFTrackLogModel 模型 dataParam 属性数据模型
 */
@interface PLVETrackDataParamModel : NSObject

/// 事件分类：系统事件-system、行为事件-behavior、虚拟事件-virtual
@property (nonatomic, copy) NSString *event_cata;

/// 譬如：click、show……
@property (nonatomic, copy) NSString *event_type;

/// @note 用于区别每一次日志上报
@property (nonatomic, copy) NSString * event_uuid;

/// @note 不用于区别不同事件
@property (nonatomic, copy) NSString *event_id;

/// 事件发生时间
@property (nonatomic, assign) NSTimeInterval occur_time;

/// 业务公共属性
@property (nonatomic, strong) NSDictionary *comm_attrs;

/// 事件专有属性
@property (nonatomic, strong) NSDictionary *spec_attrs;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
