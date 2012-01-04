//
//  KeySenderAppDelegate.h
//  KeySender
//
//  Created by Mats Willemsen on 04-01-12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface KeySenderAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
}

@property (assign) IBOutlet NSWindow *window;

@end
