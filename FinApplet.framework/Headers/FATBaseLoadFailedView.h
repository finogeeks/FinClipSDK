//
//  FATBaseLoadFailedView.h
//  FinApplet
//
//  Created by luojian on 2021/11/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FATBaseLoadFailedView : UIView

/**
 错误提示图片
 */
@property (nonatomic, strong) UIImageView *errorImageView;
/**
 错误标题
 */
@property (nonatomic, strong) UILabel *errorLabel;
/**
 错误详情
 */
@property (nonatomic, strong) UILabel *detailLabel;

@end

NS_ASSUME_NONNULL_END
