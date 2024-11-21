//
//  PLVBRTCVideoViewCanvasModel.h
//  PLVBusinessSDK
//
//  Created by Lincal on 2021/4/13.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PLVBRTCDefine.h"

NS_ASSUME_NONNULL_BEGIN

/// RTC视频画面的画布模型
///
/// 描述了渲染某路RTC流，所对应的用户RTCId、承载视图、填充模式等
@interface PLVBRTCVideoViewCanvasModel : NSObject

#pragma mark 可配置项
/// 用户RTCId
@property (nonatomic, copy) NSString * userRTCId;

/// 渲染画布视图
///
/// @note 用于承载 RTC视频画面；强引用；
///       仅在订阅 ”视频流 PLVBRTCSubscribeStreamMediaType_Video“ 时，设置此值有效；
@property (nonatomic, strong) UIView * renderCanvasView;

/// RTC视频画面 填充模式
///
/// @note 仅在订阅 ”视频流 PLVBRTCSubscribeStreamMediaType_Video“ 时，设置此值有效；
@property (nonatomic, assign) PLVBRTCVideoViewFillMode rtcVideoVideoFillMode;

/// 检查此 画布模型 是否合法
///
/// @reture YES:合法可用；NO:不合法不可用
- (BOOL)checkModelValid;

@end

NS_ASSUME_NONNULL_END
