//
//  PLVFdUtil.h
//  PLVFoundationSDK
//
//  Created by ftao on 2019/8/28.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define PLV_iOSVERSION_Compared(version) [version compare:[[UIDevice currentDevice] systemVersion] options:NSNumericSearch]
#define PLV_iOSVERSION_Ascending_Same(version) ((PLV_iOSVERSION_Compared(version) == NSOrderedAscending) || (PLV_iOSVERSION_Compared(version) == NSOrderedSame))

/// iOS系统版本判断
#define PLV_iOSVERSION_Available_8_2 PLV_iOSVERSION_Ascending_Same(@"8.2")
#define PLV_iOSVERSION_Available_9_0 PLV_iOSVERSION_Ascending_Same(@"9.0")
#define PLV_iOSVERSION_Available_10_0 PLV_iOSVERSION_Ascending_Same(@"10.0")
#define PLV_iOSVERSION_Available_11_0 PLV_iOSVERSION_Ascending_Same(@"11.0")
#define PLV_iOSVERSION_Available_13_0 PLV_iOSVERSION_Ascending_Same(@"13.0")
#define PLV_iOSVERSION_Available_(versionString) PLV_iOSVERSION_Ascending_Same(versionString)

/// 主线程保护
#ifndef plv_dispatch_main_async_safe
#define plv_dispatch_main_async_safe(block)\
    if (dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(dispatch_get_main_queue())) {\
        block();\
    } else {\
        dispatch_async(dispatch_get_main_queue(), block);\
    }
#endif

#define PLVScreenWidth ([UIScreen mainScreen].bounds.size.width)
#define PLVScreenHeight ([UIScreen mainScreen].bounds.size.height)

/// 返回安全对象类型或nil
NSString* PLV_SafeStringForValue(id value);
NSArray* PLV_SafeArraryForValue(id value);
NSDictionary* PLV_SafeDictionaryForValue(id value);

/// 安全取值
BOOL PLV_SafeBoolForValue(id value);
float PLV_SafeFloatForValue(id value);
NSInteger PLV_SafeIntegerForValue(id value);

/// 返回安全对象类型或nil
NSString* PLV_SafeStringForDictKey(NSDictionary *dict, NSString *aKey);
NSArray* PLV_SafeArraryForDictKey(NSDictionary *dict, NSString *aKey);
NSDictionary* PLV_SafeDictionaryForDictKey(NSDictionary *dict, NSString *aKey);

/// 安全取值
BOOL PLV_SafeBoolForDictKey(NSDictionary *dict, NSString *aKey);
float PLV_SafeFloatForDictKey(NSDictionary *dict, NSString *aKey);
NSInteger PLV_SafeIntegerForDictKey(NSDictionary *dict, NSString *aKey);

static inline void plv_dict_set(NSMutableDictionary *mDict, id aKey, id anObject) {
    if (anObject) {
        [mDict setObject:anObject forKey:aKey];
    }
}

CGFloat P_SafeAreaTopEdgeInsets(void);     // 安全区域上边距
CGFloat P_SafeAreaLeftEdgeInsets(void);    // 安全区域左边距
CGFloat P_SafeAreaBottomEdgeInsets(void);  // 安全区域下边距
CGFloat P_SafeAreaRightEdgeInsets(void);   // 安全区域右边距

NSError * PLVErrorCreate(NSString *domain, NSInteger code, NSString *errorDescription); /// 错误对象生成
NSError * PLVErrorWithUnderlyingError(NSError *error, NSError *underlyingError); /// 错误对象拼接
NSInteger PLVErrorLastErrorCode(NSError *error); /// 读取最后一个错误对象的code值 (最多读取5个)

/// Foundation 通用工具类
@interface PLVFdUtil : NSObject

#pragma mark - Dic&ArrayUtil

/// 检查字典是否可用 (YES-可用；NO-不可用；‘可用’代表不为空、NSDictionary类型、count大于0)
+ (BOOL)checkDictionaryUseable:(NSDictionary *)dict;

/// 检查数组是否可用 (YES-可用；NO-不可用；‘可用’代表不为空、NSArray类型、count大于0)
+ (BOOL)checkArrayUseable:(NSArray *)array;

#pragma mark - StringUtil

/// 字符串的URL编码
+ (NSString *)URLEncodedString:(NSString *)url;

/// 将 url 链接封装上 https 协议头
+ (NSString *)packageURLStringWithHTTPS:(NSString *)urlString;

