//
//  FATConstant.h
//  FinApplet
//
//  Created by Haley on 2019/3/29.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#ifndef FATConstant_h
#define FATConstant_h

typedef NS_ENUM(NSInteger,FATExtensionCode) {
    FATExtensionCodeCancel  = -1,  //取消
    FATExtensionCodeSuccess = 0,   //成功
    FATExtensionCodeFailure = 1,   //失败
};

typedef NS_ENUM(NSUInteger, FATTranstionStyle) {
    FATTranstionStyleUp,            // 页面从下往上弹出，类似present效果
    FATTranstionStylePush,          // 页面从右往左弹出，类似push效果
};

/**
 扩展API处理后的回调
 
 @param code 处理结果码
 @param result 处理结果数据
 */
typedef void (^FATExtensionApiCallback)(FATExtensionCode code, NSDictionary<NSString *, NSObject *> *result);

typedef NSString* FATShareMediaType NS_REFINED_FOR_SWIFT;

FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeText;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeImage;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeMusic;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeVideo;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeWebPage;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeMiniProgram;

// 本地缓存的最近使用的小程序列表变更
FOUNDATION_EXTERN NSString *const kRecentUsedAppletListDidChangeNotification;

#endif /* FATConstant_h */
