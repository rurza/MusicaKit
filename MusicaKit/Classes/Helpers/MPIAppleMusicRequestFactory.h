//
//  MPIAppleMusicRequestFactory.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPIAppleMusicRequestFactory : NSObject

+ (NSURLRequest *)createGetAllStorefrontsRequestsWithDeveloperToken:(NSString *)devToken;
+ (NSURLRequest *)createGetStorefrontRequestForRegionCode:(NSString *)regionCode developerToken:(NSString *)devToken;
+ (NSURLRequest *)createGetUserStorefrontRequestWithUserToken:(NSString *)usrToken developerToken:(NSString *)devToken;

//Albums
+ (NSURLRequest *)createGetAlbumsRequestWithAlbumIDs:(NSArray<NSNumber *> *)ids forStorefront:(NSString *)storefront developerToken:(NSString *)devToken;
+ (NSURLRequest *)createGetAlbumRequestWithAlbumID:(NSNumber *)id forStorefront:(NSString *)storefront developerToken:(NSString *)devToken;
@end
