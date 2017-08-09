//
//  MPIAppleMusicRecommendationsRequestsTest.m
//  MusicaKit_Tests
//
//  Created by rurza on 09/08/2017.
//  Copyright © 2017 rurza. All rights reserved.
//

#import <XCTest/XCTest.h>
@import MusicaKit;
#import "DeveloperKey.h"

@interface MPIAppleMusicRecommendationsRequestsTest : XCTestCase

@end

@implementation MPIAppleMusicRecommendationsRequestsTest

- (void)testCreateGetRecommendationsRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetRecommendationsRequestWithDeveloperToken:kDevToken andUserToken:@"123"];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
    XCTAssertNotNil([headers objectForKey:@"Music-User-Token"]);
}

- (void)testCreateGetAlbumsRecommendationsRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetAlbumRecommendationsRequestWithDeveloperToken:kDevToken andUserToken:@"123"];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
    XCTAssertNotNil([headers objectForKey:@"Music-User-Token"]);
}

- (void)testCreateGetPlaylistsRecommendationsRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetPlaylistRecommendationsRequestWithDeveloperToken:kDevToken andUserToken:@"123"];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
    XCTAssertNotNil([headers objectForKey:@"Music-User-Token"]);
}

@end
