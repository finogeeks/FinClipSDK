//
//  IFATNativeViewManager.h
//  FinApplet
//
//  Created by Haley on 2021/3/11.
//

#import <Foundation/Foundation.h>
#import "FATAppletNativeProtocol.h"
#import "FATError.h"

@protocol IFATNativeViewManager <NSObject>

@property (nonatomic, strong) Class<FATAppletNativeCameraProtocol> cameraClass;
@property (nonatomic, strong) Class<FATAppletNativeLivePlayerProtocol> livePlayerClass;
@property (nonatomic, strong) Class<FATAppletNativeLivePusherProtocol> livePusherClass;

- (BOOL)registerNativeViewType:(NSString *)type nativeViewClass:(Class<FATAppletNativeViewProtocol>)nativeViewClass;

/// 给nativeView 发送事件（前台运行的小程序）
/// @param eventName 事件名称
/// @param nativeViewId native-view id
/// @param detail 事件详细参数
/// @param completion 完成回调：error code为FATErrorCodeAppletNotFound，未找到前台运行的小程序
- (void)sendEvent:(NSString *)eventName nativeViewId:(NSNumber *)nativeViewId detail:(NSDictionary *)detail completion:(void (^)(id result, FATError *error))completion;

/// 发送 全局 事件（前台运行的小程序）
/// @param detail 事件详细参数
/// @param completion 完成回调：error code为FATErrorCodeAppletNotFound，未找到前台运行的小程序
- (void)sendCustomEventWithDetail:(NSDictionary *)detail completion:(void (^)(id result, FATError *error))completion;

/// 给nativeView 发送事件（appletId指定的小程序）
/// @param eventName 事件名称
/// @param appletId 小程序的appId, 不能为空
/// @param nativeViewId native-view id
/// @param detail 事件详细参数
/// @param completion 完成回调：error code为FATErrorCodeForegroundAppletNotFound，未找到appletId指定小程序
- (void)sendEvent:(NSString *)eventName applet:(NSString *)appletId nativeViewId:(NSNumber *)nativeViewId detail:(NSDictionary *)detail completion:(void (^)(id result, FATError *error))completion;

/// 发送 全局 事件（appletId指定的小程序）
/// @param detail 事件详细参数
/// @param appletId 小程序的appId, 不能为空
/// @param completion 完成回调：error code为FATErrorCodeForegroundAppletNotFound，未找到appletId指定小程序
- (void)sendCustomEventWithDetail:(NSDictionary *)detail applet:(NSString *)appletId completion:(void (^)(id result, FATError *error))completion;

@end
