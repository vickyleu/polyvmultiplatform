//
//  PLVDownloadDatabaseManager.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/5/23.
//  Copyright © 2022 PLV. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PLVLiveDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class PLVDownloadDatabaseManager;

/// 回调事件定义
/**
 下载任务数组 更新事件（使用时，可在收到该回调后，读取对应的数组，及时更新界面）

 @param arrayType 本次更新数组的类型
 */
typedef void (^PLVDownloadDatabaseTaskInfoArrayRefreshBlock)(PLVDownloadDatabaseManager * manager, PLVDownloadDatabaseTaskInfoArrayType arrayType);

/// 数据库管理器（单例类；特定业务的属性、方法声明，在对应业务扩展文件中）
@interface PLVDownloadDatabaseManager : NSObject

#pragma mark - [ 属性 ]

#pragma mark 事件
/// 下载任务数组 更新事件
@property (nonatomic, strong) PLVDownloadDatabaseTaskInfoArrayRefreshBlock taskInfoArrayRefreshBlock;

#pragma mark - [ 方法 ]

/// 获得单例对象
+ (instancetype)shareManager;

#pragma mark 多接收方事件
/**
 一般场景可通过上方Block事件满足，不必使用以下多接收方事件进行事件接收
 */
/**
 添加一个Block接收 数组更新事件 （与上方属性Block事件，相互独立）
 
 @param block 事件回调
 @param blockKey 回调Key（不同调用方，以此字符串来区分注册）
 */
- (void)addTaskInfoArrayRefreshBlock:(PLVDownloadDatabaseTaskInfoArrayRefreshBlock)block key:(NSString *)blockKey;

/**
 移除一个接收方 不再接收下载完成事件
 
 @param blockKey 接收方，在添加事件接收时所填Key
 */
- (void)removeTaskInfoArrayRefreshBlockWithKey:(NSString *)blockKey;

@end

NS_ASSUME_NONNULL_END
