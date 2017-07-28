//
//  MPIAppleMusicAlbum.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 27/07/2017.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicArtwork;
@class MPIAppleMusicPlayParameters;
@class MPIAppleMusicEditorialNotes;


@interface MPIAppleMusicAlbum : JSONModel

/**
 Indicates whether the album is complete. If true, the album is complete; otherwise, it is not. An album is complete if it contains all its tracks and songs.
 */
@property (nonatomic) BOOL                                      isComplete;

/**
 Indicates whether the album contains a single song.
 */
@property (nonatomic) BOOL                                      isSingle;

/**
 The number of tracks.
 */
@property (nonatomic) NSUInteger                                trackCount;

/**
 The artist’s name.
 */
@property (nonatomic) NSString                                  *artistName;

/**
 (Optional) The RIAA rating of the content. The possible values for this rating are clean and explicit. No value means no rating.
 */
@property (nonatomic) NSString<Optional>                        *contentRating;

/**
 The copyright text.
 */
@property (nonatomic) NSString                                  *copyright;

/**
 The localized name of the album.
 */
@property (nonatomic) NSString                                  *name;

/**
 The URL for sharing an album in the iTunes Store.
 */
@property (nonatomic) NSString                                  *url;

/**
 The names of the genres associated with this album.
 */
@property (nonatomic) NSArray                                   *genreNames;

/**
 The release date of the album in YYYY-MM-DD format.
 */
@property (nonatomic) NSDate                                    *releaseDate;

/**
 The album artwork.
 */
@property (nonatomic) MPIAppleMusicArtwork                      *artwork;

/**
 (Optional) The parameters to use to playback the tracks of the album.
 */
@property (nonatomic) MPIAppleMusicPlayParameters<Optional>     *playParams;

/**
 (Optional) The notes about the album that appear in the iTunes Store.
 */
@property (nonatomic) MPIAppleMusicEditorialNotes<Optional>     *editorialNotes;

@end
