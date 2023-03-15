#include "StraightFlush.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

StraightFlush :: StraightFlush(InventoryHolder hold,map<string, InventoryHolder> mapcard) : Value(0) {
    int count = 0;
    if (mapcard["H"].getInventory().size() >= 5) {
        vector<int> arr;
        for (int i = 0; i<mapcard["H"].getInventory().size(); i++) {
            arr.push_back(mapcard["H"].getInventory()[i].getAngka());
        }
        sort(arr.begin(), arr.end()); 

        for (int i = 1; i<mapcard["H"].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                if (count >= 4) {
                    this->value = arr[i] * 0.1 + 0.00 + 23.68;
                }
            }
            else {
                count = 0;
            }
        }
    }

    else if (mapcard["B"].getInventory().size() >= 5) {
        vector<int> arr;
        for (int i = 0; i<mapcard["B"].getInventory().size(); i++) {
            arr.push_back(mapcard["B"].getInventory()[i].getAngka());
        }
        sort(arr.begin(), arr.end());

        for (int i = 1; i<mapcard["B"].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                if (count >= 4) {
                    this->value = arr[i] * 0.1 + 0.03 + 23.68;
                }
            }
            else {
                count = 0;
            }
        }
    }

    else if (mapcard["K"].getInventory().size() >= 5) {
        vector<int> arr;
        for (int i = 0; i<mapcard["K"].getInventory().size(); i++) {
            arr.push_back(mapcard["K"].getInventory()[i].getAngka());
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr.begin(), arr.end());

        for (int i = 1; i<mapcard["K"].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                if (count >= 4) {
                    this->value = arr[i] * 0.1 + 0.06 + 23.68;
                }
            }
            else {
                count = 0;
            }
        }
    }

    else if (mapcard["M"].getInventory().size() >= 5) {
        vector<int> arr;
        for (int i = 0; i<mapcard["M"].getInventory().size(); i++) {
            arr.push_back(mapcard["M"].getInventory()[i].getAngka());
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr.begin(), arr.end());

        for (int i = 1; i<mapcard["M"].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                if (count >= 4) {
                    this->value = arr[i] * 0.1 + 0.09 + 23.68;
                }
            }
            else {
                count = 0;
            }
        }
    }


}

StraightFlush :: ~StraightFlush() {
}