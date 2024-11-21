//
//  PLVWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2021/02/04.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 画笔类型枚举
typedef NS_ENUM(NSInteger, PLVWebViewBrushPenType) {
    PLVWebViewBrushPenTypeFreePen, /// 自由笔划
    PLVWebViewBrushPenTypeArrow,   /// 箭头
    PLVWebViewBrushPenTypeText,    /// 文本
    PLVWebViewBrushPenTypeRect    /// 矩形
};

/// 翻页类型
typedef NS_ENUM(NSInteger, PLVChangePPTPageType) {
    PLVChangePPTPageTypePreviousStep, // 上一页
    PLVChangePPTPageTypeNextStep, // 下一页
    PLVChangePPTPageTypePPTBtnBack // 回到当前页
};

@protocol PLVWebViewBridgeProtocol <NSObject>

@optional

#pragma mark 观看场景回调

/// webView 上PPT视图准备完毕时调用
- (void)jsbridge_PPTHadPrepare;

/// [回放场景] PPT视图 需要获取视频播放器的当前播放时间点
/// @return NSTimeInterval 当前播放时间点
- (NSTimeInterval)jsbridge_getCurrentPlaybackTime;

/// [回放场景] PPT视图 讲师发起PPT位置切换
/// @note 回放中，将复现讲师对PPT的位置操作。收到此回调时，外部应根据 status 值相应切换PPT视图位置
/// @param status PPT是否需要切换至主窗口 (YES-PPT需要切至主窗口 NO-PPT需要切至小窗，视频需要切至主窗口)
- (void)jsbridge_changePPTPosition:(BOOL)status;

/// [回放场景] webView 上的文档翻页时调用
/// @note 观众本地翻页或讲师远端翻页都会执行此方法
- (void)jsbridge_pageStatusChangeWithAutoId:(NSUInteger)autoId pageNumber:(NSUInteger)pageNumber totalPage:(NSUInteger)totalPage pptStep:(NSUInteger)step maxNextNumber:(NSUInteger)maxNextNumber;

#pragma mark 推流场景回调

/// webView 需要发送消息给 socket 时调用
- (void)jsbridge_sendSocketEventWithJson:(id)jsonObject;

/// webView 上的文档切换时调用
- (void)jsbridge_documentChangeWithAutoId:(NSUInteger)autoId imageUrls:(NSArray *)imageUrls fileName:(NSString * _Nullable)fileName;

/// webView 上的文档翻页时调用
- (void)jsbridge_pageStatusChangeWithAutoId:(NSUInteger)autoId pageNumber:(NSUInteger)pageNumber totalPage:(NSUInteger)totalPage pptStep:(NSUInteger)step;

/// webView 上准备输入文字时调用
- (void)jsbridge_documentInputWithText:(NSString *)inputText textColor:(NSString *)textColor;

/// webView 上白板预览图更新时调用
- (void)jsbridge_updateWhiteboardImageData:(NSData *)imageData pageNumber:(NSUInteger)pageNumber;

/// webView 上白板或者PPT缩放时调用
/// @param zoomRatio 缩放的比例 (100 表示 100%，200 表示 200%)
- (void)jsbridge_updateWhiteboardPPTZoomRatio:(NSInteger)zoomRatio;

@end

@interface PLVWebViewBridge : NSObject

@property (nonatomic, weak) id<PLVWebViewBridgeProtocol> delegate;

+ (instancetype)bridgeWithWebview:(WKWebView *)webView webviewDelegate:(id<WKNavigationDelegate>)webViewDelegate;

+ (instancetype)bridgeWithWebview:(WKWebView *)webView;

- (void)setWebViewDelegate:(id<WKNavigationDelegate> __nullable)webViewDelegate;

#pragma mark - Call JS Method

/// 设置用户信息
/// @param userDict  socket 用户登录信息
- (void)setUserInfo:(NSDictionary *)userDict;

/// 白板、PPT内部翻页
/// @note 区别'changePPTWithAutoId:pageNumber:'，不可用于白板与PPT之间的切换，或打开新的白板或PPT
/// @param type 翻页类型
- (void)changePPTPageWithType:(PLVChangePPTPageType)type;

#pragma mark 观看专用方法

/// 刷新PPT内容
/// @param jsonObject PPT内容
/// @param delay 延迟时间 (单位毫秒)
- (void)refreshPPTWithJsonObject:(NSDictionary *)jsonObject delay:(NSUInteger)delay;

/// 【观看回放时】设置本地ppt路径
/// @param path ppt路径
- (void)pptSetLocalPath:(NSString *)path;

- (void)pptLocalStartWithVideoId:(NSString *)videoId vid:(NSString *)vid;

/// 设置视频SEI信息
/// @param newTimeStamp 时间戳信息
- (void)setSEIData:(long)newTimeStamp;

/// 加载回放PPT
/// @param vid 回放视频的vid
- (void)pptStartWithVid:(NSString *)vid DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用pptStartWithVideoId:roomId:");

