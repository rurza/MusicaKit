//
//  MPIAppleMusicResource.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 25/07/2017.
//

#import <JSONModel/JSONModel.h>
#import "MPIAppleMusicRelationship.h"

/**
 A Resource object represents a resource—such as an album, song, or playlist—in the Apple Music catalog or iCloud Music Library.
 */
@interface MPIAppleMusicResource : JSONModel

/**
 Persistent identifier of the resource. This member is required.
 */
@property (nonatomic) NSString                                  *id;

/**
 Attributes belonging to the resource (can be a subset of the attributes). The members are the names of the attributes defined in the object model.
 */
@property (nonatomic) id<Optional>                              attributes;

/**
 Relationships belonging to the resource (can be a subset of the relationships). The members are the names of the relationships defined in the object model.
 */
@property (nonatomic) id<Optional>                              relationships;

/**
 A URL subpath that fetches the resource as the primary object. This member is only present in responses.
 */
@property (nonatomic) NSString                                  *href;

/**
 The type of resource. This member is required.
 */
@property (nonatomic) NSString                                  *type;

/**
 Information about the request or response. The members may be any of the endpoint parameters.
 */
@property (nonatomic) NSString<Optional>                        *meta;

@end
