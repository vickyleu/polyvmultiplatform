//
//  PLVRewardMessage.h
//  PLVLiveScenesSDK
//
//  Created by lijingtong on 2021/6/17.
//  Copyright © 2021 PLV. All rights reserved.
// 打赏消息模型

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVRewardMessage : NSObject

/// 消息Id
/// @note 从接口拉取不为空，从即时消息收取为nil
@property (nonatomic, copy) NSString * _Nullable msgId;

/// 打赏的用户
@property (nonatomic, copy) NSString *unick;

/// 打赏的数量
@property (nonatomic, copy) NSString *goodNum;

/// 打赏内容：礼物打赏为礼物名称，现金打赏为金额
@property (nonatomic, copy) NSString *rewardContent;

/// 礼物打赏为礼物图片，现金打赏为空, 使用本地图片
@property (nonatomic, copy) NSString * _Nullable gimg;

@property (nonatomic, strong) UIImage *image;

@end

NS_ASSUME_NONNULL_END
