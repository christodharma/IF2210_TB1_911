#include "StraightFlush.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

StraightFlush :: StraightFlush(InventoryHolder hold,map<string, InventoryHolder> mapcard) : Value(0) {
    int count = 0;
    string m(1, 'M');
    string k(1, 'K');
    string b(1, 'B');
    string h(1, 'H');
    if (mapcard[h].getInventory().size() >= 5) {
        int arr[mapcard[h].getInventory().size()];
        for (int i = 0; i<mapcard[h].getInventory().size(); i++) {
            arr[i] = mapcard[h].getInventory()[i].getAngka();
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        for (int i = 1; i<mapcard[h].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                cout << count << endl;
                if (count >= 4) {
                    this->value = arr[i] * 0.1 + 0.00;
                }
            }
            else {
                count = 0;
            }
        }
    }

    else if (mapcard[b].getInventory().size() >= 5) {
        int arr[mapcard[b].getInventory().size()];
        for (int i = 0; i<mapcard[b].getInventory().size(); i++) {
            arr[i] = mapcard[b].getInventory()[i].getAngka();
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        for (int i = 1; i<mapcard[b].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                cout << count << endl;
                if (count >= 4) {
                    this->value = arr[i] * 0.1 + 0.03;
                }
            }
            else {
                count = 0;
            }
        }
    }

    else if (mapcard[k].getInventory().size() >= 5) {
        int arr[mapcard[k].getInventory().size()];
        for (int i = 0; i<mapcard[k].getInventory().size(); i++) {
            arr[i] = mapcard[k].getInventory()[i].getAngka();
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        for (int i = 1; i<mapcard[k].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                cout << count << endl;
                if (count >= 4) {
                    this->value = arr[i] * 0.1 + 0.06;
                }
            }
            else {
                count = 0;
            }
        }
    }

    else if (mapcard[m].getInventory().size() >= 5) {
        int arr[mapcard[m].getInventory().size()];
        for (int i = 0; i<mapcard[m].getInventory().size(); i++) {
            arr[i] = mapcard[m].getInventory()[i].getAngka();
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        for (int i = 1; i<mapcard[m].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                cout << count << endl;
                if (count >= 4) {
                    this->value = arr[i] * 0.1 + 0.09;
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