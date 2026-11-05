#include "armstrong_numbers.h"
#include <string>
#include <cstdlib>

namespace armstrong_numbers {
    int count_digits(int num) {
        int counter{0};
        while(num > 0) {
            num = num/10;
            ++counter;
        }    
        return counter;
    }

    int power(int base, int exponent){
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }
    bool is_armstrong_number(int original_num) {
        int sum_of_raised_digits{0};
	int num{original_num};
        int digits_length = count_digits(num);

        for(int i{0}; i < digits_length; ++i) {
	    // num % 10 obtains the digit as remainder
	    // integer division by 10 will remove the last digit
	    auto [n, digit] = std::div(num,10);
	    num = n;
            sum_of_raised_digits += power(digit, digits_length);     
        }
        return original_num == sum_of_raised_digits;
    }
}  // namespace armstrong_numbers


