//
//  FATWebExtension.h
//  FinApplet
//
//  Created by Haley on 2019/11/20.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FATConstant.h"

@class FATAppletInfo;

typedef void (^FATWebExtensionApiHandler)(FATAppletInfo *appletInfo, id param, FATExtensionApiCallback callback);
typedef void (^FATWebExtensionApiDeprecatedHandler)(id param, FATExtensionApiCallback callback);

@interface FATWebExtensionApiHandlerModel : NSObject

@property (nonatomic, assign) BOOL isOld;
@property (nonatomic, copy) FATWebExtensionApiHandler handler;
@property (nonatomic, copy) FATWebExtensionApiDeprecatedHandler deprecatedHandler;

@end

@interface FATWebExtension : NSObject

/**
 为JS注册原生API
 宿主注册需要自定义实现的API
 @param api API名
 @param handler 回调
 */
+ (BOOL)registerExtensionApi:(NSString *)api handler:(FATWebExtensionApiHandler)handler;

+ (BOOL)registerDeprecatedExtensionApi:(NSString *)api handler:(FATWebExtensionApiDeprecatedHandler)handler;

+ (NSDictionary<NSString *, FATWebExtensionApiHandlerModel *> *)webExtensionApis;

@end
