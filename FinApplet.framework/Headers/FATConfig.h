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
 * 例：https://api.finogeeks.com
 */
@property (nonatomic, copy) NSString *apiServer;

/**
 api的版本， 必填
 例：/api/v1
 */
@property (nonatomic, copy) NSString *apiPrefix;

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

/**
 获取config对象
 @param apiServer 服务器地址
*/
- (FATStoreConfig *)storeConfigWithApiServer:(NSString *)apiServer;

@end

NS_ASSUME_NONNULL_END
