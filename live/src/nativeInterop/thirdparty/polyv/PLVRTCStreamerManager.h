//
//  PLVRTCStreamerManager.h
//  PLVCloudClassStreamerDemo
//
//  Created by Lincal on 2019/10/21.
//  Copyright © 2019 plv. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PLVRTCStatistics.h"
#import "PLVLinkMicGetTokenModel.h"
#import "PLVRTCStreamerMixUser.h"
#import <PLVBusinessSDK/PLVBusinessSDK.h>
#import <PLVFoundationSDK/PLVFoundationSDK.h>
#import "PLVBeautyManager.h"

/// 混流布局类型
typedef NS_ENUM(NSInteger, PLVRTCStreamerMixLayoutType) {
    PLVRTCStreamerMixLayoutType_Unknown = 0,     // 未知
    PLVRTCStreamerMixLayoutType_Single = 1,      // 单人模式
    PLVRTCStreamerMixLayoutType_Tile = 2,        // 平铺模式
    PLVRTCStreamerMixLayoutType_MainSpeaker = 3, // 主讲模式
};

typedef NS_ENUM(NSInteger, PLVRTCStreamerManagerErrorCode) {
    /// -1: 未知错误
    PLVRTCStreamerManagerErrorCode_UnknownError = -1,
    /// 0: 无错误
    PLVRTCStreamerManagerErrorCode_NoError = 0,
    
    /// 100: 开始推流失败，流配置错误
    PLVRTCStreamerManagerErrorCode_PushStreamFailedSetupStreamError = 100,
    /// 102: 开始推流失败，流接口错误
    PLVRTCStreamerManagerErrorCode_PushStreamFailedActionError = 102,
    /// 104: 开始推流失败，Session获取错误
    PLVRTCStreamerManagerErrorCode_PushStreamFailedSessionGetError = 104,
    /// 106: 开始推流失败，Session获取非法
    PLVRTCStreamerManagerErrorCode_PushStreamFailedSessionIllegal = 106,
    
    /// 202: 更新RTCToken失败，接口错误
    PLVRTCStreamerManagerErrorCode_UpdateRTCTokenFailedAuthError = 202,
    
    /// 300: RTC内部错误
    PLVRTCStreamerManagerErrorCode_RTCManagerError = 300,
    /// 302: RTC内部错误，启动音频模块失败
    PLVRTCStreamerManagerErrorCode_RTCManagerErrorStartAudioFailed = 302,
};

NS_ASSUME_NONNULL_BEGIN

@protocol PLVRTCStreamerManagerDelegate;

/// RTC 推流管理器
@interface PLVRTCStreamerManager : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// delegate
@property (nonatomic, weak) id <PLVRTCStreamerManagerDelegate> delegate;

/// [硬件] 麦克风 是否默认开启
///
/// @note 仅在 [startLocalMicCameraPreviewByDefault] 方法调用前设置有效
///       YES:开启 NO:关闭；默认值 YES
@property (nonatomic, assign) BOOL micDefaultOpen;

/// [硬件] 摄像头 是否默认开启
///
/// @note 仅在 [startLocalMicCameraPreviewByDefault] 方法调用前设置有效
///       YES:开启 NO:关闭；默认值 NO
@property (nonatomic, assign) BOOL cameraDefaultOpen;

/// [硬件] 摄像头 是否默认前置
///
/// @note 仅在 [startLocalMicCameraPreviewByDefault] 方法调用前设置有效
///       YES:前置 NO:后置；默认值 YES
@property (nonatomic, assign) BOOL cameraDefaultFront;

#pragma mark 状态
/// 当前 是否已加入RTC房间
@property (nonatomic, assign, readonly) BOOL hadJoinedRTC;

/// 当前 是否推流已开始 (以 ‘sessionId请求成功’ 作为起始点)
@property (nonatomic, assign, readonly) BOOL pushStreamStarted;

/// 当前 rtcToken 是否可用
@property (nonatomic, assign, readonly) BOOL rtcTokenAvailable;

/// 当前 RTC服务 连接状态
@property (nonatomic, assign, readonly) PLVBLinkMicConnectionStateType connectionState;

/// 当前 本地用户网络状态
@property (nonatomic, assign, readonly) PLVBLinkMicNetworkQuality networkQuality DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用localNetworkQuality");

