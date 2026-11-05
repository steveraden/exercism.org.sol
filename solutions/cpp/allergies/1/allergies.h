#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace allergies {

    class allergy_test {
        public:
            bool is_allergic_to(std::string alergen);
            allergy_test(int i) : score(i) {
                derive_test(score);
            };
            std::unordered_set<std::string> get_allergies();
        private:
            int score{0};
            std::unordered_set<std::string> tested_allergens;	
            void derive_test(int total);

    };

    class allergens {

        public:
            static std::string for_weight(int i); 
        private: 
            static std::unordered_map<int, std::string> allergens_by_weight;

    };

}  // namespace allergies
