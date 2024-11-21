//
//  PLVChannelPlaybackInfoModel.h
//  PLVLiveScenesSDK
//
//  Created by Dhan on 2022/4/27.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVFoundationSDK/PLVSafeModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVLiveRecordFileModel : PLVSafeModel

/// 文件ID
@property (nonatomic, copy) NSString *fileId;
/// m3u8资源地址
@property (nonatomic, copy) NSString *m3u8;
/// mp4资源地址
@property (nonatomic, copy) NSString *mp4;
/// 频道场次ID
@property (nonatomic, copy) NSString *channelSessionId;
/// 时长
@property (nonatomic, copy) NSString *duration;
/// 原始场次ID
@property (nonatomic, copy) NSString *originSessionId;
/// 来源
@property (nonatomic, copy) NSString *origin;

@end

@interface PLVTargetPlaybackVideoModel : PLVSafeModel

/// 点播视频vid
@property (nonatomic, copy) NSString *videoId;
/// 直播系统生成的id
@property (nonatomic, copy) NSString *videoPoolId;
/// 资源地址
@property (nonatomic, copy) NSString *fileUrl;
/// 频道场次ID
@property (nonatomic, copy) NSString *channelSessionId;
/// 时长
@property (nonatomic, copy) NSString *duration;
/// 原始场次ID
@property (nonatomic, copy) NSString *originSessionId;
/// 来源
@property (nonatomic, copy) NSString *origin;
/// 文件ID
@property (nonatomic, copy) NSString *fileId;
/// 视频加密状态，1表示为加密状态，0为非加密
@property (nonatomic, assign) long seed;

@end

@interface PLVChannelPlaybackInfoModel : PLVSafeModel

/// 是否有回放视频，值为Y/N
@property (nonatomic, assign, readonly) BOOL hasPlaybackVideo;
/// 是否有录制文件，值为Y/N
@property (nonatomic, assign, readonly) BOOL hasRecordFile;
/// 频道回放开关，值为Y/N
@property (nonatomic, assign, readonly) BOOL enablePlayBack;
/// 频道回放来源，record为暂存列表，playback为回放列表，vod为点播列表
@property (nonatomic, copy, readonly) NSString *playbackOrigin;
/// 点播用户状态，值为Y/N
@property (nonatomic, assign, readonly) BOOL vodUserStatus;
/// 回放章节功能开关，值为Y/N
@property (nonatomic, copy, readonly) NSString *sectionEnabled;
/// 录制文件
@property (nonatomic, strong, readonly) PLVLiveRecordFileModel *recordFile;
/// 回放视频
@property (nonatomic, strong, readonly) PLVTargetPlaybackVideoModel *targetPlaybackVideo;
/// 点播地址
@property (nonatomic, copy, readonly) NSString *vodUrl;
/// 点播sessionId
@property (nonatomic, copy, readonly) NSString *vodSessionId;
/// 播放场次ID
@property (nonatomic, copy, readonly) NSString *targetSessionId;
/// 回放方式，single为单个回放，list为列表回放
@property (nonatomic, copy, readonly) NSString *type;
/// 回放类型，vod为点播回放，playback为直播回放
@property (nonatomic, copy, readonly) NSString *playbackType;

@end

NS_ASSUME_NONNULL_END
