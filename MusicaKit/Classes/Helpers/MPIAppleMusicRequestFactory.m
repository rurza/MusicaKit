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


static NSString *const kMPIAppleMusicURLScheme =                    @"https";
static NSString *const kMPIAppleMusicApiVersion =                   @"/v1";
static NSString *const kMPIAppleMusicHost =                         @"api.music.apple.com";
static NSString *const kMPIAppleMusicCatalogEndpoint =              @"/catalog";
static NSString *const kMPIAppleMusicMeEndpoint =                   @"/me";
static NSString *const kMPIAppleMusicUserTokenKey =                 @"Music-User-Token";
static NSString *const kMPIAppleMusicAlbumsEndpoint =               @"/albums";
static NSString *const kMPIAppleMusicRecommendationsEndpoint =      @"/recommendations";
static NSString *const kMPIAppleMusicSearchEndpoint =               @"/search";
static NSString *const kMPIAppleMusicStorefrontsEndpoint =          @"/storefronts";

#define MPI_ASSERT_COMPONENTS_URL NSAssert(components.URL, @"URL creation failed!")
#define MPI_ASSERT_USER_TOKEN NSAssert(usrToken.length > 0, @"User token is nil or empty")
#define MPI_ASSERT_DEVELOPER_TOKEN NSAssert(devToken.length > 0, @"Developer token is nil or empty")

@interface MPIAppleMusicRequestFactory ()
@property (nonatomic, class, readonly) NSURLComponents    *components;
@end

@implementation MPIAppleMusicRequestFactory

#pragma mark - Storefronts
+ (NSURLRequest *)createGetStorefrontRequestForRegionCode:(NSString *)regionCode developerToken:(NSString *)devToken
{
    NSURLComponents *components = self.components;
    NSString *storefrontCode = regionCode.length > 0 ? [NSString stringWithFormat:@"/%@", regionCode] : @"";
    components.path = [NSString stringWithFormat:@"%@%@%@", kMPIAppleMusicApiVersion, kMPIAppleMusicStorefrontsEndpoint,storefrontCode].lowercaseString;
    MPI_ASSERT_COMPONENTS_URL;
    return [self authorizedRequestForURL:components.URL timeoutInterval:10 withDeveloperToken:devToken andUserToken:nil];
}

+ (NSURLRequest *)createGetMultipleStorefrontsRequestWithRegionCodes:(NSArray<NSString *> *)regionCodes developerToken:(NSString *)devToken
{
    MPI_ASSERT_DEVELOPER_TOKEN;
    NSAssert(regionCodes.count > 0, @"regionCodes is empty or nil");
    NSURLComponents *components = self.components;
    components.path = [NSString stringWithFormat:@"%@%@", kMPIAppleMusicApiVersion, kMPIAppleMusicStorefrontsEndpoint];
    components.queryItems = @[[NSURLQueryItem queryItemWithName:@"ids" value:[regionCodes componentsJoinedByString:@","].lowercaseString]];
    MPI_ASSERT_COMPONENTS_URL;
    return [self authorizedRequestForURL:components.URL timeoutInterval:5 withDeveloperToken:devToken andUserToken:nil];
}

+ (NSURLRequest *)createGetAllStorefrontsRequestsWithDeveloperToken:(NSString *)devToken
{
    return [self createGetStorefrontRequestForRegionCode:nil developerToken:devToken];
}

+ (NSURLRequest *)createGetUserStorefrontRequestWithDeveloperToken:(NSString *)devToken userToken:(NSString *)usrToken
{
    MPI_ASSERT_DEVELOPER_TOKEN;
    NSURLComponents *components = self.components;
    components.path = [NSString stringWithFormat:@"%@%@%@", kMPIAppleMusicApiVersion, kMPIAppleMusicMeEndpoint, kMPIAppleMusicStorefrontsEndpoint];
    MPI_ASSERT_COMPONENTS_URL;
    return [self authorizedRequestForURL:components.URL timeoutInterval:10 withDeveloperToken:devToken andUserToken:usrToken];
}


