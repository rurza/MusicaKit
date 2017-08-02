//
//  MPIAppleMusicPlaylistResponse.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResponse.h"
#import "MPIAppleMusicPlaylistResource.h"

@interface MPIAppleMusicPlaylistResponse : MPIAppleMusicResponse
@property (nonatomic) NSArray<MPIAppleMusicPlaylistResource>        *data;
@end
