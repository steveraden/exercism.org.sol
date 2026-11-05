#include "allergies.h"

namespace allergies {

    bool allergy_test::is_allergic_to(std::string allergen) {
        return tested_allergens.count(allergen) != 0; 
    }

    void allergy_test::process_test(int total) {
        // step down from 2^7 to 2^1
        for (int i = 128; i >= 1; i/=2) {
            // taken as a a binary, i is a bit index into the allergens map
            // matching on the AND  complement of the total (as binary number) confirms
            // that the total score includes the test weight of that allergen.
            if ((total &  i) != 0) {
                tested_allergens.emplace(allergen::for_weight(i));
            }
        }
    };

    const  std::unordered_set<std::string> allergy_test::get_allergies() {
        return tested_allergens;
    }

    const std::unordered_map<int, std::string> allergen::allergens_by_weight = {
        { 0b00000001, "eggs"},
        { 0b00000010, "peanuts"},
        { 0b00000100, "shellfish"},
        { 0b00001000, "strawberries"},
        { 0b00010000, "tomatoes"},
        { 0b00100000, "chocolate"},
        { 0b01000000, "pollen"},
        { 0b10000000, "cats"},
    };

    const std::string allergen::for_weight(int i)  {
        return allergen::allergens_by_weight.at(i);
    }

}  // namespace allergies
