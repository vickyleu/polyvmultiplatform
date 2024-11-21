//
//  PLVChannelInfoModel.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2020/12/17.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PLVLiveDefine.h"

NS_ASSUME_NONNULL_BEGIN

/// 频道信息数据模型
@interface PLVChannelInfoModel : NSObject

#pragma mark - [ 属性 ]
#pragma mark 基础信息
/// PLV账户 用户Id
@property (nonatomic, copy, readonly) NSString * accountUserId;
/// 频道ID
@property (nonatomic, copy, readonly) NSString * channelId;
/// 直播场次ID（仅当讲师‘正在推流时’，可拿到最新的场次ID）
@property (nonatomic, copy, readonly) NSString * sessionId;
/// 直播频道名称
@property (nonatomic, copy, readonly) NSString * channelName;
/// 是否只支持音频观看
@property (nonatomic, assign, readonly) BOOL isOnlyAudio;

#pragma mark 限制信息
/// 频道限制状态
@property (nonatomic, assign, readonly) PLVChannelRestrictState restrictState;

#pragma mark 多线路信息
/// 可选线路数量
@property (nonatomic, assign, readonly) NSInteger lineNum;
/// 当前线路下标 (由 0 起始)
@property (nonatomic, assign, readonly) NSInteger currentLineIndex;

#pragma mark 多码率信息
/// 多码率是否开启
@property (nonatomic, assign, readonly) BOOL multirateEnabled;
/// 码率/清晰度 可选项字符串数组
@property (nonatomic, strong, readonly) NSArray <NSString *> * definitionNamesOptions;
/// 当前码率/清晰度 (仅 多码率开启时 有值)
@property (nonatomic, copy, readonly) NSString * currentDefinition;

#pragma mark 暖场信息
/// 暖场类型
@property (nonatomic, assign, readonly) PLVChannelWarmUpType warmUpType;
/// 暖场内容地址
@property (nonatomic, copy, readonly) NSString * warmUpContentUrlString;
/// 图片类型暖场的跳转链接 (若无需跳转，则此值为空)
@property (nonatomic, copy, readonly) NSString * warmUpImageHREF;

#pragma mark 跑马灯信息
/// 跑马灯类型
@property (nonatomic, assign, readonly) PLVChannelMarqueeType marqueeType;
/// TypeDefault：跑马灯内容；TypeURL：自定义地址
@property (nonatomic, copy) NSString * marquee;
/// 跑马灯字体大小
@property (nonatomic, copy, readonly) NSNumber * marqueeFontSize;
/// 跑马灯字体颜色
@property (nonatomic, copy, readonly) NSString * marqueeFontColor;
/// 跑马灯透明度
@property (nonatomic, copy, readonly) NSString * marqueeOpacity;
/// 跑马灯自定义缩放
@property (nonatomic, assign, readonly) BOOL marqueeAutoZoomEnabled;
/// 跑马灯动画类型
@property (nonatomic, assign, readonly) NSInteger marqueeSetting;
/// 跑马灯文字移动指定像素所需时间/显示时间（单位：秒）
@property (nonatomic, assign, readonly) NSInteger marqueeSpeed;

#pragma mark 防录屏水印
/// 类型
@property (nonatomic, assign, readonly) PLVChannelWatermarkType watermarkType;
/// 文字大小
@property (nonatomic, assign, readonly) PLVChannelWatermarkFontSize watermarkFontSize;
/// 是否开启水印功能
@property (nonatomic, assign, readonly) BOOL watermarkRestrict;
/// 文字内容
@property (nonatomic, copy, readonly) NSString *watermarkContent;
/// 透明度
@property (nonatomic, assign, readonly) NSInteger watermarkOpacity;

#pragma mark 播放器LOGO
/// 图片链接
@property (nonatomic, copy, readonly) NSString *logoImageUrl;
/// 跳转链接
@property (nonatomic, copy, readonly) NSString *logoHref;
/// 透明度
@property (nonatomic, assign, readonly) CGFloat logoOpacity;
/// 位置
@property (nonatomic, assign, readonly) NSUInteger logoPosition;

#pragma mark 片头广告
/// 广告类型
@property (nonatomic, assign, readonly) PLVChannelAdvertType advertType;
/// 广告图片展示链接
@property (nonatomic, copy, readonly) NSString *advertImageUrl;
/// 广告视频展示链接
@property (nonatomic, copy, readonly) NSString *advertFlvUrl;
/// 跳转链接
@property (nonatomic, copy, readonly) NSString *advertHref;
/// 广告时长
@property (nonatomic, assign, readonly) NSUInteger advertDuration;

#pragma mark 暂停广告
/// 暂停广告图片展示链接
@property (nonatomic, copy, readonly) NSString *stopAdvertImageUrl;
/// 暂停广告图片跳转链接
@property (nonatomic, copy, readonly) NSString *stopAdvertHref;

#pragma mark 弹幕信息
/// 弹幕模块是否启用
@property (nonatomic, assign, readonly) BOOL closeDanmuEnable;
/// 弹幕文字移动指定像素所需时间（单位：秒）
@property (nonatomic, assign, readonly) NSInteger barrageSpeed;

#pragma mark 流信息
/// 流ID
@property (nonatomic, copy, readonly) NSString * streamID;
/// 流类型（‘disk’表示硬盘推流）
@property (nonatomic, copy, readonly) NSString * streamType;

#pragma mark Qos
/// Qos 发送频率
@property (nonatomic, copy, readonly) NSNumber * reportFreq;
/// 卡顿统计阈值，单位秒
@property (nonatomic, assign, readonly) NSInteger stallingSendFrequency;

#pragma mark - [ 方法 ]
/// 根据数据字典，创建频道信息模型
///
/// @param dataDict 数据字典
+ (instancetype)channelInfoModelWithDataDict:(NSDictionary *)dataDict;

/// 更新频道限制信息 (异步)
///
/// @param completion 请求完成Block
- (void)updateChannelRestrictInfo:(void (^)(PLVChannelRestrictState restrictState))completion;

@end

NS_ASSUME_NONNULL_END
