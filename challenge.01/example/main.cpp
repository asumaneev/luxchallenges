#include <asumaneev/task.hpp>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

int main() {
    std::size_t size_of_sequence{};
    std::size_t size_of_frame{};
    std::cin >> size_of_sequence >> size_of_frame;

    std::list<std::uint32_t> sequence(size_of_sequence);
    for (auto& element : sequence) {
        std::cin >> element;
    }

    auto result =
        challenge_01::asumaneev::find_max_in_frame(sequence, size_of_frame);
    std::cout << result[0];
    for (std::size_t i = 1; i < result.size(); ++i) {
        std::cout << " " << result[i];
    }
    std::cout << std::endl;

    return 0;
}
