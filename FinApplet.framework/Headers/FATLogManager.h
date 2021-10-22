//
//  FATLogManager.h
//  FATLog
//
//  Created by HJH on 2018/5/21.
//

#import "FATLogEngine.h"

#define FATLogWithType(type, atag, frmt, ...)                                                                                 \
    do {                                                                                                                      \
        [[FATLogManager sharedInstance] logWithType:type tag:atag message:[NSString stringWithFormat:(frmt), ##__VA_ARGS__]]; \
    } while (0)

#define FATLogError(frmt, ...) \
    FATLogWithType(FATLogTypeError, nil, frmt, ##__VA_ARGS__)
#define FATLogWarning(frmt, ...) \
    FATLogWithType(FATLogTypeWarning, nil, frmt, ##__VA_ARGS__)
#define FATLogInfo(frmt, ...) \
    FATLogWithType(FATLogTypeInfo, nil, frmt, ##__VA_ARGS__)
#define FATLogDebug(frmt, ...) \
    FATLogWithType(FATLogTypeDebug, nil, frmt, ##__VA_ARGS__)

#define FATLogTagError(tag, frmt, ...) \
    FATLogWithType(FATLogTypeError, tag, frmt, ##__VA_ARGS__)
#define FATLogTagWarning(tag, frmt, ...) \
    FATLogWithType(FATLogTypeWarning, tag, frmt, ##__VA_ARGS__)
#define FATLogTagInfo(tag, frmt, ...) \
    FATLogWithType(FATLogTypeInfo, tag, frmt, ##__VA_ARGS__)
#define FATLogTagDebug(tag, frmt, ...) \
    FATLogWithType(FATLogTypeDebug, tag, frmt, ##__VA_ARGS__)

@class FATLoggerDriver;

@interface FATLogManager : NSObject
@property (strong, nonatomic, readonly) FATLogEngine *logEngine;

@property (assign, nonatomic) FATLogLevel level;

+ (instancetype)sharedInstance;

- (void)setup;

- (void)logWithType:(FATLogType)type tag:(NSString *)tag message:(NSString *)message;

/**
 Enable SystemLog.
 启用SystemLog。
 */
- (void)enableSystemLog;

/**
 Disable SystemLog.
 关闭SystemLog。
 */
- (void)disableSystemLog;

/**
 Enable file log. Logs will be written in files.
 打开文件log功能，将log写入文件
 */
- (void)enableFileLog;

/**
 Disable file log.
 关闭文件log功能
 */
- (void)disableFileLog;

/**
 Enable console log. We suggest don't Console Log when SystemLog is enabled.
 启用控制台log。我们建议这个功能不要同SystemLog同时开启。
 */
//- (void)enableConsoleLog;

///**
// Disable console log.
// 关闭控制台log。
// */
//- (void)disableConsoleLog;
//
///**
// Enable the browser log tool. The function requires the authorization of networking.
// 打开浏览器log调试功能。该功能须要APP网络权限。
// */
//- (void)enableRemoteConsole;

///**
// Disable the browser log tool.
// 关闭浏览器log调试功能。
// */
//- (void)disableRemoteConsole;

/**
 All the logs in memory will be written in files immediately.
 将log输出到文件.

 @return log files' path 返回所有的log文件路径
 */
- (NSArray<NSString *> *)exportLog;
@end
