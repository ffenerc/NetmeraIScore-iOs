//
//  Globals.h
//  NetmeraIOsScore
//
//  Created by Serhat SARI on 9/4/12.
//  Copyright (c) 2012 Serhat SARI. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "Netmera/Netmera.h"


@interface Globals : NSObject{

    NetmeraUser *currentUser;
    //user
    NSString *emailString;

    BOOL isLoggedIn;
    
}
extern NSString * const constantContentName;
extern NSString * const constantNickname;
extern NSString * const constantEmail;
extern NSString * const constantScore;
extern NSString * const constantCacheCount;


@property (nonatomic, retain) NetmeraUser *currentUser;
@property (nonatomic, retain) NSString *emailString;
@property (nonatomic, retain) NSMutableArray *scores;

@property BOOL isLoggedIn;

+ (id)sharedInstance;
+ (id)allocWithZone:(NSZone *)zone;
- (void) getHighestScores;
- (void) setCacheCount:(NSInteger)count;

@end
