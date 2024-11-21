//
//  PLVGLTexture.h
//  PLVFoundationSDK
//
//  Created by junotang on 2022/1/19.
//  Copyright © 2022 PLV. All rights reserved.
//

#ifndef PLVGLTexture_h
#define PLVGLTexture_h

#import <OpenGLES/ES2/glext.h>
#import <CoreVideo/CoreVideo.h>

typedef NS_ENUM(NSInteger, PLVGLTextureType) {
    PLV_NORMAL_TEXTURE, //!< 通过 glGenTextures 创建的纹理
    PLV_PIXEL_BUFFER_TEXTURE //!< 与 CVPixelBuffer 绑定的纹理
};

/// OpenGL 纹理的封装，它可以是直接通过 glGenTextures 创建的纹理，也可以是通过 CVPixelBufferRef，当使用 CVPixelBufferRef 创建时，仅支持 kCVPixelFormatType_32BGRA 格式的 CVPixelBufferRef 创建并与之绑定的纹理，
@protocol PLVGLTexture <NSObject>
/// 纹理 ID
@property (nonatomic) GLuint texture;
/// 纹理类型
@property (nonatomic) PLVGLTextureType type;
/// 是否有效
@property (nonatomic) BOOL available;
/// 宽
@property (nonatomic, readonly) int width;
/// 高
@property (nonatomic, readonly) int height;

/// 初始化
/// @param width 宽
/// @param height 高
- (instancetype)initWithWidth:(int)width height:(int)height;

/// 更新宽高
/// @param width 宽
/// @param height 高
- (void)updateWidth:(int)width height:(int)height;

/// 销毁纹理
- (void)destroy;

@end

/// 普通 gl 纹理的封装
@interface PLVNormalGLTexture : NSObject <PLVGLTexture>

/// 根据纹理号、宽、高初始化
/// @param texture 纹理 ID
/// @param width 宽
/// @param height 高
- (instancetype)initWithTexture:(GLuint)texture width:(int)width height:(int)height;

/// 根据 buffer 初始化
/// @param buffer buffer
/// @param width 宽
/// @param height 高
/// @param format buffer 格式，GL_RGBA/GL_BGRA
- (instancetype)initWithBuffer:(unsigned char *)buffer width:(int)width height:(int)height format:(GLenum)format;

/// 根据 buffer 更新纹理内容
/// @param buffer buffer
/// @param width 宽
/// @param height 高
/// @param format buffer 格式，GL_RGBA/GL_BGRA
- (void)update:(unsigned char *)buffer width:(int)width height:(int)height format:(GLenum)format;

/// 根据纹理号、宽、高更新纹理
/// @param texture 纹理 ID
/// @param width 宽
/// @param height 高
- (void)updateTexture:(GLuint)texture width:(int)width height:(int)height;


@end

/// 根据 CVPixelBuffer 生成的 gl 纹理封装，内部完成了 CVPixelBuffer 与 gl 纹理的绑定，当完成对纹理的处理之后，直接调用 pixelBuffer 就可以得到处理之后的 CVPixelBuffer
@interface PLVPixelBufferGLTexture : NSObject <PLVGLTexture>

/// 根据 CVOpenGLESTextureCacheRef 初始化
/// @param textureCache cache
- (instancetype)initWithTextureCache:(CVOpenGLESTextureCacheRef)textureCache;

/// 根据宽、高、CVOpenGLESTextureCacheRef 初始化
/// @param width 宽
/// @param height 高
/// @param textureCache cache
- (instancetype)initWithWidth:(int)width height:(int)height textureCache:(CVOpenGLESTextureCacheRef)textureCache;

/// 根据 CVPixelBuffer 初始化
/// @param pixelBuffer CVPixelBuffer
/// @param textureCache cache
- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer textureCache:(CVOpenGLESTextureCacheRef)textureCache;

/// 更新 CVPixelBuffer
/// @param pixelBuffer <#pixelBuffer description#>
- (void)update:(CVPixelBufferRef)pixelBuffer;

/// 获取与之绑定的 CVPixelBuffer
- (CVPixelBufferRef)pixelBuffer;

@end

#endif /* PLVGLTexture_h */
