//
//  FATWebExtension.h
//  FinApplet
//
//  Created by Haley on 2019/11/20.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FATConstant.h"

@interface FATWebExtension : NSObject

/**
 为JS注册原生API
 宿主注册需要自定义实现的API
 @param api API名
 @param handler 回调
 */
+ (void)registerExtensionApi:(NSString *)api handler:(void (^)(id param, FATExtensionApiCallback callback))handler;

+ (NSDictionary *)webExtensionApis;

@end
