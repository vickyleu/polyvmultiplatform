//
//  PLVInteractWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2021/12/14.
//  Copyright © 2021 PLV. All rights reserved.

#import <Foundation/Foundation.h>
#import "PLVSocketWebViewBridge.h"

NS_ASSUME_NONNULL_BEGIN

@class PLVInteractWebViewBridge;

/// 互动模块 WebSDK Bridge 的回调 （不能保证在主线程回调）
@protocol PLVInteractWebViewBridgeDelegate <NSObject>

/// 需要显示WebView的回调
/// @param webViewBridge WebSDK与JS桥接
- (void)plvInteractWebViewBridgeShowWebView:(PLVInteractWebViewBridge *)webViewBridge;

/// WebView的JS加载完毕的回调
/// @param webViewBridge WebSDK与JS桥接
- (void)plvInteractWebViewBridgeWebViewDidFinish:(PLVInteractWebViewBridge *)webViewBridge;

/// 需要关闭WebView的回调
/// @param webViewBridge WebSDK与JS桥接
- (void)plvInteractWebViewBridgeCloseWebView:(PLVInteractWebViewBridge *)webViewBridge;

/// 需要屏幕竖屏锁定的回调
/// @param webViewBridge WebSDK与JS桥接
- (void)plvInteractWebViewBridgeLockPortraitScreen:(PLVInteractWebViewBridge *)webViewBridge;

/// 需要打开外链的回调
/// @param webViewBridge WebSDK与JS桥接
/// @param linkString 链接地址
- (void)plvInteractWebViewBridge:(PLVInteractWebViewBridge *)webViewBridge openLink:(NSString *)linkString;

/// 获取更新APP状态的回调
/// @param webViewBridge WebSDK与JS桥接
/// @param jsonObject app状态更新数据
- (void)plvInteractWebViewBridge:(PLVInteractWebViewBridge *)webViewBridge updateAppStatuWithJSONObject:(id)jsonObject;

/// 前端需要调用App事件的回调
/// @param webViewBridge WebSDK与JS桥接
/// @param jsonObject 事件的参数信息
- (void)plvInteractWebViewBridge:(PLVInteractWebViewBridge *)webViewBridge callAppEvent:(id)jsonObject;

/// 获取APP信息的回调
/// @param webViewBridge WebSDK与JS桥接
- (NSDictionary *)getAPPInfoInInteractWebViewBridge:(PLVInteractWebViewBridge *)webViewBridge;

/// 获取互动信息的回调
/// @param webViewBridge WebSDK与JS桥接
- (NSDictionary *)getInteractInfoInInteractWebViewBridge:(PLVInteractWebViewBridge *)webViewBridge;

/// 大卡片 点击商品 的回调
/// @param webViewBridge WebSDK与JS桥接
/// @param jsonObject 商品详情信息
- (void)plvInteractWebViewBridge:(PLVInteractWebViewBridge *)webViewBridge bigCardClickProductButtonWithJSONObject:(id)jsonObject;

@end

/// 互动模块 WebSDK 与 JS 的桥接，用于互动 WebSDK webView与JS交互
@interface PLVInteractWebViewBridge : PLVSocketWebViewBridge

/// PLVInteractWebViewBridgeDelegate 代理
@property (nonatomic, weak) id<PLVInteractWebViewBridgeDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
