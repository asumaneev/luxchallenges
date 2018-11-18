#include <asumaneev/task.hpp>

#include <gtest/gtest.h>

#include <algorithm>
#include <fstream>
#include <vector>

using sequence_t = std::vector<int>;
using result_t = std::vector<int>;

namespace {
    std::string at_test_data_dir(std::string const& name) {
        static const std::string test_data_dir = std::string(TEST_DATA_DIR) + "/";
        return test_data_dir + name;
    }
}

class empty_sequence : public ::testing::Test {
   public:
    empty_sequence() : sequence{}, expected_result{}, frame_size(0) {}

    const sequence_t sequence;
    const result_t expected_result;
    const std::size_t frame_size;
};

TEST_F(empty_sequence, asumaneev) {
    auto result =
        challenge_01::asumaneev::find_max_in_frame(sequence, frame_size);

    ASSERT_EQ(result, expected_result);
}

class frame_size_greater_sequence : public ::testing::Test {
   public:
    frame_size_greater_sequence()
        : sequence{1, 2, 3},
          expected_result{},
          frame_size(sequence.size() + 1) {}

    const sequence_t sequence;
    const result_t expected_result;
    const std::size_t frame_size;
};

TEST_F(frame_size_greater_sequence, asumaneev) {
    ASSERT_THROW(
        challenge_01::asumaneev::find_max_in_frame(sequence, frame_size),
        std::invalid_argument);
}

class first_sequence : public ::testing::Test {
   public:
    first_sequence()
        : sequence{4, 1, 5, 7, 2}, expected_result{5, 7, 7}, frame_size(3) {}

    const int sequence[5];
    const result_t expected_result;
    const std::size_t frame_size;
};

TEST_F(first_sequence, asumaneev) {
    auto result =
        challenge_01::asumaneev::find_max_in_frame(sequence, frame_size);

    ASSERT_EQ(result, expected_result);
}

class second_sequence : public ::testing::Test {
   public:
    second_sequence()
        : sequence{3, 4, 9, 12}, expected_result{4, 9, 12}, frame_size(2) {}

    const int sequence[4];
    const result_t expected_result;
    const std::size_t frame_size;
};

TEST_F(second_sequence, asumaneev) {
    auto result =
        challenge_01::asumaneev::find_max_in_frame(sequence, frame_size);

    ASSERT_EQ(result, expected_result);
}

class third_sequence : public ::testing::Test {
   public:
    third_sequence() {
        const std::string algo_input_filename(at_test_data_dir("third_sequence.in"));

        std::ifstream algo_input(algo_input_filename);

        std::size_t sequence_size{};

        algo_input >> sequence_size;
        algo_input >> frame_size;

        sequence.resize(sequence_size);
        for (auto& element : sequence) {
            algo_input >> element;
        }

        std::size_t result_size = sequence_size - frame_size + 1;

        expected_result.resize(result_size);
        for (auto& element : expected_result) {
            algo_input >> element;
        }
    }

    sequence_t sequence;
    result_t expected_result;
    std::size_t frame_size;
};

TEST_F(third_sequence, asumaneev) {
    auto result =
        challenge_01::asumaneev::find_max_in_frame(sequence, frame_size);

    ASSERT_EQ(result, expected_result);
}

class fourth_sequence : public ::testing::Test {
   public:
    fourth_sequence() {
        const std::string algo_input_filename(at_test_data_dir("fourth_sequence.in"));

        std::ifstream algo_input(algo_input_filename);

        std::size_t sequence_size{};

        algo_input >> sequence_size;
        algo_input >> frame_size;

        sequence.resize(sequence_size);
        for (auto& element : sequence) {
            algo_input >> element;
        }

        std::size_t result_size = sequence_size - frame_size + 1;

        expected_result.resize(result_size);
        for (auto& element : expected_result) {
            algo_input >> element;
        }
    }

    sequence_t sequence;
    result_t expected_result;
    std::size_t frame_size;
};

TEST_F(fourth_sequence, asumaneev) {
    auto result =
        challenge_01::asumaneev::find_max_in_frame(sequence, frame_size);

    ASSERT_EQ(result, expected_result);
}
