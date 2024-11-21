//
//  PLVPlayer.h
//  PLVCloudClassSDK
//
//  Created by Lincal on 2020/12/4.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<PLVIJKPlayer/PLVIJKPlayer.h>)
    #import <PLVIJKPlayer/PLVIJKFFMoviePlayerController.h>
    typedef PLVIJKFFOptions PLVOptions;
#elif __has_include(<IJKMediaFramework/IJKMediaFramework.h>)
    #import <IJKMediaFramework/IJKMediaFramework.h>
    typedef IJKFFOptions PLVOptions;
#else
    #define PLV_NO_IJK_EXIST
#endif

NS_ASSUME_NONNULL_BEGIN

/// 播放器 主副类型
typedef NS_ENUM(NSInteger, PLVPlayerMainSubType) {
    PLVPlayerMainSubType_Main = 0, // 主播放器
    PLVPlayerMainSubType_Sub = 2,  // 副播放器
};

@protocol PLVPlayerDelegate;

/// 裸播放器
///
/// @note 支持直接使用 URL 进行播放；此类不具备业务逻辑，也不依赖其他业务类；
@interface PLVPlayer : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// delegate
@property (nonatomic, weak) id <PLVPlayerDelegate> delegate;

/// App进入后台时，是否暂停 主播放器 播放
///
/// @note 若需支持‘后台播放’，则需同时在 TARGETS - Capability - Background Modes 中勾选 “Audio, AirPlay, and Picture in Picture”；
///       YES:关闭后台播放 NO:开启后台播放；默认值 NO；
///       从后台进入前台时，主播放器不会自动恢复播放。请根据业务需要，自行调用恢复播放方法；
@property (nonatomic, assign) BOOL pauseMainPlayerInBackground;

/// App进入后台时，是否暂停 副播放器 播放
///
/// @note 若需支持‘后台播放’，则需同时在 TARGETS - Capability - Background Modes 中勾选 “Audio, AirPlay, and Picture in Picture”；
///       YES:关闭后台播放 NO:开启后台播放；默认值 NO；
///       从后台进入前台时，副播放器会自动恢复播放。若业务所需，可自行调用暂停播放方法；
@property (nonatomic, assign) BOOL pauseSubPlayerInBackground;

#pragma mark 数据
/// 当前帧时间戳信息
@property (nonatomic, readonly) long curFrameAUserTC;

/// 视频缓存时长
@property (nonatomic, readonly) int64_t videoCacheDuration;

/// 视频下载速率
@property (nonatomic, readonly) int64_t originalTcpSpeed;

/// 视频下载速率字符串 (示例 "100KB/s")
@property (nonatomic, readonly) NSString * tcpSpeed;

/// 视频大小
@property (nonatomic, readonly) CGSize naturalSize;

/// 当前播放时间点 (单位:秒；仅非直播场景下有值)
@property (nonatomic, readonly) NSTimeInterval currentPlaybackTime;

/// 视频总时长 (仅非直播场景下有值)
@property (nonatomic, readonly) NSTimeInterval duration;

/// 当前已缓存时长 (仅非直播场景下有值)
@property (nonatomic, readonly) NSTimeInterval playableDuration;

/// 当前倍速 (仅非直播场景下有值)
@property (nonatomic, assign, readonly) CGFloat currentSpeed;

#pragma mark 状态
@property (nonatomic, assign, readonly) IJKMPMoviePlaybackState mainPlayerPlaybackState;

@property (nonatomic, assign, readonly) IJKMPMovieLoadState mainPlayerLoadState;

/// 播放器的缩放模式，默认为IJKMPMovieScalingModeAspectFit
@property (nonatomic, assign, readonly) IJKMPMovieScalingMode scalingMode;

@property (nonatomic, assign, readonly) BOOL mainPlayerExist;

@property (nonatomic, assign, readonly) BOOL subPlayerExist;
/// 是否正在播放中
@property (nonatomic, assign, readonly) BOOL playing;

/// 主播放器 是否将暂停
@property (nonatomic, assign, readonly) BOOL willPaused;

/// 是否正在展示内容
///
/// @note ’正在展示内容‘ 指 ’内容加载中‘、’播放内容中‘
@property (nonatomic, assign) BOOL showingContent;

#pragma mark 功能对象
/// 由外部传入的，负责承载播放器画面的父视图
///
/// @note 需调用 [setupDisplaySuperview:] 方法来设置
@property (nonatomic, strong, readonly) UIView * displaySuperview;

#pragma mark - [ 方法 ]
#pragma mark 通用
/// 播放主体内容
///
/// @note 主体内容将由 主播放器 负责加载、播放；
///       相比 副播放器，主播放器对外部的回调更丰富；
///       内部不会因 副播放器 的创建，而自动销毁 主播放器，有需要请自行销毁；
///
/// @param contentURL 主体内容的媒体地址
/// @param options 播放器配置选项
- (void)loadMainContentToPlayWithContentURL:(NSURL *)contentURL withOptions:(PLVOptions *)options;

