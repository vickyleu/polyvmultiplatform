//
//  PLVFLogan.h
//  PLVFoundationSDK
//
//  Created by Dhan on 2023/2/21.
//  Copyright © 2023 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

extern void plvLoganUseASL(BOOL b);

typedef void (^PLVLoganUploadResultBlock)(NSData *_Nullable data, NSURLResponse *_Nullable response, NSError *_Nullable error);

/**
 返回文件路径
 
 @param filePath filePath nil时表示文件不存在
 */
typedef void (^PLVLoganFilePathBlock)(NSString *_Nullable filePath);

/**
 PLVLogan初始化
 
 @param aes_key16 16位aes加密key
 @param aes_iv16  16位aes加密iv
 @param max_file  日志文件最大大小，超过该大小后日志将不再被写入，单位：byte。
 */
extern void PLVLoganInit(NSData *_Nonnull aes_key16, NSData *_Nonnull aes_iv16, uint64_t max_file);

/**
 设置本地保存最大文件天数

 @param max_reversed_date 超过该文件天数的文件会被Logan删除，默认7天
 */
extern void PLVLoganSetMaxReversedDate(int max_reversed_date);

/**
 设置记录版本信息

 @param sdkVersion 版本信息
 */
extern void PLVLoganSetSdkVersion(NSString  * _Nullable sdkVersion);

/**
 记录PLVLogan日志
 
 @param type 日志类型
 @param log  日志字符串
 
 @brief
 用例：
 logan(1, @"this is a test");
 */
extern void PLVLogan(NSUInteger type, NSString *_Nonnull log);

/**
 记录PLVLogan-info日志到指定时间 建议使用loganInfo
 
 @param key 日志关键词
 @param info 日志信息
 @param timestamp 日志指定时间
 
 @brief
 用例：
 loganInfo(@"plvIplist", @"127.0.0.1", @"1666666666");
 */
extern void PLVLoganKeyInfoWithTimestamp (NSString * _Nullable key, NSString * _Nullable info, NSString * _Nullable timestamp);

/**
 记录PLVLogan-info日志
 
 @param key 日志关键词
 @param info 日志信息
 
 @brief
 用例：
 loganInfo(@"plvIplist", @"127.0.0.1");
 */
extern void PLVLoganKeyInfo (NSString * _Nullable key, NSString * _Nullable info);

/**
 将日志全部输出到控制台的开关，默认NO
 
 @param b 开关
 */
extern void PLVLoganUseASL(BOOL b);

/**
 将日志是否记录到本地的开关，默认NO——记录，YES——不记录
 
 @param b 开关
 */
extern void PLVLoganDisable(BOOL b);

/**
 立即写入日志文件
 */
extern void PLVLoganFlush(void);

/**
 日志信息输出开关，默认NO
 
 @param b 开关
 */
extern void PLVLoganPrintClibLog(BOOL b);

/**
 清除指定时间
 */
extern void PLVLoganClearLog(NSString * _Nonnull timeStamp);

/**
 清除本地所有日志
 */
extern void PLVLoganClearAllLogs(void);

/**
 返回本地所有文件日期及大小(单位byte)
 
 @return @{@"1670554609666":@"110"}
 */
extern NSDictionary *_Nullable PLVLoganAllFilesInfo(void);

extern NSDictionary *_Nullable PLVLoganFileKeyInfo(NSString * _Nonnull timeStamp);

/**
 根据日期获取上传日志的文件路径，异步方式！
 
 @param timestamp 时间戳 格式：13位
 @param filePathBlock 回调返回文件路径，在主线程中回调
 */
extern void PLVLoganUploadFilePath(NSString *_Nonnull timestamp, PLVLoganFilePathBlock _Nonnull filePathBlock);

/**
 上传指定日期的日志
 
 @param url 接受日志的服务器完整url
 @param timestamp 日志时间戳，13位时间戳
 @param appId 当前应用的唯一标识,在多App时区分日志来源App
 @param unionId 当前用户的唯一标识,用来区分日志来源用户
 @param resultBlock 服务器返回结果
 */
extern void PLVLoganUpload(NSString * _Nonnull url, NSString * _Nonnull timestamp,NSString * _Nullable appId, NSString *_Nullable unionId,NSString *_Nullable deviceId, PLVLoganUploadResultBlock _Nullable resultBlock);

/**
 返回今天日期
 
 @return @"2018-11-21"
 */
extern NSString *_Nonnull PLVLoganTodaysDate(void);

extern NSString *_Nonnull PLVLoganTodaysTime(void);

