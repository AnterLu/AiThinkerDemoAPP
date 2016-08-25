//
//  EncryptionTool.h
//  Devicexx
//
//  Created by yager on 16/8/18.
//  Copyright © 2016年 device++. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EncryptionTool : NSObject

+ (NSData *)dataWithDictionary:(NSDictionary *)dict;

+ (NSString *)md5String:(NSString *)inputStr;
+ (NSString *)generateSignature:(NSDictionary *)params;

@end
