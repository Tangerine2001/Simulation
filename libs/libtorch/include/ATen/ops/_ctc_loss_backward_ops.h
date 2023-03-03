#pragma once

// @generated by torchgen/gen.py from Operator.h

#include <tuple>
#include <vector>

// Forward declarations of any types needed in the operator signatures.
// We can't directly include these classes because it will cause circular include dependencies.
// This file is included by TensorBody.h, which defines the Tensor class.
#include <ATen/core/ATen_fwd.h>

namespace at {
namespace _ops {


struct TORCH_API _ctc_loss_backward {
  using schema = at::Tensor (const at::Tensor &, const at::Tensor &, const at::Tensor &, at::IntArrayRef, at::IntArrayRef, const at::Tensor &, const at::Tensor &, int64_t, bool);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::_ctc_loss_backward")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "_ctc_loss_backward(Tensor grad, Tensor log_probs, Tensor targets, int[] input_lengths, int[] target_lengths, Tensor neg_log_likelihood, Tensor log_alpha, int blank, bool zero_infinity=False) -> Tensor")
  static at::Tensor call(const at::Tensor & grad, const at::Tensor & log_probs, const at::Tensor & targets, at::IntArrayRef input_lengths, at::IntArrayRef target_lengths, const at::Tensor & neg_log_likelihood, const at::Tensor & log_alpha, int64_t blank, bool zero_infinity);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & grad, const at::Tensor & log_probs, const at::Tensor & targets, at::IntArrayRef input_lengths, at::IntArrayRef target_lengths, const at::Tensor & neg_log_likelihood, const at::Tensor & log_alpha, int64_t blank, bool zero_infinity);
};

struct TORCH_API _ctc_loss_backward_Tensor {
  using schema = at::Tensor (const at::Tensor &, const at::Tensor &, const at::Tensor &, const at::Tensor &, const at::Tensor &, const at::Tensor &, const at::Tensor &, int64_t, bool);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::_ctc_loss_backward")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "Tensor")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "_ctc_loss_backward.Tensor(Tensor grad, Tensor log_probs, Tensor targets, Tensor input_lengths, Tensor target_lengths, Tensor neg_log_likelihood, Tensor log_alpha, int blank, bool zero_infinity=False) -> Tensor")
  static at::Tensor call(const at::Tensor & grad, const at::Tensor & log_probs, const at::Tensor & targets, const at::Tensor & input_lengths, const at::Tensor & target_lengths, const at::Tensor & neg_log_likelihood, const at::Tensor & log_alpha, int64_t blank, bool zero_infinity);
  static at::Tensor redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & grad, const at::Tensor & log_probs, const at::Tensor & targets, const at::Tensor & input_lengths, const at::Tensor & target_lengths, const at::Tensor & neg_log_likelihood, const at::Tensor & log_alpha, int64_t blank, bool zero_infinity);
};

struct TORCH_API _ctc_loss_backward_out {
  using schema = at::Tensor & (const at::Tensor &, const at::Tensor &, const at::Tensor &, at::IntArrayRef, at::IntArrayRef, const at::Tensor &, const at::Tensor &, int64_t, bool, at::Tensor &);
  using ptr_schema = schema*;
  // See Note [static constexpr char* members for windows NVCC]
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(name, "aten::_ctc_loss_backward")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(overload_name, "out")
  STATIC_CONSTEXPR_STR_INL_EXCEPT_WIN_CUDA(schema_str, "_ctc_loss_backward.out(Tensor grad, Tensor log_probs, Tensor targets, int[] input_lengths, int[] target_lengths, Tensor neg_log_likelihood, Tensor log_alpha, int blank, bool zero_infinity=False, *, Tensor(a!) out) -> Tensor(a!)")
  static at::Tensor & call(const at::Tensor & grad, const at::Tensor & log_probs, const at::Tensor & targets, at::IntArrayRef input_lengths, at::IntArrayRef target_lengths, const at::Tensor & neg_log_likelihood, const at::Tensor & log_alpha, int64_t blank, bool zero_infinity, at::Tensor & out);
  static at::Tensor & redispatch(c10::DispatchKeySet dispatchKeySet, const at::Tensor & grad, const at::Tensor & log_probs, const at::Tensor & targets, at::IntArrayRef input_lengths, at::IntArrayRef target_lengths, const at::Tensor & neg_log_likelihood, const at::Tensor & log_alpha, int64_t blank, bool zero_infinity, at::Tensor & out);
};

}} // namespace at::_ops