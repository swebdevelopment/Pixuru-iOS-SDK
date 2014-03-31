//
//  PSDKProductScrollView.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/17/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PSDKProductScrollViewDelegate;

@interface PSDKProductScrollView : UIView <UIScrollViewDelegate>

@property (nonatomic, strong) id <PSDKProductScrollViewDelegate> delegate;

- (void)buildViewFromSizeID:(unsigned short)sizeid withProductOrientation:(unsigned char)orientation;

@end

@protocol PSDKProductScrollViewDelegate <NSObject>

- (void)createNewPreviewImage;
- (void)PSDKScrollDidStartBuilding;
- (void)PSDKScrollViewDidFinishBuilding;

@end