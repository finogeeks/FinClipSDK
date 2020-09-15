//
//  FATClient.h
//  FinApplet
//
//  Created by Haley on 2019/3/27.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "FATConfig.h"
#import "FATUIConfig.h"
#import "FATConstant.h"
#import "FATAppletInfo.h"
#import "FATAppletDelegate.h"

@interface FATClient : NSObject

@property (nonatomic, strong, readonly) FATConfig *config;

/// UI控件的样式配置
@property (nonatomic, strong, readonly) FATUIConfig *uiConfig;

@property (nonatomic, copy, readonly) NSString *version;

@property (nonatomic, assign) BOOL enableLog;

@property (nonatomic, weak) id<FATAppletDelegate> delegate;

+ (instancetype)sharedClient;

- (BOOL)initWithConfig:(FATConfig *)config error:(NSError **)error;

- (BOOL)initWithConfig:(FATConfig *)config uiConfig:(FATUIConfig *)uiConfig error:(NSError **)error;

/**
 清空内存中缓存的小程序数据
 */
- (void)clearMemoryCache;

///  删除本地缓存的小程序
- (void)clearLocalApplets;

/// 处理URL
/// @param URL 具体的URL路由
- (BOOL)handleOpenURL:(NSURL *)URL;

#pragma mark - start applet api
/**
 打开mainBundle中的小程序，with transitionStyle
 ❗️ 该api 开发者暂不可用。
 @param appletId 小程序的appId，❗️不能为空
 @param appletTitle 小程序的名称，❗️不能为空
 @param appletIconName 小程序的图标名称
 @param startParams 启动小程序时的参数，可为nil。目前支持的key只有path、query、scene。
 示例:
 @{
 @"path":@"/pages/index/index",
 @"query":@"key1=value1&key2=value2",
 @"scene" : @"1001"
 };
 @param parentVC 在哪个页面的基础上弹出小程序，❗️不能为空
 @param transitionStyle 弹出动画方式
 @param animated 是否展示动画
 @param completion 完成的回调，失败时会返回error信息
 */
- (void)startLocalApplet:(NSString *)appletId
             appletTitle:(NSString *)appletTitle
          appletIconName:(NSString *)appletIconName
             startParams:(NSDictionary *)startParams
  InParentViewController:(UIViewController *)parentVC
         transitionStyle:(FATTranstionStyle)transitionStyle
                animated:(BOOL)animated
              completion:(void (^)(BOOL result, NSError *error))completion;

/**
 打开服务器上的小程序，默认使用FATTranstionStyleUp样式

 @param appletId 小程序的appId, ❗️不能为空
 @param startParams 启动小程序时的参数，可为nil。目前支持的key只有path、query、scene。
 示例:
 @{
 @"path":@"/pages/index/index",
 @"query":@"key1=value1&key2=value2",
 @"scene" : @"1001"
 };
 @param parentVC 在哪个页面的基础上弹出小程序，❗️不能为空
 @param completion 完成的回调，失败时会返回error信息
 */
- (void)startRemoteApplet:(NSString *)appletId
              startParams:(NSDictionary *)startParams
   InParentViewController:(UIViewController *)parentVC
               completion:(void (^)(BOOL result, NSError *error))completion;

/**
 打开服务器上的小程序，带启动动画参数

 @param appletId 小程序的appId, 不能为空
 @param startParams 启动小程序时的参数，可为nil。目前支持的key只有path、query、scene。
 示例:
 @{
 @"path":@"/pages/index/index",
 @"query":@"key1=value1&key2=value2",
 @"scene" : @"1001"
 };
 @param parentVC 在哪个页面的基础上弹出小程序，❗️不能为空
 @param transitionStyle 弹出动画方式
 @param completion 完成的回调，失败时会返回error信息
 */
- (void)startRemoteApplet:(NSString *)appletId
              startParams:(NSDictionary *)startParams
   InParentViewController:(UIViewController *)parentVC
          transitionStyle:(FATTranstionStyle)transitionStyle
               completion:(void (^)(BOOL result, NSError *error))completion;

/**
 打开服务器上的小程序，带启动动画参数、关闭回调

 @param appletId 小程序的appId, 不能为空
 @param startParams 启动小程序时的参数，可为nil。目前支持的key只有path、query、scene。
 示例:
 @{
 @"path":@"/pages/index/index",
 @"query":@"key1=value1&key2=value2",
 @"scene" : @"1001"
 };
 @param parentVC 在哪个页面的基础上弹出小程序，❗️不能为空
 @param transitionStyle 弹出动画方式
 @param animated 是否展示动画
 @param completion 完成的回调，失败时会返回error信息
 @param closeCompletion 关闭小程序的回调
 */
