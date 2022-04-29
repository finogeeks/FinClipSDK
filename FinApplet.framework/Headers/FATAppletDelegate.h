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

/// 小程序灰度扩展参数
/// @param appletId 小程序id
- (NSDictionary *)grayExtensionWithAppletId:(NSString *)appletId;

#pragma mark - button open-type

/** 转发事件
 当你点击小程序右上角更多里的转发菜单，或者 点击open-type属性为share的Button时，会触发小程序里shareAppMessage方法，然后回调到原生该方法
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

/// 调用获取用户信息API（getUserInfo） 或者 点击open-type属性为getUserInfo的Button时触发
/// @param appletInfo 小程序信息
- (NSDictionary *)getUserInfoWithAppletInfo:(FATAppletInfo *)appletInfo;

/// Button open-type属性为contact，打开客服会话。
/// @param appletInfo 小程序信息
/// @param sessionFrom 会话来源
/// @param sendMessageTitle 会话内消息卡片标题
/// @param sendMessagePath 会话内消息卡片点击跳转小程序路径
/// @param sendMessageImg 会话内消息卡片图片
/// @param showMessageCard 小程序信息
- (void)contactWithAppletInfo:(FATAppletInfo *)appletInfo sessionFrom:(NSString *)sessionFrom sendMessageTitle:(NSString *)sendMessageTitle sendMessagePath:(NSString *)sendMessagePath sendMessageImg:(NSString *)sendMessageImg showMessageCard:(BOOL)showMessageCard;

/// Button open-type属性为getPhoneNumber，获取用户手机号。
/// @param appletInfo 小程序信息
/// @param bindGetPhoneNumber 获取用户手机号回调
- (void)getPhoneNumberWithAppletInfo:(FATAppletInfo *)appletInfo bindGetPhoneNumber:(void (^)(NSDictionary *result))bindGetPhoneNumber;

/// Button open-type属性为launchApp，打开APP。
/// @param appletInfo 小程序信息
/// @param appParameter 打开 APP 时，向 APP 传递的参数
/// @param bindError 打开 APP 发生错误的回调
/// @param bindLaunchApp 打开 APP 成功的回调
- (void)launchAppWithAppletInfo:(FATAppletInfo *)appletInfo appParameter:(NSString *)appParameter bindError:(void (^)(NSDictionary *result))bindError bindLaunchApp:(void (^)(NSDictionary *result))bindLaunchApp;

/// Button open-type属性为feedback，打开“意见反馈”页面。（APP 未实现时，则打开菜单栏里面的反馈）
/// @param appletInfo 小程序信息
- (void)feedbackWithAppletInfo:(FATAppletInfo *)appletInfo;

/// Button open-type属性为chooseAvatar，获取用户头像。
/// @param appletInfo 小程序信息
/// @param bindChooseAvatar 获取用户头像回调
- (void)chooseAvatarWithAppletInfo:(FATAppletInfo *)appletInfo bindChooseAvatar:(void (^)(NSDictionary *result))bindChooseAvatar;

#pragma mark - applet open and close

/**
 小程序打开完成的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didOpenCompletion:(NSError *)error;

/**
 小程序关闭完成的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didCloseCompletion:(NSError *)error;

/**
 小程序初始化完成，首页加载出来的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId initCompletion:(NSError *)error;

/**
 小程序进入活跃状态的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didActive:(NSError *)error;

/**
 小程序进入非活跃状态的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId resignActive:(NSError *)error;

/**
 小程序出错的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didFail:(NSError *)error;

/**
 小程序被销毁的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId dealloc:(NSError *)error;

#pragma mark - H5 hook events
/**
 小程序H5中发出的request包含body时会触发该事件
 requestInfo 中会包含
 bodyType: body内容的类型
 requestHref: request做在页面的链接
 requestId：请求id，每次请求都会构造，后续拦截请求时，可在query参数中通过FinClipHookBridge-RequestId匹配
 requestUrl：发起request时，请求的地址。
 value: request的body内容。
 示例
 {
     bodyType = String;
     requestHref = "http://aaronly.gitee.io/aymj";
     requestId = 16499170263357297;
     requestUrl = "https://www.finclip.com/api/v1/mop/mop-fast-trial-manager/web/visits/statistics";
     value = "{\"type\":\"download_click\"}";
 };
 */
- (void)applet:(FATAppletInfo *)appletInfo hookRequestInfo:(NSDictionary *)requestInfo;

#pragma mark - more menu

/**
 右上角胶囊中 【...】的点击事件，可在该事件中弹出自己设计的更多视图。
 因此实现了该代理事件，就不会触发下面两个自定义菜单的事件
 @param appletInfo 小程序信息
 @path 小程序页面路径，示例：pages/index/index
 */
- (void)applet:(FATAppletInfo *)appletInfo didClickMoreBtnAtPath:(NSString *)path;

/**
 更多按钮中自定义的菜单，会在页面弹出菜单时调用该api
 @param appletInfo 小程序信息
 @param path 页面路径
 */
- (NSArray<id<FATAppletMenuProtocol>> *)customMenusInApplet:(FATAppletInfo *)appletInfo atPath:(NSString *)path;

/**
 点击自定义菜单时，会触发的事件（新版）
 只有实现了该代理方法，才会触发【-clickCustomItemMenuWithInfo:completion:】
 @param contentInfo 分享信息
 @param appletInfo 小程序信息
 @param completion 分享回调（小程序分享回调：1.【code】回调状态码；2.【result】回传给小程序的回调信息）
 */
- (void)clickCustomItemMenuWithInfo:(NSDictionary *)contentInfo inApplet:(FATAppletInfo *)appletInfo completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

@end
