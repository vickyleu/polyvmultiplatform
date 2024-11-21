//
//  PLVDownloadPlaybackTaskInfo.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/5/23.
//  Copyright © 2022 PLV. All rights reserved.
//

#import "PLVDownloadTaskInfo.h"

NS_ASSUME_NONNULL_BEGIN

/// 云课堂 下载回放任务信息模型
@interface PLVDownloadPlaybackTaskInfo : PLVDownloadTaskInfo

#pragma mark - [ 属性 ]

#pragma mark 回放信息
/// 直播类型
@property (nonatomic, copy) NSString *liveType;
/// 列表类型
@property (nonatomic, copy) NSString *listType;
/// 标题名
@property (nonatomic, copy) NSString *title;
/// 视频时长
@property (nonatomic, copy) NSString *duration;
/// 码率（清晰度）
@property (nonatomic, copy) NSString *definition;
/// 视频Id
@property (nonatomic, copy) NSString *vid;
/// 直播视频Id
@property (nonatomic, copy) NSString *videoId;
/// 视频poolId
@property (nonatomic, copy) NSString *videoPoolId;
/// 频道号Id
@property (nonatomic, copy) NSString *channelId;
/// 直播场次Id
@property (nonatomic, copy) NSString *channelSessionId;
/// 原始场次ID
@property (nonatomic, copy) NSString *originSessionId;
/// 封面图地址
@property (nonatomic, copy) NSString *coverUrl;
/// 是否可缓存
@property (nonatomic, assign) BOOL playbackCacheEnabled;

#pragma mark 下载后信息
/// 视频文件路径字典（key:码率，value:文件路径）
@property (nonatomic, copy, readonly) NSDictionary *videoPathDic;
/// ppt文件夹路径
@property (nonatomic, copy, readonly) NSString *pptFolderPath;
/// ppt文件路径
@property (nonatomic, copy, readonly) NSString *pptFilePath;
/// js文件夹路径
@property (nonatomic, copy, readonly) NSString *JsFolderPath;
/// js文件路径
@property (nonatomic, copy, readonly) NSString *JsFilePath;
/// html文件路径
@property (nonatomic, copy, readonly) NSString *htmlFilePath;

/// 视频文件名字典（key:码率，value:文件名）
@property (nonatomic, copy, readonly) NSDictionary *videoFileNameDic;
/// ppt文件名
@property (nonatomic, copy, readonly) NSString *pptFileName;
/// js文件名
@property (nonatomic, copy, readonly) NSString *JsFileName;
/// html文件名
@property (nonatomic, copy, readonly) NSString *htmlFileName;

#pragma mark 辅助属性
/// 下载资源是否为多资源包，默认NO是单个资源包（为NO时，下载链接即是父类中声明的url）
@property (nonatomic, assign, readonly) BOOL multiResource;

#pragma mark 多资源包信息
/** 以下信息仅在multiResource为YES时可用 */
/// 回放视频下载链接
@property (nonatomic, copy) NSString *videoUrl;
/// 回放视频大小
@property (nonatomic, assign) unsigned long long videoSize;
/// ppt下载链接
@property (nonatomic, copy) NSString *pptZipUrl;
/// ppt资源大小
@property (nonatomic, assign) unsigned long long pptZipSize;
/// js下载链接
@property (nonatomic, copy) NSString *JsZipUrl;

#pragma mark 账号信息
/// 用户唯一标识，用于登录socket、发送日志
@property (nonatomic, copy) NSString *viewerId;
/// 用户昵称，用于登录socket、发送日志
@property (nonatomic, copy) NSString *viewerName;
/// 用户头像地址，用于登录socket
@property (nonatomic, copy) NSString *viewerAvatar;

@end

NS_ASSUME_NONNULL_END
