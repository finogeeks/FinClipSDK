//
//  FATError.h
//  FinApplet
//
//  Created by Haley on 2020/11/16.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATLogManager.h"

typedef NS_ENUM(NSUInteger, FATErrorCode){
    FATErrorCodeUnknown = 999, // 未知错误
    FATErrorCodeAppKeyInvalid = 1000, // 未初始化SDK或者appKey不合法
    FATErrorCodeInvalidParam = 1001,  // 参数不合法
    FATErrorCodeDomainInvalid = 1002, // 域名校验失败
    FATErrorCodeNetworkNotReach = 1003, // 网络未连接
    
    FATErrorCodeRequestFail = 1100, //服务器接口请求失败
    FATErrorCodeResponseDataInvalid = 1101, //服务器返回数据异常
    FATErrorCodeDownloadURLInvalid = 1102, //下载地址异常，无法下载
    FATErrorCodeDownloadDirectoryError = 1103, //下载目录出错，无法下载
    FATErrorCodeDownloadFail = 1104, //下载失败
    
    FATErrorCodeZipInvalid = 1200, //压缩包异常
    FATErrorCodeCopyResourceFail =  1201, //拷贝资源至运行环境失败
    FATErrorCodeServiceNotFound = 1202, //service 文件未找到
};

@interface FATError : NSError

- (instancetype)initWithCode:(FATErrorCode)code message:(NSString *)message;

+ (instancetype)errorWithCode:(FATErrorCode)code message:(NSString *)message;

+ (instancetype)errorWithNSError:(NSError *)error;

@end

