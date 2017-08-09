//
//  MPIAppleMusicAlbumsRequestsTest.m
//  MusicaKit_Tests
//
//  Created by rurza on 09/08/2017.
//  Copyright © 2017 rurza. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DeveloperKey.h"
@import MusicaKit;

@interface MPIAppleMusicAlbumsRequestsTest : XCTestCase

@end

@implementation MPIAppleMusicAlbumsRequestsTest

- (void)testCreateGetAlbumsRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetAlbumsRequestWithAlbumIDs:@[@19842306] forStorefront:@"pl" localization:@"pl-pl" includeTypes:MPIAppleMusicResourceTypeGenres|MPIAppleMusicResourceTypeArtists developerToken:kDevToken];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
}

- (void)testCreateGetAlbumRequest
{
    NSURLRequest *request = [MPIAppleMusicRequestFactory createGetAlbumsRequestWithAlbumIDs:@[@19842306] forStorefront:@"pl" localization:nil includeTypes:MPIAppleMusicResourceTypeAll developerToken:kDevToken];
    XCTAssertNotNil(request);
    XCTAssertNotNil(request.URL);
}

@end
