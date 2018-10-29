#include <asumaneev/task.hpp>

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using sequence_t = std::vector<int>;
using result_t =
    std::pair<sequence_t::const_iterator, sequence_t::const_iterator>;

class non_negative_sequence : public ::testing::Test {
   public:
    non_negative_sequence()
                // f                             s
        : sequence{0, 0, 1, 2, 3, 4, 3, 2, 1, 0, 0},
          expected_result{sequence.cbegin(), sequence.cend() - 1} {}

    const sequence_t sequence;
    const result_t expected_result;
};

TEST_F(non_negative_sequence, first_finder) {
    auto result = asumaneev::challenge_00::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}

TEST_F(non_negative_sequence, second_finder) {
    auto result = asumaneev::challenge_00::find_subsequence_advanced(sequence);

    ASSERT_EQ(result, expected_result);
}

class negative_sequence : public ::testing::Test {
   public:
    negative_sequence()
                //                 fs
        : sequence{-4, -3, -2, -1, -1, -2, -3, -4},
          expected_result{sequence.cbegin() + 4, sequence.cbegin() + 4} {}

    const sequence_t sequence;
    const result_t expected_result;
};

TEST_F(negative_sequence, first_finder) {
    auto result = asumaneev::challenge_00::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}

TEST_F(negative_sequence, second_finder) {
    auto result = asumaneev::challenge_00::find_subsequence_advanced(sequence);

    ASSERT_EQ(result, expected_result);
}

class zero_sequence : public ::testing::Test {
   public:
    zero_sequence()
        : sequence(100),
          expected_result{sequence.cbegin(), sequence.cend() - 1} {}

    const sequence_t sequence;
    const result_t expected_result;
};

TEST_F(zero_sequence, first_finder) {
    auto result = asumaneev::challenge_00::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}

TEST_F(zero_sequence, second_finder) {
    auto result = asumaneev::challenge_00::find_subsequence_advanced(sequence);

    ASSERT_EQ(result, expected_result);
}

class two_max : public ::testing::Test {
   public:
    two_max()
        : sequence{-1, -2, 1, 2, 3, -100, 1, 2, 3, -1, -2},
          expected_result{sequence.cbegin() + 6, sequence.cbegin() + 8} {}

    const sequence_t sequence;
    const result_t expected_result;
};

TEST_F(two_max, first_finder) {
    auto result = asumaneev::challenge_00::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}

TEST_F(two_max, second_finder) {
    auto result = asumaneev::challenge_00::find_subsequence_advanced(sequence);

    ASSERT_EQ(result, expected_result);
}
