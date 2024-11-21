//
//  PLVLiveDefine.h
//  PLVLiveScenesSDK
//
//  Created by zykhbl on 2018/7/27.
//  Copyright © 2018年 PLV. All rights reserved.
//

#ifndef PLVLiveDefine_h
#define PLVLiveDefine_h

/// 频道类型
typedef NS_OPTIONS(NSInteger, PLVChannelType) {
    /// 未知类型
    PLVChannelTypeUnknown = 0,
    /// 云课堂
    PLVChannelTypePPT     = 1 << 0,
    /// 普通直播、大班课（两种类型服务端都返回alone，SDK也看作同一类型）
    PLVChannelTypeAlone   = 1 << 1,
    /// 研讨会（暂不支持该类型）
    PLVChannelTypeSeminar = 1 << 2
};

/// 视频类型
typedef NS_ENUM(NSUInteger, PLVChannelVideoType) {
    /// 视频类型为 直播
    PLVChannelVideoType_Live = 0,
    /// 视频类型为 直播回放（注：特指直播结束后的回放，有别于‘点播’）
    PLVChannelVideoType_Playback = 2,
    /// 视频类型为 推流
    PLVChannelVideoType_Streamer = 4
};

/// 频道 直播流状态
typedef NS_ENUM(NSInteger, PLVChannelLiveStreamState) {
    PLVChannelLiveStreamState_Unknown = -1, /// 状态未知
    PLVChannelLiveStreamState_End     = 0,  /// 无直播流
    PLVChannelLiveStreamState_Live    = 1,  /// 直播中
    PLVChannelLiveStreamState_Stop    = 2   /// 直播暂停
};

/// 频道 连麦场景类型
typedef NS_ENUM(NSInteger, PLVChannelLinkMicSceneType) {
    PLVChannelLinkMicSceneType_Unknown = 0, /// 未知
    PLVChannelLinkMicSceneType_Alone_PartRtc = 1, /// 部分RTC (旧版普通直播连麦)
    PLVChannelLinkMicSceneType_Alone_PureRtc = 2, /// 完全RTC (新版普通直播连麦)
    PLVChannelLinkMicSceneType_PPT_PureRtc = 3    /// 完全RTC (云课堂连麦)
};

/// 频道 连麦媒体类型
typedef NS_ENUM(NSInteger, PLVChannelLinkMicMediaType) {
    PLVChannelLinkMicMediaType_Unknown = 0, // 未知类型
    PLVChannelLinkMicMediaType_Audio = 1,   // 音频连麦
    PLVChannelLinkMicMediaType_Video = 2,   // 视频连麦
};

/// 频道 限制类型
typedef NS_ENUM(NSInteger, PLVChannelRestrictState) {
    PLVChannelRestrictState_GetFailed = -2, /// 获取失败
    PLVChannelRestrictState_Unknown = -1,   /// 未知
    PLVChannelRestrictState_NoneRestrict = 0, /// 无限制（允许播放）
    PLVChannelRestrictState_PlayRestrict = 1, /// 播放受限（不可播放）
};

/// 频道 暖场类型
typedef NS_ENUM(NSUInteger, PLVChannelWarmUpType) {
    PLVChannelWarmUpType_None,  /// 无暖场
    PLVChannelWarmUpType_Image, /// 图片类型
    PLVChannelWarmUpType_Video, /// 视频类型
};

/// 频道 跑马灯类型
typedef NS_ENUM(NSUInteger, PLVChannelMarqueeType) {
    PLVChannelMarqueeType_None,  /// 无跑马灯
    PLVChannelMarqueeType_Fixed, /// 固定类型
    PLVChannelMarqueeType_Nick,  /// 登录用户名类型
    PLVChannelMarqueeType_URL,   /// URL自定义类型
};

/// 频道 防录屏水印类型
typedef NS_ENUM(NSUInteger, PLVChannelWatermarkType) {
    PLVChannelWatermarkType_None,  /// 无水印
    PLVChannelWatermarkType_Fixed, /// 固定类型
    PLVChannelWatermarkType_Nick,  /// 登录用户名类型
};

/// 频道 防录屏水印字体大小
typedef NS_ENUM(NSUInteger, PLVChannelWatermarkFontSize) {
    PLVChannelWatermarkFontSize_Small,    /// 小
    PLVChannelWatermarkFontSize_Middle,  /// 中
    PLVChannelWatermarkFontSize_Large   /// 大
};

/// 频道 片头广告类型
typedef NS_ENUM(NSUInteger, PLVChannelAdvertType) {
    PLVChannelAdvertType_None,   /// 无广告
    PLVChannelAdvertType_Video,  /// 视频
    PLVChannelAdvertType_Image   /// 图片
};

/// 回放视频缓存状态
typedef NS_ENUM(NSInteger, PLVPlaybackVideoCacheState) {
    PLVPlaybackVideoCacheStateUnknonwn      = -1,
    PLVPlaybackVideoCacheStateNone          = 0,   /// 没有缓存
    PLVPlaybackVideoCacheStateLocal         = 1,   /// 已经缓存
    PLVPlaybackVideoCacheStateDownloadQueue = 2    /// 缓存中
};

/// 下载状态定义
typedef NS_ENUM(NSInteger, PLVDownloadState) {
    /** 起始默认的状态 */
    PLVDownloadStateDefault = 0,     // 默认，下载器未创建（不会自动开始下载）
    
    /** 下载器创建过程的状态 */
    PLVDownloadStatePreparing = 1,   // 准备中，下载器创建中（部分下载器存在耗时的创建）
    PLVDownloadStatePrepared = 2,    // 已准备，下载器已创建（preGetFileSize为YES时，代表文件大小已获取）
    
    /** 下载过程的状态 */
    PLVDownloadStateWaiting = 3,     // 等待中，有空余下载位置将自动开始下载（用户希望下载，但未开始下载）
    PLVDownloadStateDownloading = 4, // 下载中，正在下载
    
    /** 解压过程的状态 */
    PLVDownloadStateUnzipping = 5,   // 正在解压，此时无法停止任务
    PLVDownloadStateUnzipped = 6,    // 解压结束（解压成功或失败，将通过‘下载结果的状态’来表现）
    
    /** 下载结果的状态 */
    PLVDownloadStateStopped = 7,     // 已停止，有空余下载位置也不会开始下载（用户希望停止，而非程序自动停止的）
    PLVDownloadStateSuccess = 8,     // 下载成功
    PLVDownloadStateFailed = 9       // 下载失败
};

/// 数据库数组类型定义
typedef NS_ENUM(NSInteger, PLVDownloadDatabaseTaskInfoArrayType) {
    /** 云课堂相关数组 */
    PLVDownloadDatabaseTaskInfoArray_TotalPlayback = 100,   // 所有的回放下载任务 数组
    PLVDownloadDatabaseTaskInfoArray_CompletedPlayback = 101,   // 下载完成的回放下载 数组
    PLVDownloadDatabaseTaskInfoArray_UnfinishedPlayback = 102,   // 下载未完成的回放下载 数组
};

#endif /* PLVLiveDefine_h */
