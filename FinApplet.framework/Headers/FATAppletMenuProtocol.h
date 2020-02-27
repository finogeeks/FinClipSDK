//
//  FATAppletMenuProtocol.h
//  FinApplet
//
//  Created by Haley on 2020/2/26.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol FATAppletMenuProtocol <NSObject, NSCopying>

/// 菜单id
@property (nonatomic, assign) NSInteger menuId;

/// 菜单的icon图标 （ 2倍图: 44 * 44， 3倍图：66*66）
@property (nonatomic, strong) UIImage *menuIconImage;

/// 菜单的标题
@property (nonatomic, copy) NSString *menuTitle;

@end
