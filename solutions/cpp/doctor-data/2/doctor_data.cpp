#include <string>
#include "doctor_data.h"

    using namespace heaven;

    Vessel::Vessel(std::string a1, int a2){
        name = a1;
        generation = a2;
        current_system = star_map::System::Sol;
    }
    
    Vessel::Vessel( std::string a1, 
                    int a2, 
                    star_map::System a3){
        name = a1;
        generation = a2;
        current_system = a3;
    }

    Vessel Vessel::replicate(std::string a1){
        return Vessel(a1, generation+1, current_system);
    };

    void Vessel::make_buster(){
        busters ++;
    };

    bool Vessel::shoot_buster(){
        if (busters > 0){
            --busters;
            return true;
        } else {
            return false;
        }
    };
    
    std::string heaven::get_older_bob(Vessel v1, Vessel v2){
        if (v1.generation < v2.generation) {
            return v1.name;
        } else {
            return v2.name;
        }
    }
    bool heaven::in_the_same_system(Vessel v1, Vessel v2){
         if (v1.current_system == v2.current_system) {
            return true;
        } else {
            return false;
        }
    }
