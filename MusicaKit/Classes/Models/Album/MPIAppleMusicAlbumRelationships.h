//
//  MPIAppleMusicAlbumRelationships.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicArtistRelationship;

@interface MPIAppleMusicAlbumRelationships : JSONModel

@property (nonatomic) MPIAppleMusicArtistRelationship   *artists;

@end
