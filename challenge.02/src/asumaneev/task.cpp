#include "task.hpp"

#include <algorithm>
#include <exception>

#include <iostream>

namespace challenge_02 {
namespace asumaneev {

namespace {
inline void plausibility_check(Input const& input) {
    if (input.buffer_size == 0) {
        throw std::invalid_argument("buffer_size is 0");
    }

    if (input.reading_rate == 0) {
        throw std::invalid_argument("reading_rate is 0");
    }

    if (input.writing_rate == 0) {
        throw std::invalid_argument("writing_rate is 0");
    }
}

inline std::size_t elements_to_read(Input const& input, std::size_t used_elements) {
    return std::min(input.reading_rate, used_elements);
}

inline std::size_t elements_to_write(Input const& input,
                              std::size_t used_elements,
                              std::size_t rest_message) {
    return std::min(
                    std::min(input.writing_rate, input.buffer_size - used_elements),
                    rest_message);
};

inline void dump(Steps* const output, Step step) {
    output->emplace_back(step);
}

inline void dummy_dump(Steps* const, Step) {
    return;
}

}  // namespace

std::size_t find_best_rw_time(Input const& input, Steps* const steps) {

    plausibility_check(input);

    std::size_t taken_seconds{0};
    std::size_t rest_message{input.message_len};
    std::size_t received_messsage{0};

    std::size_t used_elements{0};

    auto do_dump = (steps == nullptr) ? dummy_dump : dump;

    while (received_messsage != input.message_len) {
        std::size_t read_elements = elements_to_read(input, used_elements);
        std::size_t write_elements = elements_to_write(input, used_elements, rest_message);

        rest_message -= write_elements;
        used_elements += (write_elements - read_elements);
        received_messsage += read_elements;

        ++taken_seconds;

        do_dump(steps, {read_elements, write_elements, used_elements,
                         rest_message, received_messsage});
    }

    return taken_seconds;
}

}  // namespace asumaneev
}  // namespace challenge_02
