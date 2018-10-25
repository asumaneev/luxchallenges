#pragma once

#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

namespace asumaneev {
namespace challenge_00 {

/**
 * @brief Searches for maximal subsequence
 *
 * Provides algorithm to find subsequence
 * with maxmial sum of elements
 *
 * Based on first algorithm taken from
 * http://e-maxx.ru/algo/maximum_average_segment
 *
 * @param   sequence   sequence to look up
 * @return pair of indicies with start and end of subsequence
 */
template<typename container_t>
static auto find_subsequence(container_t const& sequence) noexcept
{
    using input_t = std::decay_t<decltype(*std::begin(sequence))>;
    using iterator_t = decltype(std::begin(sequence));

    input_t sum = input_t{};
    input_t sum_maximal = *std::begin(sequence);
    input_t sum_minimal = input_t{};

    iterator_t subsequence_start = std::begin(sequence);
    iterator_t subsequence_end = std::begin(sequence);
    iterator_t subsequence_min_start = std::begin(sequence);

    for (iterator_t it = std::begin(sequence);
         it != std::end(sequence);
         ++it)
    {
        sum += *it;
        input_t const sum_current = sum - sum_minimal;

        if (sum_current > sum_maximal)
        {
            sum_maximal = sum_current;
            subsequence_start = subsequence_min_start;
            subsequence_end = it;
        }

        if (sum < sum_minimal)
        {
            sum_minimal = sum;
            subsequence_min_start = std::next(it);
        }
    }

    return std::make_pair(subsequence_start, subsequence_end);
}

/**
 * @brief Searches for maximal subsequence
 *
 * Based on second algorithm taken from
 * http://e-maxx.ru/algo/maximum_average_segment
 *
 * @param   sequence   sequence to look up
 * @return pair of indicies with start and end of subsequence
 */
template<typename container_t>
static auto find_subsequence_advanced(container_t const& sequence) noexcept
{
    using input_t = std::decay_t<decltype(*std::begin(sequence))>;
    using iterator_t = decltype(std::begin(sequence));

    input_t sum = input_t{};
    input_t sum_maximal = sequence.front();

    iterator_t subsequence_start = std::begin(sequence);
    iterator_t subsequence_end = std::begin(sequence);
    iterator_t subsequence_min_start = std::begin(sequence);

    for (iterator_t it = std::begin(sequence);
         it != std::end(sequence);
         ++it)
    {
        sum += *it;

        if (sum > sum_maximal)
        {
            sum_maximal = sum;
            subsequence_start = subsequence_min_start;
            subsequence_end = it;
        }

        if (sum < 0)
        {
            sum = 0;
            subsequence_min_start = std::next(it);
        }
    }

    return std::make_pair(subsequence_start, subsequence_end);
}

} // namespace challenge_00
} // namespace asumaneev
