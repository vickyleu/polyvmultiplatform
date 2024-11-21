//
//  PLVBeautyManager.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/1/17.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVBusinessSDK/PLVBusinessSDK.h>

NS_ASSUME_NONNULL_BEGIN

/// 美颜管理器
///
/// @note 负责美颜功能的业务管理
@interface PLVBeautyManager : NSObject

#pragma mark - [ 方法 ]
#pragma mark 美颜设置

/// 美颜特效是否支持
/// @param option 美颜特效类型
- (BOOL)isBeautyOptionSupport:(PLVBBeautyOption)option;

/// 更新美颜特效
/// @param option 美颜特效类型
/// @param intensity 强度，0~1
- (void)updateBeautyOption:(PLVBBeautyOption)option withIntensity:(CGFloat)intensity;

/// 移除美颜特效
/// @param option 美颜特效类型
- (void)removeBeautyOption:(PLVBBeautyOption)option;

/// 移除所有美颜特效
- (void)clearBeautyOption;

/// 获取支持的美颜滤镜
- (NSArray<PLVBFilterOption *> *)getSupportFilterOptions;

/// 设置美颜滤镜
/// @param option 滤镜对象
/// @param intensity 强度，0~1
- (void)setFilterOption:(PLVBFilterOption *)option withIntensity:(CGFloat)intensity;

@end



NS_ASSUME_NONNULL_END
