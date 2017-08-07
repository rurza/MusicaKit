//
//  MPIAppleMusicSearchResponse.h
//  MusicaKit
//
//  Created by rurza on 07/08/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAppleMusicResponse.h"
@class MPIAppleMusicSearchResults;

@interface MPIAppleMusicSearchResponse : MPIAppleMusicResponse

@property (nonatomic) MPIAppleMusicSearchResults<Optional>                *results;

@end
