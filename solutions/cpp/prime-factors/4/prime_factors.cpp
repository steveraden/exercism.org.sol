#include "prime_factors.h"
#include <cstdlib>

namespace prime_factors {

    std::vector<bignum> of(bignum num) {
        std::vector<bignum> factors{};
        bignum quotient{num};
    // cheapen algorithm by eliminating even numbers
    // https://cp-algorithms.com/algebra/factorization.htmlhttps://cp-algorithms.com/algebra/factorization.html
        while (quotient % 2 == 0) {
            factors.push_back(2);
            quotient /= 2;
        }
        // up into square root up num
        for (bignum x = 3; x * x <= num; x++) {
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



