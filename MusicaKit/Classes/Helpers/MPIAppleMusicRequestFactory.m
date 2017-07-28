//
//  MPIAppleMusicRequestFactory.m
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicRequestFactory.h"
#import "NSURLRequest+HttpMethod.h"
#import "NSURLRequest+Curl.h"

static NSString *const kScheme = @"https";
static NSString *const kApiVersion = @"/v1";
static NSString *const kMainHostString = @"api.music.apple.com";
static NSString *const kCatalogEndpoint = @"/catalog";
static NSString *const kUserTokenKey = @"Music-User-Token";


@interface MPIAppleMusicRequestFactory ()
@property (nonatomic, class, readonly) NSURLComponents    *components;
@end

@implementation MPIAppleMusicRequestFactory

+ (NSURLRequest *)createGetStorefrontRequestForRegionCode:(NSString *)regionCode developerToken:(NSString *)devToken
{
    NSURLComponents *components = self.components;
    NSString *storefrontCode = regionCode.length > 0 ? [NSString stringWithFormat:@"/%@", regionCode] : @"";
    components.path = [NSString stringWithFormat:@"%@/storefronts%@", kApiVersion, storefrontCode].lowercaseString;
    NSAssert(components.URL, @"URL creation failed!");
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:components.URL cachePolicy:NSURLRequestReloadIgnoringCacheData timeoutInterval:10];
    [self authorizeRequest:request withDeveloperToken:devToken andUserToken:nil];
    NSLog(@"%@", request.curlCommand);
    return request;
}

+ (NSURLRequest *)createGetAllStorefrontsRequestsWithDeveloperToken:(NSString *)devToken
{
    return [self createGetStorefrontRequestForRegionCode:nil developerToken:devToken];
}

+ (NSURLRequest *)createGetUserStorefrontRequestWithUserToken:(NSString *)usrToken developerToken:(NSString *)devToken
{
    NSURLComponents *components = self.components;
    components.path = [NSString stringWithFormat:@"%@/me/storefront", kApiVersion].lowercaseString;
    NSAssert(components.URL, @"URL creation failed!");
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:components.URL cachePolicy:NSURLRequestReloadIgnoringCacheData timeoutInterval:10];
    [self authorizeRequest:request withDeveloperToken:devToken andUserToken:usrToken];
    NSLog(@"%@", request.curlCommand);
    return request;
}



#pragma mark – Priv
+ (NSURLComponents *)components
{
    NSURLComponents *components = [[NSURLComponents alloc] init];
    components.scheme = kScheme;
    components.host = kMainHostString;
    return components;
}

+ (void)authorizeRequest:(NSMutableURLRequest *)request withDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken
{
    [request addValue:[NSString stringWithFormat:@"Bearer %@", devToken] forHTTPHeaderField:@"Authorization"];
    if (usrToken.length > 0) {
        [request addValue:usrToken forHTTPHeaderField:kUserTokenKey];
    }
}

@end
