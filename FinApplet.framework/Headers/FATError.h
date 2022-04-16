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
    FATErrorCodeDecryptFail = 13004,    // 解密失败

    FATErrorCodeAppletNotFound = 14000,          // 未找到appletId指定小程序
    FATErrorCodeForegroundAppletNotFound = 14001 // 未找到前台运行的小程序
};

/**
 * 小程序请求返回的错误信息由后端提供
 * 使用 statusCode 和 originData 存储相关信息
 * 由于后端未返回错误标题信息，故使用 statusCode 映射获取
 */
@interface FATError : NSError

/// 请求返回的错误码
@property (nonatomic, assign) NSInteger statusCode;
/// 请求返回解析出来的原始报错信息
@property (nonatomic, copy) NSDictionary *originData;

- (instancetype)initWithCode:(FATErrorCode)code message:(NSString *)message;

+ (instancetype)errorWithCode:(FATErrorCode)code message:(NSString *)message;

+ (instancetype)errorWithNSError:(NSError *)error;

@end
