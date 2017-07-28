//
//  MPIAppleMusicArtwork.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 27/07/2017.
//

#import <JSONModel/JSONModel.h>

@protocol MPIAppleMusicArtwork;

/**
 An object that represents an artwork.
 */
@interface MPIAppleMusicArtwork : JSONModel

/**
 The URL to request the image asset. The image file name must be preceded by {w}x{h}, as placeholders for the width and height values described above (for example, {w}x{h}bb.jpg).
 */
@property (nonatomic) NSString          *url;

/**
 The average background color of the image.
 */
@property (nonatomic) NSString          *bgColor;

/**
 The primary text color that may be used if the background color is displayed.
 */
@property (nonatomic) NSString          *textColor1;

/**
 The secondary text color that may be used if the background color is displayed.
 */
@property (nonatomic) NSString          *textColor2;

/**
 The tertiary text color that may be used if the background color is displayed.
 */
@property (nonatomic) NSString          *textColor3;

/**
 The final post-tertiary text color that maybe be used if the background color is displayed.
 */
@property (nonatomic) NSString          *textColor4;

/**
 The maximum width available for the image.
 */
@property (nonatomic) NSUInteger        width;

/**
 The maximum height available for the image.
 */
@property (nonatomic) NSUInteger        height;
@end
