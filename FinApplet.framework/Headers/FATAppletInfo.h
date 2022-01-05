//
//  FATAppletInfo.h
//  FinApplet
//
//  Created by Haley on 2019/3/27.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"

@interface FATAppletSimpleInfo : NSObject
/// 小程序id
@property (nonatomic, copy) NSString *appId;

@end

@interface FATAppletInfo : NSObject

/// 小程序id
@property (nonatomic, copy) NSString *appId;

/// 小程序开发者userId
@property (nonatomic, copy) NSString *userId;

/// 小程序的机构id
@property (nonatomic, copy) NSString *groupId;

/// 小程序图标
@property (nonatomic, copy) NSString *appAvatar;

/// 小程序名称
@property (nonatomic, copy) NSString *appTitle;

/// 小程序描述
@property (nonatomic, copy) NSString *appDescription;

/// 小程序版本号
@property (nonatomic, copy) NSString *appVersion;

/// 小程序封面图
@property (nonatomic, copy) NSString *appThumbnail;

/// 小程序版本信息
@property (nonatomic, copy) NSString *versionDescription;

/// 小程序主体信息（机构名称）
@property (nonatomic, copy) NSString *groupName;

/// 小程序是否正在灰度
@property (nonatomic, assign) BOOL isGrayRelease;

/// 小程序版本索引
@property (nonatomic, strong) NSNumber *sequence;

/// 小程序是否已安装 （其实类似收藏）
@property (nonatomic, assign) BOOL installed;

/// 服务器地址
@property (nonatomic, copy) NSString *apiServer;

/**
 小程序启动时的启动参数
 */
@property (nonatomic, copy) NSDictionary *startParams;

/**
 * 小程序类型（线上版、体验版、临时版、审核版、开发版）
 */
@property (nonatomic, assign, readonly) FATAppletVersionType appletVersionType;

/**
 小程序启动时使用的加密串
 注意：使用加密串打开的方式打开小程序才有，否则为nil
 */
@property (nonatomic, copy) NSString *cryptInfo;

- (NSString *)appletVersionTypeName;

@end
