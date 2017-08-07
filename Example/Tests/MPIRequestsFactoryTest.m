//
//  MPIRequestsFactoryTest.m
//  MusicaKit_Tests
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 rurza. All rights reserved.
//

#import <XCTest/XCTest.h>
@import MusicaKit;

static NSString *const kDevToken = @"eyJhbGciOiJFUzI1NiIsInR5cCI6IkpXVCIsImtpZCI6IjMyNzlIOTY2QTYifQ.eyJpc3MiOiJGNTg3NzJHNjdKIiwiaWF0IjoxNTAwOTE4MjI3LCJleHAiOjE1MDM1MTAyMjd9.xeSwB_rzRXCOZLRqwIF0M6yoTXvOP8SnIl6pvc-x7CGAfaB3hTImeFk7Cw1-hVMll26VyshJsZmG3UTfPT8oIw";

@interface MPIRequestsFactoryTest : XCTestCase

@end

@implementation MPIRequestsFactoryTest

- (void)testCreateStorefrontRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetStorefrontRequestForRegionCode:@"PL" developerToken:kDevToken];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
}

- (void)testCreateGetAllStorefrontsRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetAllStorefrontsRequestsWithDeveloperToken:kDevToken];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
}

- (void)testCreateStorefrontForUserRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetUserStorefrontRequestWithUserToken:@"aro" developerToken:@"123"];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
    XCTAssertNotNil([headers objectForKey:@"Music-User-Token"]);
}

- (void)testCreateGetAlbumsRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetAlbumsRequestWithAlbumIDs:@[@19842306] forStorefront:@"us" developerToken:kDevToken];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
}

- (void)testCreateSearchForJamesBrown
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createSearchRequestWithPhrase:@"James Brown" forStorefront:@"us" localization:nil limit:@2 offset:nil types:MPIAppleMusicSearchTypeArtists|MPIAppleMusicSearchTypeAlbums developerToken:kDevToken];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
}

@end
