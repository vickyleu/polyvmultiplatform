//
//  PLVCustomMessage.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/11/24.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVCustomMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, copy) NSString *tip;

@property (nonatomic, copy) NSString *event;

@property (nonatomic, strong) NSDictionary *data;

@property (nonatomic, assign) int emitMode;

@end

NS_ASSUME_NONNULL_END