/// 当前 本地用户网络状态
@property (nonatomic, assign, readonly) PLVBRTCNetworkQuality localNetworkQuality;

/// 当前 流宽高比 (默认值:PLVBLinkMicStreamScale16_9)
@property (nonatomic, assign, readonly) PLVBLinkMicStreamScale streamScale;

/// 当前 流清晰度 (默认值:PLVBLinkMicStreamQuality180P)
@property (nonatomic, assign, readonly) PLVBLinkMicStreamQuality streamQuality;

/// 当前 推流质量等级 (需要外部根据实际情况传入)
@property (nonatomic, copy, readonly) NSString *streamQualityLevel;

/// 视频流画质偏好
@property (nonatomic, assign, readonly) PLVBRTCVideoQosPreference videoQosPreference;

/// 当前 混流布局模式 (值不为 1、2、3 的情况下，默认以 PLVRTCStreamerMixLayoutType_Single 作替代使用)
@property (nonatomic, assign, readonly) PLVRTCStreamerMixLayoutType mixLayoutType;

/// 当前 本地视频预览画面 镜像类型
@property (nonatomic, assign, readonly) PLVBRTCVideoMirrorMode localVideoMirrorMode;

/// 当前 本地摄像头 是否前置
@property (nonatomic, assign, readonly) BOOL localCameraFront;

/// 当前 本地闪光灯 是否开启
@property (nonatomic, assign, readonly) BOOL localCameraTorchOpen;

/// 当前 本地摄像头 是否开启
@property (nonatomic, assign, readonly) BOOL localCameraOpen;

/// 当前 本地视频流 是否停止推送
@property (nonatomic, assign, readonly) BOOL localVideoStreamMute;

/// 当前 本地麦克风 音量
@property (nonatomic, assign, readonly) CGFloat localMicVolume;

/// 当前 本地麦克风 是否开启
@property (nonatomic, assign, readonly) BOOL localMicOpen;

/// 当前 本地音频流 是否停止推送
@property (nonatomic, assign, readonly) BOOL localAudioStreamMute;

/// 当前 本地音频流 降噪等级
@property (nonatomic, assign, readonly) PLVBLinkMicNoiseCancellationLevel localNoiseCancellationLevel;

/// 当前 支持外接设备 是否开启
@property (nonatomic, assign, readonly) BOOL localExternalDeviceEnabled;

/// 当前 频道连麦功能是否开启（YES:连麦功能已开启 NO:连麦功能已关闭）, 新版连麦策略表示 当前频道是否允许观众举手
@property (nonatomic, assign, readonly) BOOL channelLinkMicOpen;

/// 当前 频道连麦媒体类型
@property (nonatomic, assign, readonly) PLVChannelLinkMicMediaType channelLinkMicMediaType;

/// 当前 本地视频流镜像类型 (默认值:PLVBRTCVideoMirrorMode_Disabled)
@property (nonatomic, assign, readonly) PLVBRTCVideoMirrorMode localVideoStreamMirrorMode;

/// 当前 推流的源类型
@property (nonatomic, assign, readonly) PLVBRTCStreamSourceType publishStreamSourceType;

#pragma mark 数据
/// 当前 频道Id (即房间Id)
@property (nonatomic, copy, readonly) NSString * channelId;

/// 当前 进入RTC频道的用户RTCId
@property (nonatomic, copy, readonly) NSString * userRTCId;

/// 当前 场次Id
@property (nonatomic, copy, readonly) NSString * sessionId;

/// [推流时间] 开始推流的时间戳
///
/// @note 单位秒，带小数，可精确至毫秒；
///       以获取 sessionId 成功为起始时间点；
///       仅在属性 [pushStreamStarted] 为 YES 时有值;
@property (nonatomic, assign, readonly) NSTimeInterval startPushStreamTimestamp;

/// [推流时间] 已有效推流时长
///
/// @note 单位秒，带小数，可精确至毫秒；
///       不包含重连时长；若退至后台期间，推流未断开，也将算入‘已有效推流时长’中；
///       仅在属性 [pushStreamStarted] 为 YES 时有值；
@property (nonatomic, assign, readonly) NSTimeInterval pushStreamValidDuration;

