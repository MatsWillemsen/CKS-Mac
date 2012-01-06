//
//  KeySenderAppDelegate.m
//  KeySender
//
//  Created by Mats Willemsen on 04-01-12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import "KeySenderAppDelegate.h"


@implementation KeySenderAppDelegate

@synthesize secondSecond;

@synthesize keyboardListen;
@synthesize mouseListen;
@synthesize keyPress;
@synthesize firstSecond;
@synthesize window;


- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    
    EventTypeSpec kEvents[] = {
        {kEventClassKeyboard, kEventRawKeyUp},
        {kEventClassMouse, kEventMouseMoved}
    };
    
    
    EventHandlerUPP handlerFunction = NewEventHandlerUPP(keyPressed);
    InstallEventHandler(GetEventMonitorTarget(), handlerFunction, GetEventTypeCount(kEvents), kEvents, NULL, &ref);
    
    startIntervalInt = 4;
    endIntervalInt = 5;
    keyChar = @"4";
        
                                                         
}



- (IBAction)sendkey:(id)sender {

}
- (IBAction)getStartInterval:(id)sender {
    startIntervalInt = [sender intValue];
}

- (IBAction)getEndInterval:(id)sender {
    endIntervalInt = [sender intValue];
}

- (IBAction)setKeys:(id)sender {
    keyChar = [sender stringValue];
}

- (IBAction)listenToMouse:(id)sender {
    if([sender state] == NSOnState) {
        EventTypeSpec kEvent[] = { 
            {kEventClassMouse,kEventMouseMoved }
        };
        RemoveEventTypesFromHandler(ref, GetEventTypeCount(kEvent), kEvent);
        AddEventTypesToHandler(ref, GetEventTypeCount(kEvent), kEvent);
    }
    else {
        EventTypeSpec kEvent[] = {
            {kEventClassMouse,kEventMouseMoved }
        };
        RemoveEventTypesFromHandler(ref, GetEventTypeCount(kEvent), kEvent);
    }
}

- (IBAction)listenToKeyboard:(id)sender {
    if([sender state] == NSOnState) {
        EventTypeSpec kEvent[] = { 
            {kEventClassKeyboard,kEventRawKeyUp }
        };
        RemoveEventTypesFromHandler(ref, GetEventTypeCount(kEvent), kEvent);
        AddEventTypesToHandler(ref, GetEventTypeCount(kEvent), kEvent);
    }
    else {
        EventTypeSpec kEvent[] = {
            {kEventClassKeyboard,kEventRawKeyUp }
        };
        RemoveEventTypesFromHandler(ref, GetEventTypeCount(kEvent), kEvent);
    }    
}

@end