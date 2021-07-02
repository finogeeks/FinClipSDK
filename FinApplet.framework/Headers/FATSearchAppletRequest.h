//
//  FATSearchAppletRequest.h
//  FinApplet
//
//  Created by beetle_92 on 2021/5/7.
//  Copyright © 2021 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FATSearchAppletRequest : NSObject

/**
 服务器地址，客户部署的后台地址，必填
 * 例：https://mp.finogeeks.com
 */
@property (nonatomic, copy) NSString *apiServer;

/**
查找的关键字
*/
@property (nonatomic, copy) NSString *text;

@end

NS_ASSUME_NONNULL_END
