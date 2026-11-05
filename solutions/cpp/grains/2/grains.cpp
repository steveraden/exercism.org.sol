#include "grains.h"
#include <exception>
#include <iostream>

namespace grains {

    unsigned long long pow(int base, unsigned int exp) {
        unsigned long long result = 1;
        for (unsigned int i = 0; i < exp; ++i) {
            result *= base;
        }
        return result;
    }
    unsigned long long square(int x){
        return pow(2, (x-1));
    }

    unsigned long long total(){
        auto result =  pow(2, 64) - 1;
        return result;
    }
}  // namespace grains
