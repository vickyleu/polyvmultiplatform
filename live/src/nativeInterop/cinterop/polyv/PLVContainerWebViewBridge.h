//
//  PLVContainerWebViewBridge.h
//  PLVLiveScenesSDK
//
//  Created by lijingtong on 2021/7/13.
//  Copyright © 2021 PLV. All rights reserved.
// 容器WebSDK JS桥接文件
// 用于容器WebSDK webView与JS交互

#import <Foundation/Foundation.h>
#import "PLVSocketWebViewBridge.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^PLVContainerResponseCallback)(id responseData);

@class PLVContainerWebViewBridge;

/// 画笔类型
typedef NS_ENUM(NSInteger, PLVContainerApplianceType) {
    PLVContainerApplianceTypeUnknown, // 未知
    PLVContainerApplianceTypeFreeLine, // 自由画笔
    PLVContainerApplianceTypeArrow, // 箭头
    PLVContainerApplianceTypeChoice, // 选择
    PLVContainerApplianceTypeEraser, // 橡皮擦
    PLVContainerApplianceTypeText, // 文本
    PLVContainerApplianceTypeMove // 移动
};

@protocol PLVContainerWebViewBridgeDelegate <NSObject>

/// 刷新最小化的容器(ppt、word各类文档统称)数据 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didRefreshMinimizeContainerDataWithJsonObject:(id)jsonObject;

/// 刷新打开的PPT容器数量 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didRefreshPptContainerTotalWithJsonObject:(id)jsonObject;

/// 刷新画笔工具权限 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didRefreshBrushToolStatusWithJsonObject:(id)jsonObject;

/// 准备开始编辑文字 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge willStartEditTextWithJsonObject:(id)jsonObject;

/// 更新画笔工具类型 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didChangeApplianceType:(PLVContainerApplianceType)applianceType;

/// 更新画笔颜色 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didChangeStrokeHexColor:(NSString *)strokeHexColor;

@optional

/// webView 需要 native 发送消息给 socket 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didSendSocketEventWithJsonObject:(id)jsonObject DEPRECATED_MSG_ATTRIBUTE("已废弃，由父类PLVSocketWebViewBridge进行处理");

/// 更新文本大小 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didChangeFontSize:(CGFloat)fontSize;

/// 更新线条宽度 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didChangeLineWidth:(CGFloat)lineWidth;

/// 更新画板缩放百分比 时调用
- (void)containerWebViewBridge:(PLVContainerWebViewBridge *)containerWebViewBridge didChangeZoomPercent:(CGFloat)percent;

@end

@interface PLVContainerWebViewBridge : PLVSocketWebViewBridge

/// PLVContainerWebViewBridge 代理
@property (nonatomic, weak) id<PLVContainerWebViewBridgeDelegate> delegate;

/// 初始化方法
/// @param webView webview对象
/// @param webViewDelegate webview代理
- (instancetype)initBridgeWithWebview:(WKWebView *)webView webviewDelegate:(id<WKNavigationDelegate>)webViewDelegate DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用父类initBridgeWithWebView:webViewDelegate:");

#pragma mark -  [ native -> js ]
#pragma mark 通用方法

/// 切换教具
/// @param type 教具类型
- (void)changeApplianceType:(PLVContainerApplianceType)type;

/// 修改文本字体大小
/// @param fontSize 字体大小
- (void)changeFontSize:(NSUInteger)fontSize;

/// 修改线条宽度
/// @param width 线条宽度
- (void)changeLineWidth:(NSUInteger)width;

/// 修改笔触颜色
/// @param hexColor 16进制颜色字符串
- (void)changeStrokeHexColor:(NSString *)hexColor;

/// 执行清空画板操作
- (void)doClear;

/// 执行重做画板操作
- (void)doRedo;

/// 执行撤回画板操作
- (void)doUndo;

/// 执行删除画笔操作
- (void)doDelete;

/// 完成编辑文字
/// @note 用于native完成文字输入后返回给webView
/// @param text 文字
- (void)finishEditText:(NSString *)text;

/// 取消编辑文字
- (void)cancelEditText;

/// 授予画笔权限
/// @note 根据socket消息得知是否需要授予画笔权限
/// @param callback js回调
- (void)givePaintBrushAuth:(PLVContainerResponseCallback)callback;

/// 移除画笔权限
/// @note 根据socket消息得知是否需要移除画笔权限
/// @param callback js回调
- (void)removePaintBrushAuth:(PLVContainerResponseCallback)callback;

