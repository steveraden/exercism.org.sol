#include "prime_factors.h"
#include <cstdlib>
#include <iostream>

//#include <algorithm>

namespace prime_factors {
    
    std::vector<bignum> of(bignum num) {
        std::vector<bignum> factors{};
        bignum quotient{num};

        // up into square root up num
        for (bignum x = 2; x * x <= num; x++) {
            // x divides num, add the term as a factor and keep dividing
            while (quotient % x == 0) {
                factors.push_back(x);
                quotient /= x;
            }
        }
        if (quotient > 1) {
            factors.push_back(quotient);
        }
        return factors;
    } 
}// namespace prime_factor

