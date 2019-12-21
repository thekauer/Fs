#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include <memory>
#include "compiler.h"

/*
template<typename S,typename T>
T match(T* arr,T val) {
    S s;
    return s.movemask(s.cmpeq(s.set(val),s.load( (typename S::msk*)arr)))-1;
}
*/
int main() {
    
    auto compiler = Compiler();
    compiler.compile("main.fs");

    return 0;
}