/// [推流时间] 总推流时长
///
/// @note 单位秒，带小数，可精确至毫秒；
///       包含重连时长；即距离 开始推流时间戳 的已过时长；
///       仅在属性 [pushStreamStarted] 为 YES 时有值；
@property (nonatomic, assign, readonly) NSTimeInterval pushStreamTotalDuration;

/// [重连时间] 单次重连时长
///
/// @note 单位秒，带小数，可精确至毫秒；
///       一次推流中，可能有多次重连，此属性为 单次重连时长；
@property (nonatomic, assign, readonly) NSTimeInterval reconnectingThisTimeDuration;

/// [重连时间] 全部重连累计时长
///
/// @note 单位秒，带小数，可精确至毫秒；
///       一次推流中，可能有多次重连，此属性为 全部重连累计时长（包括当前此刻，无论是否 ’重连中‘ 或 ’重连结束‘）；
@property (nonatomic, assign, readonly) NSTimeInterval reconnectingTotalDuration;

/// 当前 本地预览画布模型
@property (nonatomic, strong, readonly) PLVBRTCVideoViewCanvasModel * currentLocalPreviewCanvasModel;

/// 当前 混流用户顺序列表
@property (nonatomic, strong, readonly) NSArray <PLVRTCStreamerMixUser *> * mixUserList;

#pragma mark - [ 方法 ]
#pragma mark 基础调用
/// 创建 RTC推流管理器
///
/// @param rtcType rtc类型值
/// @param channelId 频道Id
+ (instancetype)rtcStreamerManagerWithRTCType:(NSString *)rtcType channelId:(NSString *)channelId;

/// 设置AppGroup和rtcType，屏幕共享功能需要使用该方法
///
/// @note 由外部根据频道信息获取到rtc类型值，同时用户自己生成AppGroup传入；
///       若AppGroup 或 rtcType 为 nil，则设置失败，无法开启屏幕共享
/// @param appGroup appGroup名 一般为 "group." 开头
/// @param rtcType rtc类型值
- (void)setupAppGroup:(NSString *)appGroup rtcType:(NSString *)rtcType;

/// 设置响应新版连麦策略、频道连麦人数和默认频道连麦方式
///
/// @note 只允许配置一次，建议创建RTC推流管理器后调用
///       仅新策略且频道允许连麦人数不为0时，新策略生效
/// @param linkMicNewStrategyEnabled 是否响应新策略
/// @param interactNumLimit 频道允许连麦最大人数
/// @param defaultChannelLinkMicMediaType 默认连麦方式
- (void)setLinkMicNewStrategyEnabled:(BOOL)linkMicNewStrategyEnabled interactNumLimit:(NSUInteger)interactNumLimit defaultChannelLinkMicMediaType:(PLVChannelLinkMicMediaType)defaultChannelLinkMicMediaType;

/// 更新 RTC Token
///
/// @param model 连麦GetToken模型
/// @param completion 更新完成回调 (updateResult YES: 更新成功；NO: 更新失败)
- (void)updateRTCTokenWith:(PLVLinkMicGetTokenModel *)model completion:(nullable void (^)(BOOL updateResult))completion;

/// 配置 本地预览画面模型
///
/// @note 仅作用于 ‘本地预览画面’ 的相关属性配置；不自动开始预览，不自动开始推流；
///
/// @param canvasModel 本地预览画面模型
- (void)setupLocalPreviewWithCanvasModel:(PLVBRTCVideoViewCanvasModel *)canvasModel;

/// 开始 本地麦克风、摄像头画面预览
///
/// @note 将根据 [micDefaultOpen]、[cameraDefaultOpen]、[cameraDefaultFront] 三项默认值，进行硬件启动；
- (void)startLocalMicCameraPreviewByDefault;

/// 加入 RTC频道
///
/// @note 调用必需先行调用 [updateRTCTokenWith:completion:] 进行RTCToken更新；
///       成功加入将收到 [plvRTCStreamerManager:localUserJoinRTCChannelComplete:] 回调；
///
/// @param userRTCId 用户RTCId
///
/// @return 执行结果 (0: 成功；<0: 失败)
- (int)joinRTCChannelWithUserRTCId:(NSString *)userRTCId;

/// 退出 RTC频道
///
/// @note 成功加入将收到 [plvRTCStreamerManager:localUserLeaveRTCChannelComplete:] 回调
///
/// @return 执行结果 (0: 成功；<0: 失败)
- (int)leaveRTCChannel;

