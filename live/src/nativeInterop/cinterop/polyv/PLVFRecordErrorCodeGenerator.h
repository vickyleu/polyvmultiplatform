//
//  PLVFRecordErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFRecordErrorCode){
    PLVFRecordErrorCodeForExample = 000
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFRecordErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFRecordErrorCode)error;

+ (NSString *)errorDescription:(PLVFRecordErrorCode)error;

@end

NS_ASSUME_NONNULL_END
