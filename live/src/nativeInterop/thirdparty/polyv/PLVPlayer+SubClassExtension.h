//
//  PLVPlayer+SubClassExtension.h
//  PLVLiveScenesSDK
//
//  Created by Lincal on 2020/12/9.
//  Copyright © 2020 PLV. All rights reserved.
//

#import "PLVPlayer.h"

NS_ASSUME_NONNULL_BEGIN

/// 面向 PLVPlayer 子类准备的扩展声明
///
/// @note 仅当您需要创建一个 PLVPlayer 子类时，需要认识此文件；
///       该文件中声明的方法，仅提供给 PLVPlayer 子类使用；
///       请子类实现以下方法。实现后，将在适当时机中，接收到方法的调用；
@interface PLVPlayer ()

- (void)callSubClassMoviePlayerLoadStateDidChange:(PLVPlayerMainSubType)mainSubType;

- (void)callSubClassMoviePlayerPlaybackStateDidChange:(PLVPlayerMainSubType)mainSubType;

- (void)callSubClassPlaybackDidFinish:(PLVPlayerMainSubType)mainSubType withReason:(IJKMPMovieFinishReason)finishReson;

- (void)callSubClassMoviePlayerWillDestroy:(PLVPlayerMainSubType)mainSubType;

- (void)callSubClassMoviePlayerFirstVideoFrameRendered:(PLVPlayerMainSubType)mainSubType time:(int)time;

@end

NS_ASSUME_NONNULL_END
