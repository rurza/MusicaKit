//
//  MPIAppleMusicPlayParameters.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 27/07/2017.
//

#import <JSONModel/JSONModel.h>

@protocol MPIAppleMusicPlayParameters;

/**
 An object that represents play parameters for resources.
 */
@interface MPIAppleMusicPlayParameters : JSONModel

/**
 The ID of the content to use for playback.
 */
@property (nonatomic) NSString  *id;

/**
 The kind of the content to use for playback.
 */
@property (nonatomic) NSString  *kind;

@end
