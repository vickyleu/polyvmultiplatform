//
//  PLVFSignConfig.h
//  PLVFoundationSDK
//
//  Created by Sakya on 2023/11/15.
//  Copyright © 2023 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVDataUtil.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLVFSignConfig : NSObject

/// 客户端SM2私钥，解密
@property (nonatomic, copy) NSString *clientSM2PrivateKey;
/// 服务端SM2公钥，参数加密
@property (nonatomic, copy) NSString *serverSM2PublicKey;
/// 接口启用加密的类型，默认不开启加密
@property (nonatomic, assign) PLVEncryptType encryptType;

/// 单例方法
+ (instancetype)sharedInstance;

/// 设置 SM2 加密模式
/// @param serverSM2PublicKey 服务端SM2公钥，参数加密
/// @param clientSM2PrivateKey 客户端SM2私钥，解密
- (void)setSM2EncryptTypeWithServerSM2PublicKey:(NSString *)serverSM2PublicKey clientSM2PrivateKey:(NSString *)clientSM2PrivateKey;

@end

NS_ASSUME_NONNULL_END
