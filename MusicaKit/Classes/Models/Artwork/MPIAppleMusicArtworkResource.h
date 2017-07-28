//
//  MPIAppleMusicArtworkResource.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 27/07/2017.
//

#import "MPIAppleMusicResource.h"
#import "MPIAppleMusicArtwork.h"

@protocol MPIAppleMusicArtworkResource;
/**
 An object that represents an artwork.
 */
@interface MPIAppleMusicArtworkResource : MPIAppleMusicResource
@property (nonatomic) MPIAppleMusicArtwork  *attributes;
@end
