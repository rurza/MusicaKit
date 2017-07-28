//
//  MPIAppleMusicEditorialNotes.m
//  MusicaKit
//
//  Created by rurza on 27/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicEditorialNotes.h"

@implementation MPIAppleMusicEditorialNotes

+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{@"shortDescription": @"short",
                                                                  @"standard":@"standard"
                                                                  }];
}

@end
