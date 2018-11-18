#include <asumaneev/task.hpp>

#include <iostream>

int main() {
    std::size_t buffer_size;
    std::size_t read_rate;
    std::size_t write_rate;
    std::size_t message_length;

    std::cin >> buffer_size >> read_rate >> write_rate >> message_length;

    challenge_02::asumaneev::Steps steps;

    std::cout << "Result: "
              << challenge_02::asumaneev::find_best_rw_time({buffer_size, read_rate, write_rate, message_length}, &steps)
              << std::endl;

    // std::size_t second{0};
    // for (auto const& step : steps) {
    //     std::cout << "Second " << (second++) << ": "
    //           << "\n\tConsumer reads\t\t" << step.read_elements
    //           << "\n\tProducer writes\t\t" << step.written_elements
    //           << "\n\tElems in buffer\t\t" << step.elements_in_buffer
    //           << "\n\tRest of message\t\t" << step.rest_message_len
    //           << "\n\tReceived message\t" << step.received_message_len
    //           << std::endl;
    // }

    return 0;
}
