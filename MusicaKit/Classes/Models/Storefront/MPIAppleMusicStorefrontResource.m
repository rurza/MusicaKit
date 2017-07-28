//
//  MPIAppleMusicStorefrontResource.m
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 26/07/2017.
//

#import "MPIAppleMusicStorefrontResource.h"

@implementation MPIAppleMusicStorefrontResource
@dynamic attributes;

- (NSString *)description
{
    return [NSString stringWithFormat:@"id: %@, name: %@", self.id, self.attributes.name];
}

@end
