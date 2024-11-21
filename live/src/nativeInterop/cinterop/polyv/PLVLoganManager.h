//
//  PLVLoganManager.h
//  PLVLiveScenesSDK
//
//  Created by Dhan on 2022/12/19.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVLoganManagerDelegate <NSObject>

- (void)loganManagerCheckAndReportIfNeedWithError:(NSError *)error;

@end

@interface PLVLoganManager : NSObject

@property (nonatomic, weak) id <PLVLoganManagerDelegate> delegate;

/// 是否禁用日志本地记录功能，默认为NO——启用日志本地记录，YES——禁用日志本地记录
@property (nonatomic, assign) BOOL logDisable;

/// 是否禁用日志上报功能，默认为NO——启用日志上报，YES——禁用日志上报
@property (nonatomic, assign) BOOL logUploadDisable;

+ (instancetype)sharedManager;

/// 检查是否存在上报任务
- (void)checkAndReportIfNeed;

@end

NS_ASSUME_NONNULL_END
