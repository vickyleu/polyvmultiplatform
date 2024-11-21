//
//  PLVHiClassManager.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2021/10/26.
//  Copyright © 2021 PLV. All rights reserved.
//
// 互动学堂课程业务逻辑管理类

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 互动学堂上课状态
typedef NS_ENUM (NSInteger, PLVHiClassStatus) {
    PLVHiClassStatusNotInClass = 0, // 未开课
    PLVHiClassStatusInClass = 1, // 上课中
    PLVHiClassStatusFinishClass = 2 // 已下课
};

/// 互动学堂学员分组状态
typedef NS_ENUM (NSInteger, PLVHiClassGroupState) {
    PLVHiClassGroupStateNotInGroup = 0, // 未加入分组
    PLVHiClassGroupStateJoiningGroup = 1, // 正在加入分组
    PLVHiClassGroupStateInGroup = 2 // 已加入分组
};

@protocol PLVHiClassManagerDelegate;

@interface PLVHiClassManager : NSObject

#pragma mark - [ 属性 ]

#pragma mark 可配置项

@property (nonatomic, weak) id<PLVHiClassManagerDelegate> delegate;

#pragma mark 数据

/// 课节相关
/// 课程码，默认为nil，仅在学生端使用课程码登录时，不为空
@property (nonatomic, copy, readonly) NSString * _Nullable courseCode;
/// 课节ID
@property (nonatomic, copy, readonly) NSString *lessonId;
/// 课节状态枚举值
@property (nonatomic, assign, readonly) PLVHiClassStatus status;
/// 上课时长（单位秒），status不为PLVHiClassStatusInClass时，duration为0
@property (nonatomic, assign, readonly) NSInteger duration;
/// 实际上课时间（时间戳），未上课时为0
@property (nonatomic, assign, readonly) NSInteger classTime;
/// 原定上课时间（时间戳），不为0
@property (nonatomic, assign, readonly) NSInteger lessonStartTime;
/// 原定下课时间（时间戳），不为0
@property (nonatomic, assign, readonly) NSInteger lessonEndTime;

/// 分组相关
/// 当前用户所处分组状态，默认为PLVHiClassGroupStateNotInGroup
@property (nonatomic, assign, readonly) PLVHiClassGroupState groupState;
/// 当前用户是否为分组组长，默认为NO
@property (nonatomic, assign, readonly) BOOL currentUserIsGroupLeader;
/// 讲师是否在当前分组中，默认为NO
@property (nonatomic, assign, readonly) BOOL teacherInGroup;
/// 当前用户所在分组ID
@property (nonatomic, copy, readonly) NSString *groupId;
/// 当前用户所在分组名
@property (nonatomic, copy, readonly) NSString *groupName;
/// 当前用户所在分组组长ID
@property (nonatomic, copy, readonly) NSString *groupLeaderId;
/// 当前用户所在分组组长昵称
@property (nonatomic, copy, readonly) NSString *groupLeaderName;

#pragma mark - [ 方法 ]

/// 单例方法
+ (instancetype)sharedManager;

/// 进入课室之前，获取到课节详情时，配置基本数据
/// @param detailDict 课节详情接口返回数据
/// @param courseCode 学生登录用的课程码，如果非学生端，以及非课程码登录，设为nil
- (void)setupWithLessonDetail:(NSDictionary *)detailDict courseCode:(NSString * _Nullable)courseCode;

/// 退出课室时，用于销毁计时器、复位数据、撤除socket消息监听
- (void)clear;

/// 进入课室时，用于设置socket消息监听、设置定时器
- (void)enterClassroom;

#pragma mark 讲师专用方法

/// 调用http接口跟socket消息，修改课节状态为上课中
- (void)startClass;

/// 调用http接口跟socket消息，修改课节状态为已下课
- (void)finishClass;

#pragma mark 学生专用方法

/// 请求课节列表获取是否有下一节课的权限，以及课节结束信息
/// @param completion 请求结束执行的代码块，如果请求失败或者无权限，lessonDict为nil，duration为0时表示请求课节结束信息失败
- (void)requestWatcherNextLessonInfoWithCompletion:(void(^)(NSDictionary *lessonDict, NSInteger duration))completion;

/// 组长请求帮助
- (BOOL)requestHelp;

/// 组长取消请求帮助
- (BOOL)cancelRequestHelp;

@end

#pragma mark - [ 代理方法 ]

/// PLVHCLiveroomViewModel 的回调
/// @note 均在主线程触发
@protocol PLVHiClassManagerDelegate <NSObject>

@optional

#pragma mark 通用回调

/// 上课通知
- (void)hiClassManagerClassStartSuccess:(PLVHiClassManager *)manager;

/// 下课通知
- (void)hiClassManagerClassFinishSuccess:(PLVHiClassManager *)manager;

/// 上课时长变化，status等于PLVHiClassStatusInClass时每一秒钟触发一次
- (void)hiClassManagerClassDurationChanged:(PLVHiClassManager *)manager duration:(NSInteger)duration;

#pragma mark 讲师回调

/// 讲师上课失败
/// @param errorMessage 用于提示用的错误信息
- (void)hiClassManagerClassStartFailure:(PLVHiClassManager *)manager errorMessage:(NSString *)errorMessage;

/// 讲师下课失败
/// @param errorMessage 用于提示用的错误信息
- (void)hiClassManagerClassFinishFailure:(PLVHiClassManager *)manager errorMessage:(NSString *)errorMessage;

/// 还有10分钟就拖堂4小时，即将触发强制下课
- (void)hiClassManagerClassWillForceFinishInTenMins:(PLVHiClassManager *)manager;

/// 拖堂超过4小时，已经强制下课
- (void)hiClassManagerClassDidForceFinish:(PLVHiClassManager *)manager;

/// 讲师已在别处登录
/// @param errorMessage 用于提示用的错误信息
- (void)hiClassManagerTeacherRelogin:(PLVHiClassManager *)manager errorMessage:(NSString *)errorMessage;

#pragma mark 学生回调

/// 准备进入分组
- (void)hiClassManagerDidPrepareJoinGroup:(PLVHiClassManager *)manager;

/// 进入分组成功
- (void)hiClassManagerDidJoinGroupSuccess:(PLVHiClassManager *)manager ackData:(NSDictionary *)data;

/// 进入分组失败
- (void)hiClassManagerDidJoinGroupFailure:(PLVHiClassManager *)manager;

/// 进入分组后，获取到分组名称、组长ID、组长名称
/// 更多信息通过属性 groupName、groupLeaderName 获取
/// @param originalLeaderId 原先组长ID
/// @param currentLeaderId 当前组长ID
- (void)hiClassManagerDidGroupLeaderUpdate:(PLVHiClassManager *)manager originalLeaderId:(NSString *)originalLeaderId currentLeaderId:(NSString *)currentLeaderId;

/// 被重新分配分组
- (void)hiClassManagerDidChangeGroup:(PLVHiClassManager *)manager;

/// 结束分组
- (void)hiClassManagerDidLeaveGroup:(PLVHiClassManager *)manager ackData:(NSDictionary *)data;

/// 老师进入分组
- (void)hiClassManagerDidTeacherJoinGroup:(PLVHiClassManager *)manager;

/// 老师离开分组
- (void)hiClassManagerDidTeacherLeaveGroup:(PLVHiClassManager *)manager;

/// 【找老师帮助】请求已取消
- (void)hiClassManagerDidCancelRequestHelp:(PLVHiClassManager *)manager;

/// 老师发送广播通知
- (void)hiClassManager:(PLVHiClassManager *)manager didReceiveHostBroadcast:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
