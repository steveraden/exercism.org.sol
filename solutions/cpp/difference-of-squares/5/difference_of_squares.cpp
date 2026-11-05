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

        int n_sum_squared = square_of_sum(n);

        // generate pairwise combination
        std::vector<int> sums_of_pairs;
        sums_of_pairs.reserve(n_sum_squared); // Critical for efficiency: prevents reallocations

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                sums_of_pairs.push_back(2 * i * j); 
            }
        }
        int sum_of_terms =  std::reduce(sums_of_pairs.begin(), sums_of_pairs.end()); 
        return n_sum_squared + sum_of_terms; 
    }

    int difference(int n){ 
       return square_of_sum(n) - sum_of_squares(n);
    }

}  // namespace difference_of_squares

