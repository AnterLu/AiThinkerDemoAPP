//
//  DeviceManager.h
//  Devicexx
//
//  Created by yager on 8/15/2016.
//  Copyright © 2016年 device++. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DeviceManager : NSObject

+ (DeviceManager *)sharedInstance;

//开启本地UDP的接收服务
- (void)openUDPServer;
- (void)closeUDPServer;

/**
 * 获取周边的设备列表
 */
- (void)nearbyDeviceListCompletionHandler:(void (^)(NSArray *deviceList, NSError *error))completionHandler;


/**
 * 绑定设备前置条件，获取设备的密码等信息
 */
- (void)bindingDeviceHost:(NSString *)devHost
               devicePort:(UInt16)devPort
        completionHandler:(void (^)(NSDictionary *devInfo, NSError *error))completionHandler;

/**
 * AP模式让设备入网
 */
- (void)sendWIFIToDevice:(NSString *)ssid
                password:(NSString *)passwd
       completionHandler:(void (^)(NSDictionary *devInfo, NSError *error))completionHandler;


#pragma mark ---以下为设备控制功能部分---start

/**
 * 控制设备状态的初始化
 */
- (void)deviceControlInit:(NSString *)userId
               serverHost:(NSString *)serverHost
               serverPort:(int32_t)serverPort
        completionHandler:(void (^)(NSDictionary *devInfo, NSError *error))completionHandler;

/**
 * 订阅设备状态变更消息
 */
- (void)subscribeMessage:(NSString *)deviceId;
//第一次获取设备状态信息
- (void)getDeviceStatas:(NSString *)deviceId;

/**
 * 控制设备状态的开关状态
 */
- (void)publishMessage:(NSString *)deviceId status:(BOOL)swithOn;

#pragma mark ---设备控制功能部分结束---end


@end
