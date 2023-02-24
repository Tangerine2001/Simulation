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



#include <ATen/ops/mkldnn_linear_ops.h>

namespace at {


// aten::mkldnn_linear(Tensor self, Tensor weight, Tensor? bias=None) -> Tensor
inline at::Tensor mkldnn_linear(const at::Tensor & self, const at::Tensor & weight, const c10::optional<at::Tensor> & bias={}) {
    return at::_ops::mkldnn_linear::call(self, weight, bias);
}

// aten::mkldnn_linear.out(Tensor self, Tensor weight, Tensor? bias=None, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & mkldnn_linear_out(at::Tensor & out, const at::Tensor & self, const at::Tensor & weight, const c10::optional<at::Tensor> & bias={}) {
    return at::_ops::mkldnn_linear_out::call(self, weight, bias, out);
}

// aten::mkldnn_linear.out(Tensor self, Tensor weight, Tensor? bias=None, *, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & mkldnn_linear_outf(const at::Tensor & self, const at::Tensor & weight, const c10::optional<at::Tensor> & bias, at::Tensor & out) {
    return at::_ops::mkldnn_linear_out::call(self, weight, bias, out);
}

}