#pragma mark Album
+ (NSURLRequest *)createGetAlbumsRequestWithAlbumIDs:(NSArray<NSNumber *> *)ids
                                       forStorefront:(NSString *)storefront
                                        localization:(NSString *)localization
                                        includeTypes:(MPIAppleMusicResourceType)types
                                      developerToken:(NSString *)devToken
{
    MPI_ASSERT_DEVELOPER_TOKEN;
    NSAssert(ids.count > 0, @"No Album IDs");
    NSURLComponents *components = self.components;
    components.path = [NSString stringWithFormat:@"%@%@/%@%@", kMPIAppleMusicApiVersion, kMPIAppleMusicCatalogEndpoint, storefront, kMPIAppleMusicAlbumsEndpoint];
    NSMutableArray *queryItems = [[NSMutableArray alloc] init];
    [queryItems addObject:[NSURLQueryItem queryItemWithName:@"ids" value:[ids componentsJoinedByString:@","]]];
    if (localization) {
        [queryItems addObject:[NSURLQueryItem queryItemWithName:@"l" value:localization]];
    }
    if (types) {
        [queryItems addObject:[NSURLQueryItem queryItemWithName:@"include" value:[self resourcesStringFromResourceTypes:types]]];
    }
    components.queryItems = queryItems;
    MPI_ASSERT_COMPONENTS_URL;
    return [self authorizedRequestForURL:components.URL timeoutInterval:10 withDeveloperToken:devToken andUserToken:nil];
}

#pragma mark Recommendation
+ (NSURLRequest *)createGetRecommendationsRequestWithDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken
{
    MPI_ASSERT_USER_TOKEN;
    MPI_ASSERT_DEVELOPER_TOKEN;
    NSURLComponents *components = self.components;
    components.path = [NSString stringWithFormat:@"%@%@%@", kMPIAppleMusicApiVersion, kMPIAppleMusicMeEndpoint, kMPIAppleMusicRecommendationsEndpoint];
    MPI_ASSERT_COMPONENTS_URL;
    return [self authorizedRequestForURL:components.URL timeoutInterval:10 withDeveloperToken:devToken andUserToken:usrToken];
}

+ (NSURLRequest *)createGetAlbumRecommendationsRequestWithDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken
{
    return [self createGetRecommendationsRequestForSearchType:MPIAppleMusicResourceTypeAlbums withDeveloperToken:devToken andUserToken:usrToken];
}

+ (NSURLRequest *)createGetPlaylistRecommendationsRequestWithDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken
{
    return [self createGetRecommendationsRequestForSearchType:MPIAppleMusicResourceTypePlaylists withDeveloperToken:devToken andUserToken:usrToken];
}

+ (NSURLRequest *)createGetRecommendationsRequestForSearchType:(MPIAppleMusicResourceType)searchType withDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken
{
    MPI_ASSERT_USER_TOKEN;
    MPI_ASSERT_DEVELOPER_TOKEN;
    NSURLComponents *components = self.components;
    components.path = [NSString stringWithFormat:@"%@%@%@", kMPIAppleMusicApiVersion, kMPIAppleMusicMeEndpoint, kMPIAppleMusicRecommendationsEndpoint];
    NSString *type;
    switch (searchType) {
        case MPIAppleMusicResourceTypeAlbums:
            type = @"albums";
            break;
        case MPIAppleMusicResourceTypePlaylists:
            type = @"playlists";
            break;
        default:
            NSAssert(NO, @"Wrong type");
            break;
    }
    components.queryItems = @[[NSURLQueryItem queryItemWithName:@"type" value:type]];
    MPI_ASSERT_COMPONENTS_URL;
    return [self authorizedRequestForURL:components.URL timeoutInterval:10 withDeveloperToken:devToken andUserToken:usrToken];
}

