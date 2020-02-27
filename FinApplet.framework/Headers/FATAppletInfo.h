//
//  FATAppletInfo.h
//  FinApplet
//
//  Created by Haley on 2019/3/27.
//  Copyright © 2019 finogeeks. All rights reserved.
//


#import <Foundation/Foundation.h>

@interface FATAppletInfo : NSObject<NSCoding>

/// 小程序id
@property (nonatomic, copy) NSString *appId;

/// 小程序开发者userId
@property (nonatomic, copy) NSString *userId;

/// 小程序图标
@property (nonatomic, copy) NSString *appAvatar;

/// 小程序名称
@property (nonatomic, copy) NSString *appTitle;

/// 小程序描述
@property (nonatomic, copy) NSString *appDescription;

/// 小程序在本地的相对路径
@property (nonatomic, copy) NSString *appPath;

/// 小程序版本号
@property (nonatomic, copy) NSString *appVersion;

@property (nonatomic, copy) NSString *appTag;

@property (nonatomic, copy) NSString *appGroup;

/// 小程序封面图
@property (nonatomic, copy) NSString *appThumbnail;

/// 小程序是否已安装 （其实类似收藏）
@property (nonatomic, assign) BOOL installed;

@property (nonatomic, strong) NSDictionary *info;

/**
 小程序的原数据
 */
@property (nonatomic, strong) NSDictionary *originalInfo;

@end

