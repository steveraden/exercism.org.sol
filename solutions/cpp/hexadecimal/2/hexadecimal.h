#pragma once
#include <string>
namespace hexadecimal {

   bool is_valid_hex_symbol(char c);
   bool is_valid_decimal_symbol(char c);
   bool is_symbol_in_string(char);
   int convert(std::string number_string);

}  // namespace hexadecimal
