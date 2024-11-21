//
//  PLVSocketWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2021/12/22.
//  Copyright © 2021 PLV. All rights reserved.

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import <PLVFoundationSDK/PLVFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

/// 负责处理 socket 事件的 bridge
@interface PLVSocketWebViewBridge : NSObject

@property (nonatomic, strong, readonly) WKWebView *webView;
@property (nonatomic, strong, readonly) PLVFWKWebViewJavascriptBridge *bridge;

/// 初始化方法
/// @param webView webview对象
/// @param webViewDelegate webview代理
- (instancetype)initBridgeWithWebView:(WKWebView *)webView webViewDelegate:(id<WKNavigationDelegate>)webViewDelegate;

- (void)setWebViewDelegate:(id<WKNavigationDelegate> __nullable)webViewDelegate;

#pragma mark - Call JS Method

/// 主动调用JS更新用户信息
/// @param appInfo  用户信息数据结构同 [getAPPInfoInWebViewBridge]
- (void)updateNativeAppParamsInfo:(NSDictionary *)appInfo;

/// 主动调用JS更新频道开关配置设置
/// @param configInfo  频道开关配置信息
- (void)updateChannelConfigInfo:(NSDictionary *)configInfo;

/// 主动调用JS的方法
/// @param event APP主动调用JS的事件，格式 如 {@"event" : @"SHOW_BULLETIN"} //打开公告
- (void)callWebViewEvent:(NSDictionary *)event;

#pragma mark Utils

// 将字典转化为 JSON 字符串
- (NSString *)jsonStringFromDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
