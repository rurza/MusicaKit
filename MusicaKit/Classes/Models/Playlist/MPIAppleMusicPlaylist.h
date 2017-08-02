//
//  MPIAppleMusicPlaylist.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicArtwork;
@class MPIAppleMusicEditorialNotes;
@class MPIAppleMusicPlayParameters;

/**
 object that represents a playlist.
 */
@interface MPIAppleMusicPlaylist : JSONModel

/**
 (Optional) The playlist artwork.
 */
@property (nonatomic) MPIAppleMusicArtwork<Optional>                *artwork;

/**
 (Optional) The display name of the curator.
 */
@property (nonatomic) NSString<Optional>                            *curatorName;

/**
 (Optional) A description of the playlist.
 */
@property (nonatomic) MPIAppleMusicEditorialNotes<Optional>         *description;

/**
 The date the playlist was last modified.
 */
@property (nonatomic) NSDate                                        *lastModifiedDate;

/**
 The localized name of the playlist.
 */
@property (nonatomic) NSString                                      *name;
/**
 (Optional) The parameters to use to playback the tracks in the playlist.
 */
@property (nonatomic) MPIAppleMusicPlayParameters<Optional>         *playParams;

/**
 The URL for sharing an album in the iTunes Store.
 */
@property (nonatomic) NSURL                                         *url;

/**
 The type of playlist.
 */
@property (nonatomic) NSString                                      *playlistType;

@end
