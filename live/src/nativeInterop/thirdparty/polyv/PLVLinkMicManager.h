//
//  PLVLinkMicManager.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2020/2/3.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PLVLinkMicGetTokenModel.h"
#import <PLVBusinessSDK/PLVBusinessSDK.h>

NS_ASSUME_NONNULL_BEGIN

/// 连麦场景类型
typedef NS_ENUM(NSInteger, PLVLinkMicSceneType) {
    PLVLinkMicSceneTypeLive       = 1, /// 旧普通直播连麦
    PLVLinkMicSceneTypeNormalLive = 2, /// 新普通直播连麦
    PLVLinkMicSceneTypeCloudClass = 3  /// 云课堂连麦
};

@protocol PLVLinkMicManagerDelegate;

/// 连麦管理器
@interface PLVLinkMicManager : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// delegate
@property (nonatomic, weak) id <PLVLinkMicManagerDelegate> delegate;

/// 连麦场景类型
@property (nonatomic, assign) PLVLinkMicSceneType linkMicType;

/// 连麦类型 (YES:音频连麦 NO:视频连麦)
@property (nonatomic, assign) BOOL linkMicOnAudio;

/// 本地用户是否为参与者
@property (nonatomic, assign) BOOL viewer;

/// 参与者 是否被允许上麦
@property (nonatomic, assign) BOOL viewerAllow;

/// 麦克风 是否默认开启
///
/// @note 仅在 [joinRtcChannelWithChannelId:] 方法调用前设置有效
///       YES:开启 NO:关闭；默认值 YES
@property (nonatomic, assign) BOOL micDefaultOpen;

/// 摄像头 是否默认开启
///
/// @note 仅在 [joinRtcChannelWithChannelId:] 方法调用前设置有效
///       YES:开启 NO:关闭；默认值 NO
@property (nonatomic, assign) BOOL cameraDefaultOpen;

/// 摄像头 是否默认前置
///
/// @note 仅在 [joinRtcChannelWithChannelId:] 方法调用前设置有效
///       YES:前置 NO:后置；默认值 YES
@property (nonatomic, assign) BOOL cameraDefaultFront;

/// [重连时间] 单次重连时长
///
/// @note 单位秒，带小数，可精确至毫秒；
///       一次连麦中，可能有多次重连，此属性为 单次重连时长；
@property (nonatomic, assign, readonly) NSTimeInterval reconnectingThisTimeDuration;

/// [重连时间] 全部重连累计时长
///
/// @note 单位秒，带小数，可精确至毫秒；
///       一次连麦中，可能有多次重连，此属性为 全部重连累计时长（包括当前此刻，无论是否 ’重连中‘ 或 ’重连结束‘）；
@property (nonatomic, assign, readonly) NSTimeInterval reconnectingTotalDuration;

/// 当前 流清晰度 (默认值:PLVBLinkMicStreamQuality180P)
@property (nonatomic, assign, readonly) PLVBLinkMicStreamQuality streamQuality;

/// 连麦时视频流宽高比 (默认值:PLVBLinkMicStreamScale16_9)
/// @note 仅支持在连麦前配置
@property (nonatomic, assign) PLVBLinkMicStreamScale streamScale;

#pragma mark 基础信息
/// 频道号ID(房间号)
@property (nonatomic, copy, readonly) NSString * channelId;

/// 本地用户(自己)连麦ID
@property (nonatomic, copy, readonly) NSString * userLinkMicId;

#pragma mark 状态相关
/// 当前是否已加入RTC频道
@property (nonatomic, assign, readonly) BOOL hadJoinedRTC;

/// 当前 本地用户网络状态
@property (nonatomic, assign, readonly) PLVBLinkMicNetworkQuality networkQuality;

/// 当前 已订阅远端流是否需要被禁用 (“禁用”指本地音视频；该值仅部分RTC类型下有意义）
@property (nonatomic, assign, readonly) BOOL subscribedRemoteStreamNeedMute;

#pragma mark - [ 方法 ]
/// 创建连麦管理器
///
/// @note 由外部根据频道信息获取到rtc类型值，并在调用此方法时传入；若传入的rtcType值无效，将创建失败，并返回 nil。
///
/// @param rtcType rtc类型值
+ (instancetype)linkMicManagerWithRTCType:(NSString *)rtcType;


/// 更新互动学堂 RTC Token
///
/// @note 目前不支持声网，声网token过期会自动调用'-updateLinkMicTokenWith:completion:'更新token
///
/// @param model 连麦GetToken模型
/// @param completion 更新完成回调
- (void)updateVClassRTCTokenWith:(PLVLinkMicGetTokenModel *)model completion:(nullable void (^)(BOOL updateResult))completion;

