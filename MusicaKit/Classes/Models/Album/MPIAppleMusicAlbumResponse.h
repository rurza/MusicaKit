//
//  MPIAppleMusicAlbumResponse.h
//  MusicaKit
//
//  Created by rurza on 27/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResponse.h"
#import "MPIAppleMusicAlbumResource.h"

@interface MPIAppleMusicAlbumResponse : MPIAppleMusicResponse
@property (nonatomic) NSArray<MPIAppleMusicAlbumResource>   *data;
@end
