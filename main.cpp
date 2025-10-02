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
    int choice;

    do {
        cout << "\n===== Sorting Benchmark Menu =====\n";
        cout << "--- Base Data ---\n";
        cout << " 1. Bubble Sort\n";
        cout << " 2. Selection Sort\n";
        cout << " 3. Insertion Sort\n";
        cout << " 4. Merge Sort\n";
        cout << " 5. Quick Sort\n";
        cout << " 6. Shell Sort\n";
        cout << " 7. Run ALL (base data)\n";

        cout << "--- Sorted Data ---\n";
        cout << " 8. Bubble Sort\n";
        cout << " 9. Selection Sort\n";
        cout << "10. Insertion Sort\n";
        cout << "11. Merge Sort\n";
        cout << "12. Quick Sort\n";
        cout << "13. Shell Sort\n";
        cout << "14. Run ALL (sorted data)\n";

        cout << "--- Reversed Data ---\n";
        cout << "15. Bubble Sort\n";
        cout << "16. Selection Sort\n";
        cout << "17. Insertion Sort\n";
        cout << "18. Merge Sort\n";
        cout << "19. Quick Sort\n";
        cout << "20. Shell Sort\n";
        cout << "21. Run ALL (reversed data)\n";

        cout << "0. Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            // base data
            case 1: bm.runSingleAlgorithm("Bubble", "data_"); break;
            case 2: bm.runSingleAlgorithm("Selection", "data_"); break;
            case 3: bm.runSingleAlgorithm("Insertion", "data_"); break;
            case 4: bm.runSingleAlgorithm("Merge", "data_"); break;
            case 5: bm.runSingleAlgorithm("Quick", "data_"); break;
            case 6: bm.runSingleAlgorithm("Shell", "data_"); break;
            case 7: bm.run("data_"); break; // run all base

            // sorted data
            case 8:  bm.runSingleAlgorithm("Bubble", "data_sorted_"); break;
            case 9:  bm.runSingleAlgorithm("Selection", "data_sorted_"); break;
            case 10: bm.runSingleAlgorithm("Insertion", "data_sorted_"); break;
            case 11: bm.runSingleAlgorithm("Merge", "data_sorted_"); break;
            case 12: bm.runSingleAlgorithm("Quick", "data_sorted_"); break;
            case 13: bm.runSingleAlgorithm("Shell", "data_sorted_"); break;
            case 14: bm.run("data_sorted_"); break; // run all sorted

            // reversed data
            case 15: bm.runSingleAlgorithm("Bubble", "data_rev_"); break;
            case 16: bm.runSingleAlgorithm("Selection", "data_rev_"); break;
            case 17: bm.runSingleAlgorithm("Insertion", "data_rev_"); break;
            case 18: bm.runSingleAlgorithm("Merge", "data_rev_"); break;
            case 19: bm.runSingleAlgorithm("Quick", "data_rev_"); break;
            case 20: bm.runSingleAlgorithm("Shell", "data_rev_"); break;
            case 21: bm.run("data_rev_"); break; // run all reversed

            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}