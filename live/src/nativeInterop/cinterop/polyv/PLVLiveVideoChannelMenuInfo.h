//
//  PLVLiveVideoChannelMenuInfo.h
//  PLVLiveScenesSDK
//
//  Created by zykhbl(zhangyukun@plv.net) on 2018/7/19.
//  Copyright © 2018年 plv.net. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVFoundationSDK/PLVSafeModel.h>

/// tab子菜单信息
@interface PLVLiveVideoChannelMenu : PLVSafeModel

/// 菜单Id
@property (nonatomic, copy, readonly) NSString *menuId;
/// 菜单类型
@property (nonatomic, copy, readonly) NSString *menuType;
/// 菜单名称
@property (nonatomic, copy, readonly) NSString *name;
/// 菜单内容，html文本，有可能为NSNull
@property (nonatomic, copy, readonly) NSString *content;
/// 菜单显示顺序
@property (nonatomic, copy, readonly) NSNumber *ordered;
/// 菜单是否展示
@property (nonatomic, assign, readonly) BOOL displayEnabled;

@end


/// 频道菜单信息
@interface PLVLiveVideoChannelMenuInfo : PLVSafeModel

/// 直播标题
@property (nonatomic, copy, readonly) NSString *name;
/// 主持人头像
@property (nonatomic, copy, readonly) NSString *coverImage;
/// 主持人
@property (nonatomic, copy, readonly) NSString *publisher;
/// 点赞数
@property (nonatomic, copy, readonly) NSNumber *likes;
/// 观看数
@property (nonatomic, copy, readonly) NSNumber *pageView;
/// 直播时间
@property (nonatomic, copy, readonly) NSString *startTime;
/// 直播状态
@property (nonatomic, copy, readonly) NSString *status;
/// 观看状态
@property (nonatomic, copy, readonly) NSString *watchStatus;
/// 直播间封面图url
@property (nonatomic, copy, readonly) NSString *splashImg;
/// 直播间的观看链接
@property (nonatomic, copy, readonly) NSString *watchUrl;
/// 频道菜单列表
@property (nonatomic, strong, readonly) NSArray<PLVLiveVideoChannelMenu*> *channelMenus;

