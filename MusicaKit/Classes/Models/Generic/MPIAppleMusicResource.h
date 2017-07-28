//
//  MPIAppleMusicResource.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 25/07/2017.
//

#import <JSONModel/JSONModel.h>
#import "MPIAppleMusicRelationship.h"

@interface MPIAppleMusicResource : JSONModel

@property (nonatomic) NSString                                  *id;
@property (nonatomic) id<Optional>                              attributes;
@property (nonatomic) id<Optional>                              relationships;
@property (nonatomic) NSString                                  *href;
@property (nonatomic) NSString                                  *type;
@property (nonatomic) NSString<Optional>                        *meta;

@end
