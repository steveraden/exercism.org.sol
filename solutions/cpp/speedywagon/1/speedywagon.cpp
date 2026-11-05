#include "speedywagon.h"

namespace speedywagon {

bool connection_check(pillar_men_sensor* sensor){
    return !(sensor == nullptr);
}

bool alarm_control(pillar_men_sensor* sensor){
    if (sensor == nullptr){
       return false; 
    } else {
        if (sensor->activity > 0) {
            return true;
        } else {
            return false;
        }
    }
}

bool uv_alarm(pillar_men_sensor* sensor){
    if (sensor == nullptr){
       return false; 
    } else {
        auto result = uv_light_heuristic(&(sensor->data));
        return (result > sensor->activity);
    }
}

int activity_counter(pillar_men_sensor* sensors, int capacity){
    int total_activity;
    for (int i{0}; i < capacity-1; i++){
        auto sensor = sensors+i;
        total_activity += sensor->activity;
    }
    return total_activity;
}
//
// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
