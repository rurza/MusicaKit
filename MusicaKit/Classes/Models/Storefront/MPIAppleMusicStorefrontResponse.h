//
//  MPIAppleMusicStorefrontResponse.h
//  JSONModel
//
//  Created by Adam Rozynski (micropixels) on 26/07/2017.
//

#import "MPIAppleMusicResponse.h"
#import "MPIAppleMusicStorefrontResource.h"

@interface MPIAppleMusicStorefrontResponse : MPIAppleMusicResponse

@property (nonatomic) NSArray<MPIAppleMusicStorefrontResource, Optional> *data;

@end
