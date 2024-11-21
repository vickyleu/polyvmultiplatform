//
//  PLVFDI18NUtil.h
//  PLVFoundationSDK
//
//  Created by Sakya on 2023/9/6.
//  Copyright © 2023 PLV. All rights reserved.
//
// 语言国际化

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define PLVFDLocalizableString(key) [PLVFDI18NUtil plv_localizedStringForKey:key value:nil]

@interface PLVFDI18NUtil : NSObject

/// 首选语言，如果设置了就用该语言，不设则取当前系统语言。
/// 支持zh-Hans、en等值，详见PLVFDLocalizable.bundle内的语言资源
@property (nonatomic, copy) NSString *preferredLanguage;

+ (instancetype)sharedInstance;

/// 配置本地化语言包的Bundle
/// @param localizableBundle 本地化语言包的Bundle
- (void)setupLocalizableBundle:(NSBundle *)localizableBundle;

+ (NSString *)plv_localizedStringForKey:(NSString *)key value:(nullable NSString *)value;

@end

NS_ASSUME_NONNULL_END
