//
//  FATConstant.h
//  FinApplet
//
//  Created by Haley on 2019/3/29.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#ifndef FATConstant_h
#define FATConstant_h

typedef NS_ENUM(NSInteger, FATExtensionCode) {
    FATExtensionCodeCancel = -1, //取消
    FATExtensionCodeSuccess = 0, //成功
    FATExtensionCodeFailure = 1, //失败
};

typedef NS_ENUM(NSUInteger, FATTranstionStyle) {
    FATTranstionStyleUp,   // 页面从下往上弹出，类似present效果
    FATTranstionStylePush, // 页面从右往左弹出，类似push效果
};

typedef NS_ENUM(NSUInteger, FATApiCryptType) {
    FATApiCryptTypeMD5, // MD5
    FATApiCryptTypeSM,  // 国密MD5
};

typedef NS_ENUM(NSUInteger, FATMoreViewStyle) {
    FATMoreViewStyleDefault,
    FATMoreViewStyleNormal
};

typedef NS_ENUM(NSUInteger, FATAppletMenuStyle) {
    FATAppletMenuStyleCommon = 0,
    FATAppletMenuStyleOnMiniProgram
};

typedef NS_ENUM(NSUInteger, FATCrashProtectionType) {
    FATCrashProtectionTypeNone = 0,
    FATCrashProtectionTypeUnrecognizedSelector = 1 << 1,
    FATCrashProtectionTypeKVOCrash = 1 << 2,
    FATCrashProtectionTypeTimerCrash = 1 << 3,
    FATCrashProtectionTypeNotificationCrash = 1 << 4,
    FATCrashProtectionTypeContainerCrash = 1 << 5,
    FATCrashProtectionTypeStringCrash = 1 << 6,
    FATCrashProtectionTypeJSONSerializationCrash = 1 << 7,

    FATCrashProtectionTypeAll = FATCrashProtectionTypeUnrecognizedSelector | FATCrashProtectionTypeKVOCrash | FATCrashProtectionTypeTimerCrash | FATCrashProtectionTypeNotificationCrash | FATCrashProtectionTypeContainerCrash | FATCrashProtectionTypeStringCrash | FATCrashProtectionTypeJSONSerializationCrash
};

typedef NS_ENUM(NSUInteger, FATAppletVersionType) {
    FATAppletVersionTypeRelease,    // 正式版，默认值
    FATAppletVersionTypeTrial,      // 体验版
    FATAppletVersionTypeTemporary,  // 临时版，IDE预览版
    FATAppletVersionTypeReview,     // 审核版
    FATAppletVersionTypeDevelopment // 开发版
};

typedef NS_ENUM(NSUInteger, FATAppletLifeCycle) {
    FATAppletLifeCycleUnknow,     // 未知阶段
    FATAppletLifeCycleLaunch,     // 启动阶段
    FATAppletLifeCycleActive,     // 运行阶段
    FATAppletLifeCycleBackground, // 后台阶段
};

/**
 扩展API处理后的回调
 
 @param code 处理结果码
 @param result 处理结果数据
 */
typedef void (^FATExtensionApiCallback)(FATExtensionCode code, NSDictionary<NSString *, NSObject *> *result);

#pragma mark - 启动小程序时的启动参数
typedef NSString *FATStartParamKey NS_REFINED_FOR_SWIFT;

FOUNDATION_EXTERN FATStartParamKey const FATStartParamPath;
FOUNDATION_EXTERN FATStartParamKey const FATStartParamQuery;
FOUNDATION_EXTERN FATStartParamKey const FATStartParamScene;

typedef NSString *FATShareMediaType NS_REFINED_FOR_SWIFT;

FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeText;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeImage;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeMusic;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeVideo;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeWebPage;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeMiniProgram;

// 本地缓存的最近使用的小程序列表变更
FOUNDATION_EXTERN NSString *const kRecentUsedAppletListDidChangeNotification;

#pragma mark - 小程序生命周期事件通知

//小程序关闭通知，ViewController和View可以监听 userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletCloseNotification;

//小程序进入后台 ViewController和View可以监听 userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletEnterBackgroundNotification;
//

#endif /* FATConstant_h */
