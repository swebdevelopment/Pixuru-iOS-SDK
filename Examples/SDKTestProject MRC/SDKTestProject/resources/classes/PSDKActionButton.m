//
//  PSDKActionButton.m
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 10/17/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import "PSDKActionButton.h"
#import <QuartzCore/QuartzCore.h>

@implementation PSDKActionButton

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Default Theme
        self.layer.borderColor = [[UIColor colorWithRed:(83.0f/255.0f) green:(215.0f/255.0f) blue:(105.0f/255.0f) alpha:1.0f] CGColor];
        self.layer.borderWidth = 2.0f;
        self.layer.cornerRadius = 5.0f;
        [self setBackgroundColor:[UIColor whiteColor]];
        [self setTitleColor:[UIColor colorWithRed:(83.0f/255.0f) green:(215.0f/255.0f) blue:(105.0f/255.0f) alpha:1.0f] forState:UIControlStateNormal];
    }
    return self;
}

@end
