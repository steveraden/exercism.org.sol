#include "atbash_cipher.h"
#include <iostream>
#include <algorithm>
#include <cctype>

namespace atbash_cipher {
    std::string plain_alphabet {"abcdefghijklmnopqrstuvwxyz"};
    std::string cipher_alphabet{"zyxwvutsrqponmlkjihgfedcba"};

    std::string encode(std::string original_text){
        std::string plain_text{normalize(original_text)};
        std::string encrypted{""};
        size_t space_counter{1};
        for (size_t i{0}; i < plain_text.size(); i++ ) {
            char c = plain_text[i];
            if (std::isdigit(c)){
                encrypted += c;
            } else {
                size_t indexer = plain_alphabet.find(std::tolower(c));
                if (indexer != std::string::npos) {
                    encrypted += cipher_alphabet[indexer];
                }
            }
            // establish a break for every 5 characters by zero index
            if ((i == (5*space_counter) - 1) 
                // omit break on last charachter
                && (i != plain_text.size()-1))
            {
                encrypted += " ";
                space_counter = space_counter +1;
            }
        }
        return encrypted;
    }

    std::string decode(std::string cipher_text) {
        std::string decrypted{""};
        //size_t space_counter{1};
        for (size_t i{0}; i < cipher_text.size(); i++ ) {
            char c = cipher_text[i];
            if (std::isdigit(c)){
                decrypted += c;
            } else {
                size_t indexer = cipher_alphabet.find(std::tolower(c));
                if (indexer != std::string::npos) {
                    decrypted +=  plain_alphabet[indexer];
                }
            }
        }
        return decrypted;
    }

    std::string normalize(std::string str) {
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) {
                    return std::ispunct(c) || std::isspace(c);
                    }), str.end());
        return str;
    }
}  // namespace atbash_cipher
