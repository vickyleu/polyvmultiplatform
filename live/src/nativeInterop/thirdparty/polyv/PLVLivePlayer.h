//
//  PLVLivePlayer.h
//  PLVCloudClassSDK
//
//  Created by Lincal on 2020/12/5.
//  Copyright © 2020 PLV. All rights reserved.
//

#import "PLVPlayer.h"

#import "PLVLiveDefine.h"
#import "PLVChannelInfoModel.h"
#import "PLVViewLogCustomParam.h"
#import "PLVLivePlayerPictureInPictureProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 加载状态
typedef NS_ENUM(NSInteger, PLVLivePlayerLoadState) {
    PLVLivePlayerLoadState_NotLoading = 0,            // 未处于加载状态
    PLVLivePlayerLoadState_ChannelInfoRequesting = 2, // 频道信息请求中
    PLVLivePlayerLoadState_ChannelRestrictInfoRequesting = 4, // 频道限制信息请求中
    PLVLivePlayerLoadState_ChannelStreamStateRequesting = 6,  // 频道流状态请求中
};

/// 网络质量（快直播独有）
typedef NS_ENUM(NSInteger, PLVLivePlayerQuickLiveNetworkQuality) {
    PLVLivePlayerQuickLiveNetworkQuality_NoConnection = 0,   // 无网络
    PLVLivePlayerQuickLiveNetworkQuality_Good = 1,           // 良好
    PLVLivePlayerQuickLiveNetworkQuality_Middle = 2,         // 一般
    PLVLivePlayerQuickLiveNetworkQuality_Poor = 3            // 较差
};


@protocol PLVLivePlayerDelegate;

/// 直播播放器
///
/// @note 若您希望了解 播放器基础功能 相关属性方法，可查看父类 PLVPlayer.h；
///       若您希望了解 直播业务 相关属性方法，可查看 PLVLivePlayer.h；
///
/// @code
/// // 使用演示
/// PLVLivePlayer * livePlayer = [[PLVLivePlayer alloc] initWithPLVAccountUserId:accountUserId channelId:channelId];
/// livePlayer.delegate = self;
/// livePlayer.liveDelegate = self;
/// [livePlayer setupDisplaySuperview:displaySuperview];
/// @endcode
@interface PLVLivePlayer : PLVPlayer<PLVLivePlayerPictureInPictureProtocol>

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// 直播播放器 liveDelegate
///
/// @note 父类 PLVPlayer 的 delegate 也有播放器基础功能的回调，详情可见 PLVPlayer.h
@property (nonatomic, weak) id <PLVLivePlayerDelegate> liveDelegate;

/// 是否观看无延迟直播 默认值 NO；
@property (nonatomic, assign) BOOL channelWatchNoDelay;

/// 是否观看快直播 默认值 NO；
@property (nonatomic, assign) BOOL channelWatchQuickLive;

/// 是否观看公共流 默认值 NO；
@property (nonatomic, assign) BOOL channelWatchPublicStream;

/// 是否开启追帧 默认值 NO；
@property (nonatomic, assign) BOOL chaseFrame;

/// 视频解码是否使用“硬解码”
///
/// @note 硬解码效率更高，而软解码兼容性更好；
///       YES:使用硬解码 NO:使用软解码；
///       默认值 YES；
@property (nonatomic, assign) BOOL videoToolBox;

/// 是否允许展示暖场内容
///
/// @note 暖场内容有’视频‘、’图片‘两种类型；后者将通过回调 告知外部，外部可自行展示；
///       默认值 YES；
///       ‘暖场’ 有别于 ’广告‘，具体业务区别可见PLV后台配置；
@property (nonatomic, assign) BOOL allowShowWarmUpContent;

/// 后台统计参数数据模型
///
/// @note 播放器发送 ViewLog 日志所需要的数据模型，详见 PLVViewLogCustomParam.h 参考可配置的统计参数
@property (nonatomic, strong) PLVViewLogCustomParam * customParam;

#pragma mark 数据
/// 频道信息数据模型
@property (nonatomic, strong, readonly) PLVChannelInfoModel * channelInfo;

