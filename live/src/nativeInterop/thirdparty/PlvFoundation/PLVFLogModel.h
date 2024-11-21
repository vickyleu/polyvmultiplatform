//
//  PLVFLogModel.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/5.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 日志系统数据模型的父类，所有日志模型都继承于这个类
 是否支持批量日志发送由子类设置
 */
@interface PLVFLogModel : NSObject

/// patch - 是否批量发送，
/// YES：批量发送，凑够 50 条才发送一次日志
/// NO：实时发送。
@property (nonatomic, assign) BOOL patch;

@end

NS_ASSUME_NONNULL_END
