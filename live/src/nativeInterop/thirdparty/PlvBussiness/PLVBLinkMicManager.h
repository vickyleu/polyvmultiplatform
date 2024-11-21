//
//  PLVBLinkMicManager.h
//  PLVBusinessSDK
//
//  Created by Lincal on 2020/3/20.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PLVBRTCDefine.h"
#import "PLVBRTCStatistics.h"
#import "PLVBRTCVideoViewCanvasModel.h"
#import "PLVBRTCVideoEncoderConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PLVBLinkMicManagerDelegate;

/// RTC管理器
///
/// @note 负责支持 连麦、RTC推流 的功能模块
@interface PLVBLinkMicManager : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// 代理
@property (nonatomic, weak) id <PLVBLinkMicManagerDelegate> delegate;

#pragma mark 数据
/// RTC频道Id (房间Id)
@property (nonatomic, copy, readonly) NSString * channelId;
/// 本地用户的RTCId
@property (nonatomic, copy, readonly) NSString * userLinkMicId;
/// RTC类型
@property (nonatomic, assign, readonly) PLVBLinkMicRTCType rtcType;
/// AppGroup
@property (nonatomic, copy, readonly) NSString * appGroup;
/// 当前 本地预览画面的画布模型
///
/// @note 只读，仅可通过 [setupLocalPreviewWithCanvasModel:] 方法进行配置；
///       读取后，对此 currentLocalPreviewCanvasModel 中的属性作修改不会生效；
///       若希望修改 本地预览画面的画布模型 的属性，且生效。请重新调用 [setupLocalPreviewWithCanvasModel:] 方法；
@property (nonatomic, strong, readonly) PLVBRTCVideoViewCanvasModel * currentLocalPreviewCanvasModel;
/// 当前 视频编码配置模型
@property (nonatomic, strong, readonly) PLVBRTCVideoEncoderConfiguration * currentVideoEncoderConfiguration;

#pragma mark 状态
/// 当前 引擎是否已就绪
@property (nonatomic, assign, readonly) BOOL engineIsReady;
/// 当前 rtcToken 是否可用
@property (nonatomic, assign, readonly) BOOL rtcTokenAvailable;
/// 当前 是否已加入rtc频道
@property (nonatomic, assign, readonly) BOOL hadJoinedRTC;
/// 当前 网络状态
@property (nonatomic, assign, readonly) PLVBLinkMicNetworkQuality networkQuality DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用localNetworkQuality");
/// 当前 网络状态
@property (nonatomic, assign, readonly) PLVBRTCNetworkQuality localNetworkQuality;
/// 当前 RTC频道 连接状态
@property (nonatomic, assign, readonly) PLVBLinkMicConnectionStateType connectionState;
/// 当前 用户角色
@property (nonatomic, assign, readonly) PLVBLinkMicRoleType roleType;
/// 当前 是否正在推流至cdn
@property (nonatomic, assign, readonly) BOOL streamPublishing;
/// 当前 已订阅远端流是否需要被禁用 (“禁用”指本地音视频；该值仅部分RTC类型下有意义）
@property (nonatomic, assign, readonly) BOOL subscribedRemoteStreamNeedMute;
/// 当前 是否已开启了屏幕采集
@property (nonatomic, assign, readonly) BOOL screenCaptureStarted;

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
/// 当前 本地视频流占位图 是否开启
@property (nonatomic, assign, readonly) BOOL localVideoStreamPlaceholderOpen;
/// 当前 本地视频数据采集 是否开启
@property (nonatomic, assign, readonly) BOOL localVideoEnable;

/// 当前 本地麦克风 音量
@property (nonatomic, assign, readonly) CGFloat localMicVolume;
/// 当前 本地麦克风 是否开启
@property (nonatomic, assign, readonly) BOOL localMicOpen;
/// 当前 本地音频数据采集 是否开启
@property (nonatomic, assign, readonly) BOOL localAudioEnable;
/// 当前 本地音频流 是否停止推送
@property (nonatomic, assign, readonly) BOOL localAudioStreamMute;
/// 当前 本地音频流 降噪等级，默认为PLVBLinkMicNoiseCancellationLevelAggressive，突出人声
@property (nonatomic, assign, readonly) PLVBLinkMicNoiseCancellationLevel localNoiseCancellationLevel;
/// 当前 支持外接设备 是否开启，默认关闭
@property (nonatomic, assign, readonly) BOOL localExternalDeviceEnabled;

