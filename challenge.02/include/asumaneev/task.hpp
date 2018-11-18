#pragma once

#include <cstdlib>
#include <list>

namespace challenge_02 {
namespace asumaneev {

struct Input {
    std::size_t buffer_size;
    std::size_t reading_rate;
    std::size_t writing_rate;
    std::size_t message_len;
};

struct Step {
    std::size_t read_elements;
    std::size_t written_elements;
    std::size_t elements_in_buffer;
    std::size_t rest_message_len;
    std::size_t received_message_len;
};

using Steps = std::list<Step>;

/**
 * @brief Greedy algorithim to find read/write sequence
 *        for best performance
 *
 * @param input    input parameters of buffer, message,
 *                 producer and consumer
 * @param steps    state of each read/write step [optional]
 * @returns number of seconds to transfer message
 */
std::size_t find_best_rw_time(Input const &input, Steps* const steps = nullptr);

}  // namespace asumaneev
}  // namespace challenge_02
