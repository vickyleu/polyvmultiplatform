//
//  PLVViewLogCustomParam.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/12/16.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// ViewLog 统计后台用户自定义参数
@interface PLVViewLogCustomParam : NSObject

#pragma mark - 直播自定义参数

/// 统计后台自定义参数1（观众/学员Id）
@property (nonatomic, copy) NSString *liveParam1;
/// 统计后台自定义参数2（观众/学员昵称）
@property (nonatomic, copy) NSString *liveParam2;
/// 统计后台自定义参数4
@property (nonatomic, copy) NSString *liveParam4;
/// 统计后台自定义参数5
@property (nonatomic, copy) NSString *liveParam5;

#pragma mark - 点播/回放自定义参数

/// 统计后台sid（观众/学员Id）
@property (nonatomic, copy) NSString *vodSid;
/// 统计后台观众/学员头像的url地址
@property (nonatomic, copy) NSString *vodViewerAvatar;

/// 统计后台自定义参数1
@property (nonatomic, copy) NSString *vodParam1;
/// 统计后台自定义参数2（观众/学员昵称）
@property (nonatomic, copy) NSString *vodParam2;
/// 统计后台自定义参数3
@property (nonatomic, copy) NSString *vodParam3;
/// 统计后台自定义参数4
@property (nonatomic, copy) NSString *vodParam4;
/// 统计后台自定义参数5
@property (nonatomic, copy) NSString *vodParam5;

/// 统计后台自定义业务索引1
@property (nonatomic, copy) NSString *vodKey1;
/// 统计后台自定义业务索引2
@property (nonatomic, copy) NSString *vodKey2;
/// 统计后台自定义业务索引3
@property (nonatomic, copy) NSString *vodKey3;

@end

NS_ASSUME_NONNULL_END