/// 更新连麦Token
///
/// @note 加入RTC连麦频道前，必须调用此方法更新连麦Token。更新完成将通过 [completion:] 进行回调。
///       若回调 NO 则表示更新失败，此时不允许加入RTC连麦频道，调用 [joinRtcChannelWithChannelId:] 将失败。
///
/// @param model 更新连麦Token所需数据模型
/// @param completion 更新完成回调 (YES: 更新成功， NO: 更新失败)
- (void)updateLinkMicTokenWith:(PLVLinkMicGetTokenModel *)model completion:(nullable void (^)(BOOL updateResult))completion;

/// 加入RTC连麦频道
///
/// @note 成功加入将收到 [joinRTCChannelComplete] 回调；调用该方法，将立刻收到返回的 int 值, 小于0表示失败，等于0表示成功。
///
/// @param channelId 频道号ID
/// @param userLinkMicId 用户连麦ID
- (int)joinRtcChannelWithChannelId:(NSString *)channelId userLinkMicId:(NSString *)userLinkMicId;

/// 退出RTC连麦频道
///
/// @note 退出RTC连麦频道，成功退出将收到 [leaveRTCChannelComplete:] 回调；
- (void)leaveRtcChannel;

/// 配置讲师连麦ID，用于讲师连麦ID不为频道号时
- (void)setTeacherUserId:(NSString *)teacherId;

/// 角色切换
- (void)switchClientRoleTo:(PLVBLinkMicRoleType)role;

/// 添加RTC画面
- (void)subscribeStreamWithRTCUserId:(NSString *)rtcUserId renderOnView:(UIView *)renderSuperView mediaType:(PLVBRTCSubscribeStreamMediaType)mediaType;

/// 根据流订阅方式 添加RTC画面
- (void)subscribeStreamWithRTCUserId:(NSString *)rtcUserId renderOnView:(UIView *)renderSuperView mediaType:(PLVBRTCSubscribeStreamMediaType)mediaType subscribeMode:(PLVBRTCSubscribeStreamSubscribeMode)subscribeMode;

/// 将某位用户的流渲染 进行移除
- (void)unsubscribeStreamWithRTCUserId:(NSString *)rtcUserId;

/// 根据流订阅方式 将某位用户的流渲染 进行移除
- (void)unsubscribeStreamWithRTCUserId:(NSString *)rtcUserId subscribeMode:(PLVBRTCSubscribeStreamSubscribeMode)subscribeMode;

- (void)switchSubscribeStreamMediaTypeWithRTCUserId:(NSString *)rtcUserId mediaType:(PLVBRTCSubscribeStreamMediaType)toMediaType;

/// 禁用或启用 全部已订阅远端流 的音视频
///
/// @note 仅在部分RTC类型下生效；
///       调用后，将改变 [subscribedRemoteStreamNeedMute] 值；未来有新流被订阅时，也将根据 [subscribedRemoteStreamNeedMute] 值同步生效处理；
///       该操作为本地操作，不会触发RTC房间内其他成员收到回调；
///
/// @param mute 禁用或启用
- (void)muteSubscribedRemoteStreamInLocalWithMute:(BOOL)mute;

/// 连麦的本地观众用户第一画面发生改变
- (void)linkMicLocalUserFirstScreenDidChanged:(BOOL)firstScreen;

/// 检测当前连麦状态
+ (void)requestLinkMicStatusWithChannelId:(NSString *)channelId
                               completion:(void (^)(NSString *status, NSString *type))completion
                                  failure:(void (^)(NSError *))failure;

#pragma mark 本地硬件管理

/// 配置 本地视频预览画面 的镜像类型
///
/// @param mirrorMode 本地视频预览画面的镜像类型 (默认值:PLVBRTCVideoMirrorMode_Auto)
- (void)setupLocalVideoPreviewMirrorMode:(PLVBRTCVideoMirrorMode)mirrorMode;

/// 切换 本地用户 的前后置摄像头
///
/// @param frontCamera 切换为 前置或后置 摄像头 (YES:前置；NO:后置)
- (void)switchLocalUserCamera:(BOOL)frontCamera;

/// 开启或关闭 本地用户 的摄像头
///
/// @note 开启：采集数据、渲染预览、取消停止本地视频流推送；关闭：停止采集数据、停止渲染预览、停止本地视频流推送；
///       将触发RTC房间内其他成员，收到回调；
///
/// @param openCamera 开启或关闭 摄像头 (YES:开启；NO:关闭)
- (void)openLocalUserCamera:(BOOL)openCamera;

