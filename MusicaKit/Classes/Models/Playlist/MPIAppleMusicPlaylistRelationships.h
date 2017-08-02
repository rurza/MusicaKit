//
//  MPIAppleMusicPlaylistRelationships.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicCuratorRelationship;
@class MPIAppleMusicTrackRelationship;

@interface MPIAppleMusicPlaylistRelationships : JSONModel
@property (nonatomic) MPIAppleMusicCuratorRelationship      *curator;
@property (nonatomic) MPIAppleMusicTrackRelationship        *tracks;
@end
