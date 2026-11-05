#include "armstrong_numbers.h"
#include <string>
#include <cmath>
#include <iostream>

namespace armstrong_numbers {

    int count_digits(int num) {
        int counter{0};
        while(num > 0) {
            num = std::floor(num/10);
            ++counter;
        }    
        return counter;
    }

    int get_digit(int num) {
        while (num > 10) {
//std::cout << "Declining Num" << num <<  "\n";
            num = num/10;
        }
        return num;
    }

    int power(int base, int exponent){
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
// std::cout << "Base" << base <<  "\n";
// std::cout << "Exponent" << exponent <<  "\n";
// std::cout << "Power" << result <<  "\n";
        return result;
    }


    bool is_armstrong_number(int num) {
        int digits_length = count_digits(num);
        int sum_of_raised_digits{0};
        int sum_of_digits{0};
        int digit{0};
        for(int i{digits_length}; i > 0; --i) {
            digit = get_digit(num);
std::cout << "Digit base expon: res" << digit << ", " << i << " " << power(digit, i-1) << "\n";

            sum_of_raised_digits += power(digit, i-1);     
            sum_of_digits += digit;
            
std::cout << "sum_of_raised_digit: " << sum_of_raised_digits ;
std::cout << "sum_of_digits: " << sum_of_digits << "\n";
//std::cout << "num : substractor: exp " << num << " , " << i << ", " << digit * power(10, i) <<  "\n";
            num -= digit * power(10, i);
        }

std::cout << "Digits Length" << digits_length << "\n";
std::cout << "Sum of Digits " << sum_of_digits << "\n";
std::cout << "Sum of Raised Digits " << sum_of_raised_digits << "\n";
        return sum_of_digits == sum_of_raised_digits;
    }
}  // namespace armstrong_numbers


