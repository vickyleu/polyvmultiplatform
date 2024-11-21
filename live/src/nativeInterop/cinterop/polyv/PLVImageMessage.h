//
//  PLVImageMessage.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/11/24.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PLVImageUploadState) {
    PLVImageUploadStateReady = 0,
    PLVImageUploadStateUploading,
    PLVImageUploadStateFailed,
    PLVImageUploadStateSuccess
};

typedef NS_ENUM(NSInteger, PLVImageMessageSendState) {
    PLVImageMessageSendStateReady = 0,
    PLVImageMessageSendStateFailed,
    PLVImageMessageSendStateSuccess
};

@interface PLVImageMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, copy) NSString *imageId;

@property (nonatomic, copy) NSString *imageName;

@property (nonatomic, copy) NSString * _Nullable imageUrl;

@property (nonatomic, strong) UIImage * _Nullable image;

// 发送图片消息时，如果processImageData不为空，优先使用该属性进行上传
// @note 使用processImageData上传的图片，SDK内部不会再做任何数据压缩
@property (nonatomic, strong) NSData * _Nullable processImageData;

@property (nonatomic, assign) CGSize imageSize;

@property (nonatomic, assign) float uploadProgress;

@property (nonatomic, assign) PLVImageUploadState uploadState;

@property (nonatomic, assign) PLVImageMessageSendState sendState;

@property (nonatomic, assign)NSTimeInterval time;

@property (nonatomic, assign) NSTimeInterval playbackTime;
/// 如果值为"extend"表示为：提醒消息
@property (nonatomic, copy) NSString * _Nullable source;

@end

NS_ASSUME_NONNULL_END
