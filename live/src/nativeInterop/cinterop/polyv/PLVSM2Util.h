//
//  PLVSM2Util.h
//  PLVFoundationSDK
//
//  Created by Sakya on 2023/11/14.
//  Copyright © 2023 PLV. All rights reserved.
//
// SM2 加密的接口工具类

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVSM2Util : NSObject

#pragma mark - 创建秘钥对
/// 创建 SM2 公私钥（基于官方文档 NID_sm2 推荐曲线）。返回值：数组元素 1 为公钥，2 为私钥
+ (NSArray<NSString *> *)createKeyPair;

#pragma mark - 椭圆曲线类型
/// 常见椭圆曲线为 NID_sm2、NID_secp256k1、NID_X9_62_prime256v1
/// 默认 NID_sm2
/// 若需要其他曲线，在 OpenSSL 源码 crypto/ec/ec_curve.c 查找
+ (void)setEllipticCurveType:(int)curveType;

#pragma mark - SM2 加密
/// SM2 加密 返回值：加密后的字符串（密文都为 Hex 格式， C1C2C3，04开头 ），失败返回 nil
/// @param plainString 明文（普通字符串格式）
/// @param publicKey 04 开头的公钥（ Hex 编码格式）
+ (NSString *)formatEncryptString:(NSString *)plainString publicKey:(NSString *)publicKey;

/// SM2 加密 返回值：加密后的字符串（密文都为 ASN1 编码格式， C1C3C2 ），失败返回 nil
/// @param plainString 明文（普通字符串格式）
/// @param publicKey 04 开头的公钥（ Hex 编码格式）
+ (nullable NSString *)encryptString:(NSString *)plainString publicKey:(NSString *)publicKey;

#pragma mark - SM2 解密
/// SM2 解密 返回值：普通明文，解密失败返回 nil
/// @param ciphertext 密文（ASN1 编码格式，C1C2C3，有 04 前缀）
/// @param privateKey 私钥（ Hex 编码格式）
+ (nullable NSString *)formatDecryptString:(NSString *)ciphertext privateKey:(NSString *)privateKey;

/// SM2 解密 返回值：普通明文，解密失败返回 nil
/// @param ciphertext 密文（ASN1 编码格式，C1C3C2，无 04 前缀）
/// @param privateKey 私钥（ Hex 编码格式）
+ (nullable NSString *)decryptString:(NSString *)ciphertext privateKey:(NSString *)privateKey;

#pragma mark - 密文格式转换
/// C1C2C3 顺序的 Hex 格式密文转为 C1C3C2 顺序。返回值：C1C3C2 顺序排列的 Hex 格式密文，失败返回 nil
/// @param ciphertext  按照 C1C2C3 顺序排列的 Hex 格式密文
/// @param hasPrefix 是否包含密文标识，默认 NO 没有标识，e.g. Java 端 BouncyCastle 库密文可能会带 04 前缀标识
+ (nullable NSString *)convertC1C2C3ToC1C3C2:(NSString *)ciphertext hasPrefix:(BOOL)hasPrefix;

/// C1C3C2 顺序的 Hex 格式密文转为 C1C2C3 顺序。返回值：C1C2C3 顺序排列的 Hex 格式密文，失败返回 nil
/// @param ciphertext 按照 C1C3C2 顺序排列的 Hex 格式密文
/// @param hasPrefix 是否包含密文标识，默认 NO 没有标识，e.g. Java 端 BouncyCastle 库密文可能会带 04 前缀标识
+ (nullable NSString *)convertC1C3C2ToC1C2C3:(NSString *)ciphertext hasPrefix:(BOOL)hasPrefix;

#pragma mark - ASN1 编码解码
/// ASN1  编码 对 c1c3c2 格式密文进行 ASN1 编码，返回值：ASN1 编码后的密文。
/// 参数：c1c3c2Hex 密文（字符串拼接 c1c3c2）
/// @param c1c3c2Hex 原始密文（c1c3c2 直接拼接的密文字符串， Hex 格式）
+ (nullable NSString *)asn1EncodeWithC1C3C2:(NSString *)c1c3c2Hex;

/// ASN1  解码 对 ASN1 格式的密文解码，返回值：解码后的密文
/// 返回值样式：c1c3c2 直接拼接；数组依次存放 @[c1,c3,c2]
/// @param asn1Hex ASN1 编码格式的密文（Hex 格式）
+ (nullable NSString *)asn1DecodeToC1C3C2:(NSString *)asn1Hex;
+ (nullable NSArray<NSString *> *)asn1DecodeToC1C3C2Array:(NSString *)asn1Hex;

@end

NS_ASSUME_NONNULL_END
