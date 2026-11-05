#pragma once

namespace space_age {

    class space_age{
        long age_in_seconds{0};
        public:
            space_age(long _age_in_seconds){
                age_in_seconds ={_age_in_seconds};
            }
            double on_earth() const;
            double on_mercury() const;
            double on_venus() const;
            double on_mars() const;
            double on_jupiter() const;
            double on_saturn() const;
            double on_uranus() const;
            double on_neptune() const;
            double seconds() const;
        };
}  // namespace space_age

