//
// WebViewJavascriptBridge 6.0.3 私有化，修改如下：
// 1. 类名、静态方法名增加 PLVF 前缀
// 2. 移除类 WebViewJavascriptBridge，因为里面包含了 UIWebView，防止审核不通过
//

#import <Foundation/Foundation.h>

NSString * PLVFWebViewJavascriptBridge_js(void);
