#include "trinary.h"
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <boost/core/demangle.hpp>
#include <cmath>
namespace trinary {

    int power(int base, int exponent) {
        if (base == 0) return 1;
        int result{1};
        for (int i{1}; i <= exponent; ++i) {
           result *= base;
        }
        return result;
    }

    bool is_trigit(char c) { 
        return (c == '0' || c == '1' || c == '2');
    }

    int to_decimal(std::string tri_str) {
        int decimal{0};
        int exponent = static_cast<int>(tri_str.size()-1);
        for (size_t i{0}; i <  tri_str.size(); ++i) {
            char glyph = tri_str.at(i);
            if (!is_trigit(glyph)) return 0;
            int trigit = glyph - '0';
            int digit = trigit * power(3, exponent);
            decimal += digit;
            --exponent;
        }
        return decimal;
    }
}
