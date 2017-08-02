//
//  MPIAppleMusicCuratorResponse.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResponse.h"
#import "MPIAppleMusicCuratorResource.h"

@interface MPIAppleMusicCuratorResponse : MPIAppleMusicResponse
@property (nonatomic) NSArray<MPIAppleMusicCuratorResource>                  *data;
@end