/// 当前频道号
@property (nonatomic, copy, readonly) NSString * channelId;

/// 直播播放器ID
@property (nonatomic, copy, readonly) NSString * livePlayerId;

/// 用户观看时长 (单位:秒；播放器暂停则不认为“观看”；不包含连麦；包含无延迟观看)
@property (nonatomic, readonly) NSInteger watchDuration;

/// 用户总观看时长 (单位:秒；播放器暂停则不认为“观看”；包含连麦；包含无延迟观看)
@property (nonatomic, readonly) NSInteger totalWatchDuration;

/// 用户停留时长 (单位:秒)
@property (nonatomic, readonly) NSInteger stayDuration;

#pragma mark 状态
/// 当前直播播放器 ‘加载状态’
@property (nonatomic, assign, readonly) PLVLivePlayerLoadState loadState;

/// 当前频道的 ‘直播流状态’
///
/// @note 枚举类型详见 PLVLiveDefine.h
@property (nonatomic, assign, readonly) PLVChannelLiveStreamState currentStreamState;

/// 当前是否为 ‘音频模式’
@property (nonatomic, assign, readonly) BOOL audioMode;

/// 播放器是否正在播放暖场视频 (有别于 ’广告‘，详情可见PLV后台配置)
@property (nonatomic, assign, readonly) BOOL playingWarmUpVideo;

/// 播放器当前是否为无延迟观看模式（无延迟直播、快直播、公共流）
@property (nonatomic, assign, readonly) BOOL noDelayWatchMode;

/// 播放器当前是否正在播放无延迟直播
@property (nonatomic, assign, readonly) BOOL noDelayLiveWatching;

/// 播放器当前是否正在播放快直播
@property (nonatomic, assign, readonly) BOOL quickLiveWatching;

/// 播放器当前是否正在播放公共流
@property (nonatomic, assign, readonly) BOOL publicStreamWatching;

#pragma mark - [ 方法 ]
/// 创建 直播播放器
///
/// @note 创建后需调用父类方法 [setupDisplaySuperview:] 进行画面添加，才可正常显示播放内容
///
/// @param accountUserId PLV账户Id
/// @param channelId 频道号Id
- (instancetype)initWithPolyvAccountUserId:(NSString *)accountUserId channelId:(NSString *)channelId DEPRECATED_MSG_ATTRIBUTE("Please use initWithPLVAccountUserId:");
- (instancetype)initWithPLVAccountUserId:(NSString *)accountUserId channelId:(NSString *)channelId;

/// 重新加载直播 （或暂停后的恢复直播）
- (void)reloadLivePlayer;

/// 切换 ’当前线路‘ 或 ’当前码率‘
///
/// @note 传入的 targetLineIndex、targetCodeRate 不一定就是最终的选定值。因为内部将判断传入值是否合法；
///       最终播放的选定值，可读取 channelInfo 的 currentLineIndex、currentDefinition 属性；
///
/// @param targetLineIndex 目标线路 (由 0 起始；比如切至线路1，则传入 0)
/// @param targetCodeRate 目标码率/清晰度 (对应字符串，可在代理方法 [plvLivePlayer:codeRateOptions:currentCodeRate:lineNum:currentLineIndex:] 中取得)
- (void)switchToLineIndex:(NSInteger)targetLineIndex codeRate:(NSString *)targetCodeRate;

/// 开启或退出 音频模式
///
/// @param audioMode 是否开启音频模式
- (void)switchToAudioMode:(BOOL)audioMode;

/// 开启或退出 无延迟观看模式
///
/// @note 该方法只支持无延迟、快直播、公共流频道(即 [channelWatchNoDelay]为YES时 、 [channelWatchQuickLive]为YES时或[channelWatchPublicStream]为YES时)；
///       该方法将改变 [noDelayWatchMode] 值；
///
/// @param noDelayWatchMode 是否开启无延迟观看模式
- (void)switchToNoDelayWatchMode:(BOOL)noDelayWatchMode;

@end

@protocol PLVLivePlayerDelegate <NSObject>

