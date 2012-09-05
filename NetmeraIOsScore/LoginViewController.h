//
//  LoginViewController.h
//  NetmeraIOsScore
//
//  Created by Serhat SARI on 9/3/12.
//  Copyright (c) 2012 Serhat SARI. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Netmera/Netmera.h"

@interface LoginViewController : UIViewController <UITextFieldDelegate>

@property (retain, nonatomic) IBOutlet UITextField *loginEmailField;
@property (retain, nonatomic) IBOutlet UITextField *loginPwdField;

@property (retain, nonatomic) IBOutlet UITextField *regEmailField;
@property (retain, nonatomic) IBOutlet UITextField *regPwdField;
@property (retain, nonatomic) IBOutlet UITextField *regNickField;
@property (retain, nonatomic) IBOutlet UITextField *regNameField;
@property (retain, nonatomic) IBOutlet UITextField *regSurnameField;

@property (retain, nonatomic) NetmeraUser *loginUser;
@property (retain, nonatomic) IBOutlet UIScrollView *scroller;

- (IBAction)LoginClick:(id)sender;
- (IBAction)registerClick:(id)sender;

@end
