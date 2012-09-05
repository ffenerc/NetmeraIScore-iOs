//
//  AppDelegate.m
//  NetmeraIOsScore
//
//  Created by Serhat SARI on 9/3/12.
//  Copyright (c) 2012 Serhat SARI. All rights reserved.
//

#import "AppDelegate.h"
#import "Netmera/Netmera.h"
#import "ViewController.h"
#import "Globals.h"

@implementation AppDelegate

- (void)dealloc
{
    [_window release];
    [_viewController release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [NetmeraClient initWithApiKey:@"WVhCd1ZYSnNQV2gwZEhBbE0wRWxNa1lsTWtZeE1qWTFOakl4T1M1dVpYUnRaWEpoTG1OdmJTVXpRVGd3SlRKR2JXOWlhVzFsY21FbE1rWm5ZV1JuWlhRbE1rWm9iMjFsTG5odGJDWnViVk5wZEdWVmNtdzlhSFIwY0NVelFTVXlSaVV5UmpFeU5qVTJNakU1TG01bGRHMWxjbUV1WTI5dEpUTkJPREFtYlc5a2RXeGxTV1E5TlRVNE1DWmhjSEJKWkQweE1qWTFOakl4T1NadWJWUmxiWEJzWVhSbFBXMXZZbWwwWlcxd2JHRjBaU1p2ZDI1bGNrbGtQWE5sY21oaGRDMXpZWEpwSm1SdmJXRnBiajF1WlhSdFpYSmhMbU52YlNadWJWTnBkR1U5TVRJMk5UWXlNVGttYjNkdVpYSlNiMnhsVkhsd1pUMHhKblpwWlhkbGNsSnZiR1ZVZVhCbFBURW1kbWxsZDJWeVNXUTljMlZ5YUdGMExYTmhjbWtt"];
    
    [NetmeraClient setCacheType:FIRST_CACHE_THEN_NETWORK];
    
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    NSInteger cacheCount = [prefs integerForKey:constantCacheCount];
    
    Globals *g = [Globals sharedInstance];
    if (cacheCount == 0) {
        [g setCacheCount:0];
    }else if (cacheCount > 5) {
        NSLog(@"[NetmeraClient deleteCacheResults];");
        [NetmeraClient deleteCacheResults];
        [g setCacheCount:0];
    }
    
    NSDate *goingToBackGroundDate = [[NSUserDefaults standardUserDefaults] objectForKey:@"goingToBackGroundDate"];
    NSTimeInterval since = [goingToBackGroundDate timeIntervalSinceNow];
    NSTimeInterval keepTime = -3600;
    if(keepTime > since){
        NSLog(@"[NetmeraClient deleteCacheResults];");
        [NetmeraClient deleteCacheResults];
        [g setCacheCount:0];
    }
        
        
    
    [self chechExistingUser];
    
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    // Override point for customization after application launch.
    self.viewController = [[[ViewController alloc] initWithNibName:@"ViewController" bundle:nil] autorelease];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    NSLog(@"background time= %@", [NSDate date]);
    [[NSUserDefaults standardUserDefaults] setObject:[NSDate date] forKey:@"goingToBackGroundDate"];
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (BOOL)chechExistingUser{

    NetmeraUser *user = [NetmeraUser getCurrentUser];
    Globals *g = [Globals sharedInstance];
    
    if ([user email] == nil || [[user email] isEqualToString:@""]) {
        return NO;
    }else{
        g.currentUser = user;
        return YES;
    }
    
}

@end
