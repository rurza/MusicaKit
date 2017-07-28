//
//  MPIAppleMusicTrack.h
//  MusicaKit
//
//  Created by rurza on 28/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicArtwork;

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

#warning to do Composer object
/**
 (Optional) The song’s composer.
 */
@property (nonatomic) id<Optional>                                        composerName;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;
@property (nonatomic) id ;

@end
