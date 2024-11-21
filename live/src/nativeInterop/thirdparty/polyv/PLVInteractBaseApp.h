//
//  PLVInteractBaseApp.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2020/9/10.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVFoundationSDK/PLVFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVInteractBaseAppDelegate;

@interface PLVInteractBaseApp : NSObject

@property (nonatomic, weak) id <PLVInteractBaseAppDelegate> delegate;

@property (nonatomic, weak) PLVJSBridge * jsBridge;

@property (nonatomic, assign) float triviaCardTimeoutSec;   /// 互动应用提交超时秒数
@property (nonatomic, assign) NSInteger triviaCardMaxRetryCount;/// 互动应用最大重试提交次数

- (instancetype)initWithJsBridge:(PLVJSBridge *)jsBridge;

- (void)processInteractMessageString:(NSString *)msgString jsonDict:(NSDictionary *)jsonDict;

- (void)callRequirePortraitScreen;

- (void)callWebviewShow;

- (void)submitResultCallback:(NSString *)json event:(NSString *)event;

- (void)submitResultTimeoutCallback:(NSString *)event;

@end

@protocol PLVInteractBaseAppDelegate <NSObject>

- (void)plvInteractAppRequirePortraitScreen:(PLVInteractBaseApp *)interactApp;

- (void)plvInteractApp:(PLVInteractBaseApp *)interactApp webviewShow:(BOOL)show;

@end

NS_ASSUME_NONNULL_END
