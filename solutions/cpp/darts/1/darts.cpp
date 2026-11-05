#include "darts.h"
#include <cmath>

namespace darts {
    int score(double x, double y) {
        double distance = radial_distance(x,y);
        if (distance <= 1) { 
            return 10;
        } else if (distance <= 5)  {
            return 5;
        } else if (distance <= 10) {
            return 1;
        } else {
            return 0;
        }
    }  

    double radial_distance(double x, double y) {
        double sum_of_squares = (x*x) + (y*y);
        return std::sqrt(sum_of_squares); 
    }
}  // namespace darts