/// 检查字符串是否可用 (YES-可用；NO-不可用；‘可用’代表不为空、NSString类型、length大于0)
+ (BOOL)checkStringUseable:(NSString *)string;

/// url string 安全的 percent-encoding，防止已 percent-encoding 的字符串二次编码
+ (NSString *)stringBySafeAddingPercentEncoding:(NSString *)urlStr;

+ (NSString *)cutSting:(NSString *)string WithCharacterLength:(NSInteger)length;

#pragma mark - UILabel Util

/// 寻找UILabel中对应的点所在位置字体属性
+ (NSDictionary *)textAttributesAtPoint:(CGPoint)point withLabel:(UILabel *)label;

#pragma mark - ImageUtil

+ (void)setImageWithURL:(NSURL *)url inImageView:(UIImageView *)imageView completed:(void(^)(UIImage *image, NSError *error, NSURL *imageURL))completedBlock;

#pragma mark - DateUtil

+ (long long)curTimeInterval;

/** 获取当前时间的13位毫秒时间戳
 @return long long 适配4s 32位机型
 */
+ (NSString *)curTimeStamp;

/// 秒时间转字符串
+ (NSString *)secondsToString:(NSTimeInterval)seconds;

/// 秒时间转字符串（固定格式） 格式 00:00:00
+ (NSString *)secondsToString2:(NSTimeInterval)seconds;

/// 字符串转时间
+ (NSTimeInterval)secondsToTimeInterval:(NSString *)timeString;

#pragma mark - HudUtil
/// HUD 提示
+ (void)showHUDWithTitle:(nullable NSString * )title detail:(nullable NSString *)detail view:(nonnull UIView *)view;

#pragma mark - Common

+ (UIViewController * _Nonnull)getCurrentViewController;

/// 获取UIApplication里面第一个UIWindow对象
+ (UIWindow *_Nonnull)getFirstUIWindowFormUIApplication;

#pragma mark - Device

+ (BOOL)isiPhoneXSeries;

/// 将屏幕转至竖屏
+ (void)changeDeviceOrientationToPortrait;

/// 将屏幕旋转至相应方向
+ (void)changeDeviceOrientation:(UIDeviceOrientation)orientation;

/// 获取设备型号名
///
/// @note 示例:iPhone XS
+ (NSString * _Nullable)getiPhoneTypeName;

#pragma mark - Alert

/// 弹系统提示窗
///
/// @param title 提示窗标题
/// @param message 提示窗描述
/// @param viewController 负责模态的控制器
/// @param cancelActionTitle 取消按钮的文本（若传nil，则默认为‘取消’）
/// @param confirmActionTitle 确认按钮的文本（若传nil，则无此按钮）
/// @param confirmActionBlock 确认按钮的点击事件
+ (void)showAlertWithTitle:(nullable NSString *)title
                   message:(nullable NSString *)message
            viewController:(nonnull UIViewController *__weak)viewController
         cancelActionTitle:(nullable NSString *)cancelActionTitle
        confirmActionTitle:(nullable NSString *)confirmActionTitle
        confirmActionBlock:(nullable void(^)(UIAlertAction * _Nonnull action))confirmActionBlock;

/// 弹系统提示窗
///
/// @param title 提示窗标题
/// @param message 提示窗描述
/// @param viewController 负责模态的控制器
/// @param cancelActionTitle 取消按钮的文本（若传nil，则默认为‘取消’）
/// @param cancelActionStyle 取消按钮的样式
/// @param cancelActionBlock 取消按钮的点击事件
/// @param confirmActionTitle 确认按钮的文本（若传nil，则无此按钮）
/// @param confirmActionStyle 确认按钮的样式
/// @param confirmActionBlock 确认按钮的点击事件
+ (void)showAlertWithTitle:(nullable NSString *)title
                   message:(nullable NSString *)message
            viewController:(nonnull UIViewController *__weak)viewController
         cancelActionTitle:(nullable NSString *)cancelActionTitle
         cancelActionStyle:(UIAlertActionStyle)cancelActionStyle
         cancelActionBlock:(nullable void(^)(UIAlertAction * _Nonnull action))cancelActionBlock
        confirmActionTitle:(nullable NSString *)confirmActionTitle
        confirmActionStyle:(UIAlertActionStyle)confirmActionStyle
        confirmActionBlock:(nullable void(^)(UIAlertAction * _Nonnull action))confirmActionBlock;

@end
