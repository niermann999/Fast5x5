#ifndef GEMM_CUSTOM_H
#define GEMM_CUSTOM_H

#include "benchmark/benchmark.h"
#include "fast5x5/fast5x5.hpp"
#include "benchmarks/shared/common.hpp"

static void gemm_custom(benchmark::State& state) {
    using M = BaseMatrix<float, SIZE, SIZE>;

    M m1 = genRandomCustomMat<float, SIZE, SIZE>();
	M m2 = genRandomCustomMat<float, SIZE, SIZE>();
	M res;

    for (auto _ : state) {
        benchmark::DoNotOptimize(m1);
        benchmark::DoNotOptimize(m2);

        matrix_mul_m_m(m1, m2, res);

        benchmark::DoNotOptimize(res);
    }
}

#endif  // GEMM_CUSTOM_H