#pragma mark 流相关
@property (nonatomic, assign, readonly) NSUInteger videoCDNWidth;
@property (nonatomic, assign, readonly) NSUInteger videoCDNHeight;
/// 当前 推流的源类型
@property (nonatomic, assign, readonly) PLVBRTCStreamSourceType publishStreamSourceType;

#pragma mark 渲染相关
/// opengl上下文
@property (nonatomic, strong, readonly) EAGLContext *eaglContext;


#pragma mark - [ 方法 ]
#pragma mark 基础调用
/// 创建 RTC管理器
///
/// @note 由外部根据频道信息获取到rtc类型值，并在调用此方法时传入；
///       若传入的rtcType值无效，将创建失败，并返回 nil。
///
/// @param rtcType rtc类型值
+ (instancetype)linkMicManagerWithRTCType:(NSString *)rtcType;

/// 设置AppGroup和rtcType，屏幕共享功能需要使用该方法
///
/// @note 由外部根据频道信息获取到rtc类型值，同时用户自己生成AppGroup传入；
///       若AppGroup 或 rtcType 为 nil，则设置失败，此时无法开启屏幕共享
/// @param appGroup appGroup名 一般为 "group." 开头
/// @param rtcType rtc类型值
- (void)setupAppGroup:(NSString *)appGroup rtcType:(NSString *)rtcType;

/// 更新 RTC Token
///
/// @note 加入RTC连麦频道前，必须调用此方法更新连麦Token。
///       调用该方法，将立刻收到返回的 int 值，小于0表示更新失败 (失败原因可见打印)，此时不允许加入RTC连麦频道，调用 [joinRtcChannelWithChannelId:] 将失败；等于0表示成功。
///
/// @param linkMicStr 连麦信息字符串
- (int)updateLinkMicTokenWithStr:(NSString *)linkMicStr;

/// 创建 RTC引擎
- (void)createRTCEngine;

/// 销毁 RTC引擎
- (void)destroyRTCEngine;

/// 加入 RTC房间
- (int)joinRtcChannelWithChannelId:(NSString *)channelId userLinkMicId:(NSString *)userLinkMicId;

/// 退出 RTC频道
- (int)leaveRtcChannel;

/// 将某位用户的流渲染于视图中
///
/// @param rtcUserId 用户RTCId
/// @param renderSuperView 承载渲染的父视图
/// @param mediaType 订阅的流的媒体类型 (支持组合)
- (void)subscribeStreamWithRTCUserId:(NSString *)rtcUserId renderOnView:(UIView *)renderSuperView mediaType:(PLVBRTCSubscribeStreamMediaType)mediaType;

/// 根据流订阅方式 将某位用户的流渲染于视图中
///
/// @param rtcUserId 用户RTCId
/// @param renderSuperView 承载渲染的父视图
/// @param mediaType 订阅的流的媒体类型 (支持组合)
/// @param subscribeMode 流的订阅方式 (当已使用 PLVBRTCSubscribeStreamSubscribeMode_ScreenFirst_Mix 方式进行订阅时，将不再支持使用其他方式，来继续订阅同个用户的流)
- (void)subscribeStreamWithRTCUserId:(NSString *)rtcUserId renderOnView:(UIView *)renderSuperView mediaType:(PLVBRTCSubscribeStreamMediaType)mediaType subscribeMode:(PLVBRTCSubscribeStreamSubscribeMode)subscribeMode;

/// 将某位用户的流渲染 进行移除
///
/// @note 该方法默认对应 PLVBRTCSubscribeStreamSubscribeMode_ScreenFirst_Mix 混合流订阅方式
///
/// @param rtcUserId 用户RTCId
- (void)unsubscribeStreamWithRTCUserId:(NSString *)rtcUserId;

/// 根据流订阅方式 将某位用户的流渲染 进行移除
///
/// @param rtcUserId 用户RTCId
/// @param subscribeMode 流的订阅方式
- (void)unsubscribeStreamWithRTCUserId:(NSString *)rtcUserId subscribeMode:(PLVBRTCSubscribeStreamSubscribeMode)subscribeMode;

- (void)switchSubscribeStreamMediaTypeWithRTCUserId:(NSString *)rtcUserId mediaType:(PLVBRTCSubscribeStreamMediaType)toMediaType;

