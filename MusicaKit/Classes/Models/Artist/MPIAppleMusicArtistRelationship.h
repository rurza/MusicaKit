//
//  MPIAppleMusicArtistRelationship.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicRelationship.h"
#import "MPIAppleMusicArtistResource.h"

@interface MPIAppleMusicArtistRelationship : MPIAppleMusicRelationship

@property (nonatomic) NSArray<MPIAppleMusicArtistResource>                   *data;

@end
