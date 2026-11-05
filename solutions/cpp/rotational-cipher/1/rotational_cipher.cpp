#include "rotational_cipher.h"
namespace rotational_cipher {

// TODO: add your solution here
std::string  rotate(std::string plain_text, int x){
    // force shift to be within Latin alphabet range
    x = x % 26; 
    
    for (char &c : plain_text) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + x) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + x) % 26;
        }
    }
    return plain_text;
}

}  // namespace rotational_cipher
