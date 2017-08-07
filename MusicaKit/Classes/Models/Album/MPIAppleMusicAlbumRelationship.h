//
//  MPIAppleMusicAlbumRelationship.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicRelationship.h"
#import "MPIAppleMusicAlbumResource.h"

@interface MPIAppleMusicAlbumRelationship : MPIAppleMusicRelationship

@property (nonatomic) NSArray<MPIAppleMusicAlbumResource>                         *data;

@end
