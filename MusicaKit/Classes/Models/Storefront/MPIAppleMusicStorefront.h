//
//  MPIAppleMusicStorefront.h
//  JSONModel
//
//  Created by Adam Rozynski (micropixels) on 26/07/2017.
//

#import <JSONModel/JSONModel.h>

@protocol MPIAppleMusicStorefront;

@interface MPIAppleMusicStorefront : JSONModel
@property (nonatomic) NSString              *name;
@property (nonatomic) NSString<Optional>    *storefrontId;
@property (nonatomic) NSString              *defaultLanguageTag;
@property (nonatomic) NSArray               *supportedLanguageTags;
@end
