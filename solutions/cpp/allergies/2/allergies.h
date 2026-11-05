#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace allergies {

    class allergy_test {
        public:
            bool is_allergic_to(std::string alergen);

            const std::unordered_set<std::string> get_allergies();

            allergy_test(int i) : score(i) {
                process_test(score);
            };

        private:
            int score;
            std::unordered_set<std::string> tested_allergens;	

            void process_test(int total);

    };

    class allergen {
        public:
            static const std::string for_weight(int i);

        private:
            static const std::unordered_map<int, std::string> allergens_by_weight;
    };
};  // namespace allergies
