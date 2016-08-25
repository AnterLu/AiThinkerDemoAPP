//
//  LoginVC.m
//  AiThinkerDemoAPP
//
//  Created by Anter_Mac on 16/8/25.
//  Copyright © 2016年 Anter. All rights reserved.
//

#import "LoginVC.h"
#import "UserManager.h"
#import "MBProgressHUD+NJ.h"
#import "SBJson.h"

@interface LoginVC ()
{
    MBProgressHUD *hub;
}

@end

@implementation LoginVC

//+ (UserManager *)sharedInstance{
//
//    static UserManager *sharedUserManager = nil;
//
//    @synchronized(self)
//    {
//        if (!sharedUserManager)
//            sharedUserManager = [[UserManager alloc] init];
//        return sharedUserManager;
//    }
//    return sharedUserManager;
//}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/**
 *  登陆按钮点击事件
 *
 *  @param sender <#sender description#>
 */
- (IBAction)loginClickAction:(id)sender {
    
//    [MBProgressHUD showMessage:@"Login..."];
    
    UserManager *userManager = [UserManager sharedInstance];
    NSString *userName = [_userName text];
    NSString *passWord = [_passWord text];
    NSString __block *resultString = [[NSString alloc] init];
    
    [userManager loginUserName:userName password:passWord completionHandler:^(id responseJSON, NSError *error) {
        
        if (responseJSON != nil) {
             NSLog(@"登陆成功： %@",responseJSON);
            resultString = responseJSON;
            [self showDialog:resultString];
        }else{
            NSLog(@"登陆失败： %@",error);
            resultString = [NSString stringWithFormat:@"%@",error];
             [self showDialog:resultString];
        }
//        [MBProgressHUD hideHUD];
    }];
}

- (void)showDialog:(NSString *)stringToShow{
    
    //success
//    2016-08-25 16:30:40.838 AiThinkerDemoAPP[6342:246258] resultString == {
//        data =     {
//            "user_id" = 64KkUrM6JZVLjQA5V46wMT;
//            "user_token" = "1dd07881-dd48-4c5e-a238-c1122ec1f12d";
//        };
//        success = 1;
//    }
    
    //faild
//    2016-08-25 16:31:19.901 AiThinkerDemoAPP[6342:246258] resultString == {
//        "error_code" = 401;
//        message = "user password incorrect";
//        success = 0;
//    }
    
//    id jsonObj = [NSJSONSerialization ];
    
    NSLog(@"stringToShow == %@",stringToShow);
    
    NSData *data = [stringToShow dataUsingEncoding:NSUTF8StringEncoding];
    NSMutableDictionary *rootDic = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableLeaves error:nil];
    
    NSLog(@"rootDic = %@",[rootDic objectForKey:@"success"]);
    
    UIAlertController *alert= [UIAlertController alertControllerWithTitle:@"info"
                                                                  message:@"Login Success!"
                                                           preferredStyle:UIAlertControllerStyleAlert];
    
    [alert addAction:[UIAlertAction actionWithTitle:@"OK"
                                              style:UIAlertActionStyleCancel
                                            handler:^(UIAlertAction *action) {
        NSLog(@"cancle!");
    }]];
    [self presentViewController:alert animated:YES completion:nil];
}

/**
 *  注册按钮点击事件
 *
 *  @param sender <#sender description#>
 */
- (IBAction)registClickAction:(id)sender {
}

/**
 *  忘记密码点击事件
 *
 *  @param sender <#sender description#>
 */
- (IBAction)forgetPasswordClickAction:(id)sender {
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
