#include "../../src/Exception.hpp"
#include <string>

const string test = "inventoryc";

int main() {
  try {
    int n = 8;
    if (n >= 7) {
      throw new IndexOutOfRangeException(n);
    }
    char warna = 'H';
    int angka = 2;
    if (warna != 'M' || angka >= 14) {
      throw new DoubleCardException(warna, angka);
    }
    if (test == "abnormal"){
        throw new AbnormalCardException('U', 90);
    }
    if (test == "inventory"){
        throw new InventoryHolderException();
    }
    cout << "aman shay!" << endl;
  } catch (Exception* e) {
    e->what();
  }
  return 0;
}