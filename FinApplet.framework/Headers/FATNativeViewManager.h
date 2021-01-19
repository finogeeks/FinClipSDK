//
//  FATNativeViewManager.h
//  FinApplet
//
//  Created by hujianhui on 2020/11/24.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FATAppletNativeProtocol.h"
extern NSString * const FATNativeViewTypeCamera; //@"camera";
extern NSString * const FATNativeViewTypeLivePlayer;//@"live-player";
extern NSString * const FATNativeViewTypeLivePusher;//@"live-pusher";


@interface FATNativeViewManager : NSObject

+ (instancetype)shareInstance;

+ (NSNumber *)fat_showNativeViewWithParamString:(NSString *)paramString;

/// 更新原生NativeView组件
/// @param paramString 原生NativeView组件参数
+ (void)fat_updateNativeViewWithParamString:(NSString *)paramString;

/// 隐藏原生NativeView组件
/// @param paramString 原生NativeView组件参数
+ (void)fat_hideNativeViewWithParamString:(NSString *)paramString;

+ (UIView <FATAppletNativeViewProtocol>*)fat_getNativeViewWithParamString:(NSString *)paramString;

+ (UIView <FATAppletNativeViewProtocol>*)fat_getNativeViewWithID:(NSInteger)ID;

/// 原生传递事件给NativeView组件
/// @param eventName 原生NativeView组件参数 
+ (void)fat_onNativeViewTask:(NSString *)eventName nativeViewId:(NSNumber *)nativeViewId detail:(NSDictionary *)detail callback:(void (^)(id result, NSError *error))callback;

//原生传递事件给全局
+ (void)fat_onCustomEvent:(NSDictionary *)params callback:(void (^)(id result, NSError *error))callback;

@property (nonatomic, assign) Class<FATAppletNativeCameraProtocol>     cameraClass;
@property (nonatomic, assign) Class<FATAppletNativeLivePlayerProtocol> livePlayerClass;
@property (nonatomic, assign) Class<FATAppletNativeLivePusherProtocol> livePusherClass;

@end


