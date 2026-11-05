#include "eliuds_eggs.h"
#include <string>

namespace chicken_coop {
   std::string convert_decimal_to_binary(const int decimal) 
   {
        int quotient{decimal};
        int remainder;
        std::string bit_string{""};
        while (quotient !=0) {
            // std::div in <cstdlib> would do this in one line
            remainder = quotient % 2;
            quotient /= 2;
            if (remainder == 1) {
                bit_string += '1';
            } else {
                bit_string += '0';
            }
        }
        return bit_string;
    }

    int count_ones_in_bit_string(std::string str){
        unsigned int count{0};
        for (char c : str){
            count += (c == '1');
        }
        return count;
    }

    int positions_to_quantity(int position)
    {
        // convert position to a binary represetnation
        std::string bit_string = convert_decimal_to_binary(position);  

        // count every 1 in the bit string and return that quantity
        return count_ones_in_bit_string(bit_string);
        // return the quantity
    }
}  // namespace chicken_coop
