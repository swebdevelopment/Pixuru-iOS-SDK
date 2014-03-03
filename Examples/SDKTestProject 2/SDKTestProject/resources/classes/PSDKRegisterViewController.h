//
//  PSDKRegisterViewController.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/28/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PSDKRegisterViewController : UIViewController <UITextFieldDelegate>

@property (strong, nonatomic) UITextField *emailField;
@property (strong, nonatomic) UITextField *passwordField;
@property (strong, nonatomic) UITextField *confirmField;
@property (strong, nonatomic) UIButton *registerButton;
@property (strong, nonatomic) UIView *registerContainerView;
@property (strong, nonatomic) UIImageView *poweredPixView;

@end
