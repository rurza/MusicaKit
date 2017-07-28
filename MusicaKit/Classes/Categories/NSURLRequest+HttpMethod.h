//
//  NSURLRequest+HttpMethod.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, HttpMethod) {
    Unknown = 0,
    Get,
    Post,
    Put
};

@interface NSURLRequest (HttpMethod)
@property (nonatomic, readonly) HttpMethod method;
@end

@interface NSMutableURLRequest (HttpMethod)
@property (nonatomic, readwrite) HttpMethod method;
@end
