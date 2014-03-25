//
//  PSDKMoveScaleViewController.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/11/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PSDKCustomButton;
@class PSDKActionButton;

@interface PSDKMoveScaleViewController : UIViewController

@property (strong, nonatomic) UIImageView *backgroundView;

@property (strong, nonatomic) UIView *lowerButtonView;
@property (strong, nonatomic) UIView *scrollContainerView;
@property (strong, nonatomic) UIImageView *poweredPixView;

@property (strong, nonatomic) PSDKCustomButton *rotateProductButton;
@property (strong, nonatomic) PSDKCustomButton *rotateImageButton;
@property (strong, nonatomic) PSDKActionButton *previewButton;

@property (nonatomic, strong) UIImage *rotateImage;

@end