/// 直播场景
@property (nonatomic, strong, readonly) NSString *scene;
/// 是否有回放视频
@property (nonatomic, assign, readonly) BOOL hasPlayback;
/// 回放开关
@property (nonatomic, strong, readonly) NSString *playBackEnabled;
/// 观众举手示意开关，默认为N 关闭
@property (nonatomic, strong, readonly) NSString *viewerSignalEnabled;
/// 奖励观众奖杯开关，默认为N 关闭
@property (nonatomic, strong, readonly) NSString *awardTrophyEnabled;
/// rtc类型
@property (nonatomic, strong, readonly) NSString *rtcType;
/// 是否还有连麦分钟数
@property (nonatomic, assign, readonly) BOOL pureRtcAvailState;
/// 是否无延迟观看
@property (nonatomic, assign, readonly) BOOL watchNoDelay;
/// 无延迟观看开关 (请以 watchNoDelay 属性为准)
@property (nonatomic, assign, readonly) BOOL pureRtcEnabled;
/// 是否快直播观看 (注意：和watchNoDelay没有联系)
@property (nonatomic, assign, readonly) BOOL watchQuickLive;
/// 快直播观看开关 (请以 watchQuickLive 属性为准)
@property (nonatomic, assign, readonly) BOOL quickLiveEnabled;
/// 是否只订阅第一画面的视频 (若 watchNoDelay 为NO，则此值必为NO)
@property (nonatomic, assign, readonly) BOOL rtcAudioSubEnabled;
/// 是否开启提醒消息功能，默认为N 关闭，开启为Y（开启后，讲师、嘉宾、助教、管理员可使用提醒消息功能）
@property (nonatomic, assign, readonly) BOOL remindEnabled;
/// 频道未开播、回放开关开启、有回放视频、开启聊天重放这四个均满足则为YES，否则为NO
@property (nonatomic, assign) BOOL chatInputDisable;
/// 公共流观看开关(请以 watchPublicStream 属性为准)
@property (nonatomic, assign, readonly) BOOL publicStreamEnabled;
/// 是否公共流观看(注意：和watchNoDelay没有联系)
@property (nonatomic, assign, readonly) BOOL watchPublicStream;
/// 并发限制以聊天室在线人数为准开关，YES为开启 ，NO为关闭 (若 chatRobotEnabled 为YES，则此值必为NO)
@property (nonatomic, assign, readonly) BOOL restrictChatEnabled;
/// 最大同时在线人数 ,<=0表示没有限制，>0表示限制的最大人数
@property (nonatomic, copy, readonly) NSNumber *maxViewer;
/// 虚拟人数设置开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL chatRobotEnabled;
/// 是否开启商品库功能，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL mobileAnchorProductEnabled;
/// 是否开启邀请连麦，YES为开启 ，NO为关闭（邀请上麦开关）
@property (nonatomic, assign, readonly) BOOL inviteAudioEnabled;
/// 最大连麦人数限制
@property (nonatomic, copy, readonly) NSNumber *linkMicLimit;
/// 手机开播分享功能开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL pushSharingEnabled;
/// 观众支持引用回复功能开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL quoteReplyEnabled;
/// 显示申请连麦序号功能开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL showJoinQueueNumberEnabled;
/// 直播间当前语言类型，zh_CN 中文、en英文、follow_browser跟随系统
@property (nonatomic, copy, readonly) NSString *watchLangType;
/// 手机开播默认混流布局 平铺：flatten, 主讲模式：lecture
@property (nonatomic, copy, readonly) NSString *mobileAlonePushMixMode;
/// 讲师后台默认头衔
@property (nonatomic, copy, readonly) NSString *teacherActor;
/// 讲师后台默认昵称
@property (nonatomic, copy, readonly) NSString *teacherNickname;
/// 讲师后台默认设置
@property (nonatomic, strong, readonly) NSDictionary *teacher;
/// 观众PPT翻页开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL viewerPptTurningEnabled;
/// 倍速播放开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL playbackMultiplierEnabled;
/// 进度条开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL playbackProgressBarEnabled;
/// 进度条操作方式，drag 拖动，prohibitDrag 禁止拖动，dragHistoryOnly 只能拖动已观看内容
@property (nonatomic, copy, readonly) NSString *playbackProgressBarOperationType;
/// 显示播放按钮开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL showPlayButtonEnabled;
/// 新版连麦模式开关， YES默认响应新版连麦界面，NO默认响应旧版连麦界面
@property (nonatomic, assign, readonly) BOOL newMicEnabled;
/// 新版连麦默认类型类型，audio默认开启语音连麦，video默认打开视频连麦，N连麦默认不打开，默认值为N
@property (nonatomic, copy, readonly) NSString *defaultOpenMicLinkEnabled;
/// 抽奖礼盒文案（中文）
@property (nonatomic, copy, readonly) NSString *lotteryGiftButtonTextCH;
/// 抽奖礼盒文案（英文）
@property (nonatomic, copy, readonly) NSString *lotteryGiftButtonTextEN;
/// 商品热卖特效开关
@property (nonatomic, assign, readonly) BOOL productHotEffectEnabled;
/// 商品热卖文案
@property (nonatomic, strong, readonly) NSDictionary *productHotEffectTips;
@property (nonatomic, strong, readonly) NSDictionary *globalRtcRecordSetting;
/// 小窗播放控制开关是否开启
@property (nonatomic, assign, readonly) BOOL fenestrulePlayEnabled;
/// 是否开启了商品支付和订单系统，YES 开启 ，NO 关闭
@property (nonatomic, assign, readonly) BOOL productPayOrderEnabled;
/// 是否开启了评论上墙功能，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL pinMsgEnabled;
/// 观看页成员列表开关
@property (nonatomic, assign, readonly) BOOL portraitOnlineListEnabled;
/// 观看分组开关
@property (nonatomic, assign, readonly) BOOL chatViewerGroupEnabled;

/// 双师相关属性
/// 是否双师模式
@property (nonatomic, assign, readonly) BOOL transmitMode;
/// 是否双师模式下的大房间，默认NO
@property (nonatomic, assign, readonly) BOOL mainRoom;
/// 双师模式下大房间频道号
@property (nonatomic, copy, readonly) NSString *mainRoomChannelId;
/// 双师模式下大房间流名
@property (nonatomic, copy, readonly) NSString *mainRoomStream;

@property (nonatomic, strong, readonly) NSDictionary *promotionInfo;

@property (nonatomic, assign, readonly) BOOL watchEventTrackEnabled;

@end
