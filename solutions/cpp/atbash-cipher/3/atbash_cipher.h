#pragma once
#include <string>

namespace atbash_cipher {
    std::string encode(std::string plain_text);
    std::string decode(std::string cipher_text);
    std::string normalize(std::string original_text);
}  // namespace atbash_cipher
