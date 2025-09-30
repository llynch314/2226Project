#include "dataset.h"
#include "dataset.cpp"
#include "benchmark.h"
#include "benchmark.cpp"
#include "sorts.h"
#include "sorts.cpp"
#include <iostream>
using namespace std;


int main() {
    Benchmark bm;

    while (true) {
        cout << "\nSorting Algorithms Project Menu\n";
        cout << "1. Generate datasets\n";
        cout << "2. Run Bubble Sort benchmark\n";
        cout << "3. Run Selection Sort benchmark\n";
        cout << "4. Run Insertion Sort benchmark\n";
        cout << "5. Run Merge Sort benchmark\n";
        cout << "6. Run Quick Sort benchmark\n";
        cout << "7. Run Shell Sort benchmark\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) generateDatasets();
        else if (choice >= 2 && choice <= 7) {
            string algorithm;
            switch (choice) {
                case 2: algorithm = "Bubble"; break;
                case 3: algorithm = "Selection"; break;
                case 4: algorithm = "Insertion"; break;
                case 5: algorithm = "Merge"; break;
                case 6: algorithm = "Quick"; break;
                case 7: algorithm = "Shell"; break;
            }
            bm.runSingleAlgorithm(algorithm);
        } else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Program exited.\n";
    return 0;
}
