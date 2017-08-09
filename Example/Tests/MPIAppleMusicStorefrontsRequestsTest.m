//
//  MPIAppleMusicStorefrontsRequestsTest.m
//  MusicaKit_Tests
//
//  Created by rurza on 09/08/2017.
//  Copyright © 2017 rurza. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DeveloperKey.h"
@import MusicaKit;

@interface MPIAppleMusicStorefrontsRequestsTest : XCTestCase

@end

@implementation MPIAppleMusicStorefrontsRequestsTest


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
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetUserStorefrontRequestWithDeveloperToken:@"123" userToken:@"aro"];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
    XCTAssertNotNil([headers objectForKey:@"Music-User-Token"]);
}

- (void)testCreateGetMultipleStorefrontsRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetMultipleStorefrontsRequestWithRegionCodes:@[@"PL", @"US"] developerToken:kDevToken];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
}
@end
