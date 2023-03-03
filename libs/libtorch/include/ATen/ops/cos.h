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



#include <ATen/ops/cos_ops.h>

namespace at {


// aten::cos(Tensor self) -> Tensor
inline at::Tensor cos(const at::Tensor & self) {
    return at::_ops::cos::call(self);
}

// aten::cos_(Tensor(a!) self) -> Tensor(a!)
inline at::Tensor & cos_(at::Tensor & self) {
    return at::_ops::cos_::call(self);
}

// aten::cos.out(Tensor self, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & cos_out(at::Tensor & out, const at::Tensor & self) {
    return at::_ops::cos_out::call(self, out);
}

// aten::cos.out(Tensor self, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & cos_outf(const at::Tensor & self, at::Tensor & out) {
    return at::_ops::cos_out::call(self, out);
}

}