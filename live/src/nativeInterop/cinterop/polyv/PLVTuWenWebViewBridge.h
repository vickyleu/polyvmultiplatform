//
//  PLVTuWenWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2023/6/5.
//  Copyright © 2023 PLV. All rights reserved.
//

#import <PLVLiveScenesSDK/PLVLiveScenesSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class PLVTuWenWebViewBridge;

/// 图文直播模块 WebSDK Bridge 的回调 （不能保证在主线程回调）
@protocol PLVTuWenWebViewBridgeDelegate <NSObject>

/// 获取APP信息的回调
/// @param webViewBridge WebSDK与JS桥接
- (NSDictionary *)getAPPInfoInTuWenWebViewBridge:(PLVTuWenWebViewBridge *)webViewBridge;

/// 前端需要调用App事件的回调
/// @param webViewBridge WebSDK与JS桥接
/// @param jsonObject 事件的参数信息
- (void)plvTuWenWebViewBridge:(PLVTuWenWebViewBridge *)webViewBridge callAppEvent:(id)jsonObject;

@end

@interface PLVTuWenWebViewBridge : PLVSocketWebViewBridge

@property (nonatomic, weak) id<PLVTuWenWebViewBridgeDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
