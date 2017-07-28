//
//  MPIAppleMusicEditorialNotes.h
//  MusicaKit
//
//  Created by rurza on 27/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <JSONModel/JSONModel.h>

/**
 An object that represents notes.
 */
@interface MPIAppleMusicEditorialNotes : JSONModel

/**
 Notes shown when the content is being prominently displayed.
 */
@property (nonatomic) NSString      *standard;

/**
 Abbreviated notes shown in-line or when the content is shown alongside other content.
 */
@property (nonatomic) NSString      *shortDescription;
@end
