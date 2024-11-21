//
//  PLVFoundationSDK.h
//  PLVFoundationSDK
//
//  Created by zykhbl on 2018/8/2.
//  Copyright © 2018年 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for PLVFoundationSDK.
FOUNDATION_EXPORT double PLVFoundationSDKVersionNumber;

//! Project version string for PLVFoundationSDK.
FOUNDATION_EXPORT const unsigned char PLVFoundationSDKVersionString[];

#import <PLVFoundationSDK/PLVConfig.h>

/*----------- 工具类 ------------*/

// 多语言
#import <PLVFoundationSDK/PLVFDI18NUtil.h>

#import <PLVFoundationSDK/PLVFdUtil.h>
#import <PLVFoundationSDK/PLVDataUtil.h>
#import <PLVFoundationSDK/PLVColorUtil.h>
#import <PLVFoundationSDK/PLVNetworkError.h>
#import <PLVFoundationSDK/PLVFNetworkUtil.h>
#import <PLVFoundationSDK/PLVFFileUtil.h>
#import <PLVFoundationSDK/PLVFWeakProxy.h>
#import <PLVFoundationSDK/PLVViewFrameUtil.h>
#import <PLVFoundationSDK/PLVNetworkAccessibility.h>
#import <PLVFoundationSDK/PLVImageUtil.h>
#import <PLVFoundationSDK/PLVKeyUtil.h>
#import <PLVFoundationSDK/PLVSM2Util.h>
#import <PLVFoundationSDK/PLVFSignConfig.h>

/*----------- 日志类 ------------*/

#import <PLVFoundationSDK/PLVFUserAgentBuilder.h>
#import <PLVFoundationSDK/PLVFBaseLogReporter.h>
#import <PLVFoundationSDK/PLVFLogReporter.h>
#import <PLVFoundationSDK/PLVFELogReporter.h>
#import <PLVFoundationSDK/PLVFViewLogReporter.h>
#import <PLVFoundationSDK/PLVFQosLogReporter.h>
#import <PLVFoundationSDK/PLVFTrackLogReporter.h>
#import <PLVFoundationSDK/PLVFLogModel.h>
#import <PLVFoundationSDK/PLVFViewLogModel.h>
#import <PLVFoundationSDK/PLVFQosLogModel.h>
#import <PLVFoundationSDK/PLVFELogModel.h>
#import <PLVFoundationSDK/PLVFTrackLogModel.h>

/*----------- 错误码 ------------*/

#import <PLVFoundationSDK/PLVFErrorBaseCodeDefine.h>
#import <PLVFoundationSDK/PLVFPlayErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFDownloadErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFUploadErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFRecordErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFRtmpErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFChatErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFLinkErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFPPTErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFInitErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFSocketErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFHttpErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFInteractionErrorCodeGenerator.h>
#import <PLVFoundationSDK/PLVFBeautyErrorCodeGenerator.h>

/*----------- 内部库 ------------*/

// 安全模型
#import <PLVFoundationSDK/PLVSafeModel.h>

// 控制台日志
#import <PLVFoundationSDK/PLVFConsoleLogger.h>

// 日志上报

#import <PLVFoundationSDK/PLVFLogan.h>

// JSBridge
#import <PLVFoundationSDK/PLVJSBridge.h>

// 授权校验
#import <PLVFoundationSDK/PLVAuthorizationManager.h>

/*----------- 重命名开源库 ------------*/

// 浮窗显示
#import <PLVFoundationSDK/PLVProgressHUD.h>

// 网络检测
#import <PLVFoundationSDK/PLVReachability.h>

// WebViewJavascriptBridge
#import <PLVFoundationSDK/PLVFWebViewJavascriptBridge_JS.h>
#import <PLVFoundationSDK/PLVFWebViewJavascriptBridgeBase.h>
#import <PLVFoundationSDK/PLVFWKWebViewJavascriptBridge.h>

// 多播代理
#import <PLVFoundationSDK/PLVMulticastDelegate.h>

