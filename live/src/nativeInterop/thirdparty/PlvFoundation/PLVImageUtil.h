//
//  PLVImageUtil.h
//  PLVFoundationSDK
//
//  Created by junotang on 2022/1/19.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PLVGLTexture.h"

NS_ASSUME_NONNULL_BEGIN

/// 数据格式
typedef NS_ENUM(NSInteger, PLVFormatType) {
    PLVFormatType_UNKNOW,   //!< 未知格式
    PLVFormatType_RGBA,     //!< 8bit R G B A
    PLVFormatType_BGRA,     //!< 8bit B G R A
    PLVFormatType_YUV420V,  //!< video range, 8bit Y1 Y2 Y3 Y4... U1 V1...
    PLVFormatType_YUV420F,   //!< full range, 8bit Y1 Y2 Y3 Y4... U1 V1...
    PLVFormatType_YUVY420
};

@interface PLVPixelBufferInfo : NSObject

@property (nonatomic, assign) PLVFormatType format;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;
@property (nonatomic, assign) int bytesPerRow;

@end

@interface PLVBuffer : NSObject
/// buffer 指针，用于 RGBA 格式
@property (nonatomic, assign) unsigned char *buffer;
/// y buffer 指针，只用于 YUV 格式
@property (nonatomic, assign) unsigned char *yBuffer;
/// uv buffer 指针，只用于 YUV 格式
@property (nonatomic, assign) unsigned char *uvBuffer;
/// u buffer 指针，只用于 YUV 格式（y420）
@property (nonatomic, assign) unsigned char *uBuffer;
/// v buffer 指针，只用于 YUV 格式（y420）
@property (nonatomic, assign) unsigned char *vBuffer;
/// 宽，用于 RGBA 格式
@property (nonatomic, assign) int width;
/// 高，用于 RGBA 格式
@property (nonatomic, assign) int height;
/// y buffer 宽，用于 YUV 格式
@property (nonatomic, assign) int yWidth;
/// y buffer 高，用于 YUV 格式
@property (nonatomic, assign) int yHeight;
/// uv buffer 宽，用于 YUV 格式
@property (nonatomic, assign) int uvWidth;
/// uv buffer 高，用于 YUV 格式
@property (nonatomic, assign) int uvHeight;
/// 行宽，用于 RGBA 格式
@property (nonatomic, assign) int bytesPerRow;
/// y buffer 行宽，用于 YUV 格式
@property (nonatomic, assign) int yBytesPerRow;
/// uv buffer 行宽，用于 YUV 格式
@property (nonatomic, assign) int uvBytesPerRow;
/// u buffer 行宽，用于 YUV 格式
@property (nonatomic, assign) int uBytesPerRow;
/// v buffer 行宽，用于 YUV 格式
@property (nonatomic, assign) int vBytesPerRow;
/// 格式
@property (nonatomic, assign) PLVFormatType format;

@end

/// 图像数据处理工具类
@interface PLVImageUtil : NSObject

/// 获取 CVPixelBuffer 信息
/// @param pixelBuffer CVPixelBuffer
- (PLVPixelBufferInfo *)getCVPixelBufferInfo:(CVPixelBufferRef)pixelBuffer;

/// 获取 CVPixelBuffer 格式
/// @param pixelBuffer CVPixelBuffer
- (PLVFormatType)getCVPixelBufferFormat:(CVPixelBufferRef)pixelBuffer;

/// OSType 转 PLVFormatType
/// @param type OSType
- (PLVFormatType)getFormatForOSType:(OSType)type;

/// PLVFormatType 转 OSType
/// @param format PLVFormatType
- (OSType)getOsType:(PLVFormatType)format;

/// CVPixelBuffer 转 CVPixelBuffer
/// @param pixelBuffer 输入 CVPixelBuffer
/// @param outputFormat CVPixelBuffer 格式
- (CVPixelBufferRef)transforCVPixelBufferToCVPixelBuffer:(CVPixelBufferRef)pixelBuffer outputFormat:(PLVFormatType)outputFormat;

/// 将 PLVBuffer 的内容复制到已存在的目标 PLVBuffer 中，同时进行格式转换
/// @param inputBuffer 输入 PLVBuffer
/// @param outputBuffer 输出 PLVBuffer
- (BOOL)transforBufferToBuffer:(PLVBuffer *)inputBuffer outputBuffer:(PLVBuffer *)outputBuffer;

/// CVPixelBuffer 转 纹理
/// @param pixelBuffer CVPixelBuffer
- (PLVPixelBufferGLTexture *)transforCVPixelBufferToTexture:(CVPixelBufferRef)pixelBuffer;

/// 初始化一个与 CVPixelBufferRef 绑定的纹理
/// @param width 宽
/// @param height 高
/// @param format 格式，仅支持 PLVFormatType_BGRA/PLVFormatType_YUV420F/PLVFormatType_YUV420V
- (PLVPixelBufferGLTexture *)getOutputPixelBufferGLTextureWithWidth:(int)width height:(int)height format:(PLVFormatType)format;

/// 使用 输入CVPixelBufferRef 填充 模板CVPixelBufferRef
/// @param pixelBuffer 模板CVPixelBufferRef
/// @param inputPixelBuffer 输入CVPixelBufferRef
-(void)fillPixelBuffer:(CVPixelBufferRef)pixelBuffer withInputPixelBuffer:(CVPixelBufferRef)inputPixelBuffer;

/// 使用输入的y420数据，填满y420的CVPixelBufferRef
/// @param pixelBuffer 模板CVPixelBufferRef
/// @param inputPixelBuffer 输入CVPixelBufferRef
-(void)fillY420PixelBuffer:(CVPixelBufferRef)pixelBuffer withInputPixelBuffer:(CVPixelBufferRef)inputPixelBuffer;

/// 用I420 的 yuv数据，组成 nv12 的 CVPixelBufferRef
- (CVPixelBufferRef)copyI420BufferToNv12:(size_t)width height:(size_t)height yData:(char *)yData uData:(char *)uData vData:(char *)vData yStride:(size_t)yStride uStride:(size_t)uStride vStride:(size_t)vStride uvBufferLength:(size_t)uvBufferLength uvBuffer:(char *)uvBuffer;

/// 把CVPixelBufferRef数据，拆分成YUV数据
- (void)changePixelBufferRef:(CVPixelBufferRef)pixelBuffer toYUVBuffer:(int)width height:(int)height yData:(char *)yData uData:(char *)uData vData:(char *)vData yStride:(int)yStride uStride:(int)uStride vStride:(int)vStride;

/// 把UIView转换为UIImage
+ (UIImage *)imageFromUIView:(UIView *)view;

/// 把UIView转换为UIImage
+ (UIImage *)imageFromUIView:(UIView *)view opaque:(BOOL)opaque scale:(CGFloat)scale;

/// 尽量将图片image压缩到指定大小mbValue（单位：MB）
/// 最多只进行两轮压缩，不论结果是否达标均会返回
+ (NSData *)compressImage:(UIImage *)image mbValue:(double)mbValue;

@end

NS_ASSUME_NONNULL_END
