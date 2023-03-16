#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <iostream>
#include <filesystem>
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

class ActionException : public Exception {
    public:
        ActionException(){}
        void what(){
            cout << "Action invalid! Silakan masukkan lagi." << endl;
        }
};

class UndetectedFile : public Exception {
    public:
        UndetectedFile(){}
        void what(){
            cout << "File tidak terdeteksi. Silakan masukkan input lagi: " << endl;
        }
};

class FalseFileType : public Exception {
    public:
        FalseFileType(){}
        void what(){
            cout << "File yang dimasukkan bukan file .txt" << endl;
        }
};

class EmptyFile : public Exception {
    public:
        EmptyFile(){}
        void what(){
            cout << "File yang dimasukkan kosong" << endl;
        }
};

class NotEnoughCard : public Exception {
    public:
        NotEnoughCard(){}
        void what(){
            cout << "File tidak berisi kartu berjumlah 52 warna dan angka" << endl;
        }
};


// class FalseAction : public Exceptio

#endif