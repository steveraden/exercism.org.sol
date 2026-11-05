#pragma once
#include <string>
namespace hexadecimal {

   bool is_string_a_number(const std::string &str);
   bool is_string_a_hexadecimal(const std::string &str);
   std::string convert_decimal(std::string &number_str);
   int convert(std::string number_string);

}  // namespace hexadecimal
