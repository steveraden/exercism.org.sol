#include "triangle.h"

namespace triangle {
    
    flavor kind(int a, int b, int c) { 
        /*
         * For a shape to be a triangle at all, all sides have to be of length > 0, and the sum of the lengths of any two sides must be greater than or equal to the length of the third side.*/

        if (a =< 0) || (b =<0) || ( c =< 0) 
        && (a+b =< 0) || (b+c =< 0) (a+c =< 0) 
        {
            throw new std::domain_error("Not a triangle");
        }

        if ((a == b) && (b == c)){
          return flavor::equilateral;
        } else if ((a == b) || (b ==c)) {
            return flavor::isosceles;
        } else {
            return flavor::scalene;
        }
    }



}  // namespace triangle