@optional
/// 直播播放器 ‘加载状态’ 发生改变
///
/// @param livePlayer 直播播放器
/// @param loadState 当前加载状态
- (void)plvLivePlayer:(PLVLivePlayer *)livePlayer loadStateDidChanged:(PLVLivePlayerLoadState)loadState;

/// 直播播放器 ‘流状态’ 更新
///
/// @param livePlayer 直播播放器
/// @param newestStreamState 当前最新的 ’流状态’
/// @param streamStateDidChanged ’流状态‘ 相对上一次 是否发生变化
- (void)plvLivePlayer:(PLVLivePlayer *)livePlayer streamStateUpdate:(PLVChannelLiveStreamState)newestStreamState streamStateDidChanged:(BOOL)streamStateDidChanged;

/// 直播播放器 发生错误
///
/// @param livePlayer 直播播放器
/// @param error 错误信息对象 (可能为nil；error.code 可详见 PLVFPlayErrorCodeGenerator.h)
- (void)plvLivePlayer:(PLVLivePlayer *)livePlayer loadMainPlayerFailureWithError:(NSError * _Nullable)error;

/// 直播播放器 ‘频道信息’ 发生改变
///
/// @param livePlayer 直播播放器
/// @param channelInfo 当前最新 ’频道信息‘ 对象
- (void)plvLivePlayer:(PLVLivePlayer *)livePlayer channelInfoDidUpdated:(PLVChannelInfoModel *)channelInfo;

/// 直播播放器 ‘码率可选项、当前码率、线路可选数、当前线路‘ 更新
///
/// @note 此回调触发时，可同时在 [channelInfo] 属性中，读取出 ‘码率信息、线路信息’ 的最新值；
///       调用 [switchToLineIndex:codeRate:] 切换 ’当前线路‘ 或 ’当前码率‘，会触发此回调；
///       [channelInfo] 刷新时，也会触发此回调，用于告知当前 ‘码率信息、线路信息’ 的最新值；
///
/// @param livePlayer 直播播放器
/// @param codeRateOptions 码率/清晰度 可选项字符串数组
/// @param currentCodeRate 当前 码率/清晰度
/// @param lineNum 线路可选数
/// @param currentLineIndex 当前线路下标 (由 0 起始)
- (void)plvLivePlayer:(PLVLivePlayer *)livePlayer codeRateOptions:(NSArray <NSString *> *)codeRateOptions currentCodeRate:(NSString *)currentCodeRate lineNum:(NSInteger)lineNum currentLineIndex:(NSInteger)currentLineIndex;

/// 直播播放器 需获知外部 ‘当前是否正在连麦’
///
/// @note 此回调不保证在主线程触发
///
/// @param livePlayer 直播播放器
///
/// @return BOOL 需返回 ‘当前外部是否正在连麦’ 的状态布尔值
- (BOOL)plvLivePlayerGetInLinkMic:(PLVLivePlayer *)livePlayer;

/// 直播播放器 需获知外部 ‘当前是否暂停观看无延迟’
///
/// @note 此回调不保证在主线程触发
///
/// @param livePlayer 直播播放器
///
/// @return BOOL 需返回 ‘当前外部是否正在连麦’ 的状态布尔值
- (BOOL)plvLivePlayerGetPausedWatchNoDelay:(PLVLivePlayer *)livePlayer;

/// 直播播放器 需展示暖场图片
///
/// @param livePlayer 直播播放器
/// @param show 是否展示 (YES:展示 NO:隐藏)
/// @param warmUpImageURLString 暖场图片链接地址
- (void)plvLivePlayer:(PLVLivePlayer *)livePlayer showWarmUpImage:(BOOL)show warmUpImageURLString:(NSString * _Nullable)warmUpImageURLString;

/// 直播播放器 快直播网络质量检测回调
///
/// @note 仅在 快直播观看 时会触发该回调(即 [quickLiveWatching]为YES时)；
///
/// @param livePlayer 直播播放器
/// @param netWorkQuality 网络质量
- (void)plvLivePlayer:(PLVLivePlayer *)livePlayer quickLiveNetworkQuality:(PLVLivePlayerQuickLiveNetworkQuality)netWorkQuality;

@end

NS_ASSUME_NONNULL_END
