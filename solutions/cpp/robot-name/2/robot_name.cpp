#include "robot_name.h"
#include "cstdlib"
#include "ctime"

namespace robot_name {
    static void robot::init_seed() {
        static bool seeded = false;
        if (!seeded) {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            seeded = true;
        }
    }

    static int get_rand() {
        init_seed();
        return std::rand();
    }

    std::string robot::make_name() {

        const char pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string name{}; 
        name.push_back(pool[get_rand() % (sizeof(pool) - 1)]);
        name.push_back(pool[get_rand() % (sizeof(pool) - 1)]);
        name.push_back((get_rand() % 10) + '0');
        name.push_back((get_rand() % 10) + '0');
        name.push_back((get_rand() % 10) + '0');

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
