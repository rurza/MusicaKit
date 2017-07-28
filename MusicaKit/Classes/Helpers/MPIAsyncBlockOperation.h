//
//  MPIAsyncBlockOperation.h
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 24/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MPIAsyncBlockOperation;
typedef void(^BlockOperation)(MPIAsyncBlockOperation *blockOperation);

@interface MPIAsyncBlockOperation : NSOperation
@property (nonatomic) BOOL operationDidFinish;

+ (instancetype)operationWithBlock:(BlockOperation)block;

@end
