#include "luhn.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

namespace luhn {
    std::string trim(std::string str) {
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) {
                    return std::isspace(c);
                    }), str.end());
        return str;
    }

    bool all_digits(std::string str){
        for (char c: str){
            if (!std::isdigit(c)){
                return false;
            }
        }
        return true;
    }

    std::string reverse(std::string str) {
        std::string reversed {""};
        for (size_t i{str.size()}; i > 0; --i) {
            reversed += str.at(i-1);
        }
        return reversed;
    } 

    bool valid(std::string data){
        auto str = trim(data);
        if (str.size() < 2)  return false;
        if (!all_digits(str)) return false;

        std::string reversed{reverse(str)};

        int acc{0};
        int digit{0};
        int mutated_even{0};
        for(size_t i{0}; i < reversed.size(); ++i) {
            digit = reversed.at(i) -'0';
            if (i % 2 == 0) {
                acc += digit; 
            } else  {
                mutated_even = 2 * digit;
                if (mutated_even > 9) {
                    mutated_even = mutated_even - 9;
                } 
                acc += mutated_even;
            }
        }
        return (acc % 10 == 0);
    }

}  // namespace luhn
