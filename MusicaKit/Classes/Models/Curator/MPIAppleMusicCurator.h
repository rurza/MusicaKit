//
//  MPIAppleMusicCurator.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicArtwork;
@class MPIAppleMusicEditorialNotes;

/**
 object that represents a curator of resources
 */
@interface MPIAppleMusicCurator : JSONModel

/**
 The curator artwork.
 */
@property (nonatomic) MPIAppleMusicArtwork                      *artwork;

/**
 (Optional) The notes about the curator.
 */
@property (nonatomic) MPIAppleMusicEditorialNotes<Optional>     *editorialNotes;

/**
 The localized name of the curator.
 */
@property (nonatomic) NSString                                  *name;

/**
 The URL for sharing a curator in Apple Music.
 */
@property (nonatomic) NSURL                                     *url;

@end
