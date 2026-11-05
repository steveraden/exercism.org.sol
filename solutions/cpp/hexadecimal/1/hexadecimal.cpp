#include "hexadecimal.h"
#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>

namespace hexadecimal {
    const  std::string hex_chars  = "0123456789ABCDEF";
    const  std::string hex_prefix = "0x";

    bool is_string_a_number(const std::string &str){
        if (str.empty()) return false;
        return std::all_of(str.begin(), str.end(), [](unsigned char c) {
            return std::isdigit(c);
            });
    }
    
    bool is_string_a_hexadecimal(const std::string &str) {
        
        if (str.empty()) return false;
        bool some_char_matched{false};
        bool saw_non_hex{false};
        for (char c : str){
            for (char h : hex_chars) {
                if (std::toupper(c)  == h) {
                    some_char_matched = true;
                }
                if (c != str.back()){
                    some_char_matched = false;
                }
            }
            if (! some_char_matched) {
                saw_non_hex = true;
            }
        } 
       return !saw_non_hex; 
    }

    std::string convert_decimal(const std::string &number_str) {
        try {
            int decimal = std::stoi(number_str);
            std::string hex_digits{""};
            int remainder{decimal};
            while (remainder !=0){
                remainder = remainder  % 16;
                hex_digits = hex_chars[remainder] + hex_digits;
                remainder = remainder / 16;
            }
            return hex_digits;
        } catch (const std::exception& e) {
            return "-1";
        }
    }

    int convert(const std::string number_str){
        try {
            
            std::string hex_string{}; 
            if (is_string_a_hexadecimal(number_str)) {
                hex_string = number_str;
            } else if (is_string_a_number(number_str)){
                hex_string = convert_decimal(number_str);
            } else {
                hex_string =  '0';
            }
            return std::stoi(hex_prefix+hex_string, nullptr, 16);
        } catch (const std::exception& e) { 
            return -1; 
        } 
    }

}  // namespace hexadecimal

/*
std::cout << "sebastian  " << hex_prefix+number_str << std::endl; stod::cout << "sebastian  " << hex_prefix+number_str << std::endl; *

 * /
 */
