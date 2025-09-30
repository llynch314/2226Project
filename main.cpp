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
    cout << "Choose which benchmark to run:\n";
    cout << "1. Bubble\n";
    cout << "2. Selection\n";
    cout << "3. Insertion\n";
    cout << "4. Merge\n";
    cout << "5. Quick\n";
    cout << "6. Shell\n";
    cout << "7. Run all\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: bm.runSingleAlgorithm("Bubble"); break;
        case 2: bm.runSingleAlgorithm("Selection"); break;
        case 3: bm.runSingleAlgorithm("Insertion"); break;
        case 4: bm.runSingleAlgorithm("Merge"); break;
        case 5: bm.runSingleAlgorithm("Quick"); break;
        case 6: bm.runSingleAlgorithm("Shell"); break;
        case 7: bm.run(); break;
        default: cout << "Invalid choice.\n"; break;
    }

    cout << "Benchmark(s) complete. Check *_results.txt files.\n";
    return 0;
}