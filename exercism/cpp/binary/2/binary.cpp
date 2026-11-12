#include "binary.h"
#include <cmath>
#include <iostream>

namespace binary {

    int pow_2(int exp){
        int accum{1};
        for(int i{1}; i <= exp; ++i){
            accum *= 2;
        }
        return accum;
    }
    
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
                std::cout << exp<< " : "  << pow_2(exp) << std::endl;
                result += pow_2(exp);  
            }
        }
        std::cout << result << std::endl;
        return result;
    }

}  // namespace binary