/// 开启或关闭 本地用户 的麦克风
///
/// @note 开启：采集数据、取消停止本地音频流推送；关闭：停止采集数据、停止本地音频流推送；
///       将触发RTC房间内其他成员，收到回调；
///
/// @param openMic 开启或关闭 麦克风 (YES:开启；NO:关闭)
- (void)openLocalUserMic:(BOOL)openMic;

#pragma mark 远端连麦用户管理

/// 允许远端用户上麦
///
/// @note 该方法 仅用于互动学堂 及 仅面向 ‘远端用户’。
/// @param userDict 用户数据字典
/// @param needAnswer 是否需要答复（主动操作上麦为YES，被动操作上麦为NO）
/// @param completedBlock 请求发送结果Block
- (void)joinResponseWithRemoteUserDict:(NSDictionary *)userDict
                            needAnswer:(BOOL)needAnswer
                             completed:(void (^)(BOOL success))completedBlock;

/// 挂断远端用户的连麦
///
/// @note 目前仅用于挂断视频连麦
///
/// @param userId 连麦用户ID
/// @param completedBlock 请求发送结果Block
- (void)closeLinkMicWithRemoteUserId:(NSString *)userId completed:(void (^ _Nullable)(BOOL success))completedBlock;

/// 禁用或取消禁用‘远端用户麦克风’
///
/// @note 该方法 仅用于互动学堂 及 仅面向 ‘远端用户’。
///
/// @param userId 用户ID
/// @param mute YES-禁用;NO-取消禁用
/// @param completedBlock 请求发送结果Block
- (void)muteMicrophoneWithRemoteUserId:(NSString *)userId mute:(BOOL)mute completed:(void (^ _Nullable)(BOOL success))completedBlock;

/// 禁用或取消禁用‘远端用户摄像头’
///
/// @note 该方法 仅用于互动学堂 及 仅面向 ‘远端用户’。
///
/// @param userId 用户ID
/// @param mute YES-禁用;NO-取消禁用
/// @param completedBlock 请求发送结果Block
- (void)muteCameraWithRemoteUserId:(NSString *)userId mute:(BOOL)mute completed:(void (^ _Nullable)(BOOL success))completedBlock;

#pragma mark 流管理

/// 配置 流清晰度
/// @note 该方法 仅用于互动学堂 及 仅面向 ‘远端用户’。
///
/// @param streamQuality 流清晰度
- (void)setupStreamQuality:(PLVBLinkMicStreamQuality)streamQuality;

@end

@protocol PLVLinkMicManagerDelegate <NSObject>

@optional

#pragma mark 本地用户（自己）事件回调
/// 本地用户 加入RTC频道成功回调
///
/// @param manager 连麦管理器
/// @param channelID 加入频道ID
/// @param uid 当前加入RTC用户的RTCId
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager joinRTCChannelComplete:(NSString * _Nonnull)channelID uid:(NSString *)uid;

/// 本地用户 加入RTC频道失败回调
///
/// @note 目前只对 UCloud 生效
///
/// @param manager 连麦管理器
/// @param channelID 加入频道ID
/// @param uid 当前加入RTC用户的RTCId
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager joinRTCChannelFailure:(NSString * _Nonnull)channelID uid:(NSString *)uid;

/// 本地用户 退出RTC频道回调
///
/// @param manager 连麦管理器
/// @param channelID 退出频道ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager leaveRTCChannelComplete:(NSString * _Nonnull)channelID;

/// 本地用户 连麦错误发生回调
///
/// @note 若自动退出RTC频道，则会触发 [leaveRTCChannelComplete:] 回调
///
/// @param manager 连麦管理器
/// @param errorCode 错误码
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didOccurError:(NSInteger)errorCode;

/// 本地用户 ’网络状态‘ 发生变化
///
/// @param manager 连麦管理器
/// @param networkQuality 当前 ‘网络状态’ 状态值
- (void)plvLinkMicManager:(PLVLinkMicManager *)manager networkQualityDidChanged:(PLVBLinkMicNetworkQuality)networkQuality;

/// 本地用户 ’连麦状态‘ 发生变化
///
/// @param manager 连麦管理器
/// @param connectionState 当前 ‘连麦状态’ 状态值
- (void)plvLinkMicManager:(PLVLinkMicManager *)manager rtcConnectionStateDidChanged:(PLVBLinkMicConnectionStateType)connectionState;

