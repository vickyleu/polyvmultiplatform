//
//  PLVFHttpErrorCodeGenerator.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2020/1/13.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFHttpErrorCode){
    PLVFHttpErrorCodeAllNetworkFailure = 000,
};


NS_ASSUME_NONNULL_BEGIN

@interface PLVFHttpErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFHttpErrorCode)error;

+ (NSString *)errorDescription:(PLVFHttpErrorCode)error;

@end

NS_ASSUME_NONNULL_END
