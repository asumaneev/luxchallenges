#include <asumaneev/task.hpp>
#include <anonymous/task.hpp>

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

TEST_F(non_negative_sequence, asumaneev) {
    auto result = challenge_00::asumaneev::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}

TEST_F(non_negative_sequence, anonymous) {
    auto result = challenge_00::anonymous::find_subsequence(sequence);

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

TEST_F(negative_sequence, asumaneev) {
    auto result = challenge_00::asumaneev::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}

TEST_F(negative_sequence, anonymous) {
    auto result = challenge_00::anonymous::find_subsequence(sequence);

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

TEST_F(zero_sequence, asumaneev) {
    auto result = challenge_00::asumaneev::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}

TEST_F(zero_sequence, anonymous) {
    auto result = challenge_00::anonymous::find_subsequence(sequence);

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

TEST_F(two_max, asumaneev) {
    auto result = challenge_00::asumaneev::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}

TEST_F(two_max, anonymous) {
    auto result = challenge_00::anonymous::find_subsequence(sequence);

    ASSERT_EQ(result, expected_result);
}
