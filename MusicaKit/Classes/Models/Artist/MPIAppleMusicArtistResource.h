//
//  MPIAppleMusicArtistResource.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
@class MPIAppleMusicArtist;

@protocol MPIAppleMusicArtistResource;

@interface MPIAppleMusicArtistResource : MPIAppleMusicResource

@property (nonatomic) MPIAppleMusicArtist<Optional>       *attributes;

@end
