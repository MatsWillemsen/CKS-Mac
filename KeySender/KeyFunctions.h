//
//  KeyFunctions.h
//  KeySender
//
//  Created by Mats Willemsen on 06-01-12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>

#ifndef VARIABLES
#define VARIABLES
int startIntervalInt;
int endIntervalInt;
NSString * keyChar;
#endif
OSStatus FindPIDForWoW(pid_t *pid);

int keyCodeForKeyString(NSString * keyString);

OSStatus keyPressed(EventHandlerCallRef nextHandler, EventRef theEvent, void *userData);

@interface KeyFunctions : NSObject

@end
