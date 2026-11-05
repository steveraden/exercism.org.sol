#include "high_scores.h"

#include <algorithm>

namespace arcade {

    std::vector<int> HighScores::list_scores() {
        return scores; 
    }

    int HighScores::latest_score() {
        return scores.back();
    }

    int HighScores::personal_best() {
        return *std::max_element(scores.begin(), scores.end());
    }

    std::vector<int> HighScores::top_three() {
        // deep copy, more performant to use shallow copy or c++20 views
        std::vector<int>sorted = scores;
        // Sort the scores in descending order
        std::sort(sorted.begin(), sorted.end(), std::greater<int>());

        // get a iterator to the third element
        // Safety check to avoid reading out of bounds
        auto end_it = sorted.begin() + std::min<size_t>(3, sorted.size());

        //  Create a new vector with the first 3 elements
        return std::vector<int> (sorted.begin(), end_it);
    }
}  // namespace arcade
