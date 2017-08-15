//
//  MPIAppleMusicRecommendationRelationships.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicRecommendationRelationship;
@class MPIAppleMusicAlbumRelationship;

@interface MPIAppleMusicRecommendationRelationships : JSONModel

/**
 could be album or playlist
 */
@property (nonatomic) id<Optional>                                              contents;
@property (nonatomic) MPIAppleMusicRecommendationRelationship<Optional>         *recommendations;

@end
