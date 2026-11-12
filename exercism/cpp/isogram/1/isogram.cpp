#include "isogram.h"
#include <string>
#include <array>
#include <cctype>
#include <iostream>

namespace isogram {
    
    bool is_isogram(std::string word) {
        if (word.empty()) return true;
        std::string letters{"abcdefghijklmnoqprstuvwxyz"};
        std::array<bool, 26> seenChars{false};
        for (size_t i{0}; i < word.size(); ++i) {
            const char &c = word[i];
            if (std::isalpha(c)) {
                size_t ordinal = std::tolower(c) - 'a';
                if (seenChars[ordinal]) { 
                    return false;
                }
                seenChars.at(ordinal) = true;
            }
        }
        return true;
    }
}  // namespace isogram
