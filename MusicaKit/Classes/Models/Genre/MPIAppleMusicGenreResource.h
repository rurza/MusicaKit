//
//  MPIAppleMusicGenreResource.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
@class MPIAppleMusicGenre;

@protocol MPIAppleMusicGenreResource;

@interface MPIAppleMusicGenreResource : MPIAppleMusicResource
@property (nonatomic) MPIAppleMusicGenre<Optional>        *attributes;
@end
