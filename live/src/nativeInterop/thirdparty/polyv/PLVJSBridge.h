//
//  PLVJSBridge.h
//  PLVFoundationSDK
//
//  Created by Lincal on 2020/9/9.
//  Copyright © 2020年 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <WebKit/WebKit.h>

@protocol PLVJSBridgeDelegate;

// Webview Js交互器 (WKWebview 封装类；可用于与 webview 进行数据交互)
@interface PLVJSBridge : NSObject

#pragma mark - 只读属性
/// webview
///
/// @note 直接 addSubview 无法正常添加该 webview，请通过 [loadWebView:]、[loadHTMLString:] 或 [loadFileURL:] 方法进行调用及添加；
///       调用后，可直接对该对象webView，进行布局设置；
@property (nonatomic, strong, readonly) WKWebView * webView;

/// webview 是否已加载完成
@property (nonatomic, assign, readonly) BOOL webviewLoadFinish;

/// webview 是否加载失败
@property (nonatomic, assign, readonly) BOOL webviewLoadFaid;

/// 当前已监听的Js方法回调列表
///
/// @note 可通过 [addObserveJsFunctions:] 添加需要监听的Js方法回调
@property (nonatomic, strong, readonly) NSMutableArray <NSString *> * jsFunctions;

#pragma mark - 可配置属性
/// delegate
@property (nonatomic, weak) id <PLVJSBridgeDelegate> delegate;

/// 是否自定义‘加载指示器’ (YES:内置加载指示器将不显示 NO:内置加载指示器将显示；默认 NO)
@property (nonatomic, assign) BOOL customActivityIndicator;

/// 调试模式 (YES:打印调试信息 NO:不打印调试信息；默认 NO)
@property (nonatomic, assign) BOOL debugMode;

#pragma mark - 添加监听
/// 添加对象作为接收者
///
/// @note 该接收者需要实现对应的Js方法
///
/// @param receiver JS方法回调的接收者
- (void)addJsFunctionsReceiver:(NSObject *)receiver;

/// 添加需要监听的Js方法回调
///
/// @note 需通过 [addJsFunctionsReceiver:] 添加对象作为接收者；该接收者需要实现对应的Js方法；满足以上条件，才能如期收到回调；
///
/// @param jsFunctions 需要监听的Js方法回调数组
- (void)addObserveJsFunctions:(NSArray <NSString *> *)jsFunctions;

#pragma mark - 页面加载
/// 加载在线 url 链接
///
/// @param url url链接
/// @param view 承载 webview 的父视图
- (void)loadWebView:(NSString *)url inView:(UIView *)view;

/// 加载本地 html 文件
///
/// @param htmlString 本地 html 解析后内容
/// @param baseURL 可访问的文件夹路径 (注意是 file:// 开头的 URL)
/// @param view 承载 webview 的父视图
- (void)loadHTMLString:(NSString *)htmlString baseURL:(NSURL *)baseURL inView:(UIView *)view;

/// 加载本地 html 文件
///
/// @note 该方法要求 iOS9 以上；对本地文件读取的兼容性更好
///
/// @param URL html 本地文件路径 (注意是 file:// 开头的 URL)
/// @param readAccessURL 可访问的文件夹路径 (注意是 file:// 开头的 URL)
/// @param view 承载 webview 的父视图
- (void)loadFileURL:(NSURL *)URL allowingReadAccessToURL:(NSURL *)readAccessURL inView:(UIView *)view API_AVAILABLE(ios(9.0));

#pragma mark - Js交互
/// 向 webview 注入 js 以调用方法
///
/// @param jsFunction js 方法名
/// @param params 需要传递的参数
- (void)call:(NSString *)jsFunction params:(NSArray *)params;

@end

// Webview Js交互器代理方法
@protocol PLVJSBridgeDelegate <NSObject>

@optional

/// webview 加载成功回调
///
/// @param jsBridge 当前对象本身
- (void)plvJSBridgeWebviewDidFinishLoad:(PLVJSBridge *)jsBridge;

/// webview 加载失败回调
///
/// @param jsBridge 当前对象本身
- (void)plvJSBridgeWebviewDidFailLoad:(PLVJSBridge *)jsBridge withError:(NSError *)error;

/// webview 需要展示或隐藏‘加载指示器’时，将触发此回调
///
/// @note 可通过此回调，来获知合适的时机，进行自定义加载指示器的展示或隐藏；
///       若需自定义加载指示器，请设置 [customActivityIndicator]，设置YES后，内置加载指示器将不显示；
///
/// @param jsBridge 当前对象本身
/// @param loadingShow 是否需要展示或隐藏‘加载指示器’ (YES:需要展示 NO:需要隐藏)
- (void)plvJSBridge:(PLVJSBridge *)jsBridge webviewLodingShow:(BOOL)loadingShow;

/// webview 需要展示确认面板
///
/// @note 当此接收到此回调时，可弹出 UIAlertController 或 一个自定义确认弹窗
///
/// @param jsBridge 当前对象本身
/// @param message 需要展示的信息 (可作为 ‘确认弹窗’ 的提示语)
/// @param frame 发起弹窗的页面框架信息
/// @param completionHandler 当确认弹窗被点击后，需回调此Block并附带BOOL参数 (YES:用户选择‘好的’ NO:用户选择‘取消’)
- (void)plvJSBridge:(PLVJSBridge *)jsBridge showConfirmPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(BOOL result))completionHandler;

@end
