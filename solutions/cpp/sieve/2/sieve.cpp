#include "sieve.h"
#include <unordered_set>
#include <iostream>

namespace sieve {
    std::vector<int> primes(int n) {
        
        std::vector<int> found_primes{};
        std::unordered_set<int> multiples{};
        int multiple{0};
    
        for ( int i =2; i <= n; ++i ) {
            if ( multiples.count(i) == 0 ) {  
                found_primes.push_back(i);
                multiple = i;  
                while (multiple <= n) { 
                    multiple = multiple + i ; 
                    multiples.emplace(multiple); 
                }
            }
        }
        return found_primes;
    }
}  // namespace sieve
