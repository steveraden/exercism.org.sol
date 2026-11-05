#include "power_of_troy.h"
#include <memory>

namespace troy {

    void give_new_artifact(human& h, std::string artifact_name){
        auto a = artifact(artifact_name);
        h.possession = std::make_unique<artifact>(a);            
    }
    
    void exchange_artifacts(std::unique_ptr<artifact>& possession_one, std::unique_ptr<artifact>& possession_two){
        std::swap(possession_one, possession_two);
    }

    void manifest_power(human& h, std::string power_name){
        h.own_power = std::make_unique<power>(power_name);
    }

    void use_power(human& caster, human& target){
        target.influenced_by = caster.own_power;
    }

    int  power_intensity(human& h){
        if (h.own_power == nullptr){
            return 0;            
        } else {
            return h.own_power.use_count();
        }
    }
}  // namespace troy
