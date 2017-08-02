//
//  MPIAppleMusicTrack.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicArtwork;
@class MPIAppleMusicEditorialNotes;
@class MPIAppleMusicPlayParameters;

/**
 represents a song
 */
@interface MPIAppleMusicTrack : JSONModel

/**
 The artist’s name.
 */
@property (nonatomic) NSString                                  *artistName;

/**
 The album artwork.
 */
@property (nonatomic) MPIAppleMusicArtwork                      *artwork;

/**
 (Optional) The song’s composer.
 */
@property (nonatomic) NSString<Optional>                        *composerName;

/**
 (Optional) The RIAA rating of the content. The possible values for this rating are clean and explicit. No value means no rating.
 */
@property (nonatomic) NSString<Optional>                        *contentRating;

/**
 The disc number the song appears on.
 */
@property (nonatomic) NSUInteger                                discNumber;

/**
 (Optional) The duration of the song in milliseconds.
 */
@property (nonatomic) NSNumber<Optional>                        *durationInMillis;

/**
 (Optional) The notes about the song that appear in the iTunes Store.
 */
@property (nonatomic) MPIAppleMusicEditorialNotes<Optional>     *editorialNotes;

/**
 The genre names the song is associated with.
 */
@property (nonatomic) NSArray                                   *genreNames;

/**
 The localized name of the song.
 */
@property (nonatomic) NSString                                  *name;

/**
 (Optional) The parameters to use to playback the song.
 */
@property (nonatomic) MPIAppleMusicPlayParameters<Optional>     *playParams;

/**
 The release date of the song
 */
@property (nonatomic) NSDate                                    *releaseDate;

/**
 The number of the song in the album’s track list.
 */
@property (nonatomic) NSUInteger                                trackNumber;

/**
 The URL for sharing a song in the iTunes Store.
 */
@property (nonatomic) NSURL                                     *url;

/**
 (Optional, classical music only) The name of the associated work.
 */
@property (nonatomic) NSString<Optional>                        *workName;

/**
 (Optional, classical music only) The movement count of this song.
 */
@property (nonatomic) NSNumber<Optional>                        *movementCount;

/**
 (Optional, classical music only) The movement name of this song.
 */
@property (nonatomic) NSString<Optional>                        *movementName;

/**
 (Optional, classical music only) The movement number of this song.
 */
@property (nonatomic) NSNumber<Optional>                        *movementNumber;

@end
