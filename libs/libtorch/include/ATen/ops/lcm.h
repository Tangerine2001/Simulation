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



#include <ATen/ops/lcm_ops.h>

namespace at {


// aten::lcm.out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & lcm_out(at::Tensor & out, const at::Tensor & self, const at::Tensor & other) {
    return at::_ops::lcm_out::call(self, other, out);
}

// aten::lcm.out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & lcm_outf(const at::Tensor & self, const at::Tensor & other, at::Tensor & out) {
    return at::_ops::lcm_out::call(self, other, out);
}

// aten::lcm(Tensor self, Tensor other) -> Tensor
inline at::Tensor lcm(const at::Tensor & self, const at::Tensor & other) {
    return at::_ops::lcm::call(self, other);
}

// aten::lcm_(Tensor(a!) self, Tensor other) -> Tensor(a!)
inline at::Tensor & lcm_(at::Tensor & self, const at::Tensor & other) {
    return at::_ops::lcm_::call(self, other);
}

}
