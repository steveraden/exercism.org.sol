#include "binary_search.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace binary_search {
    size_t find(std::vector<int> data, 
                int value,
                size_t start,
                size_t mid_point,
                size_t end
               ) 
    {
        
        if (data.size() == 0) throw std::domain_error("empty list");
        if (start > end || end < start) throw std::domain_error("not found");
        
        int middle_element = data.at(mid_point); 
        if (start == end && middle_element != value) throw std::domain_error("not found");
        

        if (middle_element == value) {
            return mid_point;
        } else if (value < middle_element) {
            size_t new_end = mid_point-1;
            size_t new_mid = (new_end-start)/2+start; 
            return find(data, value, start, new_mid, new_end); 
        } else {
            size_t new_start = mid_point+1;
            size_t new_mid = (end-new_start)/2+new_start; 
            return find(data, value, new_start, new_mid, end);
        }
    }

 
    size_t find(std::vector<int> data, int value) 
    {
        std::sort(data.begin(), data.end());
        return find(data, value, 0, data.size()/2, data.size()-1);

    }
}  // namespace binary_search
