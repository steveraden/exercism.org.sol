#include "isbn_verifier.h"
#include <string>
#include <array>
#include <cctype>
#include <numeric>

namespace isbn_verifier {
    
    std::string normalize_code(std::string code) {
        std::string result{""};
        for (char c: code){
            if (c != '-') result +=c;
        }
        return result;
    }
   
    bool is_valid(std::string code)
    {   
        std::array<int, 10> result{};
        code = normalize_code(code);
        size_t code_len = code.size();
        
        if (code_len != 10) return false;
        
        for (size_t i{0},  offset{10}; 
                i < code_len; 
                ++i, --offset)
        {
            char c = code.at(i);
            int val{0};
            if (std::isdigit(c)) {
                val = c - '0'; // ASCII ordinal decode 
            } else {
                if (offset == 1 && c == 'X') {
                    val = 10;
                } else {
                    // not the check digit, therefore bunk
                    return false;
                }
            }
            result.at(i) = val * offset;
        }
        
        int checksum = std::accumulate(result.begin(),result.end(), 0);
        if (checksum % 11 == 0 ) {
            return true;
        } else {
            return false;
        }
    }

}  // namespace isbn_verifier
