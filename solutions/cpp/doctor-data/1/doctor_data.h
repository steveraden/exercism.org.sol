#pragma once
#include <string>
namespace star_map {
     enum class System {
        AlphaCentauri,
        BetaHydri,
        DeltaEridani,
        EpsilonEridani,
        Omicron2Eridani,
        Sol
     };
}

namespace heaven {
    class Vessel{
        public:
            Vessel(std::string a1, int a2);
            Vessel( std::string a1, 
                    int a2, 
                    star_map::System system);
          
            Vessel replicate(std::string a1);
            void make_buster();
            bool shoot_buster();

            std::string name;
            int generation;
            int busters{0};
            star_map::System current_system;

    };
    
    std::string get_older_bob(Vessel v1, Vessel v2);
    bool in_the_same_system(Vessel v1, Vessel v2); 
}


