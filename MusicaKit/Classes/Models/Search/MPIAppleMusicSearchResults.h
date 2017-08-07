//
//  MPIAppleMusicSearchResults.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicAlbumResponse;
@class MPIAppleMusicArtistResponse;
@class MPIAppleMusicTrackResponse;
@class MPIAppleMusicPlaylistResponse;
@class MPIAppleMusicMusicVideoResponse;

@interface MPIAppleMusicSearchResults : JSONModel

@property (nonatomic) MPIAppleMusicAlbumResponse<Optional>              *albums;
@property (nonatomic) MPIAppleMusicArtistResponse<Optional>             *artists;
@property (nonatomic) MPIAppleMusicTrackResponse<Optional>              *songs;
@property (nonatomic) MPIAppleMusicPlaylistResponse<Optional>           *playlists;
@property (nonatomic) MPIAppleMusicMusicVideoResponse<Optional>         *musicVideos;

@end
