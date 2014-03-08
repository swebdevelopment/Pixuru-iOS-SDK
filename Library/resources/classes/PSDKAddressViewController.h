//
//  PSDKAddressBlockViewController.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 10/28/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AddressBookUI/AddressBookUI.h>

@class PSDKCustomButton;

@interface PSDKAddressViewController : UIViewController <UITextFieldDelegate, ABPeoplePickerNavigationControllerDelegate, UIPickerViewDataSource, UIPickerViewDelegate, UIAlertViewDelegate>

@property (strong, nonatomic) UIImageView *backgroundView;

@property (strong, nonatomic) UIScrollView *scrollView;
@property (strong, nonatomic) UIView *contentView;

@property (strong, nonatomic) UIView *addressContainerView;
@property (strong, nonatomic) UIView *emailContainerView;
@property (strong, nonatomic) UIImageView *poweredPixView;

@property (strong, nonatomic) UILabel *shipToLabel;

@property (strong, nonatomic) PSDKCustomButton *contactsButton;
@property (strong, nonatomic) PSDKCustomButton *countryButton;

@property (strong, nonatomic) UITextField *firstnameField;
@property (strong, nonatomic) UITextField *lastNameField;
@property (strong, nonatomic) UITextField *addressOneField;
@property (strong, nonatomic) UITextField *addressTwoField;
@property (strong, nonatomic) UITextField *cityField;
@property (strong, nonatomic) UITextField *stateField;
@property (strong, nonatomic) UITextField *zipField;
@property (strong, nonatomic) UITextField *emailTextField;


@end

