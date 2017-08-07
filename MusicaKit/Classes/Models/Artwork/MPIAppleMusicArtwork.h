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
 (Optional) The average background color of the image.
 */
@property (nonatomic) NSString<Optional>          *bgColor;

/**
 (Optional) The primary text color that may be used if the background color is displayed.
 */
@property (nonatomic) NSString<Optional>          *textColor1;

/**
 (Optional) The secondary text color that may be used if the background color is displayed.
 */
@property (nonatomic) NSString<Optional>          *textColor2;

/**
 (Optional) The tertiary text color that may be used if the background color is displayed.
 */
@property (nonatomic) NSString<Optional>          *textColor3;

/**
 (Optional) The final post-tertiary text color that maybe be used if the background color is displayed.
 */
@property (nonatomic) NSString<Optional>          *textColor4;

/**
 The maximum width available for the image.
 */
@property (nonatomic) NSUInteger        width;

/**
 The maximum height available for the image.
 */
@property (nonatomic) NSUInteger        height;
@end
