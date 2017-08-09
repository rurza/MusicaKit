#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MPIAppleMusicClient.h"
#import "MPIAppleMusicRequestFactory.h"

#import "MPIAppleMusicAlbumResponse.h"
#import "MPIAppleMusicArtistResponse.h"
#import "MPIAppleMusicCuratorResponse.h"
#import "MPIAppleMusicPlaylistResponse.h"
#import "MPIAppleMusicRecommendationResponse.h"
#import "MPIAppleMusicStorefrontResponse.h"
#import "MPIAppleMusicTrackResponse.h"
#import "MPIAppleMusicMusicVideoResponse.h"
#import "MPIAppleMusicSearchResponse.h"

#import "MPIAppleMusicArtist.h"
#import "MPIAppleMusicAlbum.h"
#import "MPIAppleMusicArtwork.h"
#import "MPIAppleMusicCurator.h"
#import "MPIAppleMusicEditorialNotes.h"
#import "MPIAppleMusicGenre.h"
#import "MPIAppleMusicPlayParameters.h"
#import "MPIAppleMusicPlaylist.h"
#import "MPIAppleMusicRecommendation.h"
#import "MPIAppleMusicStorefront.h"
#import "MPIAppleMusicTrack.h"
#import "MPIAppleMusicMusicVideo.h"

#import "MPIAppleMusicArtistRelationship.h"
#import "MPIAppleMusicCuratorRelationship.h"
#import "MPIAppleMusicPlaylistRelationship.h"
#import "MPIAppleMusicRecommendationRelationship.h"
#import "MPIAppleMusicTrackRelationship.h"
#import "MPIAppleMusicAlbumRelationship.h"
#import "MPIAppleMusicGenreRelationship.h"

#import "MPIAppleMusicAlbumRelationships.h"
#import "MPIAppleMusicCuratorRelationships.h"
#import "MPIAppleMusicMusicVideoRelationships.h"
#import "MPIAppleMusicPlaylistRelationships.h"

#import "MPIAppleMusicSearchResults.h"


FOUNDATION_EXPORT double MusicaKitVersionNumber;
FOUNDATION_EXPORT const unsigned char MusicaKitVersionString[];
