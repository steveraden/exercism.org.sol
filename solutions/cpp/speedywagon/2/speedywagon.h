#pragma once

#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

int activity_counter(pillar_men_sensor* sensors,  int capacity);

bool connection_check(pillar_men_sensor* sensor);

bool alarm_control(pillar_men_sensor* sensor);

bool uv_alarm(pillar_men_sensor* sensor);

int uv_light_heuristic(std::vector<int>* data_array);

}  // namespace speedywagon
