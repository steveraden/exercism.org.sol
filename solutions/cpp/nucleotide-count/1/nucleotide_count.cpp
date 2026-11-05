#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {
    
    std::map<char, int> count(std::string dna_seq) {
            std::map<char, int> result_map = {
                {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}
            };
            for(char c : dna_seq) {
                if (result_map.find(c) == result_map.end() ) {
                    throw std::invalid_argument("Invalid nucleotide seen"); 
                }
                ++result_map.at(c);
            }
        return result_map;
    }

}  // namespace nucleotide_count
