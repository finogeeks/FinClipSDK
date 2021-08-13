//
// Copyright (c) 2017, finogeeks.com
// All rights reserved.
//
//
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

/**
 这个类的功能是封装WKScriptMessageHandler协议，目的是避免WKUserContentController.add的强引用而不释放，产生循环引用
 */
@interface FATWeakScriptMessageDelegate : NSObject <WKScriptMessageHandler>

@property (nonatomic, weak) id<WKScriptMessageHandler> scriptDelegate;

- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)delegate;

@end
