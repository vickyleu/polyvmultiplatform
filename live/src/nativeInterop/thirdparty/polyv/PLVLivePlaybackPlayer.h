//
//  PLVLivePlaybackPlayer.h
//  PLVCloudClassSDK
//
//  Created by Lincal on 2020/12/5.
//  Copyright © 2020 PLV. All rights reserved.
//

#import "PLVPlayer.h"

#import "PLVChannelInfoModel.h"
#import "PLVViewLogCustomParam.h"
#import "PLVChannelPlaybackInfoModel.h"
#import "PLVPlaybackVideoInfoModel.h"
#import "PLVLivePlayerPictureInPictureProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 加载状态
typedef NS_ENUM(NSInteger, PLVLivePlaybackPlayerLoadState) {
    PLVLivePlaybackPlayerLoadState_NotLoading = 0,          // 未处于加载状态
    PLVLivePlaybackPlayerLoadState_VideoInfoRequesting = 2, // 回放详情信息请求中
};

@protocol PLVLivePlaybackPlayerDelegate;

/// 直播回放播放器
///
/// @note 直播回放播放器 继承自 PLVPlayer.h；
///       若您希望了解 播放器基础功能 相关属性方法，可查看 PLVPlayer.h；
///       若您希望了解 直播回放业务 相关属性方法，可查看 PLVLivePlaybackPlayer.h；
///
/// @code
/// // 使用演示
/// PLVLivePlaybackPlayer * livePlaybackPlayer = [[PLVLivePlaybackPlayer alloc] initWithPLVAccountUserId:accountUserId channelId:channelId vodId:vodId vodList:NO];
/// livePlaybackPlayer.delegate = self;
/// livePlaybackPlayer.livePlaybackDelegate = self;
/// [livePlaybackPlayer setupDisplaySuperview:displaySuperview];
/// @endcode
@interface PLVLivePlaybackPlayer : PLVPlayer<PLVLivePlayerPictureInPictureProtocol>

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// 直播回放播放器 livePlaybackDelegate
///
/// @note 父类 PLVPlayer 的 delegate 也有播放器基础功能的回调，详情可见 PLVPlayer.h
@property (nonatomic, weak) id <PLVLivePlaybackPlayerDelegate> livePlaybackDelegate;

/// 视频解码是否使用“硬解码”
///
/// @note 硬解码效率更高，而软解码兼容性更好；
///       YES:使用硬解码 NO:使用软解码；
///       默认值 YES；
@property (nonatomic, assign) BOOL videoToolBox;

/// 后台统计参数数据模型
///
/// @note 播放器发送 ViewLog 日志所需要的数据模型，详见 PLVViewLogCustomParam.h 参考可配置的统计参数
@property (nonatomic, strong) PLVViewLogCustomParam * customParam;

#pragma mark 数据
/// 频道信息数据模型
@property (nonatomic, strong, readonly) PLVChannelInfoModel * channelInfo;
/// 回放视频ID(请求'直播回放视频的信息'接口返回的视频Id，与后台回放列表看到的vid不是同一个数据)
@property (nonatomic, copy, readonly) NSString *videoId;

/// 已缓存进度
@property (nonatomic, assign, readonly) CGFloat downloadProgress;

/// 已播放进度
@property (nonatomic, assign, readonly) CGFloat playedProgress;

/// 已播放时间点字符串 (示例 "01:23")
@property (nonatomic, copy, readonly) NSString * playedTimeString;

/// 总时长字符串 (示例 "01:23")
@property (nonatomic, copy, readonly) NSString * durationTimeString;

/// 直播回放播放器ID
@property (nonatomic, copy, readonly) NSString * livePlaybackPlayerId;

/// 用户观看时长 (单位:秒；播放器暂停则不认为“观看”)
@property (nonatomic, readonly) NSInteger watchDuration;

/// 用户停留时长 (单位:秒)
@property (nonatomic, readonly) NSInteger stayDuration;

#pragma mark - [ 方法 ]
/// 创建 直播回放播放器
///
/// @note 创建后需调用父类方法 [setupDisplaySuperview:] 进行画面添加，才可正常显示播放内容
///
/// @param accountUserId PLV账户Id
/// @param channelId 频道号Id
/// @param vodId 直播回放Id
/// @param vodList 是否 ‘点播列表’ 视频
- (instancetype)initWithPolyvAccountUserId:(NSString *)accountUserId channelId:(NSString *)channelId vodId:(NSString *)vodId vodList:(BOOL)vodList DEPRECATED_MSG_ATTRIBUTE("Please use initWithPLVAccountUserId:");
- (instancetype)initWithPLVAccountUserId:(NSString *)accountUserId channelId:(NSString *)channelId vodId:(NSString *)vodId vodList:(BOOL)vodList;

