//
//  MPIAppleMusicMusicVideo.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicArtwork;
@class MPIAppleMusicEditorialNotes;
@class MPIAppleMusicPlayParameters;

/**
 object that represents a music video.
 */
@interface MPIAppleMusicMusicVideo : JSONModel

/**
 The artist’s name.
 */
@property (nonatomic) NSString                                      *artistName;

/**
 The artwork for the music video’s associated album.
 */
@property (nonatomic) MPIAppleMusicArtwork                          *artwork;

/**
 (Optional) The RIAA rating of the content. The possible values for this rating are clean and explicit. No value means no rating.
 */
@property (nonatomic) NSString<Optional>                            *contentRating;

/**
 (Optional) The duration of the music video in milliseconds.
 */
@property (nonatomic) NSNumber<Optional>                            *durationInMillis;

/**
 (Optional) The editorial notes for the music video.
 */
@property (nonatomic) MPIAppleMusicEditorialNotes<Optional>         *editorialNotes;

/**
 The music video’s associated genres.
 */
@property (nonatomic) NSArray                                       *genreNames;

/**
 The localized name of the music video.
 */
@property (nonatomic) NSString                                      *name;

/**
 (Optional) The parameters to use to playback the music video.
 */
@property (nonatomic) MPIAppleMusicPlayParameters<Optional>         *playParams;

/**
 The release date of the music video
 */
@property (nonatomic) NSDate                                        *releaseDate;

/**
 (Optional) The number of the music video in the album’s track list.
 */
@property (nonatomic) NSNumber<Optional>                            *trackNumber;

/**
 A clear url directly to the music video.
 */
@property (nonatomic) NSURL                                         *url;

/**
 (Optional) The video subtype associated with the content.
 */
@property (nonatomic) NSString<Optional>                            *videoSubType;
@end
