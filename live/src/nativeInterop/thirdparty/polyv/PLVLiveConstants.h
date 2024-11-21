//
//  PLVLiveConstants.h
//  PLVLiveScenesSDK
//
//  Created by Sakya on 2021/7/25.
//  Copyright © 2021 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 * 定义项目中URL地常量，包含默认图片地址、前端页面地址。
 */

#pragma mark - 默认图片地址常量

/// 聊天室 - 默认老师头像地址
extern NSString *const PLVLiveConstantsChatroomTeacherAvatarURL;

/// 房间 - 手机设备图片地址
extern NSString *const PLVLiveConstantsRoomEffectDeviceIconURL;

#pragma mark - URL地址

/// 图文加载的URL
extern NSString *const PLVLiveConstantsLiveFrontPictureTextURL;

/// 互动WebView URL
extern NSString *const PLVLiveConstantsInteractTriviaCardURL;

/// 新版 互动WebView URL  [协议改造]
extern NSString *const PLVLiveConstantsInteractNewWebViewURL;

/// 推流端 互动WebView URL  
extern NSString *const PLVLiveConstantsStreamerInteractWebViewURL;

/// Document PPT文档加载HTML
extern NSString *const PLVLiveConstantsDocumentPPTForMobileHTML;

/// 问答模块URL
extern NSString *const PLVLiveConstantsWatchQAURL;

/// 容器 PPT文档加载HTML
extern NSString *const PLVLiveConstantsContainerPPTForMobileHTML;

/// 边看边买 商品列表 HTML
extern NSString *const PLVLiveConstantsProductListHTML;

/// 直播间分享海报的基础 HTML
extern NSString *const PLVLiveConstantsPosterShareHTML;

/// 手机开播 直播间商品库管理 HTML
extern NSString *const PLVLiveConstantsStreamerProductHTML;
