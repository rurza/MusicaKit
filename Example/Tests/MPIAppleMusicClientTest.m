//
//  MPIAppleMusicClientTest.m
//  MusicaKit_Tests
//
//  Created by Adam Rozynski (micropixels) on 26/07/2017.
//  Copyright © 2017 rurza. All rights reserved.
//

#import <XCTest/XCTest.h>
@import MusicaKit;

static NSString *const kDevKey = @"eyJhbGciOiJFUzI1NiIsInR5cCI6IkpXVCIsImtpZCI6IjMyNzlIOTY2QTYifQ.eyJpc3MiOiJGNTg3NzJHNjdKIiwiaWF0IjoxNTAwOTE4MjI3LCJleHAiOjE1MDM1MTAyMjd9.xeSwB_rzRXCOZLRqwIF0M6yoTXvOP8SnIl6pvc-x7CGAfaB3hTImeFk7Cw1-hVMll26VyshJsZmG3UTfPT8oIw";

@interface MPIAppleMusicClientTest : XCTestCase

@end

@implementation MPIAppleMusicClientTest

- (void)testGetStorefronts
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"GetStorefronts"];
    MPIAppleMusicClient *client = [MPIAppleMusicClient sharedClient];
    client.developerToken = kDevKey;
    [client getStorefrontForRegionWithCode:nil withHandler:^(NSError *error, MPIAppleMusicStorefrontResponse *response) {
        [expectation fulfill];
    }];
    [self waitForExpectations:@[expectation] timeout:15];
}

- (void)testGetAlbum
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"GetAlbum"];
    MPIAppleMusicClient *client = [MPIAppleMusicClient sharedClient];
    client.developerToken = kDevKey;
    [client getAlbumsWithIDs:@[@19842306] forStorefront:@"us" withHandler:^(NSError *error, MPIAppleMusicAlbumResponse *response) {
        [expectation fulfill];
    }];
    [self waitForExpectations:@[expectation] timeout:15];
}

@end
