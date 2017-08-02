//
//  MPIAppleMusicPlaylistResource.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
#import "MPIAppleMusicPlaylist.h"
#import "MPIAppleMusicPlaylistRelationships.h"

@protocol MPIAppleMusicPlaylistResource;

@interface MPIAppleMusicPlaylistResource : MPIAppleMusicResource

@property (nonatomic) MPIAppleMusicPlaylist                     *attributes;
@property (nonatomic) MPIAppleMusicPlaylistRelationships        *relationships;

@end
