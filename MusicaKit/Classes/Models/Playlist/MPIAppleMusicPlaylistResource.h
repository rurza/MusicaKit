//
//  MPIAppleMusicPlaylistResource.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
@class MPIAppleMusicPlaylist;
@class MPIAppleMusicPlaylistRelationships;

@protocol MPIAppleMusicPlaylistResource;

@interface MPIAppleMusicPlaylistResource : MPIAppleMusicResource

@property (nonatomic) MPIAppleMusicPlaylist<Optional>                       *attributes;
@property (nonatomic) MPIAppleMusicPlaylistRelationships<Optional>          *relationships;

@end
