#ifndef __GENERICS_HPP__
#define __GENERICS_HPP__

#include <vector>
#include <algorithm> // std::shuffle
#include <random> // std::default_random_engine untuk shuffling
#include <chrono> // std::chrono::system_clock untuk seed dalam proses random
// #include "Card.hpp"
#include <string>
using namespace std;

template<class T>
T findMax(T a, T b);
template<class T>
T findMax(T* a, int size_a);
template <typename T>
T findMax(const std::vector<T>& vec);
template <class T>
void ShuffleT(std::vector<T>& c);
template <>
void ShuffleT(std::vector<std::string>& c);

#endif