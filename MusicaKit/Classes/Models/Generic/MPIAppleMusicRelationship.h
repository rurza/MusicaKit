//
//  MPIAppleMusicRelationship.h
//  MusicaKit
//
//  Created by rurza on 27/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>

/**
 A Relationship object represents a to-one or to-many relationship from one resource object to others. A to-one relationship contains a single object in the data array.
 The rules that apply to the members of this object are:
 Must contain one of these members: href, data, or meta.
 If a to-many relationship, may contain the next member.
 */
@interface MPIAppleMusicRelationship : JSONModel

/**
 One or more destination objects.
 */
@property (nonatomic) NSArray<Optional>                         *data;

/**
 Information about the request or response. The members may be any of the endpoint parameters.
 */
@property (nonatomic) NSDictionary<Optional>                    *meta;

/**
 Link to the next page of resources in the relationship. Contains the offset query parameter that specifies the next page.
 */
@property (nonatomic) NSURL<Optional>                           *next;
/**
 A URL subpath that fetches the resource as the primary object. This member is only present in responses.
 */
@property (nonatomic) NSString<Optional>                        *href;

@end
