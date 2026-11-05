#include <string>
#include "doctor_data.h"


    heaven::Vessel::Vessel(std::string a1, int a2){
        name = a1;
        generation = a2;
        current_system = star_map::System::Sol;
}
    
    heaven::Vessel::Vessel( std::string a1, 
                    int a2, 
                    star_map::System a3){
        name = a1;
        generation = a2;
        current_system = a3;
    }
    heaven::Vessel heaven::Vessel::replicate(std::string a1){
        return heaven::Vessel(a1, generation+1, current_system);
    };

    void heaven::Vessel::make_buster(){
        busters ++;
    };

    bool heaven::Vessel::shoot_buster(){
        if (busters > 0){
            --busters;
            return true;
        } else {
            return false;
        }
    };
    
    std::string heaven::get_older_bob(heaven::Vessel v1, heaven::Vessel v2){
        if (v1.generation < v2.generation) {
            return v1.name;
        } else {
            return v2.name;
        }
    }
    bool heaven::in_the_same_system(heaven::Vessel v1, heaven::Vessel v2){
         if (v1.current_system == v2.current_system) {
            return true;
        } else {
            return false;
        }
    }
