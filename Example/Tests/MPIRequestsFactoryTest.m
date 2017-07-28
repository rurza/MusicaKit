//
//  MPIRequestsFactoryTest.m
//  MusicaKit_Tests
//
//  Created by Adam Rozynski (micropixels) on 23/07/2017.
//  Copyright © 2017 rurza. All rights reserved.
//

#import <XCTest/XCTest.h>
@import MusicaKit;

@interface MPIRequestsFactoryTest : XCTestCase

@end

@implementation MPIRequestsFactoryTest

- (void)testCreateStorefrontRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetStorefrontRequestForRegionCode:@"PL" developerToken:@"eyJhbGciOiJFUzI1NiIsInR5cCI6IkpXVCIsImtpZCI6IjMyNzlIOTY2QTYifQ.eyJpc3MiOiJGNTg3NzJHNjdKIiwiaWF0IjoxNTAwOTE4MjI3LCJleHAiOjE1MDM1MTAyMjd9.xeSwB_rzRXCOZLRqwIF0M6yoTXvOP8SnIl6pvc-x7CGAfaB3hTImeFk7Cw1-hVMll26VyshJsZmG3UTfPT8oIw"];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
    NSDictionary *headers = request.allHTTPHeaderFields;
    XCTAssertNotNil([headers objectForKey:@"Authorization"]);
}

- (void)testCreateGetAllStorefrontsRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetAllStorefrontsRequestsWithDeveloperToken:@"eyJhbGciOiJFUzI1NiIsInR5cCI6IkpXVCIsImtpZCI6IjMyNzlIOTY2QTYifQ.eyJpc3MiOiJGNTg3NzJHNjdKIiwiaWF0IjoxNTAwOTE4MjI3LCJleHAiOjE1MDM1MTAyMjd9.xeSwB_rzRXCOZLRqwIF0M6yoTXvOP8SnIl6pvc-x7CGAfaB3hTImeFk7Cw1-hVMll26VyshJsZmG3UTfPT8oIw"];
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


@end
