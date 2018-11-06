#pragma once

#include <vector>

namespace challenge_00 {
namespace anonymous {

/**
 * @brief Searches for maximal subsequence
 *
 * Based on second algorithm taken from
 * http://e-maxx.ru/algo/maximum_average_segment
 *
 * @param   sequence   sequence to look up
 * @return pair of indicies with start and end of subsequence
 */
std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator>
find_subsequence(std::vector<int> const& sequence) noexcept;

}  // namespace anonymous
}  // namespace challenge_00
