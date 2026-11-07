#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

    int steps(int num, int acc){
        if (num == 1) {
            return acc;
        } else if (num % 2 == 0) {
            return steps((num/2), acc+1);
        } else {
            return steps((num*3+1), acc+1);
        }
    }
    
    int steps(int num) {
        if (num < 1) {
            throw std::domain_error("Bunk. Number must be posssible.");
        }
        return steps(num, 0);
    }
}  // namespace collatz_conjecture
