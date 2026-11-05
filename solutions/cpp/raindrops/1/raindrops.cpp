#include "raindrops.h"

namespace raindrops {
    std::string convert(int n){
        std::string result{""};
        result.reserve(15);
        if (n % 3 == 0 || n % 5  == 0 || n % 7 == 0) {
            if (n % 3 == 0) result.append("Pling"); 
            if (n % 5 == 0) result.append("Plang");
            if (n % 7 == 0) result.append("Plong");
        } else {
            result.append(std::to_string(n));
        }
        return result;
    }	
}  // namespace raindrops
