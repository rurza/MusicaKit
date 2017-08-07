//
//  MPIAppleMusicClient.m
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicClient.h"
#import "MPIAppleMusicRequestFactory.h"
#import "MPIAsyncBlockOperation.h"
#import "MPIAppleMusicStorefrontResponse.h"
#import "MPIAppleMusicAlbumResponse.h"
#import "MPIAppleMusicRecommendationResponse.h"
#import "MPIAppleMusicSearchResponse.h"

#define MPI_ASSERT_DEV_TOKEN NSAssert(self.developerToken.length > 0, @"Developer token must be set")
#define MPI_ASSERT_USR_TOKEN NSAssert(self.userToken.length > 0, @"User token must be set")
#define MPI_ASSERT_STOREFRONT NSAssert(storefront.length > 0, @"Storefront must be set")


@interface MPIAppleMusicClient ()
@property (nonatomic) NSOperationQueue  *operationQueue;
@property (nonatomic) NSURLSession      *session;
@end

@implementation MPIAppleMusicClient

#pragma mark – Public
+ (instancetype)sharedClient
{
    static MPIAppleMusicClient *client = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        client = [[MPIAppleMusicClient alloc] init];
    });
    return client;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.automaticallyAddOperationsToQueue = YES;
    }
    return self;
}

#pragma mark Storefronts
- (NSOperation *)getStorefrontForRegionWithCode:(NSString *)regionCode
                                    withHandler:(AppleMusicStorefrontRequestHandler)handler
{
    MPI_ASSERT_DEV_TOKEN;
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetStorefrontRequestForRegionCode:regionCode developerToken:self.developerToken];
    return [self _networkOperationWithRequest:request withHandler:^(NSError *error, id json) {
        if (handler) {
            if (error) {
                handler(error, nil);
            } else {
                MPIAppleMusicStorefrontResponse *response = [self _parsedJSON:json toModelForClass:[MPIAppleMusicStorefrontResponse class] withError:&error];
                handler(error, response);
            }
        }
    }];
}


#pragma mark Albums
- (NSOperation *)getAlbumsWithIDs:(NSArray<NSNumber *> *)ids forStorefront:(NSString *)storefront withHandler:(AppleMusicAlbumsRequestHandler)handler
{
    MPI_ASSERT_DEV_TOKEN;
    MPI_ASSERT_STOREFRONT;
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetAlbumsRequestWithAlbumIDs:ids forStorefront:storefront developerToken:self.developerToken];
    return [self _networkOperationWithRequest:request withHandler:^(NSError *error, id result) {
        if (handler) {
            if (error) {
                handler(error, nil);
            } else {
                MPIAppleMusicAlbumResponse *response = [self _parsedJSON:result toModelForClass:[MPIAppleMusicAlbumResponse class] withError:&error];
                handler(error, response);
            }
        }
    }];
}

- (NSOperation *)getAlbumWithID:(NSNumber *)storeId
                  forStorefront:(NSString *)storefront
                    withHandler:(AppleMusicAlbumsRequestHandler)handler
{
    return [self getAlbumsWithIDs:@[storeId] forStorefront:storefront withHandler:handler];
}

#pragma mark Search
- (NSOperation *)search:(NSString *)phrase
           inStorefront:(NSString *)storefront
       withLocalization:(NSString *)localization
                  limit:(NSNumber *)limit
                 offset:(NSNumber *)offset
                  types:(MPIAppleMusicSearchType)types
             andHandler:(AppleMusicSearchRequestHandler)handler
{
    MPI_ASSERT_DEV_TOKEN;
    NSAssert(phrase.length > 0, @"Empty or nil search phrase");
    NSURLRequest *request = [MPIAppleMusicRequestFactory createSearchRequestWithPhrase:phrase
                                                                         forStorefront:storefront
                                                                          localization:localization
                                                                                 limit:limit
                                                                                offset:offset
                                                                                 types:types
                                                                        developerToken:self.developerToken];
    
    return [self _networkOperationWithRequest:request withHandler:^(NSError *error, id result) {
        if (handler) {
            if (error) {
                handler(error, nil);
            } else {
                MPIAppleMusicSearchResponse *response = [self _parsedJSON:result toModelForClass:[MPIAppleMusicSearchResponse class] withError:&error];
                handler(error, response);
            }
        }
    }];
}


#pragma mark Recommendations
- (NSOperation *)getRecommendationsWithHandler:(AppleMusicRecommendationsRequestHandler)handler
{
    MPI_ASSERT_DEV_TOKEN;
    MPI_ASSERT_USR_TOKEN;
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetRecommendationsRequestWithDeveloperToken:self.developerToken andUserToken:self.userToken];
    return [self _networkOperationWithRequest:request withHandler:^(NSError *error, id result) {
        
    }];
}

#pragma mark – Private
- (NSOperation *)_networkOperationWithRequest:(NSURLRequest *)request
                                         withHandler:(NetworkRequestHandler)handler
{
    MPIAsyncBlockOperation *operation = [MPIAsyncBlockOperation operationWithBlock:^(MPIAsyncBlockOperation *blockOperation) {
        [self _performNetworkRequest:request withHandler:^(NSError *error, id result) {
            if (handler) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    handler(error, result);
                });
            }
            blockOperation.operationDidFinish = YES;
        }];
    }];
    if (self.automaticallyAddOperationsToQueue) {
        [self.operationQueue addOperation:operation];
    }
    return operation;
}

- (void)_performNetworkRequest:(NSURLRequest *)request
                   withHandler:(NetworkRequestHandler)handler
{
    [[self.session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        if (handler) {
            if (data) {
                NSError *jsonError;
                id json = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:&jsonError];
                handler(jsonError, json);
            } else if (error) {
                handler(error, nil);
            } else {
                NSAssert(TRUE, @"Not handled error");
            }
        } else {
            NSAssert(!handler, @"No handler!");
        }
    }] resume];
}

- (id)_parsedJSON:(id)json toModelForClass:(Class)class withError:(NSError * __autoreleasing *)error
{
    if ([json isKindOfClass:[NSDictionary class]]) {
        MPIAppleMusicResponse *result = [[class alloc] initWithDictionary:json error:error];
        return result;
    } else {
        return nil;
    }
}

#pragma mark Getters
- (NSOperationQueue *)operationQueue
{
    if (!_operationQueue) {
        _operationQueue = [[NSOperationQueue alloc] init];
    }
    return _operationQueue;
}

- (NSURLSession *)session
{
    if (!_session) {
        _session = [NSURLSession sharedSession];
    }
    return _session;
}

@end
