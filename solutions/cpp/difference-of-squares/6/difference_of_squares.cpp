#include <iostream>
#include <numeric>
#include <vector>

namespace difference_of_squares {

    int square_of_sum(int n)
    {
        auto gausian_sum{(n*(n+1))/2};
        return (gausian_sum * gausian_sum);
    }
    
    int sum_of_squares(int n)
    {
        return (n * (n + 1) * (2*n + 1)) / 6;
    }

    int difference(int n){ 
       return square_of_sum(n) - sum_of_squares(n);
    }

}  // namespace difference_of_squares

