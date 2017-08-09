//
//  MPIAppleMusicResourceType.h
//  MusicaKit
//
//  Created by rurza on 06/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#ifndef MPIAppleMusicResourceType_h
#define MPIAppleMusicResourceType_h

typedef NS_OPTIONS(NSInteger, MPIAppleMusicResourceType) {
    MPIAppleMusicResourceTypeAll = 0,
    MPIAppleMusicResourceTypeAlbums = 1 << 1,
    MPIAppleMusicResourceTypeArtists = 1 << 2,
    MPIAppleMusicResourceTypePlaylists = 1 << 3,
    MPIAppleMusicResourceTypeTracks = 1 << 4,
    MPIAppleMusicResourceTypeMusicVideos = 1 << 5,
    MPIAppleMusicResourceTypeGenres = 1 << 6
};

#endif /* MPIAppleMusicResourceType_h */
