#include "two_fer.h"

namespace two_fer {
    
    std::string two_fer(std::string name) {
        std::string result_str{};
        result_str += "One for ";
        result_str += name;
        result_str += ", one for me.";
        return result_str;
    }

}  // namespace two_fer
