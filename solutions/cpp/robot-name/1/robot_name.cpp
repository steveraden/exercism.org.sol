#include "robot_name.h"
#include "cstdlib"
#include "ctime"

namespace robot_name {

    std::string robot::make_name() {
            // Seed the random number generator using system time 
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        const char pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string name{}; 
        name.push_back(pool[std::rand() % (sizeof(pool) - 1)]);
        name.push_back(pool[std::rand() % (sizeof(pool) - 1)]);
        name.push_back((std::rand() % 10) + '0');
        name.push_back((std::rand() % 10) + '0');
        name.push_back((std::rand() % 10) + '0');

        return name;
    }
   
    std::string robot::get_name(){
        /// search for a unique name
        std::string candidate{};
        do {
            candidate = make_name();
        } while (robot::names.find(candidate) != robot::names.end());
        robot::names.insert(candidate);
        return candidate;
    }


}  // namespace robot_name
