#include "hamming.h"
#include <string>
#include <exception>
#include <stdexcept>

namespace hamming {

    int compute(std::string code1, std::string code2){
        size_t first_size = code1.size();
        size_t second_size = code2.size();
        int distance{0};
        if (first_size == second_size) {
            for (size_t i{0}; i < first_size; ++i) {
               if (code1[i] != code2[i]) {
                    ++distance;
                }
            }
            return distance;
        } else {
            throw std::domain_error("length of codes much match");
        }
    }
}  // namespace hamming
