//
//  MPIAppleMusicError.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 26/07/2017.
//

#import <JSONModel/JSONModel.h>

@protocol MPIAppleMusicError;

@interface MPIAppleMusicError : JSONModel

@property (nonatomic) NSString                          *id;
@property (nonatomic) NSString                          *status;
@property (nonatomic) NSString                          *code;
@property (nonatomic) NSString                          *title;
@property (nonatomic) NSString                          *detail;
@property (nonatomic) NSDictionary<Optional>            *source;
@property (nonatomic) NSDictionary<Optional>            *meta;
@property (nonatomic) NSString<Optional>                *about;

@end
