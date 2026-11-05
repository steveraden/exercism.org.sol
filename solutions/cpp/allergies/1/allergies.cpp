#include "allergies.h"
#include <iostream>

namespace allergies {

    bool allergy_test::is_allergic_to(std::string allergen) {
        return tested_allergens.count(allergen) != 0; 
    }

    void allergy_test::derive_test(int total) {
        for (int weight = 128; weight >=1; weight /= 2) {
            if ( total >= weight) {
                if (weight <= 128) {
                    tested_allergens.emplace(allergens::for_weight(weight)); 
                    total =  total - weight;
                }
            } 
        } 
    }

    std::unordered_set<std::string> allergy_test::get_allergies() {
        return tested_allergens;
    }

    std::string allergens::for_weight(int i){
        return allergens_by_weight[i];
    }


    std::unordered_map<int, std::string> allergens::allergens_by_weight = {
        { 1, "eggs"},
        { 2, "peanuts"},
        { 4, "shellfish"},
        { 8, "strawberries"},
        { 16, "tomatoes"},
        { 32, "chocolate"},
        { 64, "pollen"},
        { 128, "cats"}
    };

}  // namespace allergies
