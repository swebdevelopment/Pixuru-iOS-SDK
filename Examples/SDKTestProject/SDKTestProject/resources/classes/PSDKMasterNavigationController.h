//
//  PSDKMasterNavigationController.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 2/19/14.
//  Copyright (c) 2014 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PSDKMasterNavigationController;

@protocol PSDKMasterNavigationControllerDelegate <NSObject>

- (void)pixuruView:(PSDKMasterNavigationController *)master WillShow:(NSDictionary *)info;

@end

@interface PSDKMasterNavigationController : UINavigationController

@property (strong, nonatomic) id psdkdelegate;

- (void)initializePixuruSDKWithImage:(UIImage *)image;

- (void)setPrice:(float)price forSizeID:(unsigned short)sizeid;
- (void)setDefault:(BOOL)flag forSizeID:(unsigned short)sizeid;
- (void)setInclude:(BOOL)flag forSizeID:(unsigned short)sizeid;

- (void)setPopLabelsFont:(UIFont *)font;
- (void)setPopLabelsColor:(UIColor *)color;

@end
