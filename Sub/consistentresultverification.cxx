#include <iostream>
#include "json.hpp"
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream file1, file2;
    file1.open(argv[1]);
    file2.open(argv[2]);
    nlohmann::json jsonObject1, jsonObject2;
    nlohmann::json newJson;
    int count = 0;
    bool mismatch = false;

    if (!file1.is_open() || !file2.is_open()){
        return 1;
    }

    file1 >> jsonObject1;
    file2 >> jsonObject2;
    int n = jsonObject1["metadata"]["arraySize"];
    nlohmann::json jsonMeta1 = jsonObject1["metadata"];
    nlohmann::json jsonMeta2 = jsonObject2["metadata"];
    for (auto itr = jsonObject1.begin(); itr != jsonObject1.end(); ++itr){
        auto key = itr.key();
        nlohmann::json array1 = jsonObject1[key];
        nlohmann::json array2 = jsonObject2[key];
        if (key=="metadata"){
            continue;
        }
        else{
            nlohmann::json jsonMismatch;
            for(int i=0; i<n; i++){
                if (array1[i]!=array2[i]){
                    mismatch = true;
                    jsonMismatch[to_string(i)] = {array1[i], array2[i]};
                }
            }
            if (mismatch){
                newJson[key][argv[2]] = array2;
                newJson[key]["Mismatches"] = jsonMismatch;
                newJson[key][argv[1]] = array1;
                count++;
                mismatch = false;
            }
        }
    }
    newJson["metadata"]["File1"] = jsonMeta1;
    newJson["metadata"]["File1"]["name"] = argv[1];
    newJson["metadata"]["File2"] = jsonMeta2;
    newJson["metadata"]["File2"]["name"] = argv[2];
    newJson["metadata"]["samplesWithConflictingResults"] = count;
    cout << newJson.dump(2);
    return 0;
}