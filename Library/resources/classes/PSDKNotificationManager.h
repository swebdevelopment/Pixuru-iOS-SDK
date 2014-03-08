//
//  PSDKNotificationManager.h
//  PixuruSDK
//
//  Created by Skyler Whittlesey on 9/24/13.
//  Copyright (c) 2013 Skyler Whittlesey. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PSDKNotificationManager : NSObject

+ (PSDKNotificationManager *)sharedInstance;
+ (void)resetSharedInstance;

- (void)postNotificationWithType:(NSString *)type andError:(NSString *)error;

@end
