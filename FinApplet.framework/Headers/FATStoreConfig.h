//
//  FATStoreConfig.h
//  FinApplet
//
//  Created by Haley on 2020/12/4.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FATConstant.h"

@interface FATStoreConfig : NSObject

/**
 创建应用时生成的SDK Key，必填
 */
@property (nonatomic, copy) NSString *sdkKey;

/**
创建应用时生成的SDK secret，必填
*/
@property (nonatomic, copy) NSString *sdkSecret;

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

/**
 网络接口加密类型，默认为MD5
 */
@property (nonatomic, assign) FATApiCryptType cryptType;

/**
SDK指纹
证联环境(https://open.fdep.cn/) 时必填，其他环境的不用填
*/
@property (nonatomic, copy) NSString *fingerprint;

/**
是否需要接口加密验证（初始化多服务器时使用）
默认为不开启，当设置为YES时开启，接口返回加密数据并处理
*/
@property (nonatomic, assign) BOOL encryptServerData;

@end
