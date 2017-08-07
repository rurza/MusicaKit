//
//  MPIAppleMusicMusicVideoResponse.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResponse.h"
#import "MPIAppleMusicMusicVideoResource.h"

@interface MPIAppleMusicMusicVideoResponse : MPIAppleMusicResponse
@property (nonatomic) NSArray<MPIAppleMusicMusicVideoResource>      *data;
@end
