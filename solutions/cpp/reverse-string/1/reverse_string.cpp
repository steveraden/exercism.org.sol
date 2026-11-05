#include "reverse_string.h"
#include <iostream>
namespace reverse_string {

  std::string reverse_string(const std::string& str){
    if (str.empty()) return "";
    std::string reversed = "";    
    for (long long i = str.size() - 1; i >= 0; i--) {
        reversed += str[i]; 
    }   
    return reversed;
 }

}  // namespace reverse_string
