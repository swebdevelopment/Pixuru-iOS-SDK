//
//  ViewController.m
//  SDKTestProject
//
//  Created by Skyler Whittlesey on 2/24/14.
//  Copyright (c) 2014 Skyler Whittlesey. All rights reserved.
//

#import "ViewController.h"
#import "PSDKMasterNavigationController.h"
#import "PSDKProductSelectViewController.h"


/*

 NON-ARC PROJECTS
 
If you are building a project using manual reference counting,
be sure to add the '-fobjc-arc' flag to the iCarousel.m, and base64.m in the compile sources tab.
 
*/

@interface ViewController () <PSDKMasterNavigationControllerDelegate> // Subscribe to protocol to receive the opportunity to customize views

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
        PSDKProductSelectViewController *psvc = [[PSDKProductSelectViewController alloc] init];
        PSDKMasterNavigationController *master = [[PSDKMasterNavigationController alloc] initWithRootViewController:psvc];
        master.psdkdelegate = self;
        [master initializePixuruSDKWithImage:image];
        [image release];
        [self.navigationController presentViewController:master animated:YES completion:nil];
        [master release];
    }else{
        NSLog(@"Image not found");
        [image release];
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
        
    }else if([[info objectForKey:@"view"] isEqualToString:@"PSDKMoveScaleViewController"]){
        // etc
    }
}

@end