/// 切换 推送流 的源类型
///
/// @note 在切换至 PLVBRTCStreamSourceType_Screen(屏幕流) 之前，请确认已经调用过[setupAppGroup:rtcType:]方法
/// @param streamSourceType 流的源类型
- (void)switchPublishStreamSourceType:(PLVBRTCStreamSourceType)streamSourceType;

/// 禁用或启用 全部已订阅远端流 的音视频
///
/// @note 仅在部分RTC类型下生效；
///       调用后，将改变 [subscribedRemoteStreamNeedMute] 值；未来有新流被订阅时，也将根据 [subscribedRemoteStreamNeedMute] 值同步生效处理；
///       该操作为本地操作，不会触发RTC房间内其他成员收到回调；
///
/// @param mute 禁用或启用
- (void)muteSubscribedRemoteStreamInLocalWithMute:(BOOL)mute;

/// 配置讲师连麦ID，用于讲师连麦ID不为频道号时
- (void)setTeacherUserId:(NSString *)teacherId;

/// 切换用户角色
///
/// @param roleType 需切换至的 ’角色类型‘
- (int)setUserRoleTo:(PLVBLinkMicRoleType)roleType;

#pragma mark 视频管理
/// 配置 视频编码参数
- (void)setupVideoEncoderConfiguration:(PLVBRTCVideoEncoderConfiguration *)videoEncoderConfiguration;

/// 配置本地预览画面
///
/// @note 仅作用于 本地预览画面 的相关属性配置；
///       不自动开始预览，不自动开始推视频流；
- (void)setupLocalPreviewWithCanvasModel:(PLVBRTCVideoViewCanvasModel *)canvasModel;

/// 配置 本地视频预览画面 的镜像类型
///
/// @note 部分RTC类型下，不支持后置摄像头镜像；
///
/// @param mirrorMode 本地视频预览画面的镜像类型 (默认值:PLVBRTCVideoMirrorMode_Auto)
- (int)setupLocalVideoPreviewMirrorMode:(PLVBRTCVideoMirrorMode)mirrorMode;

/// 切换 本地用户 的前后置摄像头
///
/// @param frontCamera 切换为 前置或后置 摄像头 (YES:前置；NO:后置)
- (int)switchLocalUserCamera:(BOOL)frontCamera;

/// 开启或关闭 本地用户 的闪光灯
///
/// @param openCameraTorch 开启或关闭 闪光灯 (YES:开启；NO:关闭)
- (int)openLocalUserCameraTorch:(BOOL)openCameraTorch;

/// 开启或关闭 本地用户 的摄像头
///
/// @note 开启：采集数据、渲染预览、取消停止本地视频流推送；关闭：停止采集数据、停止渲染预览、停止本地视频流推送；
///       将触发RTC房间内其他成员，收到回调；推荐直接使用该方法；
///
/// @param openCamera 开启或关闭 摄像头 (YES:开启；NO:关闭)
- (int)openLocalUserCamera:(BOOL)openCamera;

/// 本地视频流 开启或关闭 占位图
///
/// @param openPlaceholder 开启或关闭 占位图 (YES:开启；NO:关闭)
- (int)localVideoStreamOpenPlaceholder:(BOOL)openPlaceholder;

/// 开启或停止 本地摄像头采集
///
/// @note 开启：摄像头采集数据；停止：停止摄像头采集数据
///       该方法 在部分RTC类型下 调用无效；推荐直接使用 [openLocalUserCamera:] 方法
///
/// @param enabled 开启或停止 (YES:开启；NO:停止)
- (int)enableLocalVideo:(BOOL)enabled;

/// 开启或停止 本地摄像头预览
///
/// @note 开启：渲染预览；停止：停止渲染预览
///       该方法 在部分RTC类型下 调用无效；推荐直接使用 [openLocalUserCamera:] 方法
///
/// @param start 开启或停止 (YES:开启；NO:停止)
- (int)startLocalPreview:(BOOL)start;

/// 停止或取消停止 本地视频流 推送
///
/// @note 将触发RTC房间内其 他成员，收到回调；
///       推荐直接使用 [openLocalUserCamera:] 方法
///
/// @param mute 停止或取消停止 本地视频流 (YES:停止；NO:取消停止)
- (int)muteLocalVideoStream:(BOOL)mute;

/// 开启或停止 本地视频数据处理
///
/// @note 开启后，摄像头采集的数据将会通过代理方法回调到外部进行处理
///
/// @param enabled 开启或停止 (YES:开启；NO:停止)
- (void)enableLocalVideoFrameProcess:(BOOL)enabled;

