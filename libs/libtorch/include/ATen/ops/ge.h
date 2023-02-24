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



#include <ATen/ops/ge_ops.h>

namespace at {


// aten::ge.Scalar_out(Tensor self, Scalar other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & ge_out(at::Tensor & out, const at::Tensor & self, const at::Scalar & other) {
    return at::_ops::ge_Scalar_out::call(self, other, out);
}

// aten::ge.Scalar_out(Tensor self, Scalar other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & ge_outf(const at::Tensor & self, const at::Scalar & other, at::Tensor & out) {
    return at::_ops::ge_Scalar_out::call(self, other, out);
}

// aten::ge.Scalar(Tensor self, Scalar other) -> Tensor
inline at::Tensor ge(const at::Tensor & self, const at::Scalar & other) {
    return at::_ops::ge_Scalar::call(self, other);
}

// aten::ge.Tensor_out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & ge_out(at::Tensor & out, const at::Tensor & self, const at::Tensor & other) {
    return at::_ops::ge_Tensor_out::call(self, other, out);
}

// aten::ge.Tensor_out(Tensor self, Tensor other, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & ge_outf(const at::Tensor & self, const at::Tensor & other, at::Tensor & out) {
    return at::_ops::ge_Tensor_out::call(self, other, out);
}

// aten::ge.Tensor(Tensor self, Tensor other) -> Tensor
inline at::Tensor ge(const at::Tensor & self, const at::Tensor & other) {
    return at::_ops::ge_Tensor::call(self, other);
}

}
