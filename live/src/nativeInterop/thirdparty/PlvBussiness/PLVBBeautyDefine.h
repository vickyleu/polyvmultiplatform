//
//  PLVBBeautyDefine.h
//  PolyvBusinessSDK
//
//  Created by junotang on 2022/1/17.
//  Copyright © 2022 PLV. All rights reserved.
//

#ifndef PLVBBeautyDefine_h
#define PLVBBeautyDefine_h

/// 美颜厂商类型
typedef NS_ENUM(NSInteger, PLVBBeautyType) {
    PLVBBeautyType_BE = 1, // BytedEffect
};

/// 美颜特效类型
typedef NS_ENUM(NSInteger, PLVBBeautyOption) {
    PLVBBeautyOption_BeautyWhiten = 0,              //!< 美颜 - 美白
    PLVBBeautyOption_BeautySharp = 1,               //!< 美颜 - 锐化
    PLVBBeautyOption_BeautySmooth = 2,              //!< 美颜 - 磨皮
    PLVBBeautyOption_ReshapeDeformOverAll = 3,      //!< 微整形 - 瘦脸
    PLVBBeautyOption_ReshapeDeformEye = 4,          //!< 微整形 - 眼睛大小调整
    PLVBBeautyOption_ReshapeDeformNose = 5,         //!< 微整形 - 鼻翼调整
    PLVBBeautyOption_ReshapeDeformZoomMouth = 6,    //!< 微整形 - 嘴巴大小调整
    PLVBBeautyOption_ReshapeDeformForeHead = 7,     //!< 微整形 - 发际线调整
    PLVBBeautyOption_ReshapeDeformZoomJawbone = 8,  //!< 微整形 - 下颌调整
    PLVBBeautyOption_ReshapeBeautyWhitenTeeth = 9,  //!< 微整形 - 白牙
    PLVBBeautyOption_ReshapeBeautyBrightenEye = 10, //!< 微整形 - 亮眼
};

#endif /* PLVBBeautyDefine_h */
