//
//  MPIAppleMusicCuratorResource.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
#import "MPIAppleMusicCurator.h"

@protocol MPIAppleMusicCuratorResource;

@interface MPIAppleMusicCuratorResource : MPIAppleMusicResource
@property (nonatomic) MPIAppleMusicCurator      *attributes;

@end
