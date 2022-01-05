//
//  FATBaseLoadingView.h
//  FinApplet
//
//  Created by luojian on 2021/10/27.
//  Copyright © 2021 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FATLoadingAnimationView : UIView

/**
 动画圆点
 */
@property (nonatomic, strong) UIView *dotView;
/**
 中间的小程序图标
 */
@property (nonatomic, strong) UIImageView *iconImageView;
/**
 动画轨道
 */
@property (nonatomic, strong) CAShapeLayer *trackLayer;
/**
 图片与轨道的间距
 */
@property (nonatomic, assign) CGFloat padding;
/**
 动画效果
 */
@property (nonatomic, strong) CAKeyframeAnimation *animation;

@end

@interface FATBaseLoadingView : UIView

@property (nonatomic, strong) FATLoadingAnimationView *loadingView;
/**
 小程序标题
 */
@property (nonatomic, strong) UILabel *titleLabel;

@end

NS_ASSUME_NONNULL_END
