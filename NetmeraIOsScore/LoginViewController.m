//
//  LoginViewController.m
//  NetmeraIOsScore
//
//  Created by Serhat SARI on 9/3/12.
//  Copyright (c) 2012 Serhat SARI. All rights reserved.
//

#import "LoginViewController.h"
#import "Netmera/Netmera.h"
#import "Globals.h"
#import "DSActivityView.h"

@interface LoginViewController ()

@end

@implementation LoginViewController
@synthesize loginEmailField;
@synthesize loginPwdField;
@synthesize regEmailField;
@synthesize regPwdField;
@synthesize regNickField;
@synthesize regNameField;
@synthesize regSurnameField;
@synthesize loginUser;
@synthesize scroller;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [self setLoginEmailField:nil];
    [self setLoginPwdField:nil];
    [self setRegEmailField:nil];
    [self setRegPwdField:nil];
    [self setRegNickField:nil];
    [self setRegNameField:nil];
    [self setRegSurnameField:nil];
    [self setScroller:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)dealloc {
    [loginEmailField release];
    [loginPwdField release];
    [regEmailField release];
    [regPwdField release];
    [regNickField release];
    [regNameField release];
    [regSurnameField release];
    [scroller release];
    [super dealloc];
}
- (IBAction)LoginClick:(id)sender {
    [self closeKeyboard];
    [self loginAction];
}

- (IBAction)registerClick:(id)sender {
    [self closeKeyboard];
    [self registerAction];
}

- (void)loginAction{
    [DSBezelActivityView activityViewForView:self.view withLabel:@"Loading" width:100.0f];
    
    [NetmeraUser loginInBackgroundWithTarget:self selector:@selector(callBackLoginWithError:error:withNetmeraUser:) withEmail:loginEmailField.text andPassword:loginPwdField.text];
}

- (void)callBackLoginWithError:(NSError *)error withNetmeraUser:(NetmeraUser *)user{
    [DSBezelActivityView cancelPreviousPerformRequestsWithTarget:self.view];
    [DSBezelActivityView removeView];
    Globals *g = [Globals sharedInstance];
    NSLog(@"user = %@ - %@", user.name, user.surname);
    if (error == nil) {
        g.currentUser = user;
        [self dismissModalViewControllerAnimated:YES];
    }else{
        UIAlertView *alert=[[UIAlertView alloc]initWithTitle:@"Error" message:[error.userInfo objectForKey:NSLocalizedDescriptionKey] delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
        [alert show];
        [alert release];
    }
}

- (void)registerAction{
    NSString *email = regEmailField.text;
    NSString *password = regPwdField.text;
    NSString *nickname = regNickField.text;
    NSString *name = regNameField.text;
    NSString *surname = regSurnameField.text;
    
    NetmeraUser *user = [[NetmeraUser alloc] init];
    user.email = email;
    user.password = password;
    user.nickname = nickname;
    user.name = name;
    user.surname = surname;
    
    [DSBezelActivityView activityViewForView:self.view withLabel:@"Loading" width:100.0f];
    [user registerInBackgroundWithBlock:^(NSError *error) {
        [DSBezelActivityView cancelPreviousPerformRequestsWithTarget:self.view];
        [DSBezelActivityView removeView];
        Globals *g = [Globals sharedInstance];
        if (error == nil) {
            g.currentUser = user;
            [self dismissModalViewControllerAnimated:YES];
        }else{
            UIAlertView *alert=[[UIAlertView alloc]initWithTitle:@"Error" message:[error.userInfo objectForKey:NSLocalizedDescriptionKey] delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
            [alert show];
            [alert release];
        }
    }];
    
}


- (void)closeKeyboard{
    self.scroller.contentSize = CGSizeMake(320, 480);
    [loginEmailField setEnabled:NO];
    [loginPwdField setEnabled:NO];
    [regEmailField setEnabled:NO];
    [regPwdField setEnabled:NO];
    [regNickField setEnabled:NO];
    [regNameField setEnabled:NO];
    [regSurnameField setEnabled:NO];
    
    [loginEmailField setEnabled:YES];
    [loginPwdField setEnabled:YES];
    [regEmailField setEnabled:YES];
    [regPwdField setEnabled:YES];
    [regNickField setEnabled:YES];
    [regNameField setEnabled:YES];
    [regSurnameField setEnabled:YES];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    if (textField == loginEmailField) {
        [loginPwdField becomeFirstResponder];
    }else if(textField == loginPwdField){
        [self loginAction];
    }else if(textField == regEmailField){
        [regPwdField becomeFirstResponder];
    }else if(textField == regPwdField){
        [regNickField becomeFirstResponder];
    }else if(textField == regNickField){
        [regNameField becomeFirstResponder];
    }else if(textField == regNameField){
        [regSurnameField becomeFirstResponder];
    }else if(textField == regSurnameField){
        [self registerAction];
    }
    return YES;
}

-(void) textFieldDidBeginEditing:(UITextField *)textField{
    self.scroller.contentSize = CGSizeMake(320, 649);
}
@end
