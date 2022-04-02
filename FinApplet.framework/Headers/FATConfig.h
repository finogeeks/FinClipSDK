//
//  FATConfig.h
//  FinApplet
//
//  Created by 杨涛 on 2019/2/2.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATStoreConfig.h"
#import "FATConstant.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATConfig : NSObject

/**
 appKey，也就是SDK Key，必填
 当校验不通过时，api无法使用
 */
@property (nonatomic, copy, readonly) NSString *appKey;

/**
SDK secret
*/
@property (nonatomic, copy, readonly) NSString *appSecret;

/**
 服务器地址，客户部署的后台地址，必填
 * 例：https://www.finclip.com
 */
@property (nonatomic, copy) NSString *apiServer;

/**
 apm统计服务器的地址
 如果不填，则默认与apiServer一致。
 例：https://www.finclip.com
 */
@property (nonatomic, copy) NSString *apmServer;

/// api的版本（已弃用）
@property (nonatomic, copy) NSString *apiPrefix __attribute__((deprecated("已弃用，使用后不起作用。")));

/// 小程序SDK中的api加密，默认为MD5
@property (nonatomic, assign) FATApiCryptType cryptType;

/**
SDK指纹，证联服务器时，必填
*/
@property (nonatomic, copy) NSString *fingerprint;

@property (nonatomic, copy, readonly) NSArray<FATStoreConfig *> *storeConfigs;

/**
 当前用户id，
 小程序缓存信息会存储在以userId命名的不同目录下。
 */
@property (nonatomic, copy) NSString *currentUserId;

/**
是否不让SDK申请权限
如果设置为YES，则SDK内使用权限的api，不会主动申请权限
*/
@property (nonatomic, assign) BOOL disableAuthorize;

/**
 小程序自动申请授权
 如果设置为YES，则小程序申请权限时不会弹出用户确认提示框
 */
@property (nonatomic, assign) BOOL appletAutoAuthorize;

/**
是否禁用SDK的监管接口API（默认开启：NO）
如果设置为YES，则SDK禁用监管接口API
*/
@property (nonatomic, assign) BOOL disableGetSuperviseInfo;

/**
后台自动检查更新的小程序个数
取值范围：0~50。0代表不检查更新；不设置默认是3。
*/
@property (nonatomic, assign) NSInteger appletIntervalUpdateLimit;

/**
apm 统计的扩展信息
*/
@property (nonatomic, strong) NSDictionary *apmExtension;

/** 是否开启Crash防崩溃，默认为NO。
 如果开启，可以防止如下类型的崩溃：UnrecognizedSelector、KVO、Notification、Timer、Container(数组越界，字典插入nil等)、String (越界、nil等)
 如果在开发阶段，建议关闭该属性，否则开发时不便于及时发现代码中的崩溃问题。
*/
@property (nonatomic, assign) BOOL startCrashProtection;

@property (nonatomic, strong) NSDictionary *theme;

/**
 * 数据上报时，是否压缩请求的数据
 * 默认为NO
 */
@property (nonatomic, assign) BOOL enableApmDataCompression;

/**
是否需要接口加密验证（初始化单服务器时使用）
默认为不开启，当设置为YES时开启，接口返回加密数据并处理
*/
@property (nonatomic, assign) BOOL encryptServerData;

/**
 是否开启小程序的debug模式。
 默认为不开启。当设置为YES时开启，所有的小程序都会开启vconsole。
 当设置为NO时，开发版、体验版小程序可通过更多菜单里的调试菜单打开vconsole。
 */
@property (nonatomic, assign) BOOL enableAppletDebug;

/**
小程序的自定义启动加载页，非必填。
 自定义启动加载页必须继承自FATBaseLoadingView
*/
@property (nonatomic, copy) NSString *baseLoadingViewClass;

/**
小程序的自定义启动失败页，非必填。
 自定义启动失败页必须继承自FATBaseLoadFailedView
*/
@property (nonatomic, copy) NSString *baseLoadFailedViewClass;

#pragma mark - method
/// 创建config对象
/// @param appSecret appSecret，也就是SDK Secret
/// @param appKey 也就是SDK Key
+ (instancetype)configWithAppSecret:(NSString *)appSecret appKey:(NSString *)appKey;

/**
 创建config对象
 @param storeConfigs 应用市场对象数组
*/
+ (instancetype)configWithStoreConfigs:(NSArray<FATStoreConfig *> *)storeConfigs;

@end

NS_ASSUME_NONNULL_END
