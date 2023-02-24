#pragma once

// @generated by torchgen/gen.py from Function.h

#include <ATen/Context.h>
#include <ATen/DeviceGuard.h>
#include <ATen/TensorUtils.h>
#include <ATen/TracerMode.h>
#include <ATen/core/Generator.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>



#include <ATen/ops/trace_ops.h>

namespace at {


// aten::trace(Tensor self) -> Tensor
inline at::Tensor trace(const at::Tensor & self) {
    return at::_ops::trace::call(self);
}

// aten::trace.out(Tensor self, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & trace_out(at::Tensor & out, const at::Tensor & self) {
    return at::_ops::trace_out::call(self, out);
}

// aten::trace.out(Tensor self, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & trace_outf(const at::Tensor & self, at::Tensor & out) {
    return at::_ops::trace_out::call(self, out);
}

}
