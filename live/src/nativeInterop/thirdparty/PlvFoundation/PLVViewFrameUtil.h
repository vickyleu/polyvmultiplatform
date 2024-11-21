//
//  PLVViewFrameUtil.h
//  PLVFoundationSDK
//
//  Created by Hank on 2021/1/29.
//  Copyright © 2021 PLV. All rights reserved.
//  UIView frame工具类

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define UIViewGetTop(view) [PLVViewFrameUtil getTop:view]
#define UIViewSetTop(view, top) [PLVViewFrameUtil setTop:top view:view]

#define UIViewGetBottom(view) [PLVViewFrameUtil getBottom:view]
#define UIViewSetBottom(view, bottom) [PLVViewFrameUtil setBottom:bottom view:view]

#define UIViewGetLeft(view) [PLVViewFrameUtil getLeft:view]
#define UIViewSetLeft(view, left) [PLVViewFrameUtil setLeft:left view:view]

#define UIViewGetRight(view) [PLVViewFrameUtil getRight:view]
#define UIViewSetRight(view, right) [PLVViewFrameUtil setRight:right view:view]

#define UIViewGetWidth(view) [PLVViewFrameUtil getWidth:view]
#define UIViewSetWidth(view, width) [PLVViewFrameUtil setWidth:width view:view]

#define UIViewGetHeight(view) [PLVViewFrameUtil getHeight:view]
#define UIViewSetHeight(view, height) [PLVViewFrameUtil setHeight:height view:view]

@interface PLVViewFrameUtil : NSObject

+ (CGFloat)getTop:(UIView *)view;

+ (void)setTop:(CGFloat)top view:(UIView *)view;

+ (CGFloat)getBottom:(UIView *)view;

+ (void)setBottom:(CGFloat)bottom view:(UIView *)view;

+ (CGFloat)getLeft:(UIView *)view;

+ (void)setLeft:(CGFloat)left view:(UIView *)view;

+ (CGFloat)getRight:(UIView *)view;

+ (void)setRight:(CGFloat)right view:(UIView *)view;

+ (CGFloat)getWidth:(UIView *)view;

+ (void)setPlvWidth:(CGFloat)width view:(UIView *)view;

+ (CGFloat)getHeight:(UIView *)view;

+ (void)setHeight:(CGFloat)height view:(UIView *)view;
@end

NS_ASSUME_NONNULL_END
