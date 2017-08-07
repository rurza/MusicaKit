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

#import "MPIAppleMusicSearchType.h"


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

+ (instancetype)sharedClient;
- (NSOperation *)getStorefrontForRegionWithCode:(NSString *)regionCode
                                    withHandler:(AppleMusicStorefrontRequestHandler)handler;


//Albums
- (NSOperation *)getAlbumsWithIDs:(NSArray<NSNumber *> *)ids
                    forStorefront:(NSString *)storefront
                      withHandler:(AppleMusicAlbumsRequestHandler)handler;

- (NSOperation *)getAlbumWithID:(NSNumber *)storeId
                  forStorefront:(NSString *)storefront
                    withHandler:(AppleMusicAlbumsRequestHandler)handler;

//Recommendations

//Search
- (NSOperation *)search:(NSString *)phrase
           inStorefront:(NSString *)storefront
       withLocalization:(NSString *)localization
                  limit:(NSNumber *)limit
                 offset:(NSNumber *)offset
                  types:(MPIAppleMusicSearchType)types
             andHandler:(AppleMusicSearchRequestHandler)handler;

@end
