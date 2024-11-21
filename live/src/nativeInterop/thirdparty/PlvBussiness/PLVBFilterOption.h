//
//  PLVBFilterOption.h
//  PLVBusinessSDK
//
//  Created by junotang on 2022/1/18.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/// 美颜滤镜option
@interface PLVBFilterOption : NSObject

/// 滤镜的中文名
@property (nonatomic, copy) NSString *filterName;

/// 滤镜的中文名拼音
@property (nonatomic, copy) NSString *filterSpellName;

/// 给美颜sdk使用的滤镜名
@property (nonatomic, copy) NSString *filterKey;



@end

NS_ASSUME_NONNULL_END