/// 【观看回放时】加载回放PPT
/// @param videoId 回放视频的videoId(请求'直播回放视频的信息'接口返回的视频Id，与后台回放列表看到的vid不是同一个数据)
/// @param channelId 频道Id
- (void)pptStartWithVideoId:(NSString *)videoId channelId:(NSString *)channelId;

/// 【观看暂存时】加载暂存PPT
/// @param fileId 暂存视频的fileId
/// @param channelId 频道Id
- (void)pptStartWithFileId:(NSString *)fileId channelId:(NSString *)channelId;

#pragma mark 推流专用方法

/// 设置或取消画笔权限
/// @param userType  用户权限， speaker 代表控制ppt权限+画笔权限
- (void)setPaintPermission:(NSString *)userType;

/// 设置画板是否处于可绘制状态
/// @param open  打开或关闭画板
- (void)setPaintStatus:(BOOL)open;

/// 告诉 h5 现在开始上课，h5 会清空画板
/// @param jsonDict 开始推流时发送的 socket 消息
- (void)setSliceStart:(id)jsonDict;

/// 切换 ppt 或白板
/// 如果切换的是文档，切换成功后触发回调 '-jsbridge_documentChangeWithAutoId:imageUrls:fileName:'
/// @param autoId  切换的文档的 autoId，如果是白板 autoId 为 0
/// @param pageNumber  切换到文档的第几页，-1 表示打开上次展示的页面
- (void)changePPTWithAutoId:(NSUInteger)autoId pageNumber:(NSInteger)pageNumber;

/// 设置画笔类型
/// @param type  line - 自由笔；text - 文字；arrowLine - 箭头
- (void)setDrawType:(PLVWebViewBrushPenType)type;

/// 修改画笔颜色
/// @param hexString  RGB色值，如红色为“#FF0000”
- (void)changeColor:(NSString *)hexString;

/// 执行撤回画板操作
- (void)doUndo;

/// 进入画笔删除状态
- (void)toDelete;

/// 删除所有画笔
- (void)deleteAllPaint;

/// 完成文本输入
- (void)changeTextContent:(NSString *)content;

/// 重置 白板或PPT 缩放比例为 100%
- (void)resetWhiteboardPPTZoomRatio;

#pragma mark - Register JS Method

/// 注册 'sendSocketEvent' 方法
/// 用于把 h5 接收到的操作画板产生的数据，通过 socket 发送给聊天室
/// 用于开播场景时，开始推流才需要发送 h5 画板数据到聊天室
/// 配合回调 '-jsbridge_sendSocketEventWithJson:' 使用
- (void)registerSocketEventFunction;

#pragma mark 观看专用方法

/// 注册 'pptPrepare' 方法
/// 【回放时】用于PPT视图准备完毕时接收到通知
/// 配合回调 '-jsbridge_PPTHadPrepare' 使用
- (void)registerPPTPrepareFunction;

/// 注册 'videoDuration' 方法
/// 用于PPT视图需要获取视频回放播放器当前播放时间点时接收到通知
/// 配合回调 '-jsbridge_getCurrentPlaybackTime' 使用
- (void)registerVideoDurationFunction;

/// 注册 'changePPTPosition' 方法
/// 用于讲师发起PPT位置切换时接收到通知
/// 配合回调 '-jsbridge_changePPTPosition:' 使用 
- (void)registerChangePPTPositionFunction;

/// 注册 'pptStatusChange' 方法
/// @note 用于观看端文档翻页时接收到通知
/// 配合回调 '-jsbridge_pageStatusChangeWithAutoId:pageNumber:totalPage:pptStep:maxNextNumber:' 使用
- (void)registerWatchPPTStatusChangeFunction;

#pragma mark 推流专用方法

/// 注册 'pptStatusChange' 方法
/// 用于文档翻页时接收到通知
/// 配合回调 '-jsbridge_pageStatusChangeWithAutoId:pageNumber:totalPage:pptStep:' 使用
- (void)registerPPTStatusChangeFunction;

/// 注册 'toEditText' 方法
/// 用于 webView 上准备输入文字时调用
/// 配合回调 '-jsbridge_documentInputWithText:textColor:' 使用
- (void)registerPPTInputFunction;

/// 注册 'whiteImages' 方法
/// 用于 webView 上白板预览图更新时调用
/// 配合回调 '-jsbridge_updateWhiteboardImageData:pageNumber:' 使用
- (void)registerWhiteImagesFunction;

/// 注册 'pptThumbnail'方法（续播后，需要同步该ppt的缩略图和文件名称）
/// 用于 恢复上场直播后 同步ppt缩略图
/// 配合回调 '-jsbridge_documentChangeWithAutoId:imageUrls:fileName:' 使用
- (void)registerPPTThumbnailFunction;

/// 注册 'zoomChange' 方法
/// 用于 webView 上白板或PPT尺寸缩放更新时调用
/// 配合回调 '-jsbridge_updateWhiteboardPPTZoomRatio:' 使用
- (void)registerWhiteboardPPTZoomChangeFunction;

/// 注销 'pptThumbnail'方法
- (void)removePPTThumbnailFunction;

@end

NS_ASSUME_NONNULL_END
