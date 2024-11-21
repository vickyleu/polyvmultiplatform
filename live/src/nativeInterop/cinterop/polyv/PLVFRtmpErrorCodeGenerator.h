//
//  PLVFRtmpErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFRtmpErrorCode){
    PLVFRtmpErrorCodeForExample = 000
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFRtmpErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFRtmpErrorCode)error;

+ (NSString *)errorDescription:(PLVFRtmpErrorCode)error;

@end

NS_ASSUME_NONNULL_END
