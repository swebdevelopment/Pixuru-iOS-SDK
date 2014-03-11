//
//  PSDKProductCreationManager.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/16/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PlainProduct;

@interface PSDKProductCreationManager : NSObject


+ (PSDKProductCreationManager *)sharedInstance;
+ (void)resetSharedInstance;

- (NSArray *)getProductsForKey:(unsigned char)productSelector;
- (void)setPlainProductWithProduct:(PlainProduct *)product;
- (PlainProduct *)getCurrentProduct;

- (void)setClientPhotoWithImage:(UIImage *)image;
- (UIImage *)getClientPhoto;
- (void)setBase64ImageStringWithData:(NSData *)data;
- (NSString *)getBase64ImageString;
- (void)setBase64ThumbnailStringWithString:(NSString *)encodedimage;
- (NSString *)getBase64ThumbnailString;

- (void)setProductsWithDecodedDictionary:(NSDictionary *)products;
- (void)setUserDictionaryWithDictionary:(NSDictionary *)user;
- (NSDictionary *)getUserDictionary;
- (void)setOrderDictionaryWithDictionary:(NSDictionary *)order;
- (NSDictionary *)getOrderDictionary;
- (void)setAPIErrorWithError:(NSString *)error;
- (NSString *)getAPIError;
- (void)setCurrentViewWithViewName:(NSString *)viewName;
- (NSString *)getCurrentViewName;
- (void)setDiscountDictionaryWithDictionary:(NSDictionary *)discountInfo;
- (NSDictionary *)getDiscountDictionary;
- (void)setCreditCardInfoWithDictionary:(NSDictionary *)creditinfo;
- (NSDictionary *)getCreditCardInfo;
- (void)setCustomerTypeWithIndicator:(unsigned char)type;
- (unsigned char)getCustomerType;
- (void)setInitialOrderDictionaryWithDictionary:(NSDictionary *)order;
- (NSDictionary *)getIntialOrderDictionary;
- (void)setFinalOrderDictionaryWithDictionary:(NSDictionary *)order;
- (NSDictionary *)getFinalOrderDictionary;
- (void)setInternationalShippingWithBool:(BOOL)flag;
- (BOOL)getInternationalShipping;

- (void)setPopLabelsFont:(UIFont *)font;
- (void)setPopLabelsColor:(UIColor *)color;
- (BOOL)getPopLabelToggle;
- (UIFont *)getPopLabelFont;
- (UIColor *)getPopLabelColor;

- (void)clearOrder;
- (void)setProductRotationWithRotationValue:(unsigned char)value;
- (unsigned char)getProductRotationState;
- (UIImage *)rotateInternalImageWithImage:(UIImage *)image;
- (void)setPopUpAnimation:(unsigned char)animation;
- (unsigned char)getPopUpAnimation;

@end
