//
//  KeyFunctions.cpp
//  KeySender
//
//  Created by Mats Willemsen on 06-01-12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import "KeyFunctions.h"

OSStatus FindPIDForWoW(pid_t *pid) {
    CFURLRef outAppURL;
    OSErr err;
	err = LSFindApplicationForInfo(NULL,
								   (CFStringRef)@"com.blizzard.worldofwarcraft",
								   NULL,
								   NULL,
								   &outAppURL);
    err = 0;
	FSRef desired, found;
	ProcessSerialNumber psn = {0, kNoProcess};
    
	if (!CFURLGetFSRef(outAppURL, &desired)) return errFSBadFSRef;
	do {
		err = GetNextProcess(&psn);
		if (err) return err; // -600 = process not found
		err = GetProcessBundleLocation(&psn, &found);
	} while (err || FSCompareFSRefs(&desired, &found));
	err = GetProcessPID(&psn, pid);
	if (err) return err;
	return noErr;
}