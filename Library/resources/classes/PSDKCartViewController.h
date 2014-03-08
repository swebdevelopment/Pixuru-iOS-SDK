//
//  PSDKCartViewController.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/27/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PSDKCustomButton;

@interface PSDKCartViewController : UIViewController <UITextFieldDelegate, UIPickerViewDataSource, UIPickerViewDelegate, UIAlertViewDelegate>

@property (strong, nonatomic) UIImageView *backgroundView;

@property (strong, nonatomic) UIScrollView *scrollView;
@property (strong, nonatomic) UIView *contentView;

@property (strong, nonatomic) UIImageView *productPreviewImage;
@property (strong, nonatomic) UILabel *productTypeLabel;
@property (strong, nonatomic) UIView *addressContainerView;
@property (strong, nonatomic) UIView *orderContainerView;
@property (strong, nonatomic) UIView *cartContainerView;
@property (strong, nonatomic) UIImageView *poweredPixView;
@property (strong, nonatomic) UIView *billingContainerView;

@property (strong, nonatomic) UILabel *subTotalLabel;
@property (strong, nonatomic) UILabel *taxAndShippingLabel;
@property (strong, nonatomic) UILabel *grandTotalLabel;
@property (strong, nonatomic) UILabel *subTotalAmount;
@property (strong, nonatomic) UILabel *taxAndShippingAmount;
@property (strong, nonatomic) UILabel *grandTotalAmount;

@property (strong, nonatomic) UITextField *cardNumberField;
@property (strong, nonatomic) UITextField *firstNameField;
@property (strong, nonatomic) UITextField *lastNameField;
@property (strong, nonatomic) UITextField *monthField;
@property (strong, nonatomic) UITextField *yearField;
@property (strong, nonatomic) UITextField *cvvField;
@property (strong, nonatomic) UITextField *phoneNUmberField;

@property (strong, nonatomic) UIButton *sameAsShippingButton;
@property (strong, nonatomic) PSDKCustomButton *chooseCountryButton;

@property (strong, nonatomic) UITextField *addressOneField;
@property (strong, nonatomic) UITextField *addressTwoField;
@property (strong, nonatomic) UITextField *cityField;
@property (strong, nonatomic) UITextField *stateField;
@property (strong, nonatomic) UITextField *zipField;


@end
