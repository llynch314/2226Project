#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

class Dataset {
private:
    vector<int> sizes = {50000, 100000, 150000, 300000, 450000, 600000};

    void writeToFile(const string& filename, const vector<int>& data);

public:
    void generateDatasets();
    vector<int> loadDataset(const string& filename);
};

#endif // DATASET_H
