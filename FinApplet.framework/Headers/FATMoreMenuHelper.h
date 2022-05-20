//
//  FATMoreMenuHelper.h
//  FinApplet
//
//  Created by 滔 on 2022/5/9.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATMoreMenuHelper : NSObject

/// 触发转发事件，用来获取转发时用到的小程序信息， 获取到小程序信息后，会触发- (void)forwardAppletWithInfo:(NSDictionary *)contentInfo completion:(void (^)(FATExtensionCode, NSDictionary *))completion 这个回调
/// @param appletId  小程序id
+ (void)invokeForwardMenuAction:(NSString *)appletId;


/// 打开小程序的意见反馈页面
/// @param appletId  小程序id
+ (void)goToFeedbackPage:(NSString *)appletId;


/// 打开小程序的关于页面
/// @param appletId  小程序id
+ (void)goToAboutPage:(NSString *)appletId;


/// 打开小程序的设置页面
/// @param appletId  小程序id
+ (void)goToSettingPage:(NSString *)appletId;


/// 打开/关闭小程序的debug模式  如果config设置了enableAppletDebug为ture，执行打开/关闭debug模式操作会无效
/// @param appletId  小程序id
/// @param enable  允许debug模式
+ (void)setEnableAppletDebug:(NSString *)appletId enable:(BOOL)enable;


/// 获取小程序是否打开debug模式
/// @param appletId  小程序id
+ (BOOL)isEnableAppletDebug:(NSString *)appletId;


/// 获取自定义菜单项的数据(需要小程序配合实现的菜单项，需要小程序提供额外调用参数)
/// @param appletId  小程序id
/// @param menuId 菜单id
/// @param complete  结果回调
+ (void)getMiniProgramTypeMenuData:(NSString *)appletId menuId:(NSString *)menuId complete:(void(^)(NSDictionary *result,FATAppletInfo *appletInfo))complete;
@end

NS_ASSUME_NONNULL_END