/// 创建 直播暂存播放器
///
/// @note 创建后需调用父类方法 [setupDisplaySuperview:] 进行画面添加，才可正常显示播放内容
///
/// @param accountUserId PLV账户Id
/// @param channelId 频道号Id
/// @param recordFile 录制文件
- (instancetype)initWithPLVAccountUserId:(NSString *)accountUserId channelId:(NSString *)channelId recordFile:(PLVLiveRecordFileModel *)recordFile;

/// 跳至某个时间点 (单位: 秒)
- (void)seekLivePlaybackToTime:(NSTimeInterval)toTime;

/// 切换倍速 (范围值 0.0~2.0)
- (void)switchLivePlaybackSpeedRate:(CGFloat)toSpeed;

/// 切换回放视频
///
///  @param vodId 直播回放Id (当为同一channelId下的vodId才能切换成功)
- (void)changeLivePlaybackVodId:(NSString *)vodId;

/// 切换暂存视频
/// @param fileId 暂存视频fileId(当为同一channelId下的vodId才能切换成功)
- (void)changeLivePlaybackFileId:(NSString *)fileId;

@end

@protocol PLVLivePlaybackPlayerDelegate <NSObject>

@optional
/// 直播回放播放器 发生错误
///
/// @param livePlaybackPlayer 直播回放播放器
/// @param error 错误信息对象 (可能为nil；error.code 可详见 PLVFPlayErrorCodeGenerator.h)
- (void)plvLivePlaybackPlayer:(PLVLivePlaybackPlayer *)livePlaybackPlayer loadMainPlayerFailureWithError:(NSError * _Nullable)error;

/// 直播回放播放器 需获知外部 ‘当前本地缓存’
///
/// @note 此回调不保证在主线程触发
///
/// @param livePlaybackPlayer 直播回放播放器
/// @param videoId 视频唯一标识，当为暂存时代表fileId，当为回放时代表vid
/// @param channelId 频道号
/// @param listType playback-回放列表，vod-点播列表; 默认普通直播场景为vod，三分屏为playback
///
/// @return PLVPlaybackVideoInfoModel 需返回 ‘当前本地缓存‘ 的数据模型
- (PLVPlaybackLocalVideoInfoModel *)plvLivePlaybackPlayerGetPlaybackCache:(PLVLivePlaybackPlayer *)livePlaybackPlayer videoId:(NSString * _Nullable)videoId channelId:(NSString * _Nullable)channelId listType:(NSString * _Nullable)listType isRecord:(BOOL)isRecord;

/// 直播回放播放器 定时返回当前播放进度
///
/// @param livePlaybackPlayer 直播回放播放器
/// @param downloadProgress 已缓存进度 (0.0 ~ 1.0)
/// @param playedProgress 已播放进度 (0.0 ~ 1.0)
/// @param playedTimeString 当前播放时间点字符串 (示例 "01:23")
/// @param durationTimeString 总时长字符串 (示例 "01:23")
- (void)plvLivePlaybackPlayer:(PLVLivePlaybackPlayer *)livePlaybackPlayer downloadProgress:(CGFloat)downloadProgress playedProgress:(CGFloat)playedProgress playedTimeString:(NSString *)playedTimeString durationTimeString:(NSString *)durationTimeString;

/// 直播回放播放器 ‘频道信息’ 发生改变
///
/// @param livePlaybackPlayer 直播回放播放器
/// @param channelInfo 当前最新 ’频道信息‘ 对象
- (void)plvLivePlaybackPlayer:(PLVLivePlaybackPlayer *)livePlaybackPlayer channelInfoDidUpdated:(PLVChannelInfoModel *)channelInfo;

/// 直播回放播放器 ‘视频信息’ 发生改变
///
/// @param livePlaybackPlayer 直播回放播放器
/// @param playbackVideoInfo 当前最新 ’频道信息‘ 对象
- (void)plvLivePlaybackPlayer:(PLVLivePlaybackPlayer *)livePlaybackPlayer playbackVideoInfoDidUpdated:(PLVPlaybackVideoInfoModel *)playbackVideoInfo;

/// 直播回放播放器 ‘本地视频信息’ 发生改变
///
/// @param livePlaybackPlayer 直播回放播放器
/// @param localPlaybackVideoInfo 当前最新 ’本地频道信息‘ 对象
- (void)plvLivePlaybackPlayer:(PLVLivePlaybackPlayer *)livePlaybackPlayer localPlaybackVideoInfoDidUpdated:(PLVPlaybackLocalVideoInfoModel *)localPlaybackVideoInfo;

/// 直播回放播放器“章节功能”开启
- (void)plvLivePlaybackPlayer:(PLVLivePlaybackPlayer *)livePlaybackPlayer sectionEnabled:(BOOL)sectionEnabled recordEnabled:(BOOL)recordEnabled;

/// 直播回放播放器“回放列表功能”开启
- (void)plvLivePlaybackPlayer:(PLVLivePlaybackPlayer *)livePlaybackPlayer playbackListEnabled:(BOOL)playbackListEnabled vodList:(BOOL)vodList;

@end

NS_ASSUME_NONNULL_END
