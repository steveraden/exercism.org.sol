#include "atbash_cipher.h"
#include <iostream>
#include <algorithm>
#include <cctype>

namespace atbash_cipher {
    std::string encode(std::string original_text){
        std::string plain_text{normalize(original_text)};
        std::string plain_alphabet {"abcdefghijklmnopqrstuvwxyz"};
        std::string cipher_alphabet{"zyxwvutsrqponmlkjihgfedcba"};

        std::string encrypted{""};

        for (size_t i{0}; i < plain_text.size(); i++ ) {
            char c = plain_text[i];
            if (std::isdigit(c)){
                encrypted += c;
            } else {
                char indexer = plain_alphabet.find(std::tolower(c));
                char ciphered = cipher_alphabet[indexer];
                encrypted += ciphered;
            }

            if (i % 5 == 0 && i > 0) {
                encrypted += " ";
            }
        }
        return encrypted;
    }

    std::string decode(std::string cipher_text) {
        return cipher_text;    
    }

    std::string normalize(std::string str) {
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) {
                    return std::ispunct(c) || std::isspace(c);
                    }), str.end());
        return str;
    }

}  // namespace atbash_cipher
