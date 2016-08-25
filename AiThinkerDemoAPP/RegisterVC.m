//
//  RegisterVC.m
//  AiThinkerDemoAPP
//
//  Created by Anter_Mac on 16/8/25.
//  Copyright © 2016年 Anter. All rights reserved.
//

#import "RegisterVC.h"
#import "LoginVC.h"

@interface RegisterVC ()

@end

@implementation RegisterVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)registerClickAction:(id)sender {
    UserManager *userManager = [UserManager sharedInstance];
    NSString *userName = [_registerUserName text];
    NSString *passWord = [_registerPassword text];
    [userManager registerUserName:userName password:passWord completionHandler:^(id responseJSON, NSError *error) {
        NSLog(@"返回正确的数据 == %@",responseJSON);
        NSLog(@"返回错误的信息 == %@",error);
    }];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