#pragma mark 音频管理
/// 改变 本地麦克风 录入音量
///
/// @note 数值 0 即静音；即使0也不会触发 [muteLocalAudioStream:]
///
/// @param micVolume 麦克风音量值 (0~100)
- (int)changeLocalMicVolume:(CGFloat)micVolume;

/// 开启或关闭 本地用户 的麦克风
///
/// @note 开启：采集数据、取消停止本地音频流推送；关闭：停止采集数据、停止本地音频流推送；
///       将触发RTC房间内其他成员，收到回调；推荐直接使用该方法；
///
/// @param openMic 开启或关闭 麦克风 (YES:开启；NO:关闭)
- (int)openLocalUserMic:(BOOL)openMic;

/// 开启或停止 本地麦克风采集
///
/// @note 开启：麦克风采集数据；停止：停止麦克风采集数据
///       该方法 在部分RTC类型下 调用无效；推荐直接使用 [openLocalUserMic:] 方法；
///
/// @param enabled 开启或停止 (YES:开启；NO:停止)
- (int)enableLocalAudio:(BOOL)enabled;

/// 停止或取消停止 本地音频流 推送
///
/// @note 将触发RTC房间内其他成员，收到回调；
///       该方法 在部分RTC类型下 调用无效；推荐直接使用 [openLocalUserMic:] 方法；
///
/// @param mute 停止或取消停止 本地音频流 (YES:停止；NO:取消停止)
- (int)muteLocalAudioStream:(BOOL)mute;

/// 切换噪声控制等级，默认是PLVBLinkMicNoiseCancellationLevelAggressive
- (int)switchNoiseCancellationLevelTo:(PLVBLinkMicNoiseCancellationLevel)level;

/// 开启或关闭 支持外接设备
///
/// @note 开启:支持媒体音量采集；关闭：自动音量采集
- (int)enableExternalDevice:(BOOL)enabled;

#pragma mark 转推相关
/// 添加推流地址
- (int)addPublishStreamUrl:(NSString *)streamUrl transcodingEnabled:(BOOL)transcodingEnabled;
/// 移除推流地址
- (int)removePublishStreamUrl:(NSString *)streamUrl;
/// 配置推流转码参数
- (void)setupLiveTranscoding;
/// 配置混流参数
- (int)setupLiveTranscodingUser;
/// 配置混流额外信息
- (int)setupLiveTranscodingExtraInfo:(NSString *)extroInfo;
/// 配置推流占位图
- (int)setupLiveBackgroundImage;

@end

#pragma mark - [ 代理方法 ]
/// PLVBLinkMicManager 的 Delegate
@protocol PLVBLinkMicManagerDelegate <NSObject>

@optional

#pragma mark 本地用户(自己) 事件回调

/// 本地用户 加入RTC频道成功
///
/// @param manager 连麦管理器
/// @param channelId 加入频道ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager joinRTCChannelComplete:(NSString * _Nonnull)channelId uid:(NSString *)uid;

/// 本地用户 加入RTC频道失败
///
/// @note 目前只对 UCloud 生效
///
/// @param manager 连麦管理器
/// @param channelId 加入频道ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager joinRTCChannelFailure:(NSString * _Nonnull)channelId uid:(NSString *)uid;

/// 本地用户 退出RTC频道
///
/// @param manager 连麦管理器
/// @param channelId 退出频道ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager leaveRTCChannelComplete:(NSString * _Nonnull)channelId;

/// 本地用户 被强制退出RTC频道
///
/// @param manager 连麦管理器
/// @param channelId 退出频道ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager leaveRTCChannelByServerComplete:(NSString * _Nonnull)channelId;

/// 本地用户 连麦发生错误（若自动退出RTC频道，则会触发 [leaveRTCChannelComplete:] 回调）
///
/// @param manager 连麦管理器
/// @param error 错误对象
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didOccurError:(NSError *)error;

/// 本地RTC连接状态改变
///
/// @param manager 连麦管理器
/// @param connectionState 当前rtc连接状态
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager rtcConnectionStateDidChanged:(PLVBLinkMicConnectionStateType)connectionState;

/// 本地用户 连麦Token过期
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerTokenExpires:(PLVBLinkMicManager * _Nonnull)manager;

