#include <iostream>
#include "json.hpp"
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    nlohmann::json newJson;
    int count = 0;
    bool invFound = false;

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
        else{
            nlohmann::json jsonInv;
            for(int i=0; i<n-1; i++){
                if (array[i]>array[i+1]){
                    invFound = true;
                    jsonInv[to_string(i)] = {array[i], array[i+1]};
                }
            }
            if (invFound){
                newJson[key]["ConsecutiveInversions"] = jsonInv;
                newJson[key]["sample"] = array;
                count++;
                invFound = false;
            }
        }
    }
    newJson["metadata"] = jsonMeta;
    newJson["metadata"]["file"] = argv[1];
    newJson["metadata"]["samplesWithInversions"] = count;
    cout << newJson.dump(2);
    return 0;
}