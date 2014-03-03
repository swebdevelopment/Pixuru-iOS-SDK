//
//  PSDKLoginViewController.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/28/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PSDKCustomButton;

@interface PSDKLoginViewController : UIViewController <UITextFieldDelegate, UIAlertViewDelegate>

@property (strong, nonatomic) UITextField *emailField;
@property (strong, nonatomic) UITextField *passwordField;
@property (strong, nonatomic) PSDKCustomButton *forgotButton;

@property (strong, nonatomic) UIView *loginContainerView;
@property (strong, nonatomic) UIImageView *poweredPixView;

@end