- (void)startRemoteApplet:(NSString *)appletId
              startParams:(NSDictionary *)startParams
   InParentViewController:(UIViewController *)parentVC
          transitionStyle:(FATTranstionStyle)transitionStyle
                 animated:(BOOL)animated
               completion:(void (^)(BOOL result, NSError *error))completion
          closeCompletion:(dispatch_block_t)closeCompletion;

/**
 打开服务器上的小程序，带提交序列、动画参数

 @param appletId 小程序的appId, 不能为空
 @param sequence 提交审核的序列
 @param startParams 启动小程序时的参数，可为nil。目前支持的key只有path、query、scene。
 示例:
 @{
 @"path":@"/pages/index/index",
 @"query":@"key1=value1&key2=value2",
 @"scene" : @"1001"
 };
 @param parentVC 在哪个页面的基础上弹出小程序，❗️不能为空
 @param transitionStyle 弹出动画方式
 @param animated 是否展示动画
 @param completion 完成的回调，失败时会返回error信息
 */
- (void)startRemoteApplet:(NSString *)appletId
                 sequence:(NSNumber *)sequence
              startParams:(NSDictionary *)startParams
   InParentViewController:(UIViewController *)parentVC
          transitionStyle:(FATTranstionStyle)transitionStyle
                 animated:animated
               completion:(void (^)(BOOL result, NSError *error))completion;

/// 当前正在使用的小程序
- (FATAppletInfo *)currentApplet;

#pragma mark - close applet
/**
关闭当前的小程序
@param animated 是否显示动画
*/
- (void)closeCurrentApplet:(BOOL)animated;

/**
关闭当前打开的所有小程序
*/
- (void)closeAllApplets;

#pragma mark - recent used applet api
/**
 获取本地已缓存的小程序
 
 @return 小程序数组<FATAppletInfo>
 */
- (NSArray *)getAppletsFromLocalCache;

/**
 从本地缓存中删除小程序
 
 @param appletId 小程序id
 @return BOOL 结果
 */
- (BOOL)removeAppletFromLocalCache:(NSString *)appletId;

#pragma mark - extension api
/**
 注册扩展Api
 
 @param extApiName 扩展的api名称
 @param handler 回调
 @return 返回注册结果
 */
- (BOOL)registerExtensionApi:(NSString *)extApiName handle:(void (^)(id param, FATExtensionApiCallback callback))handler;

/// 为HTML 注册要调用的原生 api
/// @param webApiName 原生api名字
/// @param handler 回调
- (BOOL)fat_registerWebApi:(NSString *)webApiName handle:(void (^)(id param, FATExtensionApiCallback callback))handler;

/// 原生调用HTML中的JS函数
/// @param eventName 函数名
/// @param paramString 函数的参数字典转成的json
/// @param pageId webView ID
/// @param hanler 调用结果回调
- (void)fat_callWebApi:(NSString *)eventName paramString:(NSString *)paramString pageId:(NSNumber *)pageId handler:(void (^)(id result, NSError *error))hanler;

/// 获取webView
/// @param frame frame
/// @param URL 网页的URL
/// @param appletId 小程序ID
- (UIView *)webViewWithFrame:(CGRect)frame URL:(NSURL *)URL appletId:(NSString *)appletId;

#pragma mark - tool api
/**
 保存文件到小程序的缓存路径
 
 @param fileData 文件的二进制数据
 @param fileName 文件名，需要保证文件名唯一，否则可能会覆盖
 @return 文件的本地路径，例如:finfile://tmp_fdfdkfjdkfjdkjfdkjf.jpg
 */
- (NSString *)saveFile:(NSData *)fileData fileName:(NSString *)fileName;

/**
将文件路径转为绝对路径
如果是 网络文件路径，则直接返回。
如果是小程序中的路径，比如finfile://tmp_fdfdkfjdkfjdkjfdkjf.jpg ，则会转为本地绝对路径
如果是小程序包中的文件路径，比如image/xxx.jpg，也会转为绝对路径
其他情况则返回传入的路径

@param path  文件路径
@return 文件的绝对路径
*/
- (NSString *)fat_absolutePathWithPath:(NSString *)path;

/**
 生成当前页面截图
 
 */
- (UIImage *)getCurrentAppletImage;

@end
