#include "eliuds_eggs.h"
#include <string>
#include <chrono>
#include <iostream>
#include <exception>

namespace chicken_coop {
    long convert_decimal_to_binary(long n){
        // this was after an AI model suggested while searching for an algorithm
        // an algorithm that can produce a binary without materilziing a string.
        if (n == 0) return 0;

        int binary_num[64]; 
        int i = 0;

        // 1. Store the binary remainders in the array
        while (n > 0) {
            binary_num[i] = n % 2;
            n = n / 2;
            i++;
        }

        long long final_result = 0;
        long long place_value = 1;

        // 2. Combine the array elements from index 0 up to i-1
        for (int j = 0; j < i; j++) {
            final_result += binary_num[j] * place_value;
            place_value *= 10; // Move to the next decimal place (1, 10, 100, 1000...)
        }
        return final_result;
    }

    // Implements Brian Kernighan’s trick for counting set bits
    // https://medium.com/@nallaamulya043/brian-kernighans-trick-for-counting-set-bits-in-java-hamming-weight-988cc4ec9c59
    long count_ones_in_decimal(unsigned long num) // Changed input to unsigned
    {
        std::cout << "long  was " << num << "\n";
        unsigned long count{0};
        while (num) {
            // Unset the rightmost set bit
            num &= (num - 1); 
            // Count that bit
	std::cout << "coming down num?" << num << "\n";
            ++count;
        }
        return count;
    }

    int positions_to_quantity(long position)
    {
        auto start = std::chrono::steady_clock::now();

        // convert position to a binary represetnation
        //std::string bit_string =  convert_decimal_to_binary(position);  
        long bit_string = convert_decimal_to_binary(position);  
        // count every 1 in the bit string and return that quantity
        int count = count_ones_in_decimal(bit_string);

        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "Duration was " << duration.count() << "\n";

        return count;
        // return the quantity
    }
}  // namespace chicken_coop
