//
//  MPIAppleMusicRecommendation.h
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface MPIAppleMusicRecommendation : JSONModel

/**
 Whether the recommendation is of group type.
 */
@property (nonatomic) BOOL                  isGroupRecommendation;

/**
 The localized title for the recommendation.
 */
@property (nonatomic) NSString              *title;

/**
 The localized reason for the recommendation.
 */
@property (nonatomic) NSString              *reason;

/**
 The resource types supported by the recommendation.
 */
@property (nonatomic) NSArray<NSString *>   *resourceTypes;

/**
 The date in UTC format when the recommendation is updated.
 */
@property (nonatomic) NSDate                *nextUpdateDate;

@end
