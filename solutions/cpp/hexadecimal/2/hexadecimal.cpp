#include "hexadecimal.h"
#include <string>
#include <iostream>

namespace hexadecimal {

    bool is_symbol_in_string(char c, std::string valid_symbols) {
        bool some_char_matched;
        for (char s : valid_symbols) {
            if (std::toupper(c)  == s) {
                some_char_matched = true;
            } 
        }
        return some_char_matched;
    }

    bool is_valid_hex_symbol(char c) {
        return is_symbol_in_string(c , "0123456789ABCDEF");
    }

    bool is_valid_decimal_symbol(char c) {
        return is_symbol_in_string(c , "0123456789");
    }


    int convert(std::string number_str){
        int acc{0};
        for (char c :  number_str) {
            if (is_valid_hex_symbol(c)) {
                if (is_valid_decimal_symbol(c)) {
                    acc = (acc * 16) + (c - '0');
                } else {
                    acc = (acc * 16) + (std::toupper(c) - 'A' + 10 );
                }
            } else {
                acc  = 0;
            }
        }
        return acc;
    }
}  // namespace hexadecimal