/// 角色切换
///
/// @note 主播：将发布本地流；观众：将停止发布本地流；
///
/// @param roleType 需切换至的 ’角色类型‘
- (void)switchRoleTypeTo:(PLVBLinkMicRoleType)roleType;

#pragma mark 流管理
/// 配置 流宽高比
///
/// @param streamScale 流宽高比
- (void)setupStreamScale:(PLVBLinkMicStreamScale)streamScale;

/// 配置 流清晰度
///
/// @param streamQuality 流清晰度，当推流模版开关开启时，根据枚举值自动使用模板
- (void)setupStreamQuality:(PLVBLinkMicStreamQuality)streamQuality;

/// 配置推流模版中的推流质量等级
/// @param streamQualityLevel 推流质量等级，只有推流模版开关开启时有效，根据推流模版中的 推流质量等级匹配
- (void)setupStreamQualityLevel:(NSString *)streamQualityLevel;

/// 配置 本地视频流 的镜像类型
///
/// @note 该方法仅影响 远端用户观看本地视频流画面的镜像效果，而不影响本地预览画面的镜像效果
///
/// @param mirrorMode 本地视频流的镜像类型 (默认值:PLVBRTCVideoMirrorMode_Disabled)
- (void)setupLocalVideoStreamMirrorMode:(PLVBRTCVideoMirrorMode)mirrorMode;

/// 配置视频流画质偏好
- (void)setupVideoQosPreference:(PLVBRTCVideoQosPreference)qosPreference;

/// 配置 混流用户顺序列表
///
/// @param mixUserList 混流用户顺序列表
- (void)setupMixUserList:(NSArray <PLVRTCStreamerMixUser *>*)mixUserList;

/// 切换推送流的源类型
///
/// @note 切换用户推流的源类型 摄像头或屏幕流；
///       在切换至 PLVBRTCStreamSourceType_Screen(屏幕流) 之前，请确认已经调用过[setupAppGroup:rtcType:]方法
///
/// @param streamSourceType 流的源类型(默认为:PLVBRTCStreamSourceType_Camera)
- (void)switchLocalUserStreamSourceType:(PLVBRTCStreamSourceType)streamSourceType;

- (void)subscribeStreamWithRTCUserId:(NSString *)rtcUserId renderOnView:(UIView *)renderSuperView mediaType:(PLVBRTCSubscribeStreamMediaType)mediaType;

- (void)unsubscribeStreamWithRTCUserId:(NSString *)rtcUserId;

#pragma mark CDN流管理
/// 开始推流
///
/// @note 将触发 [plvRTCStreamerManager:pushStreamStartedDidChanged:] 回调，可获知推流是否成功
///
/// @param stream 流名
/// @param rtmpUrl 推流地址
/// @param isContinue 是否恢复上次未结束的直播（该值如果为YES 表示该场直播延续上次的直播 sessionId会与上场直播相同）
- (void)startPushStreamWithStream:(NSString *)stream rtmpUrl:(NSString *)rtmpUrl continueLastLive:(BOOL)isContinue;

/// 停止推流
- (void)stopPushStream;

/// 配置 混流布局模式
///
/// @param mixLayoutType 混流布局模式
- (void)setupMixLayoutType:(PLVRTCStreamerMixLayoutType)mixLayoutType;

#pragma mark 本地硬件管理
/// 配置 本地视频预览画面 的镜像类型
///
/// @param mirrorMode 本地视频预览画面的镜像类型 (默认值:PLVBRTCVideoMirrorMode_Auto)
- (void)setupLocalVideoPreviewMirrorMode:(PLVBRTCVideoMirrorMode)mirrorMode;

/// 切换 本地用户 的前后置摄像头
///
/// @param frontCamera 切换为 前置或后置 摄像头 (YES:前置；NO:后置)
- (void)switchLocalUserCamera:(BOOL)frontCamera;

/// 开启或关闭 本地用户 的闪光灯
///
/// @param openCameraTorch 开启或关闭 闪光灯 (YES:开启；NO:关闭)
- (void)openLocalUserCameraTorch:(BOOL)openCameraTorch;

/// 开启或关闭 本地用户 的摄像头
///
/// @note 开启：采集数据、渲染预览、取消停止本地视频流推送；关闭：停止采集数据、停止渲染预览、停止本地视频流推送；
///       将触发RTC房间内其他成员，收到回调；
///
/// @param openCamera 开启或关闭 摄像头 (YES:开启；NO:关闭)
- (void)openLocalUserCamera:(BOOL)openCamera completion:(nullable void (^)(int openResult))completion;

