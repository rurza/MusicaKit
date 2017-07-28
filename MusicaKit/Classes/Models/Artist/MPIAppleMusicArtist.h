//
//  MPIAppleMusicArtist.h
//  MusicaKit
//
//  Created by rurza on 27/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicEditorialNotes;

/**
 represents an artist of an album where an artist can be one or more persons
 */
@interface MPIAppleMusicArtist : JSONModel

/**
 (Optional) The notes about the artist that appear in the iTunes Store.
 */
@property (nonatomic) MPIAppleMusicEditorialNotes<Optional>     *editorialNotes;

/**
 The names of the genres associated with this artist.
 */
@property (nonatomic) NSArray                                   *genreNames;

/**
 The localized name of the artist.
 */
@property (nonatomic) NSString                                  *name;

/**
 The URL for sharing an artist in the iTunes Store.
 */
@property (nonatomic) NSURL                                     *url;
@end
