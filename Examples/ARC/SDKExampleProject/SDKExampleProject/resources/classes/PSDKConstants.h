//
//  PSDKConstants.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/17/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <Foundation/Foundation.h>

#define IS_RETINA ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] && ([UIScreen mainScreen].scale == 2.0))
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

typedef enum : unsigned short{
    
    FRAMED_8X10 = 101,
    FRAMED_11X14 = 102,
    FRAMED_16X20 = 103,
    FRAMED_24X30 = 104,
    FRAMED_6X6 = 105,
    FRAMED_12X12 = 106,
    FRAMED_20X20 = 107,
    FRAMED_20X6 = 108,
    FRAMED_30X8 = 109,
    FRAMED_40X10 = 110,
    
    CANVAS_8X10 = 201,
    CANVAS_11X14 = 202,
    CANVAS_16X20 = 203,
    CANVAS_24X30 = 204,
    CANVAS_6X6 = 205,
    CANVAS_12X12 = 206,
    CANVAS_3_PANEL_12X12 = 207,
    CANVAS_4_PANEL_12X12 = 208,
    CANVAS_20X20 = 209,
    CANVAS_20X6 = 210,
    CANVAS_30X8 = 211,
    CANVAS_40X10 = 212,
    
    METAL_8X10 = 301,
    METAL_11X14 = 302,
    METAL_16X20 = 303,
    METAL_24X30 = 304,
    METAL_6X6 = 305,
    METAL_12X12 = 306,
    METAL_3_PANEL_12X12 = 307,
    METAL_4_PANEL_12X12 = 308,
    METAL_20X20 = 309,
    METAL_20X6 = 310,
    METAL_30X8 = 311,
    METAL_40X10 = 312,
    
    WOOD_8X10 = 401,
    WOOD_11X14 = 402,
    WOOD_16X20 = 403,
    WOOD_24X30 = 404,
    WOOD_6X6 = 405,
    WOOD_12X12 = 406,
    WOOD_3_PANEL_12X12 = 407,
    WOOD_4_PANEL_12X12 = 408,
    WOOD_20X20 = 409,
    WOOD_20X6 = 410,
    WOOD_30X8 = 411,
    WOOD_40X10 = 412,
    
    OTHER_IPHONE_5_CASE = 501,
    OTHER_IPAD_CASE_HARD = 502,
    OTHER_IPAD_CASE_SOFT = 503,
    OTHER_FLEXIBLE_MAGNET = 504,
    OTHER_WHITE_CERAMIC_MUG = 505,
    OTHER_CLEAR_KEYCHAIN = 506,
    OTHER_DOG_TAGS = 507,
    OTHER_SMALL_TSHIRT = 508,
    OTHER_MEDIUM_TSHIRT = 509,
    OTHER_LARGE_TSHIRT = 510,
    OTHER_EXTRA_LARGE_TSHIRT = 511,
    OTHER_TOTE_BAG = 512,
    OTHER_7_INCH_SLEEVE = 513,
    OTHER_10_INCH_SLEEVE = 514,
    OTHER_15_INCH_SLEEVE = 515
    
}ProductTypes;

typedef enum : unsigned char{
    
    IMAGE_TYPE_CLIENT = 0,
    IMAGE_TYPE_INTERNAL = 1,
    IMAGE_ROTATE_UP = 0,
    IMAGE_ROTATE_RIGHT = 1,
    IMAGE_ROTATE_DOWN = 2,
    IMAGE_ROTATE_LEFT = 3,
    
    PRODUCT_ROTATE_UP = 0,
    PRODUCT_ROTATE_SIDE = 1
    
}ProductRotations;

typedef enum : unsigned char{

    POPUP_FADE_IN = 0,
    POPUP_SLIDE_DOWN = 1,
    POPUP_SLIDE_UP = 2,
    
}PopupAnimations;

@interface PSDKConstants : NSObject

// PSDKNotification
extern NSString *const NOTIFICATION_TYPE_CANCEL;
extern NSString *const NOTIFICATION_TYPE_COMPLETE;
extern NSString *const NOTIFICATION_TYPE_GUEST;
extern NSString *const NOTIFICATION_TYPE_LOGIN;
extern NSString *const NOTIFICATION_TYPE_REGISTER;
extern NSString *const NOTIFICATION_TYPE_FAIL;

@end
