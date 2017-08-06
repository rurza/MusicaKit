//
//  MPIAppleMusicCuratorRelationships.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicPlaylistRelationship;

@interface MPIAppleMusicCuratorRelationships : JSONModel
@property (nonatomic) MPIAppleMusicPlaylistRelationship             *playlists;
@end
