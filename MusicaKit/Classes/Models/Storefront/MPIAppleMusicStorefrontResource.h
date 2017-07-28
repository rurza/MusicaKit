//
//  MPIAppleMusicStorefrontResource.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 26/07/2017.
//

#import "MPIAppleMusicResource.h"
#import "MPIAppleMusicStorefront.h"

@protocol MPIAppleMusicStorefrontResource;

@interface MPIAppleMusicStorefrontResource : MPIAppleMusicResource

@property (nonatomic) MPIAppleMusicStorefront  *attributes;

@end
