#include "eliuds_eggs.h"
#include <string>
#include <chrono>
#include <iostream>
#include <exception>

namespace chicken_coop {
    // Implements Brian Kernighan’s trick for counting set bits
    // https://medium.com/@nallaamulya043/brian-kernighans-trick-for-counting-set-bits-in-java-hamming-weight-988cc4ec9c59
    int positions_to_quantity(long position)
    {
        unsigned long count{0};
        while (position) {
            // Unset the rightmost set bit
            position &= (position - 1); 
            // Count that bit
            ++count;
        }
        return count;
    }
}  // namespace chicken_coop
