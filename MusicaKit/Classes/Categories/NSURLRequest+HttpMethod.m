//
//  NSURLRequest+HttpMethod.m
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "NSURLRequest+HttpMethod.h"

static NSString *const kHttpMethodGet = @"GET";
static NSString *const kHttpMethodPost = @"POST";
static NSString *const kHttpMethodPut = @"PUT";

@implementation NSURLRequest (HttpMethod)

- (HttpMethod)method
{
    if ([self.HTTPMethod isEqualToString:kHttpMethodGet]) {
        return Get;
    }
    if ([self.HTTPMethod isEqualToString:kHttpMethodPost]) {
        return Post;
    }
    if ([self.HTTPMethod isEqualToString:kHttpMethodPut]) {
        return Put;
    }
    return Unknown;
}

@end

@implementation NSMutableURLRequest (HttpMethod)

- (void)setMethod:(HttpMethod)method
{
    switch (method) {
            case Get:
            self.HTTPMethod = kHttpMethodGet;
            break;
            case Post:
            self.HTTPMethod = kHttpMethodPost;
            break;
            case Put:
            self.HTTPMethod = kHttpMethodPut;
            break;
        default:
            self.HTTPMethod = @"";
            break;
    }
}

@end
