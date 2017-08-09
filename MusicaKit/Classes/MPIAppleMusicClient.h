//
//  MPIAppleMusicClient.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

@import Foundation;

@class MPIAppleMusicStorefrontResponse;
@class MPIAppleMusicAlbumResponse;
@class MPIAppleMusicRecommendationResponse;
@class MPIAppleMusicSearchResponse;

#import "MPIAppleMusicResourceType.h"


typedef void(^NetworkRequestHandler)(NSError *error, id result);
typedef void(^AppleMusicStorefrontRequestHandler)(NSError *error, MPIAppleMusicStorefrontResponse *response);
typedef void(^AppleMusicAlbumsRequestHandler)(NSError *error, MPIAppleMusicAlbumResponse *response);
typedef void(^AppleMusicRecommendationsRequestHandler)(NSError *error, MPIAppleMusicRecommendationResponse *response);
typedef void(^AppleMusicSearchRequestHandler)(NSError *error, MPIAppleMusicSearchResponse *response);



@interface MPIAppleMusicClient : NSObject

@property (nonatomic)           BOOL                automaticallyAddOperationsToQueue;
@property (nonatomic)           NSString            *developerToken;
@property (nonatomic)           NSString            *userToken;
@property (nonatomic, readonly) NSOperationQueue    *operationQueue;
@property (nonatomic)           NSString            *storefront;
@property (nonatomic)           NSString            *localization;

+ (instancetype)sharedClient;


//Storefronts
- (NSOperation *)getStorefrontForRegionWithCode:(NSString *)regionCode
                                    withHandler:(AppleMusicStorefrontRequestHandler)handler;

- (NSOperation *)getStorefrontsForRegionCodes:(NSArray<NSString *> *)regionCodes
                                  withHandler:(AppleMusicStorefrontRequestHandler)handler;

- (NSOperation *)getUserStorefrontWithHandler:(AppleMusicStorefrontRequestHandler)handler;

- (NSOperation *)getAllStorefrontsWithHandler:(AppleMusicStorefrontRequestHandler)handler;


//Albums
- (NSOperation *)getAlbumsWithIDs:(NSArray<NSNumber *> *)ids
                    forStorefront:(NSString *)storefront
                     localization:(NSString *)localization
                     includeTypes:(MPIAppleMusicResourceType)types
                      withHandler:(AppleMusicAlbumsRequestHandler)handler;

- (NSOperation *)getAlbumWithID:(NSNumber *)albumId
                  forStorefront:(NSString *)storefront
                   localization:(NSString *)localization
                   includeTypes:(MPIAppleMusicResourceType)types
                    withHandler:(AppleMusicAlbumsRequestHandler)handler;

//Recommendations
- (NSOperation *)getRecommendationsWithHandler:(AppleMusicRecommendationsRequestHandler)handler;
- (NSOperation *)getAlbumRecommendationsWithHandler:(AppleMusicRecommendationsRequestHandler)handler;
- (NSOperation *)getPlaylistRecommendationsWithHandler:(AppleMusicRecommendationsRequestHandler)handler;

//Search
- (NSOperation *)search:(NSString *)phrase
           inStorefront:(NSString *)storefront
       withLocalization:(NSString *)localization
                  limit:(NSNumber *)limit
                 offset:(NSNumber *)offset
                  types:(MPIAppleMusicResourceType)types
             andHandler:(AppleMusicSearchRequestHandler)handler;

@end
