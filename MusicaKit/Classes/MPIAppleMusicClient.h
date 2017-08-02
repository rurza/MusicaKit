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

typedef void(^NetworkRequestHandler)(NSError *error, id result);
typedef void(^AppleMusicStorefrontRequestHandler)(NSError *error, MPIAppleMusicStorefrontResponse *response);
typedef void(^AppleMusicAlbumsRequestHandler)(NSError *error, MPIAppleMusicAlbumResponse *response);


@interface MPIAppleMusicClient : NSObject

@property (nonatomic)           BOOL                automaticallyAddOperationsToQueue;
@property (nonatomic)           NSString            *developerToken;
@property (nonatomic)           NSString            *userToken;
@property (nonatomic, readonly) NSOperationQueue    *operationQueue;

+ (instancetype)sharedClient;
- (NSOperation *)getStorefrontForRegionWithCode:(NSString *)regionCode
                                    withHandler:(AppleMusicStorefrontRequestHandler)handler;


//Albums
- (NSOperation *)getAlbumsWithIDs:(NSArray<NSNumber *> *)ids forStorefront:(NSString *)storefront withHandler:(AppleMusicAlbumsRequestHandler)handler;

@end