/// 开启或关闭 本地用户 的麦克风
///
/// @note 开启：采集数据、取消停止本地音频流推送；关闭：停止采集数据、停止本地音频流推送；
///       将触发RTC房间内其他成员，收到回调；
///
/// @param openMic 开启或关闭 麦克风 (YES:开启；NO:关闭)
- (void)openLocalUserMic:(BOOL)openMic;

/// 设置摄像头的变焦倍数
/// @param zoomRatio zoomRatio 变焦
- (void)setCameraZoomRatio:(CGFloat)zoomRatio;

/// 获取摄像头的变焦倍数
- (CGFloat)getCameraZoomRatio;

/// 获取摄像头的最大变焦倍数
- (CGFloat)getMaxCameraZoomRatio;

#pragma mark 连麦事件管理
/// 开启或关闭 ”视频连麦“，新版策略下表示开启或关闭观众端”视频连麦“举手
///
/// @param open 开启或关闭
/// @param emitCompleteBlock 开启或关闭 ”视频连麦“ 的请求发送结果Block
- (void)openVideoLinkMic:(BOOL)open emitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

/// 开启或关闭 ”音频连麦“，新版策略下表示开启或关闭观众端”音频连麦“举手
///
/// @param open 开启或关闭
/// @param emitCompleteBlock 开启或关闭 ”音频连麦“ 的请求发送结果Block
- (void)openAudioLinkMic:(BOOL)open emitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

/// 关闭 “连麦功能” ，新版策略表示关闭远端举手
///
/// @note 区别于 [openVideoLinkMic:emitCompleteBlock:]、[openAudioLinkMic:emitCompleteBlock:] 两个方法，该方法内部自行判断当前连麦类型，去执行“关闭连麦”的操作；
///
/// @param emitCompleteBlock 关闭 “连麦功能” 的请求发送结果Block
- (void)closeLinkMicEmitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

/// 将所有观众下麦
- (BOOL)removeAllAudiences;

#pragma mark 连麦用户管理
/// 允许远端用户上麦
///
/// @note 该方法仅面向 ‘远端用户’；若操作 ‘本地用户’，该方法将调用失败并回调 NO；
///
/// @param userDict 用户数据字典
/// @param emitCompleteBlock 允许用户上麦 的请求发送结果Block
- (void)allowRemoteUserJoinLinkMic:(NSDictionary *)userDict emitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

/// 允许远端用户上麦 (兼容有’举手‘概念的用户)
///
/// @note 该方法仅面向 ‘远端用户’；若操作 ‘本地用户’，该方法将调用失败并回调 NO；
///
/// @param userDict 用户数据字典
/// @param raiseHand 用户当前是否举手 (传nil表示不携带相关字段；@"0"表示不举手；@"1"表示举手；仅针对部分用户类型生效；无‘举手’概念的用户，可直接使用 [allowRemoteUserJoinLinkMic:emitCompleteBlock:] 方法)
/// @param emitCompleteBlock 允许用户上麦 的请求发送结果Block
- (void)allowRemoteUserJoinLinkMic:(NSDictionary *)userDict raiseHand:(nullable NSString *)raiseHand emitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

/// 挂断远端用户的连麦
///
/// @note 该方法仅面向 ‘远端用户’；若操作 ‘本地用户’，该方法将调用失败并回调 NO；
///
/// @param userDict 用户数据字典
/// @param emitCompleteBlock 挂断远端用户的连麦 的请求发送结果Block
- (void)closeRemoteUserLinkMic:(NSDictionary *)userDict emitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

/// 强制挂断远端用户的连麦
///
/// @note 该方法仅面向 ‘远端用户’；若操作 ‘本地用户’，该方法将调用失败并回调 NO；
///
/// @param userDict 用户数据字典
/// @param emitCompleteBlock 挂断远端用户的连麦 的请求发送结果Block
- (void)forceCloseRemoteUserLinkMic:(NSDictionary *)userDict emitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

