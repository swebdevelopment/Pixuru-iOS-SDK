//
//  PSDKProcessOrderViewController.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/28/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PSDKCustomButton;

@interface PSDKProcessOrderViewController : UIViewController <UIAlertViewDelegate>

@property (strong, nonatomic) UIImageView *backgroundView;

@property (strong, nonatomic) UITextView *textField;
@property (strong, nonatomic) UIProgressView *progressIndicator;
@property (strong, nonatomic) PSDKCustomButton *doneButton;
@property (strong, nonatomic) UIImageView *poweredPixView;

@end
