//
//  MPIAppleMusicTrackResponse.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResponse.h"
#import "MPIAppleMusicTrackResource.h"

@interface MPIAppleMusicTrackResponse : MPIAppleMusicResponse
@property (nonatomic) NSArray<MPIAppleMusicTrackResource>       *data;
@end
