//
//  MPIAppleMusicMusicVideoRelationships.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicAlbumRelationship;
@class MPIAppleMusicArtistRelationship;
@class MPIAppleMusicGenreRelationship;

@interface MPIAppleMusicMusicVideoRelationships : JSONModel

@property (nonatomic) MPIAppleMusicAlbumRelationship<Optional>      *albums;
@property (nonatomic) MPIAppleMusicArtistRelationship<Optional>     *artists;
@property (nonatomic) MPIAppleMusicGenreRelationship<Optional>      *genres;

@end
