//
//  PLVLivePictureInPictureManager.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/2/9.
//  Copyright © 2022 PLV. All rights reserved.
//
//  画中画功能管理类

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 画中画模式
typedef NS_OPTIONS(NSUInteger, PLVLivePictureInPictureMode) {
    PLVLivePictureInPictureMode_AVPlayer = 1, // 系统AVPlayer 画中画模式
    PLVLivePictureInPictureMode_IJKPlayer API_AVAILABLE(ios(15.0)) = 2 // IJKPlayer 画中画模式
};

@protocol PLVLivePictureInPictureRestoreDelegate;

@interface PLVLivePictureInPictureManager : NSObject

#pragma mark - [ 属性 ]

#pragma mark 可配置项

/// 画中画恢复前的用户界面逻辑代理
@property (nonatomic, weak, nullable) id <PLVLivePictureInPictureRestoreDelegate> restoreDelegate;

/// 设置画中画开启模式，请在创建播放器前设置此属性（默认PLVLivePictureInPictureMode_AVPlayer）
@property (nonatomic, assign) PLVLivePictureInPictureMode pictureInPictureMode;

/// 画中画控件（包括播放/暂停、快进、后退）是否可见（YES 可见，NO不可见 默认 YES 可见）
@property (nonatomic, assign) BOOL pictureInPictureControlsVisible;

/// 是否允许在切换到后台时自动启动画中画，默认NO
@property (nonatomic, assign) BOOL canAutoStartPictureInPicture;

/// 画中画播放器是否正在播放正片
@property (nonatomic, assign, readonly) BOOL pictureInPicturePlayerPlaying;

/// 画中画小窗是否开启
@property (nonatomic, assign, readonly) BOOL pictureInPictureActive;

#pragma mark - [ 方法 ]

/// 单例方法
+ (instancetype)sharedInstance;

/// 停止画中画
- (void)stopPictureInPicture;

/// 检查是否支持开启画中画，ipad需要在9.0以上版本，iPhone需要在14.0以上版本
- (BOOL)checkPictureInPictureSupported;

/// 静音画中画
- (void)mute;

/// 取消静音画中画
- (void)cancelMute;

@end

#pragma mark - [ 代理方法 ]

/// 画中画恢复代理
@protocol PLVLivePictureInPictureRestoreDelegate <NSObject>

@optional

/// 点击画中画恢复按钮，画中画关闭之前的用户界面恢复实现
/// @param completionHandler completionHandler
- (void)plvPictureInPictureRestoreUserInterfaceForPictureInPictureStopWithCompletionHandler:(void (^)(BOOL restored))completionHandler;

@end

NS_ASSUME_NONNULL_END
