#include "grains.h"
#include "cmath"
#include <exception>
#include <iostream>

namespace grains {

	unsigned long long square(int x){
       return pow(2, (x-1));
	}

    unsigned long long total(){
        auto result =  pow(2, 64) - 1;
        return result;
    }
}  // namespace grains
