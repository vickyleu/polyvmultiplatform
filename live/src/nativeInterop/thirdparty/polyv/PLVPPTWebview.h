//
//  PLVPPTWebview.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2020/9/16.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <PLVFoundationSDK/PLVFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVPPTWebviewDelegate;

/// PPT视图
///
/// @note 直播，添加至相应视图中即可；
///       回放，添加至相应视图中，并调用 [pptStart] 方法即可；
///
/// @code
/// // 直播场景 代码演示
/// // 1.创建及加载
/// PLVPPTWebview * pptWebiew = [[PLVPPTWebview alloc] init];
/// [someView addSubview:pptWebiew];
/// pptWebiew.frame = someView.bounds;
/// [pptWebiew loadOnlinePPT];
///
/// // 2. socket 登录成功后设置用户信息
/// pptWebiew.userInfo = userInfo;
///
/// // 3. 接收到 socket PPT事件则执行刷新
/// [pptWebiew refreshPPT:json];
/// @endcode
DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用PLVWebViewBridge")
@interface PLVPPTWebview : UIView
 
#pragma mark - 配置属性
/// delegate
@property (nonatomic, weak) id <PLVPPTWebviewDelegate> delegate;

/// 直播场景，在 socket 登录成功后，需将用户信息同步至 PPT视图
@property (nonatomic, strong) NSDictionary * userInfo;

#pragma mark - 高级配置属性
/// jsbridge delegate
///
/// @note 当需要接收 webview 回调事件时，可设置此 jsDelegate
@property (nonatomic, weak) id <PLVJSBridgeDelegate> jsDelegate;

/// 是否自定义‘加载指示器’ (YES:内置加载指示器将不显示 NO:内置加载指示器将显示；默认 NO)
///
/// @note 需同时设置 jsDelegate，以接收对应的回调。回调介绍，具体请参考 <PLVJSBridgeDelegate>
@property (nonatomic, assign) BOOL customActivityIndicator;

/// 调试模式 (YES:打印调试信息 NO:不打印调试信息；默认 NO)
@property (nonatomic, assign) BOOL jsDebugMode;

#pragma mark - 页面加载
/// 加载在线 互动页面
- (void)loadOnlinePPT;

/// 加载本地 互动页面
///
/// @param htmlString 本地 html 解析后内容
/// @param baseURL 可访问的文件夹路径 (注意是 file:// 开头的 URL)
- (void)loadLocalPPTWithHTMLString:(NSString *)htmlString baseURL:(NSURL *)baseURL;

/// 加载本地 html 文件
///
/// @note 该方法要求 iOS9 以上；对本地文件读取的兼容性更好
///
/// @param URL html 本地文件路径 (注意是 file:// 开头的 URL)
/// @param readAccessURL 可访问的文件夹路径 (注意是 file:// 开头的 URL)
- (void)loadLocalPPTWithFileURL:(NSURL *)URL allowingReadAccessToURL:(NSURL *)readAccessURL API_AVAILABLE(ios(9.0));

#pragma mark - 直播场景相关方法
/// 刷新PPT内容
///
/// @param json PPT内容
- (void)refreshPPT:(NSString *)json;

/// 刷新PPT内容
///
/// @param json PPT内容
/// @param delay 延迟时间 (单位毫秒)
- (void)refreshPPT:(NSString *)json delay:(NSUInteger)delay;

/// 设置视频SEI信息
///
/// @param json SEI信息
- (void)setSEIData:(NSString *)json;

#pragma mark - 双向画笔相关方法
/// 设置画笔相关权限
///
/// @param paint 画笔权限 (YES:允许使用 NO:禁用)
/// @param control 操作ppt权限 (YES:允许使用 NO:禁用)
- (void)setPaintPermission:(BOOL)paint controlPPTPermission:(BOOL)control;

/// 设置画板可绘制状态
///
/// @param status 可绘制状态 (close:关闭画笔 open:开启画笔)
- (void)setPaintStatus:(NSString *)status;

/// 设置画笔颜色
///
/// @param color 画笔颜色色值字符串
- (void)setBrushColor:(NSString *)color;

/// 开启画笔删除状态
- (void)toDelete;

#pragma mark - 回放场景相关方法
/// 加载回放PPT
///
/// @param vid 回放视频的vid
- (void)pptStart:(NSString *)vid;

/// 【观看回放时】加载回放PPT
/// @param videoId 回放视频的videoId(请求'直播回放视频的信息'接口返回的视频Id，与后台回放列表看到的vid不是同一个数据)
/// @param channelId 频道Id
- (void)pptStartWithVideoId:(NSString *)videoId channelId:(NSString *)channelId;

/// 【观看暂存时】加载暂存PPT
/// @param fileId 暂存视频的fileId
/// @param channelId 频道Id
- (void)pptStartWithFileId:(NSString *)fileId channelId:(NSString *)channelId;

/// PPT 恢复播放
///
/// @param currentTime 当前播放时间点
- (void)pptPlay:(long)currentTime;

/// PPT 暂停播放
///
/// @param currentTime 当前播放时间点
- (void)pptPause:(long)currentTime;

/// PPT 跳至某个播放点
///
/// @param toTime 需要跳至的播放时间点
- (void)pptSeek:(long)toTime;

@end

@protocol PLVPPTWebviewDelegate <NSObject>

@optional

#pragma mark - 通用回调
/// PPT视图 已准备完毕
///
/// @param pptWebview PPT视图对象
- (void)plvPPTWebviewHadPrepared:(PLVPPTWebview *)pptWebview;


#pragma mark - 直播场景回调
/// [直播场景] PPT视图 发送笔触数据
///
/// @note 开启画笔权限的连麦学员，在操作绘画后，需将生成的笔触数据，回调给外部处理；
///
/// @param pptWebview PPT视图对象
/// @param jsonData PPT视图对象
- (void)plvPPTWebview:(PLVPPTWebview *)pptWebview sendPaintInfo:(NSString *)jsonData;


#pragma mark - 回放场景回调
/// [回放场景] PPT视图 需要获取视频播放器的当前播放时间点
///
/// @param pptWebview PPT视图对象
///
/// @return NSTimeInterval 当前播放时间点
- (NSTimeInterval)plvPPTWebviewGetPlayerCurrentTime:(PLVPPTWebview *)pptWebview;

/// [回放场景] PPT视图 讲师发起PPT位置切换
///
/// @note 回放中，将复现讲师对PPT的位置操作。收到此回调时，外部应根据 status 值相应切换PPT视图位置
///
/// @param pptWebview PPT视图对象
/// @param status PPT是否需要切换至主窗口 (YES:PPT需要切至主窗口 NO:PPT需要切至小窗，视频需要切至主窗口)
- (void)plvPPTWebview:(PLVPPTWebview *)pptWebview changePPTPosition:(BOOL)status;

@end

NS_ASSUME_NONNULL_END