#pragma mark Search
+ (NSURLRequest *)createSearchRequestWithPhrase:(NSString *)phrase
                                  forStorefront:(NSString *)storefront
                                   localization:(NSString *)localization
                                          limit:(NSNumber *)limit
                                         offset:(NSNumber *)offset
                                          types:(MPIAppleMusicResourceType)searchTypes
                                 developerToken:(NSString *)devToken
{
    MPI_ASSERT_DEVELOPER_TOKEN;
    NSURLComponents *components = self.components;
    components.path = [NSString stringWithFormat:@"%@%@/%@%@", kMPIAppleMusicApiVersion, kMPIAppleMusicCatalogEndpoint, storefront, kMPIAppleMusicSearchEndpoint];
    NSMutableArray *queryItems = [[NSMutableArray alloc] init];
    NSURLQueryItem *searchPhrase = [NSURLQueryItem queryItemWithName:@"term" value:phrase];
    [queryItems addObject:searchPhrase];
    if (localization) {
        [queryItems addObject:[NSURLQueryItem queryItemWithName:@"l" value:localization]];
    }
    if (limit) {
        if (limit.integerValue > 25) {
            limit = @25;
        }
        [queryItems addObject:[NSURLQueryItem queryItemWithName:@"limit" value:limit.stringValue]];
    }
    if (offset) {
        [queryItems addObject:[NSURLQueryItem queryItemWithName:@"offset" value:offset.stringValue]];
    }
    if (searchTypes) {
        NSString *searchTypeString = [self resourcesStringFromResourceTypes:searchTypes];
        if (searchTypeString) {
            [queryItems addObject:[NSURLQueryItem queryItemWithName:@"types" value:searchTypeString]];
        }
    }
    components.queryItems = queryItems;
    MPI_ASSERT_COMPONENTS_URL;
    return [self authorizedRequestForURL:components.URL timeoutInterval:15 withDeveloperToken:devToken andUserToken:nil];
}

#pragma mark – Priv
+ (NSURLComponents *)components
{
    NSURLComponents *components = [[NSURLComponents alloc] init];
    components.scheme = kMPIAppleMusicURLScheme;
    components.host = kMPIAppleMusicHost;
    return components;
}

+ (void)authorizeRequest:(NSMutableURLRequest *)request withDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken
{
    NSAssert(devToken.length > 0, @"Dev Token is nil or empty");
    [request addValue:[NSString stringWithFormat:@"Bearer %@", devToken] forHTTPHeaderField:@"Authorization"];
    if (usrToken.length > 0) {
        [request addValue:usrToken forHTTPHeaderField:kMPIAppleMusicUserTokenKey];
    }
}

+ (NSMutableURLRequest *)authorizedRequestForURL:(NSURL *)url timeoutInterval:(NSTimeInterval)interval withDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken
{
    return [self authorizedRequestForURL:url timeoutInterval:interval withDeveloperToken:devToken andUserToken:usrToken httpMethod:Get];
}

+ (NSMutableURLRequest *)authorizedRequestForURL:(NSURL *)url timeoutInterval:(NSTimeInterval)interval withDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken httpMethod:(HttpMethod)method
{
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url cachePolicy:NSURLRequestReloadIgnoringCacheData timeoutInterval:interval];
    [self authorizeRequest:request withDeveloperToken:devToken andUserToken:usrToken];
    if (method) {
        request.method = method;
    }
    NSLog(@"%@", request.curlCommand);
    return request;
}

+ (NSString *)resourcesStringFromResourceTypes:(MPIAppleMusicResourceType)types
{
    NSMutableArray *resourceTypesArray = [[NSMutableArray alloc] init];
    if ((types & MPIAppleMusicResourceTypeAlbums) != 0) {
        [resourceTypesArray addObject:@"albums"];
    }
    if ((types & MPIAppleMusicResourceTypeArtists) != 0) {
        [resourceTypesArray addObject:@"artists"];
    }
    if ((types & MPIAppleMusicResourceTypePlaylists) != 0) {
        [resourceTypesArray addObject:@"playlists"];
    }
    if ((types & MPIAppleMusicResourceTypeTracks) != 0) {
        [resourceTypesArray addObject:@"songs"];
    }
    if ((types & MPIAppleMusicResourceTypeMusicVideos) != 0) {
        [resourceTypesArray addObject:@"music-videos"];
    }
    if ((types & MPIAppleMusicResourceTypeGenres) != 0) {
        [resourceTypesArray addObject:@"genres"];
    }
    return [resourceTypesArray componentsJoinedByString:@","];
}

@end
