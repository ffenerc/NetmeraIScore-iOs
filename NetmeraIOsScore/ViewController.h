//
//  ViewController.h
//  NetmeraIOsScore
//
//  Created by Serhat SARI on 9/3/12.
//  Copyright (c) 2012 Serhat SARI. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Score.h"

@interface ViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property (retain, nonatomic) IBOutlet UIButton *playgame;
@property (retain, nonatomic) Score *currentScore;
@property (retain, nonatomic) IBOutlet UILabel *scoreLabel;
@property (retain, nonatomic) IBOutlet UITableView *scoreBoard;


- (IBAction)logoutClicked:(id)sender;

- (IBAction)playGame:(id)sender;

@end
