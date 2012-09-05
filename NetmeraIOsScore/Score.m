//
//  Score.m
//  NetmeraIOsScore
//
//  Created by Serhat SARI on 9/4/12.
//  Copyright (c) 2012 Serhat SARI. All rights reserved.
//

#import "Score.h"

@implementation Score

@synthesize email;
@synthesize nickname;
@synthesize score;


-(NSString*)description{
    
    NSString *description=[NSString stringWithFormat:@"score: %@ \nnickname: %@ \nemail: %@", score, nickname, email];
    
    return description;
}


@end
