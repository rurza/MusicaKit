//
//  MPIAppleMusicRecommendationResource.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResource.h"
#import "MPIAppleMusicRecommendation.h"
#import "MPIAppleMusicRecommendationRelationships.h"

@protocol MPIAppleMusicRecommendationResource;

@interface MPIAppleMusicRecommendationResource : MPIAppleMusicResource

@property (nonatomic) MPIAppleMusicRecommendation                   *attributes;
@property (nonatomic) MPIAppleMusicRecommendationRelationships      *relationships;

@end
