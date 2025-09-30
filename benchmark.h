#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>

class Benchmark {
public:
    void run(); // run all algorithms on all datasets
    void runSingleAlgorithm(const std::string& algorithmName); // run one algorithm

private:
    double timeAlgorithm(void (*sortFunc)(std::vector<int>&), std::vector<int> data);
};

#endif
