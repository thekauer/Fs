#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include <memory>
#include "get_highest_simd.hpp"
#include "simd.h"


template<typename S,typename T>
T match(T* arr,T val) {
    S s;
    return s.movemask(s.cmpeq(s.set(val),s.load( (typename S::msk*)arr)))-1;
}

int main() {

    //std::cout << get_highest_supported_simd();

    unsigned char arr[32];
    for(int i=0;i<32;i++) {
        arr[i]=i;
    }
    auto res = match<SSE2,unsigned char>(arr,0);
    std::cout << (int)res;
    
    return 0;
}