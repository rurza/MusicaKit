//
//  MPIAppleMusicRequestFactory.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MPIAppleMusicSearchType.h"

@interface MPIAppleMusicRequestFactory : NSObject

//Storefront
+ (NSURLRequest *)createGetAllStorefrontsRequestsWithDeveloperToken:(NSString *)devToken;
+ (NSURLRequest *)createGetStorefrontRequestForRegionCode:(NSString *)regionCode developerToken:(NSString *)devToken;
+ (NSURLRequest *)createGetUserStorefrontRequestWithUserToken:(NSString *)usrToken developerToken:(NSString *)devToken;

//Albums
+ (NSURLRequest *)createGetAlbumsRequestWithAlbumIDs:(NSArray<NSNumber *> *)ids forStorefront:(NSString *)storefront developerToken:(NSString *)devToken;
+ (NSURLRequest *)createGetAlbumRequestWithAlbumID:(NSNumber *)id forStorefront:(NSString *)storefront developerToken:(NSString *)devToken;

#pragma mark Search
+ (NSURLRequest *)createSearchRequestWithPhrase:(NSString *)phrase
                                  forStorefront:(NSString *)storefront
                                   localization:(NSString *)localization
                                          limit:(NSNumber *)limit
                                         offset:(NSNumber *)offset
                                          types:(MPIAppleMusicSearchType)searchTypes
                                 developerToken:(NSString *)devToken;

#pragma mark Recommendation
+ (NSURLRequest *)createGetRecommendationsRequestWithDeveloperToken:(NSString *)devToken andUserToken:(NSString *)usrToken;
@end
