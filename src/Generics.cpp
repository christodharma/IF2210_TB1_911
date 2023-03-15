#include "Generics.hpp"

template<class T>
T findMax(T a, T b){
    return (a>b)?a:b;
};
template<class T>
T findMax(T* a, int size_a){
    T max = a[0];
    for (int i = 1; i < size_a; i++)
    {
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
};
template <class T>
T findMax(const std::vector<T>& vec) {
    T max = vec[0];
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    return max;
}
template <class T>
void ShuffleT(std::vector<T>& c) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(c.begin(), c.end(), std::default_random_engine(seed));
}
// template <>
// void ShuffleT(std::vector<std::__cxx11::basic_string<char>>& c) {
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//     std::shuffle(c.begin(), c.end(), std::default_random_engine(seed));
// }