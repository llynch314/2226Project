#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>

using namespace std;

class Benchmark {
public:
    void run(const string& prefix);
    void runSingleAlgorithm(const string& algorithmName, const string& prefix);

private:
    double timeAlgorithm(void (*sortFunc)(vector<int>&), vector<int> data);
};


#endif
