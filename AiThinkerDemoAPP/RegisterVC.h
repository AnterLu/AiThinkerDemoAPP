//
//  RegisterVC.h
//  AiThinkerDemoAPP
//
//  Created by Anter_Mac on 16/8/25.
//  Copyright © 2016年 Anter. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UserManager.h"

@interface RegisterVC : UIViewController

//@property (strong, nonatomic) UserManager *userManager;

@property (weak, nonatomic) IBOutlet UITextField *registerUserName;
@property (weak, nonatomic) IBOutlet UITextField *registerPassword;

@end
