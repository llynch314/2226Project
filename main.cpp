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

    while (true) {
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
        cout << "Enter your choice:";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        //Base data
        if (choice >= 1 && choice <= 6) {
            static const string algos[] = {"Bubble", "Selection", "Insertion", "Merge", "Quick", "Shell"};
            bm.runSingleAlgorithm(algos[choice-1], "base");
        } else if (choice == 7) {
            bm.run("base");
        }
        //Sorted data
        else if (choice >= 8 && choice <= 13) {
            static const string algos[] = {"Bubble", "Selection", "Insertion", "Merge", "Quick", "Shell"};
            bm.runSingleAlgorithm(algos[choice-8], "sorted");
        } else if (choice == 14) {
            bm.run("sorted");
        }
        //Reversed data
        else if (choice >= 15 && choice <= 20) {
            static const string algos[] = {"Bubble", "Selection", "Insertion", "Merge", "Quick", "Shell"};
            bm.runSingleAlgorithm(algos[choice-15], "reversed");
        } else if (choice == 21) {
            bm.run("reversed");
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}