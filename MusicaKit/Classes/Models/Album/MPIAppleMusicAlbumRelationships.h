//
//  MPIAppleMusicAlbumRelationships.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicArtistRelationship;
@class MPIAppleMusicTrackRelationship;

@interface MPIAppleMusicAlbumRelationships : JSONModel

@property (nonatomic) MPIAppleMusicArtistRelationship   *artists;
@property (nonatomic) MPIAppleMusicTrackRelationship    *tracks;

@end
