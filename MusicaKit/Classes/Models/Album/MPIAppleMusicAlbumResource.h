//
//  MPIAppleMusicAlbumResource.h
//  MusicaKit
//
//  Created by rurza on 27/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
//#import "MPIAppleMusicAlbum.h"
//#import "MPIAppleMusicAlbumRelationships.h"
@class MPIAppleMusicAlbum;
@class MPIAppleMusicAlbumRelationships;

@protocol MPIAppleMusicAlbumResource;

@interface MPIAppleMusicAlbumResource : MPIAppleMusicResource

@property (nonatomic) MPIAppleMusicAlbum<Optional>                      *attributes;
@property (nonatomic) MPIAppleMusicAlbumRelationships<Optional>         *relationships;

@end
