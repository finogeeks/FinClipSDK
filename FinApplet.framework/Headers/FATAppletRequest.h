//
//  FATAppletRequest.h
//  FinApplet
//
//  Created by Haley on 2020/11/15.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"

@interface FATAppletRequest : NSObject

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
小程序的启动参数，非必填。
支持的key，请参考FATStartParamKey
*/
@property (nonatomic, copy) NSDictionary<FATStartParamKey, NSString *> *startParams;

/**
 小程序的索引。
 每提交一次小程序，都会生成一个索引，所以想打开指定版本小程序，就必须传该值
*/
@property (nonatomic, strong) NSNumber *sequence;

/**
打开小程序时的转场动画方式
*/
@property (nonatomic, assign) FATTranstionStyle transitionStyle;

/**
是否动画，默认为YES
*/
@property (nonatomic, assign) BOOL animated;

@end

/// 小程序解密请求（二维码打开小程序）
@interface FATAppletDecryptRequest : NSObject

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
