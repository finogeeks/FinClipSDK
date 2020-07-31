//
//  FATUIConfig.h
//  FinApplet
//
//  Created by Haley on 2020/7/29.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FATUIConfig : NSObject

/// 导航栏的标题样式，目前支持了font
@property (nonatomic, strong) NSDictionary<NSAttributedStringKey, id> *navigationTitleTextAttributes;

/// 是否隐藏小程序 更多中的反馈与投诉的菜单
@property (nonatomic, assign) BOOL hideFeedbackMenu;

/// 是否隐藏回到首页菜单
@property (nonatomic, assign) BOOL hideBackToHome;

/** 是否自适应暗黑模式。
 如果设置为YES，则更多页面、关于等原生页面会随着手机切换暗黑，也自动调整为暗黑模式
 */
@property (nonatomic, assign) BOOL autoAdaptDarkMode;

@end

