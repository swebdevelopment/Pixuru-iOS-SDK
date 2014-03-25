//
//  ViewController.m
//  SDKExampleProject
//
//  Created by Skyler Whittlesey on 3/25/14.
//  Copyright (c) 2014 Skyler Whittlesey. All rights reserved.
//

#import "ViewController.h"
#import "PSDKMasterNavigationController.h"
#import "PSDKProductSelectViewController.h"
#import "PSDKAddressViewController.h"
#import "PSDKCartViewController.h"
#import "ShippingDiscountView.h"
#import "CheckOutPopUpView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (IBAction)goPixuru:(id)sender {
    UIImage *image = [UIImage imageNamed:@"borabora.jpg"];
    
    if(image){
        // Initialize the SDK with an image and root view controller (PSDKProductSelectViewController)
        PSDKProductSelectViewController *psvc = [[[PSDKProductSelectViewController alloc] init] autorelease];
        PSDKMasterNavigationController *master = [[PSDKMasterNavigationController alloc] initWithRootViewController:psvc];
        master.psdkdelegate = self;
        [master initializePixuruSDKWithImage:image];
        [self.navigationController presentViewController:master animated:YES completion:nil];
    }else{
        NSLog(@"Image not found");
    }
}

#pragma mark - PSDK Delegate
- (void)pixuruView:(PSDKMasterNavigationController *)master WillShow:(NSDictionary *)info
{
    // This delegate method will be called during the viewDidLoad method of each view controller, after default subviews are built but befiore the view is shown
    // Use this chance to customize or move any subview from the view controller, they are all public properties you can view in the class headers
    // The info dictionary consists of one key-value, the key being 'view' and the value always being the class name of the view being shown
    // You can use any method you like to access the class properties for customization, below a cast is shown
    // Be sure to import the headers of the classes you want to customize
    
    // Here is the format logged out
    NSLog(@"Info: %@", info);
    
    if([[info objectForKey:@"view"] isEqualToString:@"PSDKProductSelectViewController"]){
        [((PSDKProductSelectViewController *)[master topViewController]).carousel setBackgroundColor:[UIColor blackColor]];
        
    }else if([[info objectForKey:@"view"] isEqualToString:@"PSDKAddressViewController"]){
        ((PSDKAddressViewController *)[master topViewController]).countryPickerDoneButtonFontColor = [UIColor greenColor];
    }else if([[info objectForKey:@"view"] isEqualToString:@"PSDKCartViewController"]){
        ((PSDKCartViewController *)[master topViewController]).countryPickerDoneButtonFont = [UIFont systemFontOfSize:44.0f];
    }
}

- (void)pixuruView:(PSDKMasterNavigationController *)master WillShowPopUp:(NSDictionary *)info
{
    // This delegate method will send a pointer to the actual instance of the pop up
    // Just test for the class or use any other way you would like to access the instance
    // Called right before the view is shown to the user
    
    if([[info objectForKey:@"view"] isKindOfClass:[ShippingDiscountView class]]){
        // ShippingDiscountView *sdv = (ShippingDiscountView *)[info objectForKey:@"view"];
        // [sdv setBackgroundColor:[UIColor greenColor]];
        
    }else if([[info objectForKey:@"view"] isKindOfClass:[CheckOutPopUpView class]]){
        // etc
    }
}

@end
