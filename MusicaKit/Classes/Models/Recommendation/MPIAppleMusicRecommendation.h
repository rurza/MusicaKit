//
//  MPIAppleMusicRecommendation.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>
@class MPIAppleMusicRecommendationTitle;

/**
 Object that represents recommended resources for a user calculated using their selected preferences.
 */
@interface MPIAppleMusicRecommendation : JSONModel

/**
 Whether the recommendation is of group type.
 */
@property (nonatomic) BOOL                                          isGroupRecommendation;

/**
 The localized title for the recommendation.
 */
@property (nonatomic) MPIAppleMusicRecommendationTitle<Optional>    *title;

/**
 The localized reason for the recommendation.
 */
@property (nonatomic) NSDictionary<Optional>                        *reason;

/**
 The resource types supported by the recommendation.
 */
@property (nonatomic) NSArray<NSString *>                           *resourceTypes;

/**
 The date in UTC format when the recommendation is updated.
 */
@property (nonatomic) NSDate                                        *nextUpdateDate;

@end
