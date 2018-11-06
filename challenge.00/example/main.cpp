#include "main.hpp"

#include <anonymous/task.hpp>
#include <asumaneev/task.hpp>

#include <algorithm>
#include <exception>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>

using sequence_t = std::vector<int>;
using result_t =
    std::pair<sequence_t::const_iterator, sequence_t::const_iterator>;
using sequence_finder_t = std::function<result_t(sequence_t const&)>;

static const std::unordered_map<std::string, sequence_finder_t> finders{
    {"asumaneev",
     [](const sequence_t& seq) {
         return challenge_00::asumaneev::find_subsequence(seq);
     }},
    {"anonymous", challenge_00::anonymous::find_subsequence},
};

std::size_t get_sequence_size() {
    std::cout << "Enter number of elements:" << std::endl;

    std::size_t number_of_elements{};
    std::cin >> number_of_elements;

    if (number_of_elements > 100) {
        throw std::invalid_argument(
            "Number of elements too large for an example (or you just enter a "
            "negative number)");
    }

    return number_of_elements;
}

sequence_t get_sequence(std::size_t const number_of_elements) {
    std::cin.ignore();
    std::cout << "Do you want a rand sequence? [Yes/no]" << std::endl;
    std::string rand_answer;
    std::getline(std::cin, rand_answer);

    std::transform(rand_answer.begin(), rand_answer.end(), rand_answer.begin(),
                   ::tolower);

    sequence_t sequence;
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

    return sequence;
}

sequence_finder_t get_finder() {
    static const std::string none = "none";

    std::cout << "Whose algorithm do you want to test? [" << none;
    for (auto const& finder : finders) {
        std::cout << "/" << finder.first;
    }
    std::cout << "]:" << std::endl;

    while (true) {
        std::string author;
        std::getline(std::cin, author);
        std::transform(author.begin(), author.end(), author.begin(), ::tolower);

        if (author == none) {
            return sequence_finder_t{};
        } else {
            try {
                return finders.at(author);
            } catch (std::out_of_range&) {
                std::cout << "No such author: '" << author
                          << "'. Try again:" << std::endl;
            }
        }
    }
}

int main() {
    std::size_t number_of_elements = get_sequence_size();
    sequence_t sequence = get_sequence(number_of_elements);

    for (sequence_finder_t finder = get_finder(); finder != nullptr; finder = get_finder()) {
        auto sequence_indicies = finder(sequence);

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
            if (it == sequence_indicies.first ||
                it == sequence_indicies.second) {
                std::cout << "[" << *it << "] ";
            } else {
                std::cout << *it << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
