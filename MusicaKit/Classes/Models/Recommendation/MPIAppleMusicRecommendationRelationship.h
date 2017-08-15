//
//  MPIAppleMusicRecommendationRelationship.h
//  MusicaKit
//
//  Created by rurza on 06/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
#import "MPIAppleMusicRecommendationResource.h"

@interface MPIAppleMusicRecommendationRelationship : JSONModel
@property (nonatomic) NSArray<MPIAppleMusicRecommendationResource *><MPIAppleMusicRecommendationResource>  *data;
@end
