//
//  PLVInteractWebview.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2020/9/10.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PLVFoundationSDK/PLVFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVInteractWebviewDelegate;

// 互动应用 Webview
@interface PLVInteractWebview : NSObject

@property (nonatomic, weak) id <PLVInteractWebviewDelegate> delegate;

@property (nonatomic, strong, readonly) PLVJSBridge * jsBridge;

@property (nonatomic, strong, readonly) WKWebView * webview;

@end

// 互动应用 Webview 代理方法
@protocol PLVInteractWebviewDelegate <NSObject>

- (void)plvInteractWebview:(PLVInteractWebview *)interactWebview
didReceiveInteractMessageString:(NSString *)msgString
                  jsonDict:(NSDictionary *)jsonDict;

@end

NS_ASSUME_NONNULL_END
