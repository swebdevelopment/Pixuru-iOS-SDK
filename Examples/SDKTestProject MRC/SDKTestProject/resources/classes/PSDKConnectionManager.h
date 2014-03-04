//
//  PSDKConnectionManager.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/27/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PSDKConnectionManagerDelegate;

@interface PSDKConnectionManager : NSObject <NSURLConnectionDelegate>

+ (PSDKConnectionManager *)sharedInstance;

@property (nonatomic, strong) id delegate;
@property (nonatomic, assign) BOOL isProcessing;

- (void)checkForDiscountUsingDiscountCode:(NSString *)code andEmail:(NSString *)email success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)checkForExistingCardInfoUsingSuccess:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)loginUserWithEmail:(NSString *)email andPassword:(NSString *)password success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)registerNewUserWithEmail:(NSString* )email password:(NSString *)password success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)registerGuestUserWithEmail:(NSString *)email success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)resetPasswordForEmail:(NSString *)email success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)initialOrderCallWithJSON:(NSMutableDictionary *)json success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)finalOrderCallWithJSON:(NSMutableDictionary *)json success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)purchaseCartWithJSON:(NSMutableDictionary *)json success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *))failure;
- (void)cancelCurrentConnection;

@end

@protocol PSDKConnectionManagerDelegate <NSObject>

@optional
- (void)requestSetCurrentProgress:(double)progress;

@end