//
//  CheckOutPopUpView.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/30/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PSDKCustomButton;

@protocol CheckOutPopUpViewDelegate;

@interface CheckOutPopUpView : UIView

@property (nonatomic, strong) id <CheckOutPopUpViewDelegate> delegate;

@property (strong, nonatomic) PSDKCustomButton *guestButton;
@property (strong, nonatomic) PSDKCustomButton *registerButton;
@property (strong, nonatomic) PSDKCustomButton *loginButton;
@property (strong, nonatomic) PSDKCustomButton *cancelButton;

@end

@protocol CheckOutPopUpViewDelegate <NSObject>

- (void)initiateGuestCheckOut;
- (void)initiateRegisterCheckOut;
- (void)initiateLoginCheckOut;
- (void)checkOutPopUpDidClose;

@end