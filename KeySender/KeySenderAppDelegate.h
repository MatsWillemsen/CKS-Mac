//
//  KeySenderAppDelegate.h
//  KeySender
//
//  Created by Mats Willemsen on 04-01-12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>
#import "KeyFunctions.h"


EventHandlerRef ref;

@interface KeySenderAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
    NSTextField *firstSecond;
    NSTextField *secondSecond;
    NSTextField *keyPress;
    NSButton *mouseListen;
    NSButton *keyboardListen;
}
@property (assign) IBOutlet NSButton *keyboardListen;
@property (assign) IBOutlet NSButton *mouseListen;
@property (assign) IBOutlet NSTextField *keyPress;
@property (assign) IBOutlet NSTextField *firstSecond;
@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSTextField *secondSecond;
- (IBAction)getStartInterval:(id)sender;
- (IBAction)getEndInterval:(id)sender;
- (IBAction)setKeys:(id)sender;
- (IBAction)listenToMouse:(id)sender;
- (IBAction)listenToKeyboard:(id)sender;

@end