/// 进入RTC频道后，适合配置 本地硬件默认值 的时机回调
///
/// @note 进入RTC频道后进行的 ‘本地硬件默认值’ 配置操作调用，都应该参考此回调的时机来进行，否则可能配置无效；
///       即，进入RTC频道后，需要等待此回调触发，才表示此时配置将生效；
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerCanSetupLocalHardwareDefaultState:(PLVBLinkMicManager * _Nonnull)manager;

#pragma mark 本地设备事件回调

/// （不推荐使用）本地用户 ‘网络状态’ 发生改变回调
///
/// @param manager 连麦管理器
/// @param networkQuality 当前网络状态值
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager networkQualityDidChanged:(PLVBLinkMicNetworkQuality)networkQuality DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用-plvbLinkMicManager:localNetworkQualityDidChanged:");

/// 本地用户 ‘网络状态’ 发生改变回调
///
/// @param manager 连麦管理器
/// @param networkQuality 当前网络状态值
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager localNetworkQualityDidChanged:(PLVBRTCNetworkQuality)networkQuality;

/// 本地摄像头准备就绪
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerCameraDidReady:(PLVBLinkMicManager * _Nonnull)manager;

/// 本地视频流（摄像头）关闭回调
///
/// 调用openCamera:completion:方法将触发此回调；仅在前者方法调用‘成功’后，此回调才被调用，并告知最终本地视频流的开关状态；
///
/// @param manager 连麦管理器
/// @param videoMuted 本地视频流是否关闭
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didLocalVideoMuted:(BOOL)videoMuted;

/// 本地声音监测回调
///
/// @param manager 连麦管理器
/// @param localVoiceValue 本地声音音量值；取值范围为 0.0 ~ 1.0
/// @param voiceAudible 是否接收到本地可听得见的声音（以 localVoiceValue 是否大于 0.156 为准；若需以其他值为准，可自行根据 localVoiceValue 作判断）
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager localVoiceValue:(CGFloat)localVoiceValue receivedLocalAudibleVoice:(BOOL)voiceAudible;

#pragma mark 远端用户(别人) 事件回调
/// 远端用户 加入RTC频道
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didJoinedOfUid:(NSString *)uid;

/// 远端用户 退出RTC频道
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didOfflineOfUid:(NSString *)uid;

/// 远端用户 音频流禁止状态更新回调
///
/// @param manager 连麦管理器
/// @param muted 音频流是否禁止
/// @param uid 禁止状态更新的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didAudioMuted:(BOOL)muted byUid:(NSString *)uid;

/// 远端用户 视频流禁止状态更新回调
///
/// @param manager 连麦管理器
/// @param muted 视频流是否禁止
/// @param uid 禁止状态更新的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didVideoMuted:(BOOL)muted byUid:(NSString *)uid;

/// 远端用户 音频流 ‘mute状态’ 更新回调
///
/// @param manager 连麦管理器
/// @param muted 音频流是否mute
/// @param streamSourceType 流的源类型
/// @param uid mute状态更新对应的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didAudioMuted:(BOOL)muted streamSourceType:(PLVBRTCSubscribeStreamSourceType)streamSourceType byUid:(NSString *)uid;

/// 远端用户 视频流 ‘mute状态’ 更新回调
///
/// @param manager 连麦管理器
/// @param muted 视频流是否mute
/// @param streamSourceType 流的源类型
/// @param uid mute状态更新的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didVideoMuted:(BOOL)muted streamSourceType:(PLVBRTCSubscribeStreamSourceType)streamSourceType byUid:(NSString *)uid;

/// 远端用户 可订阅流加入房间
///
/// @note 仅部分RTC类型下会触发该回调；
///
/// @param manager 连麦管理器
/// @param uid 加入房间的可订阅流对应的远端用户uid
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didNewStreamJoinRoomOfUid:(NSString *)uid;

/// 远端用户 流加入房间 回调
///
/// @param manager 连麦管理器
/// @param streamSourceType 流的源类型
/// @param userRTCId 流所属的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager streamJoinRoom:(PLVBRTCSubscribeStreamSourceType)streamSourceType userRTCId:(NSString *)userRTCId;

/// 远端用户 流离开房间 回调
///
/// @note 已订阅过的流离开房间，才会触发此回调；未曾订阅过的流离开房间，不触发此回调；
///
/// @param manager 连麦管理器
/// @param streamSourceType 流的源类型
/// @param userRTCId 流所属的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager streamLeaveRoom:(PLVBRTCSubscribeStreamSourceType)streamSourceType userRTCId:(NSString *)userRTCId;

