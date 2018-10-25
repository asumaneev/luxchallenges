#include <asumaneev/task.hpp>

#include <cmath>
#include <random>

static std::vector<int> random_sequence(const std::size_t number_of_elements) noexcept
{
    std::vector<int> result;
    result.reserve(number_of_elements);

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{0, 50};

    while(result.size() < number_of_elements)
    {
        result.push_back(static_cast<int>(std::round(d(gen))));
    }

    return result;
}

#ifndef PERFORM_BENCHMARK

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>

int main()
{
    std::cout << "Enter number of elements:" << std::endl;

    std::size_t number_of_elements{};
    std::vector<int> sequence;

    std::cin >> number_of_elements;

    if (number_of_elements <= 0)
    {
        throw std::invalid_argument("Number of elements cannot be zero or negative");
    }
    else if (number_of_elements > 100)
    {
        throw std::invalid_argument("Number of elements too large for an example");
    }

    std::cout << "Do you want a rand sequence? [Yes/no]" << std::endl;
    std::string rand_answer;
    std::cin.ignore(); std::getline(std::cin, rand_answer);

    std::transform(rand_answer.begin(), rand_answer.end(), rand_answer.begin(), ::tolower);

    if (rand_answer.empty() || rand_answer == "yes")
    {
        sequence = random_sequence(number_of_elements);
    }
    else
    {
        sequence.reserve(number_of_elements);
        std::cout << "Enter a sequence of " << number_of_elements << " elements:" << std::endl;
        while (sequence.size() < number_of_elements)
        {
            int tmp{};
            std::cin >> tmp;
            sequence.push_back(tmp);
        }
    }

    auto sequence_indicies = asumaneev::challenge_00::find_subsequence_advanced(sequence);

    std::cout << "\tStart: " << std::distance(sequence.cbegin(), sequence_indicies.first) << std::endl;
    std::cout << "\tEnd: " << std::distance(sequence.cbegin(), sequence_indicies.second) << std::endl;
    std::cout << "\tSum: " << std::accumulate(sequence_indicies.first, sequence_indicies.second + 1, int{}) << std::endl;
    std::cout << "\tSequence: ";
    for (auto it = sequence.cbegin(); it != sequence.cend(); ++it)
    {
        if (it == sequence_indicies.first || it == sequence_indicies.second)
        {
            std::cout << "[" << *it << "] ";
        }
        else
        {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

#else

#include <benchmark/benchmark.h>

static const auto large_sequence = random_sequence(10000000);

static void BM_first_finder(benchmark::State& state)
{
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(asumaneev::challenge_00::find_subsequence(large_sequence));
    }
}

BENCHMARK(BM_first_finder);

static void BM_second_finder(benchmark::State& state)
{
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(asumaneev::challenge_00::find_subsequence_advanced(large_sequence));
    }
}

BENCHMARK(BM_second_finder);

static void BM_first_finder_complexity(benchmark::State& state)
{
    const auto sequence = random_sequence(state.range(0));
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(asumaneev::challenge_00::find_subsequence(sequence));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_first_finder_complexity)
    ->RangeMultiplier(2)->Range(1<<10, 1<<20)->Complexity(benchmark::oN);

static void BM_second_finder_complexity(benchmark::State& state)
{
    const auto sequence = random_sequence(state.range(0));
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(asumaneev::challenge_00::find_subsequence_advanced(sequence));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_second_finder_complexity)
    ->RangeMultiplier(2)->Range(1<<10, 1<<20)->Complexity(benchmark::oN);

BENCHMARK_MAIN();

#endif // PERFORM_BENCHMARK
