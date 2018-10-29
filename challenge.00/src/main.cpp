#include "main.hpp"

#include <asumaneev/task.hpp>

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>

int main() {
    std::cout << "Enter number of elements:" << std::endl;

    std::size_t number_of_elements{};
    std::vector<int> sequence;

    std::cin >> number_of_elements;

    if (number_of_elements > 100) {
        throw std::invalid_argument(
            "Number of elements too large for an example (or you just enter a negative number)");
    }

    std::cout << "Do you want a rand sequence? [Yes/no]" << std::endl;
    std::string rand_answer;
    std::cin.ignore();
    std::getline(std::cin, rand_answer);

    std::transform(rand_answer.begin(), rand_answer.end(), rand_answer.begin(),
                   ::tolower);

    if (rand_answer.empty() || rand_answer == "yes") {
        sequence = random_sequence(number_of_elements);
    } else {
        sequence.reserve(number_of_elements);
        std::cout << "Enter a sequence of " << number_of_elements
                  << " elements:" << std::endl;
        while (sequence.size() < number_of_elements) {
            int tmp{};
            std::cin >> tmp;
            sequence.push_back(tmp);
        }
    }

    auto sequence_indicies =
        asumaneev::challenge_00::find_subsequence(sequence);

    std::cout << "\tStart: "
              << std::distance(sequence.cbegin(), sequence_indicies.first)
              << std::endl;
    std::cout << "\tEnd: "
              << std::distance(sequence.cbegin(), sequence_indicies.second)
              << std::endl;
    std::cout << "\tSum: "
              << std::accumulate(sequence_indicies.first,
                                 sequence_indicies.second + 1, int{})
              << std::endl;
    std::cout << "\tSequence: ";
    for (auto it = sequence.cbegin(); it != sequence.cend(); ++it) {
        if (it == sequence_indicies.first || it == sequence_indicies.second) {
            std::cout << "[" << *it << "] ";
        } else {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
