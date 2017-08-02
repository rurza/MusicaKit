//
//  MPIAppleMusicCuratorRelationship.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicRelationship.h"
#import "MPIAppleMusicCuratorResource.h"

@interface MPIAppleMusicCuratorRelationship : MPIAppleMusicRelationship
@property (nonatomic) NSArray<MPIAppleMusicCuratorResource>         *data;
@end
