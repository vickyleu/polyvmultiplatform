//
//  PLVWErrorManager.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/2/11.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVFoundationSDK/PLVFErrorBaseCodeDefine.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVWErrorManagerProtocol <NSObject>

@optional

- (NSString *)customLocalizedDescriptionWithModul:(PLVFErrorCodeModul)modul code:(NSInteger)code;

- (NSString *)customHelpAnchorErrorWithModul:(PLVFErrorCodeModul)modul code:(NSInteger)code;

@end

@interface PLVWErrorManager : NSObject

/// 用来自定义错误码描述的 delegate
/// 注意：该 delegate 是单代理，不是多代理
@property (nonatomic, weak) NSObject<PLVWErrorManagerProtocol> *delegate;

+ (instancetype)sharedManager;

- (NSError *)errorWithModul:(PLVFErrorCodeModul)modul code:(NSInteger)code;

@end

NS_ASSUME_NONNULL_END
