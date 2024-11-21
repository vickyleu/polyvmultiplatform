//
//  PLVProductWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2022/5/16.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <PLVLiveScenesSDK/PLVLiveScenesSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class PLVProductWebViewBridge;

/// 商品列表模块 WebSDK Bridge 的回调 （不能保证在主线程回调）
@protocol PLVProductWebViewBridgeDelegate <NSObject>

/// 获取APP信息的回调
/// @param webViewBridge WebSDK与JS桥接
- (NSDictionary *)getAPPInfoInProductWebViewBridge:(PLVProductWebViewBridge *)webViewBridge;

/// 点击商品的回调
/// @param webViewBridge WebSDK与JS桥接
/// @param jsonObject 商品详情信息
- (void)plvProductWebViewBridge:(PLVProductWebViewBridge *)webViewBridge clickProductButtonWithJSONObject:(id)jsonObject;

/// 需要显示职位详情的回调
/// @param webViewBridge WebSDK与JS桥接
/// @param jsonObject 商品详情信息
- (void)plvProductWebViewBridge:(PLVProductWebViewBridge *)webViewBridge showJobDetailWithJSONObject:(id)jsonObject;

@end

@interface PLVProductWebViewBridge : PLVSocketWebViewBridge

/// PLVProductWebViewBridgeDelegate 代理
@property (nonatomic, weak) id<PLVProductWebViewBridgeDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
