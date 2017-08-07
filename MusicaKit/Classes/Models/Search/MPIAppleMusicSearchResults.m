//
//  MPIAppleMusicSearchResults.m
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicSearchResults.h"

@implementation MPIAppleMusicSearchResults

+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{@"albums":@"albums",
                                                                  @"musicVideos":@"music-videos",
                                                                  @"songs":@"songs",
                                                                  @"playlists":@"playlists",
                                                                  @"artists":@"artists"
                                                                  }];
}

@end
