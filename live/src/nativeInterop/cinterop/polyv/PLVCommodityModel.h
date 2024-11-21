//
//  PLVECCommodityModel.h
//  PLVLiveScenesSDK
//
//  Created by ftao on 2020/6/29.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 商品数据模型
@interface PLVCommodityModel : NSObject

/// 商品主键
@property (nonatomic, assign) NSInteger productId;
/// 排序号
@property (nonatomic, assign) NSInteger rank;
/// 显示序号
@property (nonatomic, assign) NSInteger showId;
/// 商品名称
@property (nonatomic, copy) NSString *name;
/// 原价格
@property (nonatomic, copy) NSString *price;
/// 实际价格
@property (nonatomic, copy) NSString *realPrice;
/// 收益率/价格
@property (nonatomic, copy) NSString *yield;
/// 商品标签
@property (nonatomic, copy) NSString *features;
/// 商品标签数组
@property (nonatomic, strong) NSArray *featureArray;
/// 商品描述
@property (nonatomic, copy) NSString *productDesc;
/// 封面图片地址
@property (nonatomic, copy) NSString *cover;
/// 商品类型 normal正常商品、finance金融
@property (nonatomic, copy) NSString *productType;
/// 状态：1上架，2下架
@property (nonatomic, assign) NSInteger status;
/// 商品链接类型, 10:通用链接,使用link字段，11:多平台链接，使用mobileAppLink字段
@property (nonatomic, assign) NSInteger linkType;
/// 商品链接，通用链接
@property (nonatomic, copy) NSString *link;
/// 移动端app链接，默认为空串
@property (nonatomic, copy) NSString *mobileAppLink;
/// 购买按钮显示文案
@property (nonatomic, copy) NSString *btnShow;
/// 卡片推送规则，bigCard 大卡片、smallCard 小卡片
@property (nonatomic, copy) NSString *productPushRule;
/// 商品购买方式（ inner 直接购买、link 外链购买）
@property (nonatomic, copy) NSString *buyType;
/// 商品物流类型
@property (nonatomic, copy) NSString *deliveryType;
/// 用于统计
@property (nonatomic, copy) NSString *logId;
/// 其它参数
@property (nonatomic, strong) NSDictionary *params;
/// 格式化跳转的商品链接，已进行类型判断
@property (nonatomic, copy) NSString *formattedLink;

+ (instancetype)commodityModelWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
