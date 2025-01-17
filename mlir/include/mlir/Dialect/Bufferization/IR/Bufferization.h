//===- Bufferization.h - Bufferization dialect ------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_DIALECT_BUFFERIZATION_IR_BUFFERIZATION_H_
#define MLIR_DIALECT_BUFFERIZATION_IR_BUFFERIZATION_H_

#include "mlir/Dialect/Bufferization/IR/AllocationOpInterface.h"
#include "mlir/Dialect/Bufferization/IR/BufferizableOpInterface.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"

//===----------------------------------------------------------------------===//
// Bufferization Dialect
//===----------------------------------------------------------------------===//

#include "mlir/Dialect/Bufferization/IR/BufferizationOpsDialect.h.inc"

namespace mlir {
class RewritePatternSet;
class MLIRContext;

namespace bufferization {
/// Populate patterns for folding to_memref and to_tensor ops.
/// Note: to_memref(to_tensor(x)) without type changes are handled by a folder.
void populateBufferizationOpFoldingPatterns(RewritePatternSet &patterns,
                                            MLIRContext *context);
} // namespace bufferization
} // namespace mlir

//===----------------------------------------------------------------------===//
// Bufferization Dialect Operations
//===----------------------------------------------------------------------===//

#define GET_OP_CLASSES
#include "mlir/Dialect/Bufferization/IR/BufferizationOps.h.inc"

#endif // MLIR_DIALECT_BUFFERIZATION_IR_BUFFERIZATION_H_
