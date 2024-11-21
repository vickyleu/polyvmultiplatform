//
//  PLVBBeautyManager.h
//  PLVBusinessSDK
//
//  Created by junotang on 2022/1/17.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PLVBBeautyDefine.h"
#import <OpenGLES/ES2/glext.h>
#import "PLVBFilterOption.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PLVBBeautyResourceProvider;
@protocol PLVBBeautyManagerDelegate;

/// 美颜管理器
///
/// @note 负责支持 视频数据美颜处理 的功能模块
@interface PLVBBeautyManager : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// 素材和授权的提供者
@property (nonatomic, strong) id <PLVBBeautyResourceProvider> resourceProvider;

@property (nonatomic, weak) id <PLVBBeautyManagerDelegate> delegate;

#pragma mark 数据
/// 美颜类型
@property (nonatomic, assign, readonly) PLVBBeautyType beautyType;

#pragma mark 状态
/// 当前 美颜是否已就绪
@property (nonatomic, assign, readonly) BOOL beautyIsReady;

@property (nonatomic, strong) EAGLContext *eaglContext;

#pragma mark - [ 方法 ]
#pragma mark 基础调用
/// 创建 美颜管理器
///
/// @note 由外部根据频道信息获取到美颜类型值，并在调用此方法时传入；
///       若传入的beautyType值无效，将创建失败，并返回 nil。
///
/// @param beautyType 美颜类型值
+ (instancetype)beautyManagerWithBeautyType:(NSString *)beautyType;


/// 创建初始化美颜SDK
/// @param resourceProvider 素材和授权的提供者
- (int)createBeautyTaskWithResourceProvider:(id<PLVBBeautyResourceProvider>)resourceProvider;

/// 销毁美颜SDK
- (int)destroyTask;

#pragma mark 美颜设置

/// 美颜特效是否支持
/// @param option 美颜特效类型
- (BOOL)isBeautyOptionSupport:(PLVBBeautyOption)option;

/// 更新美颜特效
/// @param option 美颜特效类型
/// @param intensity 强度，0~1
- (void)updateBeautyOption:(PLVBBeautyOption)option withIntensity:(CGFloat)intensity;

/// 移除美颜特效
/// @param option 美颜特效类型
- (void)removeBeautyOption:(PLVBBeautyOption)option;

/// 移除所有美颜特效
- (void)clearBeautyOption;

/// 获取支持的美颜滤镜
- (NSArray<PLVBFilterOption *> *)getSupportFilterOptions;

/// 设置美颜滤镜
/// @param option 滤镜对象
/// @param intensity 强度，0~1
- (void)setFilterOption:(PLVBFilterOption *)option withIntensity:(CGFloat)intensity;

/// 美颜处理，只支持 OpenGL 2D 纹理的输入、输出
/// @param texture 输入纹理
/// @param outputTexture 输出纹理
/// @param width 宽
/// @param height 高
/// @param rotate 算法检测角度
/// @param timeStamp 时间戳
/// @return 0:处理成功 
- (int)processTexture:(GLuint)texture outputTexture:(GLuint)outputTexture width:(int)width height:(int)height rotate:(int)rotate timeStamp:(double)timeStamp;

@end


#pragma mark 美颜素材和授权提供协议
@protocol PLVBBeautyResourceProvider <NSObject>

/// 模型文件路径
- (NSString *)modelDirPath;

/// 滤镜路径
/// @param filterName 滤镜名称
- (NSString *)filterPath:(NSString *)filterName;

/// 贴纸路径
/// @param stickerName 贴纸名称
- (NSString *)stickerPath:(NSString *)stickerName;

/// 特效素材路径
/// @param nodeName 特效名称
- (NSString *)composerNodePath:(NSString *)nodeName;

/// 在线授权文件的保存路径，需要拼接授权文件的名字
- (NSString *)licensePath;

/// 请求在线授权文件需要的key
- (NSString *)licenseKey;

/// 请求在线授权文件需要的Secret
- (NSString *)licenseSecret;

@end

#pragma mark - [ 代理方法 ]
/// 美颜管理器代理
@protocol PLVBBeautyManagerDelegate <NSObject>

- (void)plvbBeautyManager:(PLVBBeautyManager * _Nonnull)manager didOccurError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
