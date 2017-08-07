//
//  MPIAppleMusicGenreRelationship.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicRelationship.h"
#import "MPIAppleMusicGenreResource.h"

@interface MPIAppleMusicGenreRelationship : MPIAppleMusicRelationship
@property (nonatomic) NSArray<MPIAppleMusicGenreResource>                   *data;
@end
