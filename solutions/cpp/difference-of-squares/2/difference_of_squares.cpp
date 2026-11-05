#include "difference_of_squares.h"
#include <iostream>

namespace difference_of_squares {

    int square_of_sum(int n)
    {
        auto gausian_sum{(n*(n+1))/2};
        std::cout << gausian_sum * gausian_sum << "\n";
        return (gausian_sum * gausian_sum);
    }
    
    int sum_of_squares(int n)
    {
	    int output{0};
        for(int i{0}; i < n; ++i) {
            output += (i+1) * (i+1);
        }
        return output;
    }

    int difference(int n){ 
       return square_of_sum(n) - sum_of_squares(n);
    }

}  // namespace difference_of_squares

