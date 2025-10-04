#include "dataset.h"
#include <fstream>
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

void Dataset::writeToFile(const string& filename, const vector<int>& data) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Error: Could not open file " << filename << "\n";
        return;
    }
    for (int num : data) {
        out << num << " ";
    }
    out.close();
}

void Dataset::generateDatasets() {
    srand(static_cast<unsigned>(time(0)));

    for (int n : sizes) {
        vector<int> pool(4'000'000);
        for (int i = 0; i < 4'000'000; ++i)
            pool[i] = i + 1;

        for (int i = pool.size() - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(pool[i], pool[j]);
        }

        vector<int> data(pool.begin(), pool.begin() + n);
        writeToFile("data_" + to_string(n) + ".txt", data);

        vector<int> sortedData = data;
        sort(sortedData.begin(), sortedData.end());
        writeToFile("data_sorted_" + to_string(n) + ".txt", sortedData);

        vector<int> revData = sortedData;
        reverse(revData.begin(), revData.end());
        writeToFile("data_rev_" + to_string(n) + ".txt", revData);

        cout << "Generated datasets for size " << n << "\n";
    }
}


vector<int> Dataset::loadDataset(const string& filename) {
    ifstream in(filename);
    vector<int> data;
    int num;
    while (in >> num) {
        data.push_back(num);
    }
    return data;
}
