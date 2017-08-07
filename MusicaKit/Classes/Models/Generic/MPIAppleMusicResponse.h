//
//  MPIAppleMusicResponse.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 25/07/2017.
//

#import <JSONModel/JSONModel.h>
#import "MPIAppleMusicError.h"

@interface MPIAppleMusicResponse : JSONModel

@property (nonatomic) NSArray<Optional>                         *data;
@property (nonatomic) id<Optional>                              results;
@property (nonatomic) NSArray<Optional, MPIAppleMusicError>     *errors;
@property (nonatomic) NSDictionary<Optional>                    *meta;
@property (nonatomic) NSString<Optional>                        *next;
@property (nonatomic) NSString<Optional>                        *href;


@end
