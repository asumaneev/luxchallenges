#include "main.hpp"

#include <asumaneev/task.hpp>
#include <benchmark/benchmark.h>

static const auto large_sequence = random_sequence(10000000);

static void BM_first_finder(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            asumaneev::challenge_00::find_subsequence(large_sequence));
    }
}

BENCHMARK(BM_first_finder);

static void BM_second_finder(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            asumaneev::challenge_00::find_subsequence_advanced(large_sequence));
    }
}

BENCHMARK(BM_second_finder);

static void BM_first_finder_complexity(benchmark::State& state) {
    const auto sequence = random_sequence(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            asumaneev::challenge_00::find_subsequence(sequence));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_first_finder_complexity)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 20)
    ->Complexity(benchmark::oN);

static void BM_second_finder_complexity(benchmark::State& state) {
    const auto sequence = random_sequence(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            asumaneev::challenge_00::find_subsequence_advanced(sequence));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_second_finder_complexity)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 20)
    ->Complexity(benchmark::oN);

BENCHMARK_MAIN();
