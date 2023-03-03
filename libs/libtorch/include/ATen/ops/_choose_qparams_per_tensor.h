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



#include <ATen/ops/_choose_qparams_per_tensor_ops.h>

namespace at {


// aten::_choose_qparams_per_tensor(Tensor self, bool reduce_range=False) -> (float, int)
inline ::std::tuple<double,int64_t> _choose_qparams_per_tensor(const at::Tensor & self, bool reduce_range=false) {
    return at::_ops::_choose_qparams_per_tensor::call(self, reduce_range);
}

}