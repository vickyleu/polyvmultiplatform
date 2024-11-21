//
//  PLVImageEmotionMessage.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2021/7/7.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PLVImageEmotionMessageSendState) {
    PLVImageEmotionMessageSendStateReady  = 0,
    PLVImageEmotionMessageSendStateFailed,
    PLVImageEmotionMessageSendStateSuccess
};

@interface PLVImageEmotionMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, copy) NSString *imageId;

@property (nonatomic, copy) NSString *imageName;

@property (nonatomic, copy) NSString * _Nullable imageUrl;

@property (nonatomic, assign) CGSize imageSize;

@property (nonatomic, assign) NSTimeInterval time;

@property (nonatomic, assign) NSTimeInterval playbackTime;

///图片表情消息的发送状态
@property (nonatomic, assign) PLVImageEmotionMessageSendState sendState;

@end

NS_ASSUME_NONNULL_END
