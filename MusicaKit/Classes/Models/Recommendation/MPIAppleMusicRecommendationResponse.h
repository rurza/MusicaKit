//
//  MPIAppleMusicRecommendationResponse.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResponse.h"
#import "MPIAppleMusicRecommendationResource.h"

@interface MPIAppleMusicRecommendationResponse : MPIAppleMusicResponse
@property (nonatomic) NSArray<MPIAppleMusicRecommendationResource>  *data;
@end
