//
//  MPIAppleMusicTrackResource.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
@class MPIAppleMusicTrack;

@protocol MPIAppleMusicTrackResource;

@interface MPIAppleMusicTrackResource : MPIAppleMusicResource
@property (nonatomic) MPIAppleMusicTrack<Optional>        *attributes;
@end
