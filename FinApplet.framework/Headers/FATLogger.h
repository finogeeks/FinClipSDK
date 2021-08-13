//
//  FATLogger.h
//  FATLog
//
//  Created by HJH on 2021/1/8.
//

#import <Foundation/Foundation.h>

@class FATLogFormatter;

@protocol FATLogger <NSObject>
+ (instancetype)logger;
- (void)log:(NSString *)logString;
@end

//即NS.Log
@interface FATSystemLogger : NSObject <FATLogger>

@end

@interface FATFileLogger : NSObject <FATLogger>

/**
 Default value is 1024 * 256 Bytes.
 */
@property (assign, nonatomic) NSInteger maxCacheSize;

/**
 Bytes. Default value is 1024*1024*30 bytes.
 */
@property (assign, nonatomic) unsigned long long maxSingleFileSize;

/**
 Init method.

 @param path Path of log files
 @param storagedDay Storaged days of log files. Default value is 1.
 @return FATFileLogger instance
 */
- (instancetype)initWithDirectoryRootPath:(NSString *)path storagedDay:(NSUInteger)storagedDay NS_DESIGNATED_INITIALIZER;

/**
 All cached logs will be written to file immediately.

 @return All the log File's paths
 */
- (NSArray<NSString *> *)exportLog;
@end
