#include "pangram.h"
#include <cctype>
#include <bitset>
#include <string>

namespace pangram {
        
    // shift the ASCII code of an alpha character to a zero-index
    unsigned char normalize_char(unsigned char ch){
        char highC = std::toupper(ch);
        return (highC - 'A') % 26;
    }


    bool is_pangram(std::string phrase) {
        std::bitset<26> occurences;
        for (char c : phrase) {
           auto ch = static_cast<unsigned char>(c);
           if (std::isalpha(ch)) {
                occurences.set(normalize_char(ch));
            }
            // passover punctionation of any kind
        }
        return occurences.all(); 
    }

}  // namespace pangram
