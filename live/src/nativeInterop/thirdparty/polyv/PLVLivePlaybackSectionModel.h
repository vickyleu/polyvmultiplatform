//
//  PLVLivePlaybackSectionModel.h
//  PLVLiveScenesSDK
//
//  Created by Dhan on 2021/12/6.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVFoundationSDK/PLVSafeModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 回放章节信息数据模型
@interface PLVLivePlaybackSectionModel : PLVSafeModel

/// PPT的id，白板的autoId为0
@property (nonatomic, copy) NSString *autoId;
/// 文档类型
@property (nonatomic, copy) NSString *docType;
/// 事件
@property (nonatomic, copy) NSString *event;
/// 缩略图地址
@property (nonatomic, copy) NSString *image;
/// 页码
@property (nonatomic, copy) NSString *pageId;
/// 用于PPT请求数据，与PPT直播的回放相关，普通直播回放值为null
@property (nonatomic, copy) NSString *sessionid;
/// ppt时间
@property (nonatomic, assign) NSTimeInterval timeStamp;
/// PPT标题
@property (nonatomic, copy) NSString *title;

@end

NS_ASSUME_NONNULL_END
