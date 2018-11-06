#include "task.hpp"

#include <iterator>
#include <utility>

namespace challenge_00 {
namespace anonymous {

std::pair<std::vector<int>::const_iterator,
                 std::vector<int>::const_iterator>
find_subsequence(std::vector<int> const& sequence) noexcept {
    using input_t = std::decay_t<decltype(*std::begin(sequence))>;
    using iterator_t = decltype(std::begin(sequence));

    input_t sum = input_t{};
    input_t sum_maximal = sequence.front();

    iterator_t subsequence_start = std::begin(sequence);
    iterator_t subsequence_end = std::begin(sequence);
    iterator_t subsequence_min_start = std::begin(sequence);

    for (iterator_t it = std::begin(sequence); it != std::end(sequence); ++it) {
        sum += *it;

        if (sum >= sum_maximal) {
            sum_maximal = sum;
            subsequence_start = subsequence_min_start;
            subsequence_end = it;
        }

        if (sum < 0) {
            sum = 0;
            subsequence_min_start = std::next(it);
        }
    }

    return std::make_pair(subsequence_start, subsequence_end);
}

}  // namespace anonymous
}  // namespace challenge_00
