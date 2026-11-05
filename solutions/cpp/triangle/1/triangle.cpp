#include "triangle.h"

namespace triangle {
    
    flavor kind(int a, int b, int c) { 
        if ((a == b) && (b == c)){
          return flavor::equilateral;
        } else if ((a == b) || (b ==c)) {
            return flavor::isosceles;
        } else {
            return flavor::scalene;
        }
    }

}  // namespace triangle
