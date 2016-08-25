//
//  UserManager.h
//  Devicexx
//
//  Created by yager on 8/15/2016.
//  Copyright © 2016年 device++. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserManager : NSObject

+ (UserManager *)sharedInstance;

/**
 * 用户名、密码进行注册
 */
- (void)registerUserName:(NSString *)username
                password:(NSString *)password
       completionHandler:(void (^)(id responseJSON, NSError *error))completionHandler;

/**
 * 用户名、密码进行登录
 */
- (void)loginUserName:(NSString *)username
             password:(NSString *)password
    completionHandler:(void (^)(id responseJSON, NSError *error))completionHandler;

/**
 *  用户名进行设备绑定操作
 * 
 *  硬件信息devInfo字典参数信息取值示例：
 *  NSString *device_access_key = devInfo[@"access_key"];
 *  NSString *device_password   = devInfo[@"password"];
 *  NSString *device_id         = devInfo[@"deviceId"];
 *  NSString *device_ts         = devInfo[@"ts"]；
 *
 */
- (void)bindDeviceForUser:(NSString *)userToken
               deviceInfo:(NSDictionary *)devInfo
        completionHandler:(void (^)(id responseJSON, NSError *error))completionHandler;


/**
 *  用户名进行设备解除绑定操作
 *
 *  硬件信息devInfo字典参数信息取值示例：
 *  NSString *device_id         = devInfo[@"deviceId"];
 *  NSString *device_password   = devInfo[@"password"];
 *
 */
- (void)unbindDeviceForUser:(NSString *)userToken
                 deviceInfo:(NSDictionary *)devInfo
          completionHandler:(void (^)(id responseJSON, NSError *error))completionHandler;

/**
 * 用户进行设备部署，获取设备的信息
 */
- (void)deployDeviceForUser:(NSString *)userToken
                 deviceInfo:(NSDictionary *)devInfo
          completionHandler:(void (^)(id responseJSON, NSError *error))completionHandler;


/**
 * 获取用户绑定过的设备列表
 */
- (void)deviceListForUser:(NSString *)userToken
        completionHandler:(void (^)(id responseJSON, NSError *error))completionHandler;
@end
