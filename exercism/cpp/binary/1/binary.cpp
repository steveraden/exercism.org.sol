#include "binary.h"
#include <cmath>
#include <iostream>

namespace binary {

    /*int pow_2(int digit, int place){
        int accum{1};
        for(int i{0}; i <= place; ++i){
            accum *= 2 * digit;
        }
        return accum;
    }*/
    
    int convert(std::string binCode)
    {
        int result{0};
        int digit{0};
        size_t bitLength = binCode.length();
        for (size_t exp{0}, i{bitLength}; i > 0; --i, ++exp)       
        {
            digit = binCode.at(i-1) - '0';
            if (digit != 1 && digit != 0) return 0;
            if (digit == 1 ) {
                std::cout << exp<< " : "  << std::pow(2, exp) << std::endl;
                result += std::pow(2, exp);  
            }
        }
        std::cout << result << std::endl;
        return result;
    }

}  // namespace binary
