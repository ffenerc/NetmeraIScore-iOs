//
//  Globals.m
//  Sanal Market
//
//  Created by Ozkan ALTUNER on 08.04.2010.
//  Copyright 2010 Orangeplus. All rights reserved.
//

#import "Globals.h"
#import <sqlite3.h>
#import "Netmera/Netmera.h"
#import "Score.h"

@implementation Globals

@synthesize emailString;
@synthesize isLoggedIn;
@synthesize currentUser;
@synthesize scores;

NSString * const constantContentName = @"ScoresDeneme";
NSString * const constantNickname = @"nickname";
NSString * const constantEmail = @"email";
NSString * const constantScore = @"score";

NSString * const constantCacheCount = @"cacheCount";

// the instance of class is stored here
static Globals *myInstance = nil;

+ (id)sharedInstance {
	if (myInstance == nil) {
		myInstance = [[super allocWithZone:Nil] init];
	}
	return myInstance;
}

+ (id)allocWithZone:(NSZone *)zone {
    @synchronized(self) {
        if(myInstance == nil)  {
            myInstance = [super allocWithZone:zone];
            return myInstance;
        }
    }
    return nil;
}

- (id)init {
	self = [super init];
	if (self != nil) {
		currentUser = nil;
		emailString = [[NSString alloc] init];
		isLoggedIn = NO;
        scores = [[NSMutableArray alloc] init];
    }
	return self;
}

- (void) getHighestScores{
    

    double startTime = CFAbsoluteTimeGetCurrent();
    NetmeraService *service = [[NetmeraService alloc]initWithName:constantContentName];
    [service setSortBy:constantScore];
    [service setSortOrder:descending];
    
    NSError *err = nil;
    NSArray *netmeraContentArray = [service search:&err];
    
    double endTime = CFAbsoluteTimeGetCurrent();
    
    NSLog(@"time duration: %f", endTime - startTime);
    //[service searchInBackgroundWithBlock:^(NSArray *netmeraContentArray, NSError *error) {

        for (NetmeraContent *content in netmeraContentArray) {
            Score *score = [[Score alloc] init];
            [score setEmail:[content getString:constantEmail]];
            [score setNickname:[content getString:constantNickname]];
            [score setScore:[NSNumber numberWithInt:[content getInt:constantScore]]];
            [scores addObject:score];
            //NSLog(@"%@", [score score]);
            [score release];
        }
    //}];
    
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    NSInteger cacheCount = [prefs integerForKey:constantCacheCount];

    if (cacheCount > 5) {
        NSLog(@"[NetmeraClient deleteCacheResults];");
        [NetmeraClient deleteCacheResults];
        [self setCacheCount:0];
    }else{
        cacheCount += 1;
        [self setCacheCount:cacheCount];
    }
    
    
    [service release];
}

- (void) setCacheCount:(NSInteger)count{
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    [prefs setInteger:count forKey:constantCacheCount];
    [[NSUserDefaults standardUserDefaults] synchronize];
}
@end
