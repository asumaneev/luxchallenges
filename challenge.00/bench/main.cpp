#include "main.hpp"

#include <asumaneev/task.hpp>
#include <anonymous/task.hpp>
#include <benchmark/benchmark.h>

static const auto large_sequence = random_sequence(10000000);

static void BM_asumaneev(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_00::asumaneev::find_subsequence(large_sequence));
    }
}

BENCHMARK(BM_asumaneev);

static void BM_anonymous(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_00::anonymous::find_subsequence(large_sequence));
    }
}

BENCHMARK(BM_anonymous);

static void BM_asumaneev_complexity(benchmark::State& state) {
    const auto sequence = random_sequence(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_00::asumaneev::find_subsequence(sequence));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_asumaneev_complexity)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 20)
    ->Complexity(benchmark::oN);

static void BM_anonymous_complexity(benchmark::State& state) {
    const auto sequence = random_sequence(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_00::anonymous::find_subsequence(sequence));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_anonymous_complexity)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 20)
    ->Complexity(benchmark::oN);

BENCHMARK_MAIN();
