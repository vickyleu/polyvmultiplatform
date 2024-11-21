//
//  PLVQAWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2024/2/27.
//  Copyright © 2024 PLV. All rights reserved.
//
// 问答模块 Bridge

#import <PLVLiveScenesSDK/PLVLiveScenesSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class PLVQAWebViewBridge;

/// 问答模块 WebSDK Bridge 的回调 （不能保证在主线程回调）
@protocol PLVQAWebViewBridgeDelegate <NSObject>

/// 获取APP信息的回调
/// @param webViewBridge WebSDK与JS桥接
- (NSDictionary *)getAPPInfoInQAWebViewBridge:(PLVQAWebViewBridge *)webViewBridge;

@end

@interface PLVQAWebViewBridge : PLVSocketWebViewBridge

@property (nonatomic, weak) id<PLVQAWebViewBridgeDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
