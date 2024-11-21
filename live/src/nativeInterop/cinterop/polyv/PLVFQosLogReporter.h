//
//  PLVFQosLogReporter.h
//  PLVFoundationSDK
//
//  Created by MissYasiky on 2019/12/24.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <PLVFoundationSDK/PLVFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

/*
 Qos日志上报器，目前只支持 PLVProductTypeVod 和 PLVProductTypeLive 两种类型，不支持批量日志上报
 */
@interface PLVFQosLogReporter : PLVFLogReporter

@end

NS_ASSUME_NONNULL_END
