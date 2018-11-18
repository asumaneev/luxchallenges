#pragma once

#include <algorithm>
#include <exception>
#include <iterator>
#include <type_traits>
#include <vector>

namespace challenge_01 {
namespace asumaneev {

namespace {

template <typename container_t>
using iterator_of = decltype(std::cbegin(container_t{}));

template <typename container_t>
using value_of = typename std::iterator_traits<iterator_of<container_t>>::value_type;

template <typename iterator_t>
using is_ra_iterator = std::is_base_of<std::random_access_iterator_tag,
                                       typename std::iterator_traits<iterator_t>::iterator_category>;

template <typename iterator_t,
          typename std::enable_if<is_ra_iterator<iterator_t>::value>::type* = nullptr>
constexpr bool iterator_less(iterator_t const lhs,
                             iterator_t const rhs,
                             iterator_t) {
    return lhs < rhs;
}

template <typename iterator_t,
          typename std::enable_if<!is_ra_iterator<iterator_t>::value>::type* = nullptr>
constexpr bool iterator_less(iterator_t const lhs,
                             iterator_t const rhs,
                             iterator_t const begin) {
    return std::distance(begin, lhs) < std::distance(begin, rhs);
}

template <typename container_t>
constexpr auto size(container_t const& c) noexcept {
    return c.size();
}

template <typename value_t, std::size_t array_size>
constexpr std::size_t size(value_t const (&array)[array_size]) noexcept {
    return array_size;
}

/**
 * @brief Searches for maximal element in subsequence of size \p frame_size
 *
 * Complexity:
 *      - Average: Thetta(n^2). See https://www.eecs.yorku.ca/course_archive/2003-04/S/2011/pdf/DatStr_011_AlgorithmAnalysisContinued.pdf (p. 5)
 *      - Worst case: O(n * m) (sorted descending)
 *      Where n is sequence size, m is frame size
 *
 * @tparam  container_t     type of sequence
 * @param   sequence        sequnence of elements to look up
 * @param   sequence_size   size of sequence
 * @param   frame_size      size of subsequence to look up
 * @returns vector of subsequences' maximal elements
 */
template <typename container_t>
std::vector<value_of<container_t>> find_max_in_frame_impl(
    container_t const& sequence,
    std::size_t const sequence_size,
    std::size_t const frame_size) {
    using iterator_t = iterator_of<container_t>;
    using value_t = value_of<container_t>;

    if (sequence_size < frame_size) {
        throw std::invalid_argument("sequence is less than frame");
    }

    if (sequence_size == 0) {
        return {};
    }

    //  initialize with invalid iterator
    iterator_t current_max_it = std::end(sequence);

    //  algorithm ends, when there is not enough elements for frame
    iterator_t const end = std::next(std::end(sequence), -frame_size + 1);

    std::vector<value_t> result;
    result.reserve(sequence_size);

    for (
         iterator_t begin_frame_it = std::begin(sequence);
         begin_frame_it != end;
         ++begin_frame_it
    ) {
        iterator_t const end_frame_it = std::next(begin_frame_it, frame_size);

        //  frame:[begin_frame_it, end_frame_it)

        if (iterator_less(current_max_it, begin_frame_it, std::begin(sequence))
            || current_max_it == std::end(sequence)) {
            //  previous max element of frame is out of new frame
            //  do proper search
            current_max_it = std::max_element(begin_frame_it, end_frame_it);
        } else if (*current_max_it < *std::prev(end_frame_it)) {
            //  previous max element of frame is less than new element
            current_max_it = std::prev(end_frame_it);
        } // else nothing changed

        result.push_back(*current_max_it);
    }

    return result;
}

}  // namespace

/**
 * @brief Searches for maximal element in subsequence of size \p frame_size
 *
 * @tparam  container_t     type of sequence
 * @param   sequence        sequnence of elements to look up
 * @param   frame_size      size of subsequence to look up
 * @returns vector of subsequences' maximal elements
 */
template <typename container_t>
auto find_max_in_frame(container_t const& sequence,
                       std::size_t const frame_size) {
    return find_max_in_frame_impl(sequence, size(sequence), frame_size);
}

/**
 * @brief Searches for maximal element in subsequence of size \p frame_size
 *
 * @tparam  value_t         type of sequence elements
 * @param   sequence_ptr    pointer to sequence's first element
 * @param   sequence_size   size of sequence
 * @param   frame_size      size of subsequence to look up
 * @returns vector of subsequences' maximal elements
 */
template<typename value_t>
auto find_max_in_frame(value_t const * const sequence_ptr,
                       std::size_t sequence_size,
                       std::size_t const frame_size) {
    if (sequence_ptr == nullptr) {
        throw std::invalid_argument("sequence_ptr == nullptr");
    }
    return find_max_in_frame_impl(sequence_ptr, sequence_size, frame_size);
}


}  // namespace asumaneev
}  // namespace challenge_01
