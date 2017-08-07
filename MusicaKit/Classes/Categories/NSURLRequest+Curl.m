//
//  NSURLRequest+Curl.m
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 24/07/2017.
//

#import "NSURLRequest+Curl.h"

@implementation NSURLRequest (Curl)

- (NSString *)curlCommand
{
    NSMutableString *command = [[NSMutableString alloc] init];
    [command appendFormat:@"curl -X %@", self.HTTPMethod];
    for (NSString *key in self.allHTTPHeaderFields) {
        [command appendFormat:@" -H '%@:%@'", key, self.allHTTPHeaderFields[key]];
    }
    if (self.HTTPBody) {
        [command appendFormat:@" -d '%@'", [[NSString alloc] initWithData:self.HTTPBody encoding:NSUTF8StringEncoding]];
    }
    [command appendFormat:@" '%@'", self.URL.absoluteString];
    return command;
}

@end
