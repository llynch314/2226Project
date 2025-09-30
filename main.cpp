#include "benchmark.h"
#include "benchmark.cpp"
#include "dataset.h"
#include "dataset.cpp"
#include "sorts.h"
#include "sorts.cpp"
#include <iostream>
using namespace std;

int main() {
    Benchmark bm;

    cout << "===== Sorting Algorithms Benchmark =====\n";
    cout << "Datasets already generated.\n";
    cout << "Starting continuous benchmark run...\n";

    bm.run(); // run all algorithms on all datasets

    cout << "All benchmarks completed. Results saved in *_results.txt files.\n";
    return 0;
}
