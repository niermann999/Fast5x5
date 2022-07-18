#ifndef GEMM_CUSTOM_H
#define GEMM_CUSTOM_H

#include "benchmark/benchmark.h"
#include "fast5x5/fast5x5.hpp"
#include "gemm_header.h"
#include "random.hpp"

static void gemm_custom(benchmark::State& state) {
    alignas(32) double a[SIZE * SIZE];
    alignas(32) double b[SIZE * SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i * SIZE + j] = randomDouble(0, 100'000.0);
            b[i * SIZE + j] = randomDouble(0, 100'000.0);
        }
    }

    using M = BaseMatrix<double, SIZE, SIZE>;
    M m1(a), m2(b), res;

    for (auto _ : state) {
        benchmark::DoNotOptimize(res);

        matrix_mul_m_m(m1, m2, res);
    }
}

#endif  // GEMM_CUSTOM_H
