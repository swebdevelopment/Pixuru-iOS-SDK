//
//  PlainProduct.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/17/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface PlainProduct : NSObject

@property (nonatomic) unsigned short sizeId;
@property (nonatomic) unsigned short minHeight;
@property (nonatomic) unsigned short minWidth;
@property (nonatomic) unsigned char availableInternational;

@property (nonatomic) float price;

@property (nonatomic, strong) NSString *desc;
@property (nonatomic, strong) NSString *imageName;
@property (nonatomic, strong) UIImage *thumbnail;

@end
