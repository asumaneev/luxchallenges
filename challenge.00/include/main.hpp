#pragma once

#include <cmath>
#include <random>
#include <vector>

static std::vector<int> random_sequence(
    const std::size_t number_of_elements) noexcept {
    std::vector<int> result;
    result.reserve(number_of_elements);

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{0, 50};

    while (result.size() < number_of_elements) {
        result.push_back(static_cast<int>(std::round(d(gen))));
    }

    return result;
}
