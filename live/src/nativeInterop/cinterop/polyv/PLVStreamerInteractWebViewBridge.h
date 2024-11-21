//
//  PLVStreamerInteractWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2024/5/15.
//  Copyright © 2024 PLV. All rights reserved.
//

#import <PLVLiveScenesSDK/PLVLiveScenesSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class PLVStreamerInteractWebViewBridge;

/// 开播端互动模块 WebSDK Bridge 的回调 （不能保证在主线程回调）
@protocol PLVStreamerInteractWebViewBridgeDelegate <NSObject>

/// 获取APP信息的回调
/// @param webViewBridge WebSDK与JS桥接
- (NSDictionary *)getAPPInfoInStreamerInteractBridge:(PLVStreamerInteractWebViewBridge *)webViewBridge;

/// 需要显示WebView的回调
/// @param webViewBridge WebSDK与JS桥接
- (void)plvStreamerInteractBridgeShowWebView:(PLVStreamerInteractWebViewBridge *)webViewBridge;

/// 需要关闭WebView的回调
/// @param webViewBridge WebSDK与JS桥接
- (void)plvStreamerInteractBridgeCloseWebView:(PLVStreamerInteractWebViewBridge *)webViewBridge;

/// 前端需要调用App事件的回调
/// @param webViewBridge WebSDK与JS桥接
/// @param jsonObject 事件的参数信息
- (void)plvStreamerInteractBridge:(PLVStreamerInteractWebViewBridge *)webViewBridge callAppEvent:(id)jsonObject;

@end

@interface PLVStreamerInteractWebViewBridge : PLVSocketWebViewBridge

/// PLVStreamerInteractWebViewBridgeDelegate 代理
@property (nonatomic, weak) id<PLVStreamerInteractWebViewBridgeDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
