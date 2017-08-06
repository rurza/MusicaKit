//
//  MPIAppleMusicRecommendationRelationships.m
//  MusicaKit
//
//  Created by rurza on 02/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicRecommendationRelationships.h"
#import "MPIAppleMusicPlaylistRelationship.h"
#import "MPIAppleMusicRecommendationRelationship.h"

@implementation MPIAppleMusicRecommendationRelationships

- (void)setContentsWithNSDictionary:(NSDictionary *)dictionary
{
    NSError *error;
    id result = [[MPIAppleMusicPlaylistRelationship alloc] initWithDictionary:dictionary error:&error];
    if (error) {
        result = [[MPIAppleMusicRecommendationRelationship alloc] initWithDictionary:dictionary error:nil];
    }
    self.contents = result;
}

@end
