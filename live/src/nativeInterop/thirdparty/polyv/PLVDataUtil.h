//
//  PLVDataUtil.h
//  PLVNetworkSDK
//
//  Created by zykhbl on 2018/7/30.
//  Copyright © 2018年 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 只在SDK内部使用，不向外提供
 NSData数据处理通用工具类
 */

/// 加密类型
typedef NS_ENUM(NSUInteger, PLVEncryptType) {
    PLVEncryptType_None = 0,        ///  不开启加密
    PLVEncryptType_AES  = 1,        ///  AES 加密 【如果加密的话没设置SM2加密则默认AES加密】
    PLVEncryptType_SM2  = 2         ///  SM2 加密
};

@interface PLVDataUtil : NSObject

#pragma mark - MD5
/**
 MD5 加密方法
 @note 当传入的参数为非法空字符(如：nil、NSNull)时返回""
 @param input 待加密的字符串
 @return 32 位小写加密串
 */
+ (NSString *)md5HexDigest:(NSString *)input;

/// 获取文件MD5加密值
/// @param filePath 文件路径
+ (NSString *)md5OfFile:(NSString *)filePath;

#pragma mark - 二进制/十六进制
/**
 二进制转十六进制
 
 @param data 二进制
 @return 十六进制字符串
 */
+ (NSString *)hexStringFromData:(NSData *)data;

/**
 十六进制字符串转二进制
 
 @param hexString 十六进制字符串
 @return 二进制
 */
+ (NSData *)dataForHexString:(NSString *)hexString;

#pragma mark - AES 128
/**
 AES 128 加密
 
 @param data 待加密的数据
 @param key key 值
 @param iv iv 向量值
 @return 加密后的 data 数据
 */
+ (NSData *)AES128EncryptData:(NSData *)data withKey:(NSString *)key iv:(NSString *)iv;

/**
 AES 128 解密
 
 @param data 待解密数据
 @param key key 值
 @param iv iv 向量值
 @return 解密的 data 数据
 */
+ (NSData *)AES128DecryptData:(NSData *)data withKey:(NSString *)key iv:(NSString *)iv;

#pragma mark - AES 256
/**
 AES 256 加密
 
 @param data 待加密的数据
 @param key key 值
 @param iv iv 向量值
 @return 加密后的 data 数据
 */
+ (NSData *)AES256EncryptData:(NSData *)data withKey:(NSString *)key iv:(NSString *)iv;

/**
 AES 256 解密
 
 @param data 待解密数据
 @param key key 值
 @param iv iv 向量值
 @return 解密的 data 数据
 */
+ (NSData *)AES256DecryptData:(NSData *)data withKey:(NSString *)key iv:(NSString *)iv;

#pragma mark - URL SafeBase64

/**
 普通字符的URL safeBase64 编码
 @note 当传入的参数为非法空字符(如：nil、NSNull)时返回""
 @param string 待编码字符串
 @return 编码的 safeBase64 字符串
 */
+ (NSString *)safeUrlBase64Encode:(NSString *)string;

/**
 URL safeBase64 字符解码
 
 @param safeUrlbase64Str 编码的 safeBase64 字符串
 @return data base64 数据
 */
+ (NSData *)safeUrlBase64Decode:(NSString *)safeUrlbase64Str;


/// Base64 编码
/// @note 当传入的参数为非法空字符(如：nil、NSNull)时返回""
/// @param inputString 待编码字符串
/// @return Base64编码后的字符串
+ (NSString *)base64String:(NSString *)inputString;

/// url safe Base64 编码
/// @note 当传入的参数为非法空字符(如：nil、NSNull)时返回""
/// @param inputString  待编码字符串
/// @return Base64编码后的字符串
+ (NSString *)urlSafeBase64String:(NSString *)inputString;

/// SHA1 加密
/// @note 当传入的参数为非法空字符(如：nil、NSNull)时返回""
/// @param inputString 待机密字符串
/// @return SHA1加密后的字符串
+ (NSString *)sha1String:(NSString *)inputString;

/// SHA256 加密
/// @note 当传入的参数为非法空字符(如：nil、NSNull)时返回""
/// @param inputString 待机密字符串
/// @return SHA256加密后的字符串
+ (NSString *)sha256String:(NSString *)inputString;

/// AES-128 加密，不使用加密向量
+ (NSData *)AES128EncryptedDataWithKey:(NSString *)key data:(NSData *)data;

/// AES-128 解密，不使用加密向量
+ (NSData *)AES128DecryptedDataWithKey:(NSString *)key data:(NSData *)data;

/// AES-128 加密
+ (NSData *)AES128EncryptedDataWithKey:(NSString *)key iv:(NSString *)iv data:(NSData *)data;

/// AES-128 解密
+ (NSData *)AES128DecryptedDataWithKey:(NSString *)key iv:(NSString *)iv data:(NSData *)data;

+ (NSData *)AES128Operation:(uint32_t)operation key:(NSData *)keyData iv:(NSData *)ivData data:(NSData *)contentData;

/// 十六进制字符串转NSData
+ (NSData *)dataWithHexString:(NSString *)hexString;

#pragma mark 数据格式转换

+ (NSString *)jsonStringWithJSONObject:(id)jsonObject;

+ (id)dictionaryWithJsonString:(NSString *)jsonString;

@end