/// 播放其他内容
///
/// @note 其他内容将由 副播放器 负责加载、播放；
///       相比 主播放器，副播放器对外部的回调更精简；
///       内部不会因 主播放器 的创建，而自动销毁 副播放器，有需要请自行销毁；
///
/// @param contentURL 其他内容的媒体地址
/// @param options 播放器配置选项
- (void)loadSubContentToPlayWithContentURL:(NSURL *)contentURL withOptions:(PLVOptions *)options;

/// 设置 承载播放器画面 的父视图
///
/// @param displayeSuperview 承载播放器画面的父视图
- (void)setupDisplaySuperview:(UIView *)displayeSuperview;

/// 设置 播放器 的缩放模式
///
/// @param scalingMode 缩放模式，默认为IJKMPMovieScalingModeAspectFit
- (void)setupScalingMode:(IJKMPMovieScalingMode)scalingMode;

/// 清理 主播放器
- (void)clearMainPlayer;

/// 清理 副播放器
- (void)clearSubPlayer;

/// 清理 全部播放器
- (void)clearAllPlayer;

/// 暂停 主播放器 播放
- (void)pause;

/// 暂停 副播放器 播放
- (void)subPlayerPause;

/// 静音 主播放器
- (void)mute;

/// 取消静音 主播放器
- (void)cancelMute;

/// 静音 副播放器
- (void)subPlayerMute;

/// 取消静音 副播放器
- (void)subPlayerCancleMute;

#pragma mark 快直播相关
/// 获取快直播下的包重传次数
- (int64_t)getWebrtcNackCount;

/// 获取快直播下的视频包接收个数
- (int64_t)getWebrtcVideoPacketReceive;

#pragma mark 非直播相关
/// 开始 主播放器 播放
- (void)play;

/// 开始 副播放器 播放
- (void)subPlayerPlay;

/// 主播放器 视频跳至某个时间点
- (void)seekToTime:(NSTimeInterval)toTime;

/// 主播放器 切换倍速 (范围值 0.0~2.0)
- (void)switchSpeedRate:(CGFloat)toSpeed;

@end

@protocol PLVPlayerDelegate <NSObject>

@optional
/// 播放器加载前，回调options配置对象
///
/// @note 播放器在加载前，将触发此回调，并附带 PLVOptions，有自定义配置需求时，可对此对象进行参数设置。
///       当集成的是 PLVIJKPlayer 时，请按 PLVIJKFFOptions 来处理 options；
///       当集成的是 IJKMediaFramework 时，请按 IJKFFOptions 来处理 options；
///
/// @param player 播放器对象
/// @param options 播放配置对象
- (PLVOptions *)plvPlayer:(PLVPlayer *)player playerWillLoad:(PLVPlayerMainSubType)mainSubType withOptions:(PLVOptions *)options;

/// 播放器 已准备好播放
///
/// @param player 播放器对象
/// @param mainSubType 播放器主副类型
- (void)plvPlayer:(PLVPlayer *)player playerIsPreparedToPlay:(PLVPlayerMainSubType)mainSubType;

/// 播放器 ’加载状态‘ 发生改变
///
/// @param player 播放器对象
/// @param mainSubType 播放器主副类型
- (void)plvPlayer:(PLVPlayer *)player playerLoadStateDidChange:(PLVPlayerMainSubType)mainSubType;

/// 播放器 ’播放状态‘ 发生改变
///
/// @param player 播放器对象
/// @param mainSubType 播放器主副类型
- (void)plvPlayer:(PLVPlayer *)player playerPlaybackStateDidChange:(PLVPlayerMainSubType)mainSubType;

/// 播放器 ’是否正在播放中‘状态 发生改变
///
/// @param player 播放器对象
/// @param mainSubType 播放器主副类型
/// @param playing 当前是否正在播放
- (void)plvPlayer:(PLVPlayer *)player playerPlayingStateDidChange:(PLVPlayerMainSubType)mainSubType playing:(BOOL)playing;

/// 播放器 播放结束
///
/// @param player 播放器对象
/// @param mainSubType 播放器主副类型
/// @param finishReson 播放结束原因
- (void)plvPlayer:(PLVPlayer *)player playerPlaybackDidFinish:(PLVPlayerMainSubType)mainSubType finishReson:(IJKMPMovieFinishReason)finishReson;

/// 播放器 已销毁
///
/// @param player 播放器对象
/// @param mainSubType 播放器主副类型
- (void)plvPlayer:(PLVPlayer *)player playerDidDestroyed:(PLVPlayerMainSubType)mainSubType;

/// 主播放器 ‘SEI信息’ 发生改变
///
/// @param player 播放器对象
/// @param timeStamp 附带的时间戳信息
- (void)plvPlayer:(PLVPlayer *)player playerSeiDidChanged:(long)timeStamp;

@end


NS_ASSUME_NONNULL_END
