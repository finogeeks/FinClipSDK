//
//  FATAppletDelegate.h
//  FinApplet
//
//  Created by Haley on 2019/11/4.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletMenuProtocol.h"
#import "FATConstant.h"
#import "FATAppletInfo.h"

@protocol FATAppletDelegate <NSObject>

@optional
/** 转发事件
 当你点击小程序右上角更多里的转发菜单时，会触发小程序里shareAppMessage方法，然后回调到原生该方法
 @param contentInfo 小程序相关信息，里面包含小程序id、小程序名称、小程序图标、小程序截图（5：4）等。
 {
    appAvatar = "小程序图标地址";
    appDescription = "小程序的描述信息";
    appId = "小程序id";
    appInfo =  {}; // 客户可在appInfo中自定义字段，appInfo内容会透传
    appStartParams =     {
        path = "点击转发时的小程序页面路径";
    };
    appThumbnail = "小程序封面图的路径，可能是网络路径或者本地路径，宽高比是5:4";
    appTitle = "小程序名称";
    userId = "小程序开发者id";
}
 @param completion 执行完后的回调，如果你转发操作执行完后，希望告知小程序端转发结果，就需要调用该block。
 */
- (void)forwardAppletWithInfo:(NSDictionary *)contentInfo completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

/// 获取用户信息
/// @param appletInfo 小程序信息
- (NSDictionary *)getUserInfoWithAppletInfo:(FATAppletInfo *)appletInfo;

/// 更多按钮中自定义的菜单，会在页面弹出菜单时调用该api
/// @param path 点击菜单时的当前页面路径
- (NSArray<id<FATAppletMenuProtocol>> *)customMenusInMoreItemAtPath:(NSString *)path;

/// 点击自定义菜单时，会触发的事件
/// @param customMenu 自定义菜单对象
/// @param path 当前页面路径
- (void)customMenu:(id<FATAppletMenuProtocol>)customMenu didClickAtPath:(NSString *)path;

@end

