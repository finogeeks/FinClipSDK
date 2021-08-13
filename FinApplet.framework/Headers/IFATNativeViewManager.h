//
//  IFATNativeViewManager.h
//  FinApplet
//
//  Created by Haley on 2021/3/11.
//

#import <Foundation/Foundation.h>
#import "FATAppletNativeProtocol.h"

@protocol IFATNativeViewManager <NSObject>

@property (nonatomic, strong) Class<FATAppletNativeCameraProtocol> cameraClass;
@property (nonatomic, strong) Class<FATAppletNativeLivePlayerProtocol> livePlayerClass;
@property (nonatomic, strong) Class<FATAppletNativeLivePusherProtocol> livePusherClass;

- (BOOL)registerNativeViewType:(NSString *)type nativeViewClass:(Class<FATAppletNativeViewProtocol>)nativeViewClass;

/// 给nativeView 发送事件
/// @param eventName 事件名称
/// @param nativeViewId native-view id
/// @param detail 事件详细参数
/// @param completion 完成回调
- (void)sendEvent:(NSString *)eventName nativeViewId:(NSNumber *)nativeViewId detail:(NSDictionary *)detail completion:(void (^)(id result, NSError *error))completion;

/// 发送 全局 事件
/// @param detail 事件详细参数
/// @param completion 完成回调
- (void)sendCustomEventWithDetail:(NSDictionary *)detail completion:(void (^)(id result, NSError *error))completion;

@end
