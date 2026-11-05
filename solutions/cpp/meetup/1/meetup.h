#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

// This problem requires you to install and use the boost date_time library.
// CMake will try to find and configure it for you if it is installed on your
// system.
// See <http://www.boost.org/doc/libs/1_74_0/doc/html/date_time.html> for
// documentation on boost::gregorian::date

namespace meetup {

    class scheduler{

        public:
            int month;
            int year;
            scheduler(short unsigned int _month, short unsigned int _year){
                month = _month;
                year = _year;
            } 
            // helpers who could be private
            const boost::gregorian::date teenth(boost::date_time::weekdays day_of_week) const;
            const boost::gregorian::date first_day(boost::date_time::weekdays day_of_week) const;
            const boost::gregorian::date second_day(boost::date_time::weekdays day_of_week ) const;
            const boost::gregorian::date third_day(boost::date_time::weekdays day_of_week ) const;
            const boost::gregorian::date fourth_day(boost::date_time::weekdays day_of_week ) const;
            const boost::gregorian::date last_day(boost::date_time::weekdays day_of_week ) const;
            // teenth
            const boost::gregorian::date monteenth() const;
            const boost::gregorian::date tuesteenth() const;
            const boost::gregorian::date wednesteenth() const;
            const boost::gregorian::date thursteenth() const;
            const boost::gregorian::date friteenth() const;
            const boost::gregorian::date saturteenth() const;
            const boost::gregorian::date sunteenth() const;
            // first
            const boost::gregorian::date first_monday() const;
            const boost::gregorian::date first_tuesday() const;
            const boost::gregorian::date first_wednesday() const;
            const boost::gregorian::date first_thursday() const;
            const boost::gregorian::date first_friday() const;
            const boost::gregorian::date first_saturday() const;
            const boost::gregorian::date first_sunday() const;
            // second
            const boost::gregorian::date second_monday() const;
            const boost::gregorian::date second_tuesday() const;
            const boost::gregorian::date second_wednesday() const;
            const boost::gregorian::date second_thursday() const;
            const boost::gregorian::date second_friday() const;
            const boost::gregorian::date second_saturday() const;
            const boost::gregorian::date second_sunday() const;
            // third
            const boost::gregorian::date third_monday() const ;
            const boost::gregorian::date third_tuesday() const ;
            const boost::gregorian::date third_wednesday() const ;
            const boost::gregorian::date third_thursday() const ;
            const boost::gregorian::date third_friday() const ;
            const boost::gregorian::date third_saturday() const ;
            const boost::gregorian::date third_sunday() const ;
            // fourth
            const boost::gregorian::date fourth_monday() const ;
            const boost::gregorian::date fourth_tuesday() const ;
            const boost::gregorian::date fourth_wednesday() const ;
            const boost::gregorian::date fourth_thursday() const ;
            const boost::gregorian::date fourth_friday() const ;
            const boost::gregorian::date fourth_saturday() const ;
            const boost::gregorian::date fourth_sunday() const ;
            // last
            const boost::gregorian::date last_monday() const ;
            const boost::gregorian::date last_tuesday() const ;
            const boost::gregorian::date last_wednesday() const ;
            const boost::gregorian::date last_thursday() const ;
            const boost::gregorian::date last_friday() const ;
            const boost::gregorian::date last_saturday() const ;
            const boost::gregorian::date last_sunday() const ;
    };
}  // namespace meetup
