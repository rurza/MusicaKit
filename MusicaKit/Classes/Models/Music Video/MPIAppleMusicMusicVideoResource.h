//
//  MPIAppleMusicMusicVideoResource.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
@class MPIAppleMusicMusicVideo;
@class MPIAppleMusicMusicVideoRelationships;

@protocol MPIAppleMusicMusicVideoResource;

@interface MPIAppleMusicMusicVideoResource : MPIAppleMusicResource
@property (nonatomic) MPIAppleMusicMusicVideo<Optional>                 *attributes;
@property (nonatomic) MPIAppleMusicMusicVideoRelationships<Optional>    *relationships;
@end
