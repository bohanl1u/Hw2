#include <iostream>
#include "json.hpp"
#include <fstream>
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include <vector>
#include <chrono>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    chrono::high_resolution_clock::time_point start;
    nlohmann::json jsonObject;
    nlohmann::json newJson;
    string csv = "Sample,InsertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess\n";

    if (!file.is_open()){
        return 1;
    }

    file >> jsonObject;
    int n = jsonObject["metadata"]["arraySize"];
    nlohmann::json jsonMeta = jsonObject["metadata"];

    for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){
        auto key = itr.key();
        nlohmann::json array = jsonObject[key];
        if (key=="metadata"){
            continue;
        }
        else {
            csv += key + ",";
            int ICompares=0, IMemAccesses=0, MCompares=0, MMemAccesses=0, QCompares=0, QMemAccesses=0;
            vector<int> tempVec;
            for (int i = 0; i < n - 1; i++) {
                tempVec.push_back(array[i]);
            }
            start = chrono::high_resolution_clock::now();
            InsertionSort(&tempVec, ICompares, IMemAccesses);
            auto end = chrono::high_resolution_clock::now();
            double elapsed = chrono::duration<double, micro>(end - start).count();
            csv += to_string(elapsed) + ",";
            csv += to_string(ICompares) + ",";
            csv += to_string(IMemAccesses) + ",";

            start = chrono::high_resolution_clock::now();
            MergeSort(&tempVec, MCompares, MMemAccesses);
            end = chrono::high_resolution_clock::now();
            elapsed = chrono::duration<double, micro>(end - start).count();
            csv += to_string(elapsed) + ",";
            csv += to_string(MCompares) + ",";
            csv += to_string(MMemAccesses) + ",";

            start = chrono::high_resolution_clock::now();
            QuickSort(&tempVec, QCompares, QMemAccesses);
            end = chrono::high_resolution_clock::now();
            elapsed = chrono::duration<double, micro>(end - start).count();
            csv += to_string(elapsed) + ",";
            csv += to_string(QCompares) + ",";
            csv += to_string(QMemAccesses);

            csv += "\n";
        }
    }

    cout<< csv;

}