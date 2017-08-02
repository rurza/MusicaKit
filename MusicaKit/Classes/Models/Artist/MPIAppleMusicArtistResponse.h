//
//  MPIAppleMusicArtistResponse.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResponse.h"
#import "MPIAppleMusicArtistResource.h"

@interface MPIAppleMusicArtistResponse : MPIAppleMusicResponse
@property (nonatomic) NSArray<MPIAppleMusicArtistResource>      *data;
@end
