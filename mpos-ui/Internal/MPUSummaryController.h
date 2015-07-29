/*
 * mpos-ui : http://www.payworksmobile.com
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 payworks GmbH
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <mpos.core/mpos-extended.h>
#import "MPUAbstractController.h"

@protocol MPUSummaryDelegate

@required
- (void) summaryRefundClicked:(NSString *)transactionIdentifier;
- (void) summarySendReceiptClicked:(NSString *)transactionIdentifier;
- (void) summaryPrintReceiptClicked:(NSString *)transactionIdentifier;
- (void) summaryRetryClicked;
- (void) summaryCloseClicked;

@end

@interface MPUSummaryController : MPUAbstractController<UIAlertViewDelegate>

@property (nonatomic, strong) MPTransaction *transaction;
@property (nonatomic, strong) MPUTransactionParameters *parameters;
@property(nonatomic, retain) id<MPUSummaryDelegate> delegate;

@property (nonatomic, assign) BOOL retryEnabled;
@property (nonatomic, assign) BOOL refundEnabled;

- (void)updatePrintReceiptButtonText;
- (void)updateSendReceiptButtonText;

@end