/// 当前 ’单次重连时长‘ 定时回调
///
/// @note 仅在属性 [hadJoinedRTC] 为 YES 时，每1秒回调通知一次最新值；
///       在即将 清零重置 前，会回调一次 最终的数值，无论此刻是否已间隔足够1秒；
///       在 清零重置 后，也将回调一次；
/// @param manager 连麦管理器
/// @param reconnectingThisTimeDuration 单次重连时长 (单位秒，带小数，可精确至毫秒)
- (void)plvLinkMicManager:(PLVLinkMicManager *)manager currentReconnectingThisTimeDuration:(NSInteger)reconnectingThisTimeDuration;

#pragma mark 远端用户（别人）事件回调
/// 远端用户 加入RTC频道回调
///
/// @param manager 连麦管理器
/// @param uid 远端用户id
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didJoinedOfUid:(NSString *)uid;

/// 远端用户 退出RTC频道回调
///
/// @param manager 连麦管理器
/// @param uid 远端用户id
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didOfflineOfUid:(NSString *)uid;

/// 远端用户 音频流禁止状态更新回调
///
/// @param manager 连麦管理器
/// @param muted 音频流是否禁止
/// @param uid 禁止状态更新的用户连麦ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didAudioMuted:(BOOL)muted byUid:(NSString *)uid;

/// 远端用户 视频流禁止状态更新回调
///
/// @param manager 连麦管理器
/// @param muted 视频流是否禁止
/// @param uid 禁止状态更新的用户连麦ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didVideoMuted:(BOOL)muted byUid:(NSString *)uid;

/// 远端用户 音频流 ‘mute状态’ 更新回调
///
/// @param manager 连麦管理器
/// @param muted 音频流是否mute
/// @param streamSourceType 流的源类型
/// @param uid mute状态更新对应的用户连麦ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didAudioMuted:(BOOL)muted streamSourceType:(PLVBRTCSubscribeStreamSourceType)streamSourceType byUid:(NSString *)uid;

/// 远端用户 视频流 ‘mute状态’ 更新回调
///
/// @param manager 连麦管理器
/// @param muted 视频流是否mute
/// @param streamSourceType 流的源类型
/// @param uid mute状态更新的用户连麦ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didVideoMuted:(BOOL)muted streamSourceType:(PLVBRTCSubscribeStreamSourceType)streamSourceType byUid:(NSString *)uid;

/// 远端用户 可订阅流加入
///
/// @note 目前只对 UCloud 生效
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didNewStreamJoinRoomOfUid:(NSString *)uid;

/// 远端用户 流加入房间 回调
///
/// @param manager 连麦管理器
/// @param streamSourceType 流的源类型
/// @param userRTCId 流所属的用户连麦ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager streamJoinRoom:(PLVBRTCSubscribeStreamSourceType)streamSourceType userRTCId:(NSString *)userRTCId;

/// 远端用户 流离开房间 回调
///
/// @note 已订阅过的流离开房间，才会触发此回调；未曾订阅过的流离开房间，不触发此回调；
///
/// @param manager 连麦管理器
/// @param streamSourceType 流的源类型
/// @param userRTCId 流所属的用户连麦ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager streamLeaveRoom:(PLVBRTCSubscribeStreamSourceType)streamSourceType userRTCId:(NSString *)userRTCId;

#pragma mark 通用(自己、别人) 事件回调
/// 远端用户 全部流已退出房间
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager remoteUserTotalStreamsDidLeaveRoom:(NSString *)uid;

/// 全部连麦成员的音频音量 回调
///
/// @note 该回调的时间间隔约为 100ms~300ms
///
/// @param manager 连麦管理器
/// @param volumeDict 连麦成员音量字典 (key:用户连麦ID，value:对应的流的音量值；value取值范围为 0.0 ~ 1.0)
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager reportAudioVolumeOfSpeakers:(NSDictionary<NSString *, NSNumber *> * _Nonnull)volumeDict;

/// RTC频道内某位用户 ‘网络状态’ 发生改变回调
///
/// @param manager 连麦管理器
/// @param userRTCId 当前回调对应的用户RTCId
/// @param txQuality 该用户的上行网络状态
/// @param rxQuality 该用户的下行网络状态
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager userNetworkQualityDidChanged:(NSString *)userRTCId txQuality:(PLVBLinkMicNetworkQuality)txQuality rxQuality:(PLVBLinkMicNetworkQuality)rxQuality;

/// 全部远端用户上行时延回调
///
/// @note 该回调的时间间隔约为 100ms~300ms
///
/// @param manager 连麦管理器
/// @param rttDict 上行时延字典(key：用户连麦ID，value：时延 单位毫秒)
- (void)plvLinkMicManager:(PLVLinkMicManager *)manager userRttDict:(NSDictionary <NSString *, NSNumber *> *)rttDict;

@end

NS_ASSUME_NONNULL_END
