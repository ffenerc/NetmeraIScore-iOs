//
//  ViewController.m
//  NetmeraIOsScore
//
//  Created by Serhat SARI on 9/3/12.
//  Copyright (c) 2012 Serhat SARI. All rights reserved.
//

#import "ViewController.h"
#import "Globals.h"
#import "LoginViewController.h"
#import "DSActivityView.h"
#import "Score.h"


@interface ViewController ()

@end

@implementation ViewController
@synthesize playgame;
@synthesize currentScore;
@synthesize scoreLabel;
@synthesize scoreBoard;

int counterIncreaser = 850000;

- (void)viewDidLoad
{
    [super viewDidLoad];

}

- (void) viewDidAppear:(BOOL)animated{
    Globals *g = [Globals sharedInstance];
    if (g.currentUser == nil) {
        LoginViewController *loginView = [[LoginViewController alloc] init];
        [self presentModalViewController:loginView animated:YES];
        [loginView release];
    }else{
        [g getHighestScores];
        [scoreBoard reloadData];
    }
}

- (void)viewDidUnload
{
    [self setPlaygame:nil];
    [self setScoreLabel:nil];
    [self setScoreBoard:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

- (IBAction)logoutClicked:(id)sender {
    [NetmeraUser logout];
    LoginViewController *loginView = [[LoginViewController alloc] init];
    [self presentModalViewController:loginView animated:YES];
    [loginView release];
}
- (void)dealloc {
    [playgame release];
    [scoreLabel release];
    [scoreBoard release];
    [super dealloc];
}
- (IBAction)playGame:(id)sender {
    
    [DSBezelActivityView activityViewForView:self.view withLabel:@"Game is playing..." width:200.0f];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        sleep(1);
        dispatch_async(dispatch_get_main_queue(), ^{
            [DSBezelActivityView cancelPreviousPerformRequestsWithTarget:self.view];
            [DSBezelActivityView removeView];
            
            int r = arc4random() % counterIncreaser;
            
            if (counterIncreaser < 1000000) {
                counterIncreaser += 10000;
            }
            
            if (currentScore != nil) {
                [currentScore release];
            }
            
            Globals *g = [Globals sharedInstance];
            currentScore = [[Score alloc] init];
            [currentScore setEmail:g.currentUser.email];
            [currentScore setNickname:g.currentUser.nickname];
            [currentScore setScore:[NSNumber numberWithInt:r]];
            
            scoreLabel.text = [currentScore.score stringValue];
            
            NSString *msg = [NSString stringWithFormat:@"Your greate score is: %@", currentScore.score];
            
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Your Score"
                                                            message:msg
                                                           delegate:self
                                                  cancelButtonTitle:@"Submit"
                                                  otherButtonTitles:@"Cancel", nil];
            [alert show];
            [alert release];
        });
    });
    
    
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    
    if (buttonIndex == 0) {
        [self createScoreContent];
        Globals *g = [Globals sharedInstance];
        [g getHighestScores];
        
        for (int i = 0; i < g.scores.count; i++) {
            Score *score = [g.scores objectAtIndex:i];
            if (currentScore != nil && [score.score intValue]< [currentScore.score intValue]) {
                [g.scores insertObject:currentScore atIndex:i];
                score = currentScore;
                break;
            }
        }
        
        [scoreBoard reloadData];
        
    }else{
        //nothing
    }
    
}

- (void) createScoreContent{
    Globals *g = [Globals sharedInstance];
    NetmeraContent *content=[[NetmeraContent alloc]initWithObjectName:constantContentName];
    [content add:constantNickname object:g.currentUser.nickname];
    [content add:constantEmail object:g.currentUser.email];
    [content add:constantScore object:currentScore.score];
    
    [content createInBackgroundWithBlock:^(NetmeraContent *content, NSError *error){
        [g getHighestScores];
    }];
}



- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    Globals *g = [Globals sharedInstance];
    if ([g.scores count] < 10) return [g.scores count];
    else return 10;
}



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    
    NSString *cellIdentifier=@"cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:cellIdentifier];
    }
    
    Globals *g = [Globals sharedInstance];
    Score *score = [g.scores objectAtIndex:indexPath.row];
    
    NSString *cellText = [NSString stringWithFormat:@"%i. %@", indexPath.row + 1, score.nickname];
    cell.textLabel.text = cellText;
    cell.detailTextLabel.text = [score.score stringValue];
    
    
    if ([score.email isEqualToString:g.currentUser.email]) {
        CGFloat cS = 255.0f;
        UIColor *colorLabel = [[UIColor alloc] initWithRed:255.0f/cS green:0.0f/cS blue:0.0f/cS alpha:1.0f];
        cell.textLabel.textColor = colorLabel;
        cell.detailTextLabel.textColor = colorLabel;
        [colorLabel release];
    }
    return cell;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section{
    return [NSString stringWithFormat:@"High Scores"];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
}


@end
