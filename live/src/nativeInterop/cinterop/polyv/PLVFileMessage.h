//
//  PLVFileMessage.h
//  PLVLiveScenesSDK
//
//  Created by Dhan on 2022/7/19.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVFileMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, assign) NSTimeInterval time;

@property (nonatomic, assign) NSTimeInterval playbackTime;// 聊天回放不知道这次要不要支持先放在这里
/// 如果值为"extend"表示为：提醒消息
@property (nonatomic, copy) NSString * _Nullable source;

@property (nonatomic, copy) NSString *url;

@property (nonatomic, copy) NSString *name;

@end

NS_ASSUME_NONNULL_END
