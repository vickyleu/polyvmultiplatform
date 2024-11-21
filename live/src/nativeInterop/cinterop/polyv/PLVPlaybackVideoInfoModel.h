//
//  PLVPlaybackVideoInfoModel.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/5/24.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 回放视频的信息model
@interface PLVPlaybackVideoInfoModel : NSObject

@property (nonatomic, copy) NSString *liveType;           // 直播类型

@property (nonatomic, copy) NSString *title;              // 视频标题
@property (nonatomic, copy) NSString *duration;           // 视频时长
@property (nonatomic, copy) NSString *firstImage;         // 首图地址
@property (nonatomic, copy) NSString *fileUrl;            // 视频地址

@property (nonatomic, copy) NSString *vid;               // 视频Id
@property (nonatomic, copy) NSString *videoId;            // 视频Id
@property (nonatomic, copy) NSString *videoPoolId;        // 视频poolId
@property (nonatomic, copy) NSString *fileId;             // 文件id
@property (nonatomic, copy) NSString *channelId;          // 频道Id
@property (nonatomic, copy) NSString *channelSessionId;   // 直播场次
@property (nonatomic, copy) NSString *originSessionId;    // 原始场次ID

@property (nonatomic, assign) BOOL playbackCacheEnabled;  // 是否可缓存

@property (nonatomic, copy) NSString *listType;           // 列表类型

// cache info
@property (nonatomic, assign) BOOL status;                // 缓存状态
@property (nonatomic, copy) NSString *videoUrl;           // 视频地址
@property (nonatomic, assign) NSInteger videoSize;        // 视频大小
@property (nonatomic, copy) NSString *zipUrl;          // 包含ppt、video、js的压缩包地址
@property (nonatomic, assign) NSInteger zipSize;       // zip包大小
@property (nonatomic, copy) NSString *pptJsonUrl;         // JS地址

#pragma mark 账号信息
/// 用户唯一标识，用于登录socket、发送日志
@property (nonatomic, copy) NSString *viewerId;
/// 用户昵称，用于登录socket、发送日志
@property (nonatomic, copy) NSString *viewerName;
/// 用户头像地址，用于登录socket
@property (nonatomic, copy) NSString *viewerAvatar;

+ (instancetype)playbackVideoInfoModelWithJsonDict:(NSDictionary *)jsonDict;

/// 通过record暂存视频信息的json生成model
+ (instancetype)playbackVideoInfoModelWithRecordJsonDict:(NSDictionary *)jsonDict;

@end

/// 本地播放回放模型（代表下载完成的回放）
@interface PLVPlaybackLocalVideoInfoModel : PLVPlaybackVideoInfoModel
// 视频相关资源的总路径（配置后自动解析出videoPoolId、localVideoPath、basePath、localHtmlPath、pptPath；仅适用于需ppt播放的资源解析）
@property (nonatomic, copy) NSString *fileIdPath;

@property (nonatomic, copy) NSString *localVideoPath;

@property (nonatomic, copy) NSString *basePath;
@property (nonatomic, copy) NSString *localHtmlPath;

@property (nonatomic, copy) NSString *pptPath;

@property (nonatomic, copy) NSString *thumbnailPath;

/// 任务总数据大小数值
@property (nonatomic, assign) unsigned long long totalBytesExpectedToWrite;

@end

NS_ASSUME_NONNULL_END
