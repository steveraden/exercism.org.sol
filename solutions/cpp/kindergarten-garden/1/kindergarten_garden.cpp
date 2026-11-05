#include "kindergarten_garden.h"
#include <array>
#include <vector>
#include <string> 
#include <sstream> 
#include <cctype>
#include <iostream>

namespace kindergarten_garden {

    Plants decode_plant(char plant_initial){
        switch (std::toupper(plant_initial)) {
            case 'C': return Plants::clover;
            case 'G': return Plants::grass;
            case 'V': return Plants::violets;
            case 'R': return Plants::radishes;
            default:  return Plants::sunflower;
        }
    }


    size_t find_student_index(std::string student) {
        std::array<std::string, 12> students{
            "Alice", "Bob", "Charlie", "David", 
            "Eve", "Fred", "Ginny", "Harriet", 
            "Ileana", "Joseph", "Kincaid", "Larry"};

        size_t result{std::string::npos};
        for (size_t i = 0; i <= students.size(); ++i){
            if (students.at(i) == student){
                result = i;
                break;
            }        
        }
        return result;
    }

    std::array<Plants, 4> plants(std::string flower_data, std::string student)
    { 
        std::vector<Plants> working_plants;
        std::array<Plants, 4> student_plants{};
        std::stringstream ss(flower_data);
        std::string code_line;
        size_t student_index = kindergarten_garden::find_student_index(student);

        while (std::getline(ss, code_line, '\n')) {
            auto first_flower_code = code_line[student_index+student_index];
            auto second_flower_code = code_line[student_index+student_index+1];
            working_plants.push_back(kindergarten_garden::decode_plant(first_flower_code)); 
            working_plants.push_back(kindergarten_garden::decode_plant(second_flower_code)); 
        }
        std::copy(working_plants.begin(), working_plants.end(), student_plants.begin());
        return student_plants;
    }

}

