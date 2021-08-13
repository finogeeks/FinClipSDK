//
//  FATLogEngine.h
//  FATLog
//
//  Created by HJH on 2021/1/8.
//

#import <Foundation/Foundation.h>
#import "FATLogger.h"

@class FATLoggerDriver;
@class FATLogFormatter;

typedef NS_ENUM(NSUInteger, FATLogFormatType) {
    FATLogFormatTypeSystemLog = 0,
    FATLogFormatTypeConsole, //暂时没用
    FATLogFormatTypeFile,
};

typedef NS_ENUM(NSUInteger, FATLogType) {
    FATLogTypeError = 0,
    FATLogTypeWarning,
    FATLogTypeInfo,
    FATLogTypeDebug,
};

typedef NS_ENUM(NSUInteger, FATLogLevel) {
    FATLogLevelOff = 0,
    FATLogLevelError,
    FATLogLevelWarning,
    FATLogLevelInfo,
    FATLogLevelDebug,
};

@protocol FATFormatable <NSObject>
- (NSString *)completeLogWithType:(FATLogType)type
                              tag:(NSString *)tag
                          message:(NSString *)message
                     timeInterval:(NSTimeInterval)timeInterval;
@end

@interface FATLogEngine : NSObject
- (void)addDriver:(FATLoggerDriver *)driver;

- (void)removeDriver:(FATLoggerDriver *)driver;

- (void)removeAllDrivers;

- (void)logWithType:(FATLogType)type tag:(NSString *)tag message:(NSString *)message timeInterval:(NSTimeInterval)timeInterval;

- (NSArray<FATLoggerDriver *> *)allDrivers;
@end

@interface FATLoggerDriver : NSObject
@property (strong, nonatomic) id<FATLogger> logger;
@property (strong, nonatomic) id<FATFormatable> formatter;
@property (assign, nonatomic) FATLogLevel level;

- (instancetype)initWithLogger:(id<FATLogger>)logger
                     formatter:(id<FATFormatable>)formatter
                         level:(FATLogLevel)level NS_DESIGNATED_INITIALIZER;

- (void)logWithType:(FATLogType)type tag:(NSString *)tag message:(NSString *)message timeInterval:(NSTimeInterval)timeInterval;
@end

@interface FATLogFormatter : NSObject <FATFormatable>
+ (instancetype)formatterWithType:(FATLogFormatType)type;
+ (instancetype)SystemLogFormatter;
+ (instancetype)ConsoleFormatter;
+ (instancetype)FileFormatter;

- (instancetype)initWithType:(FATLogFormatType)type;
@end

@interface FATDateFormatter : NSObject
+ (instancetype)sharedInstance;

- (NSString *)dateStringWithTimeInterval:(NSTimeInterval)timeInterval;
@end
