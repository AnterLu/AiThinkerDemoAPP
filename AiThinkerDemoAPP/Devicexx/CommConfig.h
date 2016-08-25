//
//  CommConfig.h
//  Devicexx
//
//  Created by yager on 8/15/2016.
//  Copyright © 2016年 device++. All rights reserved.
//

/**
 * 服务器路径配置 http://api.vcd.io:4567/v1/
 * 注意：此地址不能加上 "http://"
 */
#define NETWORK_URL @"api.vcd.io:4567/v1"


/**
 * 合作厂商key、secret; 由Devcie++提供给合作厂商
 */
#define ACCESS_KEY    @"8e0bb23839955bde1346b6e9395347ff"
#define ACCESS_SECRET @"cafdeb099d45eee7e2faddea091fd609"


//仅在DEBUG模式下打印日志，发布APP不会打印日志
#ifdef DEBUG
# define NSLog(fmt, ...) NSLog((@"%s -%d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
# define NSLog(...) {}
#endif