/// 插入 socket 数据
/// @note native 在接受以下socket消息时，需将消息转发给js：
/// 'onSliceID'、'onSliceDraw'、'onSliceOpen'、'onSliceClose'、'onSliceControl'
/// @param socketData socket原数据
- (void)joinSocketData:(NSString *)socketData  DEPRECATED_MSG_ATTRIBUTE("已废弃，由父类PLVSocketWebViewBridge进行处理");

/// 设为组长或移除组长
/// @note 根据socket消息得知是否需要设置为，触发后如果是组长，内部会自动授予画笔权限，无需另外发送 givePaintBrushAuth 到 webview 中
/// @param isLeader 是否设为组长，YES:设为组长，NO：移除组长
/// @param callback js回调
- (void)setOrRemoveGroupLeader:(BOOL)isLeader callback:(PLVContainerResponseCallback)callback;

/// 切换房间，用于开始或结束分组讨论时切换房间
/// @param ackData leaveDiscuss、joinDiscuss 这两个Socket事件的Ack回调数据
/// @param callback js回调
- (void)switchRoomWithAckData:(NSDictionary *)ackData datacallback:(_Nullable PLVContainerResponseCallback)callback;

#pragma mark 讲师、组长专属方法

/// 打开文档
/// @note 讲师、组长专属方法
/// @param autoId 文档autoId
- (void)openPptWithAutoId:(NSUInteger)autoId;

/// 关闭文档
/// @note 讲师、组长专属方法
/// @param autoId 文档autoId
- (void)closePptWithAutoId:(NSUInteger)autoId;

/// 操作容器(ppt、word各类文档统称)
/// @note 讲师、组长专属方法
/// @param containerId 容器内容Id
/// @param close 关闭、打开
- (void)operateContainerWithContainerId:(NSString *)containerId close:(BOOL)close;

/// 重置画板缩放
/// @note 讲师、组长专属方法
- (void)resetZoom;

#pragma mark - [ js -> native ]
#pragma mark 通用方法注册

/// 注册'sendSocketData' 方法
/// 用于把 webView 接收到的操作画板产生的数据，通过 socket 发送给聊天室
- (void)registerSendSocketData DEPRECATED_MSG_ATTRIBUTE("已废弃，由父类PLVSocketWebViewBridge进行处理");

/// 注册'startEditText' 方法
/// 用于接收 webView 开始输入文字 回调
- (void)registerStartEditText;

/// 注册'toggleOperationStatus' 方法
/// 用于接收 webView 刷新画笔工具是否可用状态回调
- (void)registerToggleOperationStatus;

#pragma mark 讲师、组长专属方法注册

/// 注册'refreshMinimizeContainerData' 方法
/// @note 讲师、组长专属方法
/// 用与接收 webView 刷新最小化的容器数据
- (void)registerRefreshMinimizeContainerData;

/// 注册'refreshPptContainerTotal' 方法
/// @note 讲师、组长专属方法
/// 用与接收 webView 刷新打开的 PPT 容器数量
- (void)registerRefreshPptContainerTotal;

/// 注册'zoomPercenChange' 方法
/// @note 讲师、组长专属方法
/// 用与接收 webView 回调当前 画板缩放百分比
- (void)registerZoomPercenChange;

#pragma mark 学生专属方法注册

/// 注册'changeAppliance' 方法
/// @note 学生专属方法
/// 用于接收 webview 切换画笔工具类型 回调
- (void)registerChangeApplianceType;

/// 注册'changeStrokeStyle' 方法
/// @note 学生专属方法
/// 用于接收 webview 切换画笔颜色 回调
- (void)registerChangeStrokeHexColor;

/// 注册'changeFontSize' 方法
/// @note 学生专属方法
/// 用于接收 webview 切换文本字体大小 回调
- (void)registerChangeFontSize;

/// 注册'changeLineWidth' 方法
/// @note 学生专属方法
/// 用于接收 webview 切换线条宽度 回调
- (void)registerChangeLineWidth;

#pragma mark - [ native -> socket]
#pragma mark 讲师、组长专属方法

/// 授予画笔权限
/// @note 用于讲师、组长授予学生画笔权限
/// @param userId 用户Id
/// @param sessionId sessionId
- (void)setPaintBrushAuthWithUserId:(NSString *)userId sessionId:(NSString *)sessionId;

/// 移除画笔权限
/// @note 用于讲师、组长移除学生画笔权限
/// @param userId 用户Id
- (void)removePaintBrushAuthWithUserId:(NSString *)userId;

@end

NS_ASSUME_NONNULL_END
