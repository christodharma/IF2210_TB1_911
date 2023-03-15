#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <iostream>

using namespace std;

class Exception {
    public:
        virtual void what() = 0;
};

class IndexOutOfRangeException : public Exception {
    private:
        int index;
    public:
        IndexOutOfRangeException(int index){
            this->index = index;
        }
        void what(){
            cout << this->index << " berada di luar jangkauan" << endl;
        }
};

class DoubleCardException : public Exception {
    private:
        char warna;
        int angka;
    public:
        DoubleCardException(char warna, int angka){
            this->warna = warna;
            this->angka = angka;
        } 
        void what(){
            cout << "Gagal karena terdapat 2 kartu dengan angka " << this->angka << " dan warna " << this->warna << " yang sama";
        }
};

class AbnormalCardException : public Exception {
    private:
        char warna;
        int angka;
    public:
        AbnormalCardException(char warna, int angka){
            this->warna = warna;
            this->angka = angka;
        }
        void what(){
            cout << "Gagal karena tidak ada kartu dengan angka " << this->angka << " dan warna " << this->warna << " yang sesuai";
        }
};

class InventoryHolderException : public Exception {
    public:
        InventoryHolderException(){}
        void what(){
            cout << "Inventory Holder tidak dapat diakes secara langsung!" << endl;
        }
    
};

// class FalseAction : public Exceptio

#endif