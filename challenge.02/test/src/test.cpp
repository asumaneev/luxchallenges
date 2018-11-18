#include <asumaneev/task.hpp>

#include <gtest/gtest.h>

class Test0 : public ::testing::Test {
public:
    Test0() : input{20, 20, 15, 35}, expected_result{4} {}

    void SetUp() {
        steps.clear();
    }

    const challenge_02::asumaneev::Input input;
    const std::size_t expected_result;

    challenge_02::asumaneev::Steps steps;
};

TEST_F(Test0, asumaneev) {
    auto result =
        challenge_02::asumaneev::find_best_rw_time(input, &steps);

    for (auto const& step : steps) {
        ASSERT_EQ(step.elements_in_buffer
                      + step.rest_message_len
                      + step.received_message_len,
                      input.message_len);
    }

    ASSERT_EQ(result, expected_result);
}

class Test1 : public ::testing::Test {
public:
    Test1() : input{1000, 1000, 1000, 10000}, expected_result{21} {}

    void SetUp() {
        steps.clear();
    }

    const challenge_02::asumaneev::Input input;
    const std::size_t expected_result;

    challenge_02::asumaneev::Steps steps;
};

TEST_F(Test1, asumaneev) {
    auto result =
        challenge_02::asumaneev::find_best_rw_time(input, &steps);

    for (auto const& step : steps) {
        ASSERT_EQ(step.elements_in_buffer
                      + step.rest_message_len
                      + step.received_message_len,
                      input.message_len);
    }

    ASSERT_EQ(result, expected_result);
}

class Test2 : public ::testing::Test {
public:
    Test2() : input{15, 5, 15, 10000}, expected_result{2001} {}

    void SetUp() {
        steps.clear();
    }

    const challenge_02::asumaneev::Input input;
    const std::size_t expected_result;

    challenge_02::asumaneev::Steps steps;
};

TEST_F(Test2, asumaneev) {
    auto result =
        challenge_02::asumaneev::find_best_rw_time(input, &steps);

    for (auto const& step : steps) {
        ASSERT_EQ(step.elements_in_buffer
                      + step.rest_message_len
                      + step.received_message_len,
                      input.message_len);
    }

    ASSERT_EQ(result, expected_result);
}

class Test3 : public ::testing::Test {
public:
    Test3() : input{20, 10, 10, 100}, expected_result{11} {}

    void SetUp() {
        steps.clear();
    }

    const challenge_02::asumaneev::Input input;
    const std::size_t expected_result;

    challenge_02::asumaneev::Steps steps;
};

TEST_F(Test3, asumaneev) {
    auto result =
        challenge_02::asumaneev::find_best_rw_time(input, &steps);

    for (auto const& step : steps) {
        ASSERT_EQ(step.elements_in_buffer
                      + step.rest_message_len
                      + step.received_message_len,
                      input.message_len);
    }

    ASSERT_EQ(result, expected_result);
}

class Test4 : public ::testing::Test {
public:
    Test4() : input{20, 100, 100, 1000}, expected_result{100} {}

    void SetUp() {
        steps.clear();
    }

    const challenge_02::asumaneev::Input input;
    const std::size_t expected_result;

    challenge_02::asumaneev::Steps steps;
};

TEST_F(Test4, asumaneev) {
    auto result =
        challenge_02::asumaneev::find_best_rw_time(input, &steps);

    for (auto const& step : steps) {
        ASSERT_EQ(step.elements_in_buffer
                      + step.rest_message_len
                      + step.received_message_len,
                      input.message_len);
    }

    ASSERT_EQ(result, expected_result);
}

