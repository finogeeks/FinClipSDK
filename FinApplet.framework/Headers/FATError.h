//
//  FATError.h
//  FinApplet
//
//  Created by Haley on 2020/11/16.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATLogManager.h"

typedef NS_ENUM(NSUInteger, FATErrorCode) {
    FATErrorCodeUnknown = 9999,          // 未知错误
    FATErrorCodeAppKeyInvalid = 10000,   // 未初始化SDK或者appKey不合法
    FATErrorCodeInvalidParam = 10001,    // 参数不合法
    FATErrorCodeDomainInvalid = 10002,   // 域名校验失败
    FATErrorCodeNetworkNotReach = 10003, // 网络未连接

    FATErrorCodeRequestFail = 11000,            //服务器接口请求失败
    FATErrorCodeResponseDataInvalid = 11001,    //服务器返回数据异常
    FATErrorCodeDownloadURLInvalid = 11002,     //下载地址异常，无法下载
    FATErrorCodeDownloadDirectoryError = 11003, //下载目录出错，无法下载
    FATErrorCodeDownloadFail = 11004,           //下载失败
    FATErrorCodeResponseDataUnchanged = 11005,  //服务器返回数据无变化

    FATErrorCodeZipInvalid = 12000,       //压缩包异常
    FATErrorCodeCopyResourceFail = 12001, //拷贝资源至运行环境失败
    FATErrorCodeServiceNotFound = 12002,  //service 文件未找到

    FATErrorCodeNotTrialAccess = 13000, // 没有体验权限
    FATErrorCodeTrialCanceled = 13001,  // 体验版已取消
    FATErrorCodeTempExpried = 13002,    // ide临时二维码过期
    FATErrorCodeSameAppID = 13003,      // 相同的小程序ID
};

@interface FATError : NSError

- (instancetype)initWithCode:(FATErrorCode)code message:(NSString *)message;

+ (instancetype)errorWithCode:(FATErrorCode)code message:(NSString *)message;

+ (instancetype)errorWithNSError:(NSError *)error;

@end
