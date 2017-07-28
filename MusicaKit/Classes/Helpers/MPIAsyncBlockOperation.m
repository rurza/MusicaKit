//
//  MPIAsyncBlockOperation.m
//  MusicaKit
//
//  Created by Adam Rozynski (micropixels) on 24/07/2017.
//  Copyright © 2017 micropixels. All rights reserved.
//

#import "MPIAsyncBlockOperation.h"


@interface MPIAsyncBlockOperation ()
@property (nonatomic, copy) BlockOperation  block;
@property (nonatomic) BOOL                  isFinished;
@property (nonatomic) BOOL                  isExecuting;
@end

@implementation MPIAsyncBlockOperation

+ (instancetype)operationWithBlock:(BlockOperation)block
{
    MPIAsyncBlockOperation *operation = [[MPIAsyncBlockOperation alloc] init];
    operation.block = block;
    return operation;
}

- (void)start
{
    self.isExecuting = YES;
    if (self.block) {
        self.block(self);
    } else {
        self.operationDidFinish = YES;
    }
}

- (void)setOperationDidFinish:(BOOL)operationDidFinish
{
    _operationDidFinish = operationDidFinish;
    self.isExecuting = !operationDidFinish;
    self.isFinished = operationDidFinish;
}


- (void)setIsFinished:(BOOL)isFinished
{
    [self willChangeValueForKey:@"isFinished"];
    _isFinished = isFinished;
    [self didChangeValueForKey:@"isFinished"];
}

- (void)setIsExecuting:(BOOL)isExecuting
{
    [self willChangeValueForKey:@"isExecuting"];
    _isExecuting = isExecuting;
    [self didChangeValueForKey:@"isExecuting"];
}

@end
