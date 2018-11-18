#include <asumaneev/task.hpp>

#include <benchmark/benchmark.h>

#include <limits>

static void BM_asumaneev_test1(benchmark::State& state) {
    static challenge_02::asumaneev::Input test1_input{1000, 1000, 1000, 10000};

    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_02::asumaneev::find_best_rw_time(test1_input));
    }
}

BENCHMARK(BM_asumaneev_test1);

static void BM_asumaneev_test2(benchmark::State& state) {
    static challenge_02::asumaneev::Input test2_input{15, 5, 15, 10000};

    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_02::asumaneev::find_best_rw_time(test2_input));
    }
}

BENCHMARK(BM_asumaneev_test2);

static void BM_asumaneev_worst_case(benchmark::State& state) {
    static challenge_02::asumaneev::Input worst_case{1, 2, 2,
                                                     // std::numeric_limits<std::size_t>::max() / 1000
                                                     50000000
                                                    };

    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_02::asumaneev::find_best_rw_time(worst_case));
    }
}

BENCHMARK(BM_asumaneev_worst_case);

static challenge_02::asumaneev::Input hard_input{1, 2, 2, 100000};

static void BM_asumaneev_no_dump(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_02::asumaneev::find_best_rw_time(hard_input));
    }
}

BENCHMARK(BM_asumaneev_no_dump);

static void BM_asumaneev_dump(benchmark::State& state) {
    challenge_02::asumaneev::Steps steps;
    for (auto _ : state) {
        benchmark::DoNotOptimize(
            challenge_02::asumaneev::find_best_rw_time(hard_input, &steps));
    }
}

BENCHMARK(BM_asumaneev_dump);

BENCHMARK_MAIN();
