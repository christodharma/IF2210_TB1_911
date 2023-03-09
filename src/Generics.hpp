#ifndef __GENERICS_HPP__
#define __GENERICS_HPP__

#include <vector>

template<class T>
T max(T a, T b){
    return (a>b)?a:b;
};
template<class T>
T max(T* a, int size_a){
    T max = a[0];
    for (int i = 1; i < size_a; i++)
    {
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
};
template<class T>
T max(vector<T> a){
    T max = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
};

#endif