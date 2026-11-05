#pragma once
#include <array>
#include <string>

namespace kindergarten_garden {

    enum Plants {
        clover,
        grass,
        violets,
        radishes,
        sunflower
    };
   
    Plants decode_plant(char plant_initial);
    
    size_t find_student_index(std::string student);
        
    std::array<Plants, 4> plants(std::string flower_data, std::string student);
}  // namespace kindergarten_garden
