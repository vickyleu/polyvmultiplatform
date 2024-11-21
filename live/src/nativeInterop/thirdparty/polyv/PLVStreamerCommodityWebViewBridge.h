//
//  PLVStreamerCommodityWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2022/10/10.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <PLVLiveScenesSDK/PLVLiveScenesSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class PLVStreamerCommodityWebViewBridge;

/// 商品列表模块 WebSDK Bridge 的回调 （不能保证在主线程回调）
@protocol PLVStreamerCommodityWebViewBridgeDelegate <NSObject>

/// 获取APP信息的回调
/// @param webViewBridge WebSDK与JS桥接
- (NSDictionary *)getAPPInfoInStreamerCommodityWebViewBridge:(PLVStreamerCommodityWebViewBridge *)webViewBridge;

@end

@interface PLVStreamerCommodityWebViewBridge : PLVSocketWebViewBridge

/// PLVStreamerCommodityWebViewBridgeDelegate 代理
@property (nonatomic, weak) id<PLVStreamerCommodityWebViewBridgeDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