/// 禁用或取消禁用 远端用户麦克风
///
/// @note 该方法仅面向 ‘远端用户’；若操作 ‘本地用户’，该方法将调用失败并回调 NO；
///
/// @param userDict 用户数据字典
/// @param muteMic 禁用或取消禁用
/// @param emitCompleteBlock 禁用或取消禁用 远端用户麦克风 的请求发送结果Block
- (void)muteRemoteUserMic:(NSDictionary *)userDict muteMic:(BOOL)muteMic emitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

/// 禁用或取消禁用 远端用户摄像头
///
/// @note 该方法仅面向 ‘远端用户’；若操作 ‘本地用户’，该方法将调用失败并回调 NO；
///       [channelLinkMicMediaType] 为PLVChannelLinkMicMediaType_Audio时 (即’音频连麦‘下)，该方法将调用失败；
///
/// @param userDict 用户数据字典
/// @param muteCamera 禁用或取消禁用
/// @param emitCompleteBlock 禁用或取消禁用 远端用户摄像头 的请求发送结果Block
- (void)muteRemoteUserCamera:(NSDictionary *)userDict muteCamera:(BOOL)muteCamera emitCompleteBlock:(nullable void (^)(BOOL emitSuccess))emitCompleteBlock;

#pragma mark 美颜管理

/// 初始化美颜功能，初始化结果由代理回调给出
- (void)initBeauty;

/// 开启或关闭 美颜处理
/// @param enabled 开启或停止 (YES:开启；NO:关闭)
- (void)enableBeautyProcess:(BOOL)enabled;

/// 获取美颜管理器
- (PLVBeautyManager *)shareBeautyManager;

#pragma mark 降噪管理

- (int)switchNoiseCancellationLevelTo:(PLVBLinkMicNoiseCancellationLevel)level;

#pragma mark 外接设备管理

- (int)enableExternalDevice:(BOOL)enabled;

@end


#pragma mark - [ 代理方法 ]
/// PLVRTCStreamerManager 的 Delegate
@protocol PLVRTCStreamerManagerDelegate <NSObject>

@optional
#pragma mark RTC房间事件
/// 本地用户 加入RTC频道回调
///
/// @param manager RTC 推流管理器
/// @param channelId 频道Id
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager localUserJoinRTCChannelComplete:(NSString *)channelId;

/// 本地用户 退出RTC频道回调
///
/// @param manager RTC 推流管理器
/// @param channelId 频道Id
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager localUserLeaveRTCChannelComplete:(NSString *)channelId;

// 本地用户 强制退出RTC频道回调
///
/// @param manager RTC 推流管理器
/// @param channelId 频道Id
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager localUserLeaveRTCChannelByServerComplete:(NSString *)channelId;

/// sessionId 场次Id发生变化
///
/// @param manager RTC 推流管理器
/// @param sessionId 当前 sessionId
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager sessionIdDidChanged:(NSString *)sessionId;

/// （不推荐使用）本地用户 ’网络状态‘ 发生变化
///
/// @param manager RTC 推流管理器
/// @param networkQuality 当前 ‘网络状态’ 状态值
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager networkQualityDidChanged:(PLVBLinkMicNetworkQuality)networkQuality DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用-plvRTCStreamerManager:localNetworkQualityDidChanged:");

/// 本地用户 ’网络状态‘ 发生变化
///
/// @param manager RTC 推流管理器
/// @param networkQuality 当前 ‘网络状态’ 状态值
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager localNetworkQualityDidChanged:(PLVBRTCNetworkQuality)networkQuality;

/// RTC频道统计信息回调
/// 该回调每间隔2秒抛出一次，只在进入频道后触发
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager rtcStatistics:(PLVRTCStatistics *)statistics;

#pragma mark CDN推流事件
/// ‘是否推流已开始’状态 发生变化
///
/// @param manager RTC 推流管理器
/// @param pushStreamStarted 当前 ‘是否推流已开始’ 状态
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager pushStreamStartedDidChanged:(BOOL)pushStreamStarted;

/// 当前 ’已有效推流时长‘ 定时回调
///
/// @note 仅在属性 [pushStreamStarted] 为 YES 时，每1秒回调通知一次最新值；
///       在即将 清零重置 前，会回调一次 最终的数值，无论此刻是否已间隔足够1秒；
///       在 清零重置 后，也将回调一次；
///
/// @param manager RTC 推流管理器
/// @param pushStreamValidDuration 已有效推流时长 (单位秒，带小数，可精确至毫秒)
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager currentPushStreamValidDuration:(NSTimeInterval)pushStreamValidDuration;

