#include "grade_school.h"
#include <algorithm>
#include <iostream>

namespace grade_school {

    const roster_map_t school::roster() const {
        return roster_;
    }

    void school::add(std::string name, int grade_number)
    {
        auto roster_iter = roster_.find(grade_number);
        bool grade_has_students = roster_iter != roster_.end(); 
        bool student_not_in_roster = std::all_of(
            roster_.begin(), roster_.end(),
            [name](const auto &pair) { 
            auto &students = pair.second;
            auto iter = std::find(students.begin(), students.end(), name);
            return iter == students.end();
        });
        
        if (student_not_in_roster) {
            if (grade_has_students) {
                auto &students = roster_iter->second;
                students.push_back(name);
                std::sort(students.begin(), students.end());
            } else {
               roster_.insert({grade_number, std::vector<std::string>{name}});
            }
        }
    }

    std::vector<std::string> school::grade(int grade_number) const {
        auto iter = roster_.find(grade_number);
        if (iter != roster_.end()){
             return roster_.at(grade_number);
        } else {
            return {};
        }
    }
}  // namespace grade_school
