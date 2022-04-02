//
//  FATAppletRequest.h
//  FinApplet
//
//  Created by Haley on 2020/11/15.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"

@interface FATAppletBaseRequest : NSObject
#pragma mark - server info

/**
 服务器地址，客户部署的后台地址，必填
 * 例：https://mp.finogeeks.com
 */
@property (nonatomic, copy) NSString *apiServer;

#pragma mark - 小程序 info

/**
小程序id，必填
*/
@property (nonatomic, copy) NSString *appletId;

/**
小程序名称，非必填
*/
@property (nonatomic, copy) NSString *appName;

/**
 小程序图标的网络地址，非必填
 */
@property (nonatomic, copy) NSString *appletLogo;

/**
小程序的启动参数，非必填。
支持的key，请参考FATStartParamKey
*/
@property (nonatomic, copy) NSDictionary<FATStartParamKey, NSString *> *startParams;

/**
打开小程序时的转场动画方式
*/
@property (nonatomic, assign) FATTranstionStyle transitionStyle;

/**
是否动画，默认为YES
*/
@property (nonatomic, assign) BOOL animated;

@end

@interface FATAppletRequest : FATAppletBaseRequest

/**
 小程序的索引。
 每提交一次小程序，都会生成一个索引，所以想打开指定版本小程序，就必须传该值
*/
@property (nonatomic, strong) NSNumber *sequence;

/**
 离线小程序压缩包路径
 */
@property (nonatomic, copy) NSString *offlineMiniprogramZipPath;

/**
 离线基础库压缩包路径
 */
@property (nonatomic, copy) NSString *offlineFrameworkZipPath;

/// 体验版小程序会带小程序信息
@property (nonatomic, copy) NSDictionary *trialInfo;

@end

/// 小程序解密请求（二维码打开小程序）
@interface FATAppletDecryptRequest : NSObject

@property (nonatomic, copy) NSString *appletId; //管理小程序打开体验版，info加密信息中没有带appletId字段
/**
 加密信息
*/
@property (nonatomic, copy) NSString *info;

/**
打开小程序时的转场动画方式
*/
@property (nonatomic, assign) FATTranstionStyle transitionStyle;

/**
是否动画，默认为YES
*/
@property (nonatomic, assign) BOOL animated;

@end

@interface FATAppletQrCodeRequest : NSObject

/**
 二维码内容
*/
@property (nonatomic, strong) NSString *qrCode;

/**
 打开小程序时的转场动画方式
 */
@property (nonatomic, assign) FATTranstionStyle transitionStyle;

/**
是否动画，默认为YES
*/
@property (nonatomic, assign) BOOL animated;

@end

/// 运行本地小程序
@interface FATLocalAppletRequest : FATAppletBaseRequest

/**
 小程序可访问的域名白名单列表，非必填
 */
@property (nonatomic, copy) NSArray *domainList;

/**
 小程序分包信息，必填。
 */
@property (nonatomic, copy) NSArray *packages;

/**
 小程序的离线包地址，必填。
 */
@property (nonatomic, copy) NSString *offlineMiniprogramZipPath;

/**
 小程序压缩包密码，必填
 */
@property (nonatomic, copy) NSString *zipPassword;

/**
 是否使用本地小程序缓存，非必填
 如果设置为YES，则会使用的小程序缓存。
 否则，则每次打开小程序都会使用传入的小程序离线包
 */
@property (nonatomic, assign) BOOL useAppletCache;

/**
 基础库离线包地址，必填
 */
@property (nonatomic, copy) NSString *offlineFrameworkZipPath;

/**
 是否使用基础库缓存，非必填
 如果设置为YES，则会使用的基础库缓存。
 否则，则每次打开小程序都会使用传入的基础库
 */
@property (nonatomic, assign) BOOL useFrameworkCache;

@end