/// 当前 ’单次重连时长‘ 定时回调
///
/// @note 仅在属性 [pushStreamStarted] 为 YES 时，每1秒回调通知一次最新值；
///       在即将 清零重置 前，会回调一次 最终的数值，无论此刻是否已间隔足够1秒；
///       在 清零重置 后，也将回调一次；
///
/// @param manager RTC 推流管理器
/// @param reconnectingThisTimeDuration 单次重连时长 (单位秒，带小数，可精确至毫秒)
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager currentReconnectingThisTimeDuration:(NSInteger)reconnectingThisTimeDuration;

/// 更新 混流布局 失败回调
///
/// @param manager RTC 推流管理器
/// @param type 当前混流布局
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager updateMixLayoutDidOccurError:(PLVRTCStreamerMixLayoutType)type;

#pragma mark 本地用户硬件事件
/// 本地声音监测回调
///
/// @param manager 连麦管理器
/// @param localVoiceValue 本地声音音量值；取值范围为 0.0 ~ 1.0
/// @param voiceAudible 是否接收到本地可听得见的声音（以 localVoiceValue 是否大于 0.156 为准；若需以其他值为准，可自行根据 localVoiceValue 作判断）
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager localVoiceValue:(CGFloat)localVoiceValue receivedLocalAudibleVoice:(BOOL)voiceAudible;

#pragma mark 远端用户事件
/// 远端用户 加入RTC频道回调
///
/// @param manager RTC 推流管理器
/// @param uid 远端用户id
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager didJoinedOfUid:(NSString *)uid;

/// 远端用户 退出RTC频道回调
///
/// @param manager RTC 推流管理器
/// @param uid 远端用户id
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager didOfflineOfUid:(NSString *)uid;

/// 远端用户 ’音频流禁用状态‘ 发生改变
///
/// @param manager RTC 推流管理器
/// @param userRTCId 远端用户的RTCId
/// @param audioMuted 当前 ’音频流是否禁用‘
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager remoteUser:(NSString *)userRTCId audioMuted:(BOOL)audioMuted;

/// 远端用户 ’视频流禁用状态‘ 发生改变
///
/// @param manager RTC 推流管理器
/// @param userRTCId 远端用户的RTCId
/// @param videoMuted 当前 ’视频流是否禁用‘
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager remoteUser:(NSString *)userRTCId videoMuted:(BOOL)videoMuted;

#pragma mark 全部用户事件
/// 全部连麦成员的音频音量 回调
///
/// @note 该回调的时间间隔约为 100ms~300ms
///
/// @param manager RTC 推流管理器
/// @param volumeDict 连麦成员音量字典 (key:用户连麦ID，value:对应的流的音量值；value取值范围为 0.0 ~ 1.0)
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager reportAudioVolumeOfSpeakers:(NSDictionary<NSString *, NSNumber *> *)volumeDict;

#pragma mark 屏幕共享事件
/// 屏幕采集开启的事件回调
///
/// @param manager RTC 推流管理器
- (void)plvRTCStreamerManagerDidScreenCaptureStarted:(PLVRTCStreamerManager *)manager;

/// 屏幕采集停止的事件回调
///
/// @param manager RTC 推流管理器
/// @param reason 屏幕分享停止的原因
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager didScreenCaptureStopedReason:(PLVBRTCScreenCaptureFinishedReason)reason;

#pragma mark 管理器状态事件
/// 推流管理器 ‘发生错误’ 回调
///
/// @param manager RTC 推流管理器
/// @param error 错误对象 (error.code 对应 PLVRTCStreamerManagerErrorCode 错误码；)
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager didOccurError:(NSError *)error;

#pragma mark 美颜处理事件

/// 美颜初始化回调
/// @param manager RTC 推流管理器
/// @param result 0：初始化成功，其他错误详见错误回调
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager beautyDidInitWithResult:(int)result;

/// 美颜处理错误回调
/// @param manager RTC 推流管理器
/// @param error 错误对象
- (void)plvRTCStreamerManager:(PLVRTCStreamerManager *)manager beautyProcessDidOccurError:(NSError *)error;

@end


NS_ASSUME_NONNULL_END
