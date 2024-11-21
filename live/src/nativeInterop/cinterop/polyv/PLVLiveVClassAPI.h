//
//  PLVLiveVClassAPI.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2021/7/1.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVLiveVClassAPI : NSObject

/// 讲师登录接口返回的token，登出时置nil
/// @note 一般在内部进行配置，仅当讲师端缓存有Token时会在外部直接设置
@property (class, nonatomic, strong) NSString * _Nullable teachToken;

/// 学生登录接口返回的token，登出时置nil
/// @note 仅在内部进行配置
@property (class, nonatomic, strong, readonly) NSString * _Nullable watchToken;

/// 获取课程或课节简单信息
/// @param courseCode 课程号
/// @param lessonId 课节ID
/// @param successHandler 登录成功时，触发该block
/// @param failureHandler 登录失败时，触发该block
+ (void)courseOrLessonSimpleInfoWithCourseCode:(NSString * _Nullable)courseCode
                                      lessonId:(NSString * _Nullable)lessonId
                                       success:(void (^)(NSDictionary *responseDict))successHandler
                                       failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 获取课节结束信息
/// @param lessonId 课节ID
/// @param isTeach 是否是讲师端获取
/// @param successHandler 登录成功时，触发该block
/// @param failureHandler 登录失败时，触发该block
+ (void)lessonFinishInfoWithLessonId:(NSString *)lessonId
                             isTeach:(BOOL)isTeach
                             success:(void (^)(NSDictionary *responseDict))successHandler
                             failure:(void (^ _Nullable)(NSError *error))failureHandler;

@end

@interface PLVLiveVClassAPI (Teach)

/// 讲师登录接口
/// @param mobile 讲师11位手机号
/// @param password 讲师密码
/// @param code 区号，可为空，默认+86
/// @param userId 机构Id，可为空，讲师重复时不可为空
/// @param mutipleCompanyHandler 讲师重复时，触发该block，返回讲师所属机构列表
/// @param success 登录成功时，触发该block
/// @param failure 登录失败时，触发该block
+ (void)teacherLoginWithMobile:(NSString *)mobile
                      password:(NSString *)password
                          code:(NSString * _Nullable)code
                        userId:(NSString * _Nullable)userId
                mutipleCompany:(void (^)(NSArray *responseArray))mutipleCompanyHandler
                       success:(void (^)(NSDictionary *responseDict, NSArray *lessonArray))success
                       failure:(void (^ _Nullable)(NSError *error))failure;

/// 校验当前进入该课节的老师是否被顶出去
/// @param lessonId 课节ID
/// @param reloginHandler 确认老师被顶出去时，触发该block
/// @param successHandler 接口调用成功时，触发该block
/// @param failureHandler 接口调用失败时，触发该block
+ (void)teacherReloginVerifyWithLessonId:(NSString *)lessonId
                                 relogin:(void (^)(NSString *errorDesc))reloginHandler
                                 success:(void (^ _Nullable)(NSDictionary *responseDict))successHandler
                                 failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 讲师获取课节列表接口
/// @param userId 机构Id，可为空
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)teacherLessonListWithUserId:(NSString * _Nullable)userId
                            success:(void (^)(NSArray *responseArray))successHandler
                            failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 讲师获取课节状态接口
/// @param lessonId 课节ID
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)teacherLessonStatusWithLessonId:(NSString *)lessonId
                                success:(void (^)(NSDictionary *responseDict))successHandler
                                failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 讲师获取课节详情接口
/// @param lessonId 课节ID
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)teacherLessonDetailWithLessonId:(NSString *)lessonId
                                success:(void (^)(NSDictionary *responseDict))successHandler
                                failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 讲师修改课节状态
/// @param lessonId 课节ID
/// @param status 课节状态（0：未开课，1：上课中，2：已下课）
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)teacherChangeLessonStatusWithLessonId:(NSString *)lessonId
                                       status:(NSInteger)status
                                      success:(void (^)(id responseObject))successHandler
                                      failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 讲师端获取聊天室token
