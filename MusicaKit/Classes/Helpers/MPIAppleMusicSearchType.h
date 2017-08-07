//
//  MPIAppleMusicSearchType.h
//  MusicaKit
//
//  Created by rurza on 06/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#ifndef MPIAppleMusicSearchType_h
#define MPIAppleMusicSearchType_h

typedef NS_OPTIONS(NSInteger, MPIAppleMusicSearchType) {
    MPIAppleMusicSearchTypeAll = 0,
    MPIAppleMusicSearchTypeAlbums = 1 << 1,
    MPIAppleMusicSearchTypeArtists = 1 << 2,
    MPIAppleMusicSearchTypePlaylists = 1 << 3,
    MPIAppleMusicSearchTypeTracks = 1 << 4,
    MPIAppleMusicSearchTypeMusicVideos = 1 << 5
};

#endif /* MPIAppleMusicSearchType_h */
