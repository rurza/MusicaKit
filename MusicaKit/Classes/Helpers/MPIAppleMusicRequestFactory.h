//
//  MPIAppleMusicRequestFactory.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MPIAppleMusicResourceType.h"

@interface MPIAppleMusicRequestFactory : NSObject

#pragma mark Storefronts
+ (NSURLRequest *)createGetStorefrontRequestForRegionCode:(NSString *)regionCode developerToken:(NSString *)devToken;
+ (NSURLRequest *)createGetMultipleStorefrontsRequestWithRegionCodes:(NSArray<NSString *> *)regionCodes developerToken:(NSString *)devToken;
+ (NSURLRequest *)createGetUserStorefrontRequestWithDeveloperToken:(NSString *)devToken userToken:(NSString *)usrToken;
+ (NSURLRequest *)createGetAllStorefrontsRequestsWithDeveloperToken:(NSString *)devToken;

#pragma mark Albums
+ (NSURLRequest *)createGetAlbumsRequestWithAlbumIDs:(NSArray<NSNumber *> *)ids
                                       forStorefront:(NSString *)storefront
                                        localization:(NSString *)localization
                                        includeTypes:(MPIAppleMusicResourceType)types
                                      developerToken:(NSString *)devToken;


#pragma mark Search
+ (NSURLRequest *)createSearchRequestWithPhrase:(NSString *)phrase
                                  forStorefront:(NSString *)storefront
                                   localization:(NSString *)localization
                                          limit:(NSNumber *)limit
                                         offset:(NSNumber *)offset
                                          types:(MPIAppleMusicResourceType)searchTypes
                                 developerToken:(NSString *)devToken;

#pragma mark Recommendation
+ (NSURLRequest *)createGetRecommendationsRequestWithDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken;
+ (NSURLRequest *)createGetAlbumRecommendationsRequestWithDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken;
+ (NSURLRequest *)createGetPlaylistRecommendationsRequestWithDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken;

@end