#pragma mark 通用(自己、别人) 事件回调
/// 远端用户 全部流已退出房间
///
/// @note “全部流已退出房间” 不代表 “远端用户退出房间”
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager remoteUserTotalStreamsDidLeaveRoom:(NSString *)uid;

/// 全部连麦成员的音频音量 回调
///
/// @note 该回调的时间间隔约为 100ms~300ms
///
/// @param manager 连麦管理器
/// @param volumeDict 连麦成员音量字典 (key:用户连麦ID，value:对应的流的音量值；value取值范围为 0.0 ~ 1.0)
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager reportAudioVolumeOfSpeakers:(NSDictionary<NSString *, NSNumber *> * _Nonnull)volumeDict;

///（不推荐使用）RTC频道内某位用户 ‘网络状态’ 发生改变回调
///
/// @param manager 连麦管理器
/// @param userRTCId 当前回调对应的用户RTCId
/// @param txQuality 该用户的上行网络状态
/// @param rxQuality 该用户的下行网络状态
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager userNetworkQualityDidChanged:(NSString *)userRTCId txQuality:(PLVBLinkMicNetworkQuality)txQuality rxQuality:(PLVBLinkMicNetworkQuality)rxQuality DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用-plvbLinkMicManager:networkQualityChangedWithUserId:txQuality:rxQuality:");

/// RTC频道内某位用户 ‘网络状态’ 发生改变回调
///
/// @param manager 连麦管理器
/// @param userRTCId 当前回调对应的用户RTCId
/// @param txQuality 该用户的上行网络状态
/// @param rxQuality 该用户的下行网络状态
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager networkQualityChangedWithUserId:(NSString *)userRTCId txQuality:(PLVBRTCNetworkQuality)txQuality rxQuality:(PLVBRTCNetworkQuality)rxQuality;

/// RTC频道统计信息回调
/// 该回调每间隔2秒抛出一次，只在进入频道后触发
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager rtcStatistics:(PLVBRTCStatistics *)statistics;

/// 全部远端用户上行时延回调
///
/// @note 该回调的时间间隔约为 100ms~300ms
///
/// @param manager 连麦管理器
/// @param rttDict 上行时延字典(key：用户连麦ID，value：时延 单位毫秒)
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager userRttDict:(NSDictionary <NSString *, NSNumber *> *)rttDict;

#pragma mark 推流事件回调
/// 推流到CDN结果
///
/// @param manager 连麦管理器
/// @param sucess 推流结果
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager streamPublishedResult:(BOOL)sucess;

/// CDN推流断流回调
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerStreamUnpublished:(PLVBLinkMicManager * _Nonnull)manager;

#pragma mark 屏幕共享事件回调
/// 屏幕采集开启的事件回调
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerDidScreenCaptureStarted:(PLVBLinkMicManager * _Nonnull)manager;

/// 屏幕采集停止的事件回调
///
/// @param manager 连麦管理器
/// @param reason 屏幕分享停止的原因
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didScreenCaptureStopedReason:(PLVBRTCScreenCaptureFinishedReason)reason;

#pragma mark 特定场景事件回调
/// 特定场景下 获知流权限的回调事件
///
/// @return 约定的流权限
- (NSString *)plvbLinkMicManagerGetUCStreamAuthority:(PLVBLinkMicManager * _Nonnull)manager;


#pragma mark 视频数据回调

/// Texture类型的视频数据回调，用于外部做视频数据处理
///
/// @param manager 连麦管理器
/// @param sourceTextureId 源纹理数据
/// @param sourceFrameWidth 源视频宽度
/// @param sourceFrameHeight 源视频高度
/// @param sourceFrameTimeStamp 源视频帧时间戳，单位毫秒
/// @param processedTextureId 处理后的纹理数据
/// @reture 0:处理成功，非0则使用未经美颜处理的源数据给RTC处理
- (int)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager
captureVideoFrameTextureId:(GLuint)sourceTextureId
          videoFrameWidth:(uint32_t)sourceFrameWidth
         videoFrameHeight:(uint32_t)sourceFrameHeight
      videoFrameTimeStamp:(uint64_t)sourceFrameTimeStamp
processedVideoFrameTextureId:(GLuint)processedTextureId;

@end

NS_ASSUME_NONNULL_END
