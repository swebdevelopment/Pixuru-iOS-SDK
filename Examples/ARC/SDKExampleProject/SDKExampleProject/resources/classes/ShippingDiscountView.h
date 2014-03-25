//
//  ShippingDiscountView.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 3/18/14.
//  Copyright (c) 2014 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PSDKConnectionManager.h"

@class PSDKCustomButton;

@protocol ShippingDiscountViewDelegate <NSObject>

- (void)applyDiscount:(NSDictionary *)discountData;
- (void)discountFailed;
- (void)discountPopUpDidClose;

@end

@interface ShippingDiscountView : UIView <PSDKConnectionManagerDelegate, UITextFieldDelegate>

@property (nonatomic, strong) id <ShippingDiscountViewDelegate> delegate;

@property (strong, nonatomic) PSDKCustomButton *discountButton;
@property (strong, nonatomic) PSDKCustomButton *cancelButton;
@property (strong, nonatomic) UIProgressView *progressIndicator;
@property (strong, nonatomic) UITextField *discountField;

- (void)setUserEmail:(NSString *)email;
- (void)resize;
- (void)openKeyboard;

@end
