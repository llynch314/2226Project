#include "benchmark.h"
#include "sorts.h"
#include "dataset.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;

double Benchmark::timeAlgorithm(void (*sortFunc)(vector<int>&), vector<int> data) {
    auto start = high_resolution_clock::now();
    sortFunc(data);
    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

void Benchmark::run() {
    vector<string> algorithms{"Bubble", "Selection", "Insertion", "Merge", "Quick", "Shell"};
    for (const string &alg : algorithms) runSingleAlgorithm(alg);
}

void Benchmark::runSingleAlgorithm(const string& algorithmName) {
    vector<int> sizes{50000, 100000, 150000, 300000, 450000, 600000};

    ofstream outFile(algorithmName + "_results.txt", ios::app);

    for (int n : sizes) {
        cout << "Running " << algorithmName << " sort for size " << n << "...\n";

        vector<int> base = loadDataset("data_" + to_string(n) + ".txt");
        double total = 0.0;

        for (int trial = 0; trial < 5; trial++) {
            if (algorithmName == "Bubble") total += timeAlgorithm(bubbleSort, base);
            else if (algorithmName == "Selection") total += timeAlgorithm(selectionSort, base);
            else if (algorithmName == "Insertion") total += timeAlgorithm(insertionSort, base);
            else if (algorithmName == "Merge") total += timeAlgorithm(mergeSort, base);
            else if (algorithmName == "Quick") total += timeAlgorithm(quickSort, base);
            else if (algorithmName == "Shell") total += timeAlgorithm(shellSort, base);
        }

        double avg = total / 5.0;
        outFile << "Data size: " << n << " Average time: " << avg << " ms\n";
    }

    outFile.close();
    cout << algorithmName << " results saved to " << algorithmName << "_results.txt\n";
}