/// @param lessonId 课节ID
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)teacherChatTokenWithLessonId:(NSString *)lessonId
                             success:(void (^)(NSDictionary *responseDict))successHandler
                             failure:(void (^ _Nullable)(NSError *error))failureHandler;


/// 讲师端获取直播api接口频道级别token
/// @param lessonId 课节ID
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)teacherGetLiveAPIChannelTokenWithLessonId:(NSString *)lessonId
                                          success:(void (^)(NSDictionary *))successHandler
                                          failure:(void (^ _Nullable)(NSError *))failureHandler;

/// 讲师端获取文档token
/// @param lessonId 课节ID
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)teacherDocumentTokenWithLessonId:(NSString *)lessonId
                            success:(void (^)(NSDictionary *responseDict))successHandler
                            failure:(void (^ _Nullable)(NSError *error))failureHandler DEPRECATED_MSG_ATTRIBUTE("Please use 'teacherGetLiveAPIChannelTokenWithLessonId:success:failure:' instead");

/// 讲师端登出
+ (void)teacherLogout;

@end

@interface PLVLiveVClassAPI (Watch)

/// 无条件观看接口，课程号与课节ID必须一个不为空
/// @param courseCode 课程号
/// @param lessonId 课节ID
/// @param name 昵称
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)watcherVerifyNoneWithCourseCode:(NSString * _Nullable)courseCode
                               lessonId:(NSString * _Nullable)lessonId
                                   name:(NSString *)name
                                success:(void (^)(NSDictionary *responseDict, NSArray *lessonArray))successHandler
                                failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 验证码观看接口，课程号与课节ID必须一个不为空
/// @param courseCode 课程号
/// @param lessonId 课节ID
/// @param name 昵称
/// @param code 验证码
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)watcherVerifyCodeWithCourseCode:(NSString * _Nullable)courseCode
                               lessonId:(NSString * _Nullable)lessonId
                                   name:(NSString *)name
                                   code:(NSString *)code
                                success:(void (^)(NSDictionary *responseDict, NSArray *lessonArray))successHandler
                                failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 白名单观看接口，课程号与课节ID必须一个不为空
/// @param courseCode 课程号
/// @param lessonId 课节ID
/// @param studentCode 学生码
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)watcherVerifyWhiteListWithCourseCode:(NSString * _Nullable)courseCode
                                    lessonId:(NSString * _Nullable)lessonId
                                 studentCode:(NSString *)studentCode
                                     success:(void (^)(NSDictionary *responseDict, NSArray *lessonArray))successHandler
                                     failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 观看端获取课节列表接口，课程号与课节ID必须一个不为空
/// @param courseCode 课程号
/// @param lessonId 课节ID
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)watcherLessonListWithCourseCode:(NSString * _Nullable)courseCode
                               lessonId:(NSString * _Nullable)lessonId
                                success:(void (^)(NSArray *responseArray))successHandler
                                failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 观看端获取课程/课节详情接口
/// @param courseCode 课程号
/// @param lessonId 课节ID
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)watcherLessonDetailWithCourseCode:(NSString * _Nullable)courseCode
                                 lessonId:(NSString *)lessonId
                                  success:(void (^)(NSDictionary *responseDict))successHandler
                                  failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 观看端获取聊天室token
/// @param courseCode 课程号
/// @param lessonId 课节ID
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)watcherChatTokenWithCourseCode:(NSString * _Nullable)courseCode
                              lessonId:(NSString *)lessonId
                               success:(void (^)(NSDictionary *responseDict))successHandler
                               failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 观看端获取直播api接口频道级别token
/// @param lessonId 课节ID
/// @param courseCode 课程号
/// @param successHandler 调用成功时，触发该block
/// @param failureHandler 调用失败时，触发该block
+ (void)watcherGetLiveAPIChannelTokenWithLessonId:(NSString *)lessonId
                                       courseCode:(NSString * _Nullable)courseCode
                                          success:(void (^)(NSDictionary *responseDict))successHandler
                                          failure:(void (^ _Nullable)(NSError *error))failureHandler;

/// 观看端登出
+ (void)watcherLogout;

@end

NS_ASSUME_NONNULL_END
