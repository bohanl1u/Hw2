#include <iostream>
#include "json.hpp"
#include <fstream>
#include "insertionsort.h"
using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    nlohmann::json newJson;

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
            for (int i = 0; i < n - 1; i++) {
            }
        }
    }
}