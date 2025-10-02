#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>

class Benchmark {
public:
    void run(const std::string& prefix); // run all algorithms with given dataset type
    void runSingleAlgorithm(const std::string& algorithmName, const std::string& prefix);

private:
    double timeAlgorithm(void (*sortFunc)(std::vector<int>&), std::vector<int> data);
};


#endif
