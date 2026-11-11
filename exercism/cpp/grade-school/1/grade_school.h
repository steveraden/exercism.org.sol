#pragma once
#include <string>
#include <map>
#include <vector>

    namespace grade_school {

        using roster_map_t = std::map<int, std::vector<std::string>>;
        class school {
            public:
                const roster_map_t roster() const;
                void add(std::string name, int grade);
                std::vector<std::string> grade(int grade) const;
            private:
                roster_map_t roster_;

    };
}  // namespace grade_school
