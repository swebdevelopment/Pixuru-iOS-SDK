##Pixuru iOS SDK

- [About Pixuru and the SDK](#about-pixuru-and-the-sdk)
- [Adding the files to your project](#adding-the-files-to-your-project)
- [Critical Steps for Non-ARC Apps](#critical-steps-for-non-arc-apps)
- [iPhone-Only App Recommendations](#iphone-only-app-recommendations)
- [Initialize the SDK](#initialize-the-sdk)
- [Customize the Appearance](#customize-the-appearance)
- [ClientOptions.plist](#clientoptions.plist)
- [Notifications](#notifications)
- [Test Purchases](#test-purchases)
- [Launch Checklist](#launch-checklist)

--------------------------------------
###About Pixuru and the SDK
--------------------------------------

Pixuru is one of the leading print commerce SDK's throughout the world.  We turn mobile phone images into high quality art pieces for your wall.  Our product line includes, canvas, wood, metal and framed prints.  Our line extends to iPhone cases, laptop sleeves and more.  Our partnerships include Facetune, CloneCamera, AlienSky and others.  

The Pixuru SDK can be installed easily and soon your users will be able to print their photos right from your app's UI.  [Email us] (mailto:craig.hensel@pixuru.com) for partnership inquiries.

####An App Key from Pixuru is required to publish an app including the Pixuru SDK

--------------------------------------
###Adding the files to your project
--------------------------------------

1. Drag and drop the PixuruSDKLibrary folder into your project, checking the "Copy items into destination group’s folder (if needed)” box and adding the framework to the appropriate targets in your project.

2. Add the following libraries if they are not already part of your project:
	- AddressBook
 	- AddressBookUI
 	- QuartzCore

--------------------------------------
###Critical Steps for Non-ARC Apps
--------------------------------------

The Pixuru SDK has two dependencies that are not compiled into the static library.

If you are building a project using manual reference counting, be sure to add the `-fobjc-arc` flag to the iCarousel.m, and base64.m in the compile sources tab.
You need to be using the LLVM for this.

--------------------------------------
###iPhone-Only App Recommendations
--------------------------------------

All of the images in the Pixuru SDK are set up to support universal binaries. If your application is iPhone-only, we suggest deleting the `iPad Images` folder within the `resources` directory of the SDK to cut down on the size of the SDK.

--------------------------------------
###Initialize the SDK
--------------------------------------

The SDK is launched using the `presentViewController:` method of **UINavigationController**.

Instantiate the **PSDKMasterNavigationController** with the **PSDKProductSelectViewController** as its root view controller.

If you wish to customize the SDK views, you must subscribe to **PSDKMasterNavigationController** through the `psdkdelegate` property. Customizing the product carousel is the only UI customization that does not occur in the delegate method (see example below).  

**On iPad:** the **PSDKMasterNavigationController** will include two keys:

1. `view` with the class name `PSDKProductSelectView`
2. `orientation` with two possible values: `landscape` and `portrait`

The `orientation` key will will register on initial loading of the iPad view, and when any rotation happens. This allows you to have any customizations ready for each orientation.

*Here is a simple example, using the default style:*

```
PSDKProductSelectViewController *psvc = [[PSDKProductSelectViewController alloc] init];

PSDKMasterNavigationController *master = [[PSDKMasterNavigationController alloc] initWithRootViewController:psvc];
master.psdkdelegate = self;`
```

*Here is a complex example, showing complete customization:*

```
PSDKProductSelectViewController *psvc = [[PSDKProductSelectViewController alloc] init];
psvc.carouselLowlightFont = [UIFont fontWithName:@"HelveticaNeue-Thin" size:20.0f];
psvc.carouselHighlightFont = [UIFont fontWithName:@"HelveticaNeue-Light" size:22.0f];
psvc.carouselLowlight = [UIColor colorWithWhite:0.0f alpha:0.6f];
psvc.carouselHighlight = [UIColor colorWithRed:(245.0f/255.0f) green:(245.0f/255.0f) blue:(245.0f/255.0f) alpha:1.0f];

PSDKMasterNavigationController *master = [[PSDKMasterNavigationController alloc] initWithRootViewController:psvc];
[master setPopLabelsColor:[UIColor colorWithRed:(245.0f/255.0f) green:(245.0f/255.0f) blue:(245.0f/255.0f) alpha:1.0f]];
master.psdkdelegate = self;
[master initializePixuruSDKWithImage:imageView.image];
master.navigationBar.barTintColor = [UIColor blackColor];
master.navigationBar.titleTextAttributes = @{NSForegroundColorAttributeName : [UIColor colorWithRed:(245.0f/255.0f) green:(245.0f/255.0f) blue:(245.0f/255.0f) alpha:1.0f]};
```

Any time the SDK is freshly presented, you need to call the `initializePixuruSDKWithImage:` method of **PSDKMasterNavigationController**:

```
UIImage *image = [UIImage imageNamed:@"FooFoo.jpg"];
    if(image){
    [master initializePixuruSDKWithImage:image];
    [self.navigationController presentViewController:master animated:YES completion:nil];
    }else{
    NSLog(@"Image not found");
    }
```

--------------------------------------
###Customize the Appearance
--------------------------------------

There are a few different methods of visual customization in the SDK.

To gain complete control over the look and feel of the SDK, you must subscribe to the protocol method that the **PSDKMasterNavigationController** provides. During the `viewDidLoad:` method of each view controller Pixuru SDK will call this delegate method, offering you the chance to customize the appearance of its subviews. The method will be called after all the subviews have been built, framed, and default styled, but before the view is shown to the user. If you are subscribing to this method, be sure to import the headers to the classes that you wish to customize.

All of the available views can be seen in the header files of each view controller.

Grab the value for key `view` in the info dictionary, which will always be the class name for the view being shown.

```
- (void)pixuruView:(PSDKMasterNavigationController *)master WillShow:(NSDictionary *)info;
{
	if([[info objectForKey:@"view"] isEqualToString:@"PSDKProductSelectViewController"]){
		// Using a cast to access the carousel view, and changing its color.
        [((PSDKProductSelectViewController *)[master topViewController]).carousel setBackgroundColor:[UIColor blackColor]];
        
    }else if([[info objectForKey:@"view"] isEqualToString:@"PSDKMoveScaleViewController"]){
        // etc
    }
}
```

You can use `UIAppearance` for various UI elements such as the navigation bar, etc.

There are also several open classes that have been copied for you outside of the static library.

They come with default stylings already applied inside their .m files, which you can change and add on to.

These include:

- **PSDKActionButton.h/.m**
- **PSDKCancelButton.h/.m**
- **PSDKCustomButton.h/.m**

The **Action** and **Cancel** buttons are found exclusively in the navigation bar, while the **Custom** button is used as the instance of all other UI buttons within the SDK. 

Customizing these allows you to theme the app to your liking.

Here's an example using a custom image for `PSDKActionButton.m` (the customizations go in `PSDKActionButton.m` directly):

```
[self setBackgroundColor:[UIColor clearColor]];
[self setTitleColor:[UIColor clearColor] forState:UIControlStateNormal];
[self setBackgroundImage:[UIImage imageNamed:@"forward"] forState:UIControlStateNormal];
[self setBackgroundImage:[UIImage imageNamed:@"forward-pressed"] forState:UIControlStateHighlighted];
```

You may need to adjust the bounds on custom button images to prevent stretching and pixelation, particularly if you choose to use images instead of text. Do that through the delegate method, like in this example:

```
[((PSDKProductSelectViewController *)[master topViewController]).cancelButton setBounds:CGRectMake(0, 0, 44, 44)];
[((PSDKProductSelectViewController *)[master topViewController]).previewButton setBounds:CGRectMake(0, 0, 44, 44)];
```

--------------------------------------
###ClientOptions.plist
--------------------------------------

The **ClientOptions.plist** included with the SDK contains several required key fields, and many optional ones.

####General Options:

* **production_mode** 			
    (BOOL)   - YES if using production servers, NO if using debug/staging (debug mode will log information for you into the console)
* **popup_animation** 			
    (Number) - Determines the animation style of the checkout pop up, 0=fade in, 1=slide down, 2=slide up
* **appKey**          			
    (String) - Unique value sent to you by Pixuru. Identifies your app to credit you for orders.	
* **enable_user_login**			
    (BOOL)   - If set to NO, all checkouts will be as guests — users will not be able to register or log in to an existing Pixuru account.		
* **wrap_carousel**				
    (BOOL)   - If set to NO, the product selection carousel will not scroll endlessly (wrapping values).
* **ipad_sdk_rotation** 
    (BOOL)  - If set to true, SDK views will rotate on iPad.

####View Options:
			
* **viewTitle**					
    (String) - Title of the view in the navigation header.		
* **leftBarButtonTitle**			
    (String) - Button text for the left bar button, when present. Typically “Back” or “Cancel”		
* **rightBarButtonTitle**			
    (String) - Button text for the left bar button, when present. Typically “Next” or “Checkout”

####Product Options:

* **addToBasePrice**				
    (NUMBER) - An (optional) amount (USD) to add to the minimum price of the product as determined by Pixuru. If addToBasePrice = 5.99 for a given product and the product base price is $125.00, the product price displayed in and used by the SDK will be $130.99.
* **included** 					
    (BOOL)   - A simple bool to show/hide particular products. If include = 0 for a given product, that product will not be shown to users.
* **sizeid**  					
    (NUMBER) - **DO NOT EDIT THESE VALUES**

--------------------------------------
###Notifications
--------------------------------------

The Pixuru SDK provides system notifications for significant events. 

These notifications are intended to provide as much information as you would like (within reason) to include in your own tracking as you wish. 

Make sure to subscribe to **PSDKNotification** using the `defaultCenter` to receive the notifications.

The types of notification defined in the `type` key include:

- order_cancel
- order_complete
- guest_checkout
- user_login
- user_registered
- api_fail

####Structure of the notifications:

```
{
    type: "order_complete",
    info:{
        date: "",
	view: "Cart View",
	user:{
	    email: "",
	    address:{
	        firstname: "",							           
                lastname: "",						        
                street: "",						
                street2: "",							
                city: "",							
                state: "",							
                zip: "",							
                country: ""
	    }
        },
        order:{
            orderid: "",
            item: "",
            subtotal: "",
	    discount: "",
	    taxshipping: "",
	    total: ""
        },
        error: ""
    }
}
```

--------------------------------------
###Test Purchases
--------------------------------------

When in debug mode, you can use the following sandbox credit card to make test purchases:

Credit card number: 4111 1111 1111 1111

Expiration: any future date

CVV: any 3 digits

--------------------------------------
###Launch Checklist
--------------------------------------

**Prior to submitting your app to Apple with the SDK enabled, it is critical that you:**
- Change the production_mode bool in ClientOptions.plist to "YES" to connect to the production API
- Include your valid appKey from Pixuru in ClientOptions.plist
