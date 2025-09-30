#include "benchmark.h"
#include "sorts.h"
#include "dataset.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;

Dataset ds;
double Benchmark::timeAlgorithm(void (*sortFunc)(vector<int>&), vector<int> data) {
    auto start = high_resolution_clock::now();
    sortFunc(data);
    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

void Benchmark::run() {
    vector<string> algorithms{"Bubble", "Selection", "Insertion", "Merge", "Quick", "Shell"};
    for (const string &alg : algorithms) {
        cout << "\n=== Starting benchmarks for " << alg << " Sort ===\n";
        runSingleAlgorithm(alg);
        cout << "=== Finished benchmarks for " << alg << " Sort ===\n";
    }
}
void Benchmark::runSingleAlgorithm(const string& algorithmName) {
    vector<int> sizes{50000, 100000, 150000, 300000, 450000, 600000};

    ofstream outFile(algorithmName + "_results.txt", ios::app);
    if (!outFile.is_open()) {
        cerr << "Error: could not open results file for " << algorithmName << "\n";
        return;
    }

    for (int n : sizes) {
        cout << "[Stage] Running " << algorithmName << " sort for dataset size " << n << "...\n";

        // Load dataset
        vector<int> base = ds.loadDataset("data_" + to_string(n) + ".txt");
        if (base.empty()) {
            cerr << "Error: dataset file for size " << n << " not found.\n";
            continue;
        }

        double total = 0.0;
        outFile << "\n--- " << algorithmName << " Sort, Data size: " << n << " ---\n";
        outFile.flush(); // immediately write header

        for (int trial = 1; trial <= 5; trial++) {
            cout << "   Trial " << trial << "...\n";

            double t = 0.0;
            if (algorithmName == "Bubble") t = timeAlgorithm(bubbleSort, base);
            else if (algorithmName == "Selection") t = timeAlgorithm(selectionSort, base);
            else if (algorithmName == "Insertion") t = timeAlgorithm(insertionSort, base);
            else if (algorithmName == "Merge") t = timeAlgorithm(mergeSort, base);
            else if (algorithmName == "Quick") t = timeAlgorithm(quickSort, base);
            else if (algorithmName == "Shell") t = timeAlgorithm(shellSort, base);

            total += t;

            // write each trial immediately and flush
            outFile << "Trial " << trial << ": " << t << " ms\n";
            outFile.flush();
        }

        double avg = total / 5.0;
        outFile << "Average time: " << avg << " ms\n";
        outFile.flush();

        cout << "[Done] " << algorithmName << " sort for size " << n
             << " (Avg: " << avg << " ms)\n";
    }

    outFile.close();
    cout << "Results for " << algorithmName
         << " saved to " << algorithmName << "_results.txt\n";
}
