/**
 * @file binary_numeric_split_info.hpp
 * @author Ryan Curtin
 *
 * After a binary numeric split has been made, this holds information on the
 * split (just the split point).
 */
#ifndef __MLPACK_METHODS_HOEFFDING_TREES_BINARY_NUMERIC_SPLIT_INFO_HPP
#define __MLPACK_METHODS_HOEFFDING_TREES_BINARY_NUMERIC_SPLIT_INFO_HPP

#include <mlpack/core.hpp>

namespace mlpack {
namespace tree {

template<typename ObservationType = double>
class BinaryNumericSplitInfo
{
 public:
  BinaryNumericSplitInfo() { /* Nothing to do. */ }
  BinaryNumericSplitInfo(const ObservationType& splitPoint) :
      splitPoint(splitPoint) { /* Nothing to do. */ }

  template<typename eT>
  size_t CalculateDirection(const eT& value) const
  {
    return (value < splitPoint) ? 0 : 1;
  }

  //! Serialize the split (save/load the split points).
  template<typename Archive>
  void Serialize(Archive& ar, const unsigned int /* version */)
  {
    ar & data::CreateNVP(splitPoint, "splitPoint");
  }

 private:
  ObservationType splitPoint;
};

} // namespace tree
} // namespace mlpack

#endif
