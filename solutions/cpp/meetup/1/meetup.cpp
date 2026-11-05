#include "meetup.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <iostream>
#include <exception>

namespace meetup {
    using namespace boost::gregorian;
    const date scheduler::teenth(boost::date_time::weekdays day_of_week) const {
        date d(year, month, 13);
        day_iterator it{d};
        return boost::date_time::next_weekday(*it, 
                greg_weekday(day_of_week));
    }

    const date scheduler::first_day(boost::date_time::weekdays day_of_week) const {
        date d(year, month, 1);
        day_iterator it{d};
        return boost::date_time::next_weekday(*it, 
                greg_weekday(day_of_week));
    }

    const date scheduler::second_day(boost::date_time::weekdays day_of_week ) const {
        date d(year, month, 8);
        day_iterator it{d};
        return boost::date_time::next_weekday(*it, 
                greg_weekday(day_of_week));
    }

    const date scheduler::third_day(boost::date_time::weekdays day_of_week ) const {
        date d(year, month, 15);
        day_iterator it{d};
        return boost::date_time::next_weekday(*it, 
                greg_weekday(day_of_week));
    }

    const date scheduler::fourth_day(boost::date_time::weekdays day_of_week ) const {
        date d(year, month, 22);
        day_iterator it{d};
        return boost::date_time::next_weekday(*it, 
                greg_weekday(day_of_week));
    }

    const date scheduler::last_day(boost::date_time::weekdays day_of_week ) const {
        // if the month is feburary this is the same as fourth_day()
        if (month == Feb) {
            return fourth_day(day_of_week);
        } else {
            date d(year, month, 29);
            day_iterator it{d};
            date canidate = boost::date_time::next_weekday(*it, 
                    greg_weekday(day_of_week));
            if (canidate.month() == month) {
                return canidate;
            } else {
                return fourth_day(day_of_week);
            }
        }
    }

    const date scheduler::monteenth() const {
        return teenth(boost::date_time::Monday);
    }

    const date scheduler::tuesteenth() const {
        return teenth(boost::date_time::Tuesday);
    }
    const date scheduler::wednesteenth() const {
        return teenth(boost::date_time::Wednesday);
    }
    const date scheduler::thursteenth() const {
        return teenth(boost::date_time::Thursday);
    }
    const date scheduler::friteenth() const {
        return teenth(boost::date_time::Friday);
    }
    const date scheduler::saturteenth() const {
        return teenth(boost::date_time::Saturday);
    }
    const date scheduler::sunteenth() const {
        return teenth(boost::date_time::Sunday);
    }

    // first 
    const date scheduler::first_monday() const {
        return first_day(boost::date_time::Monday);
    }
    const date scheduler::first_tuesday() const {
        return first_day(boost::date_time::Tuesday);
    }
    const date scheduler::first_wednesday() const {
        return first_day(boost::date_time::Wednesday);
    }
    const date scheduler::first_thursday() const {
        return first_day(boost::date_time::Thursday);
    }
    const date scheduler::first_friday() const {
        return first_day(boost::date_time::Friday);
    }
    const date scheduler::first_saturday() const {
        return first_day(boost::date_time::Saturday);
    }

    const date scheduler::first_sunday() const {
        return first_day(boost::date_time::Sunday);
    }

    // second
    const date scheduler::second_monday() const {
        return second_day(boost::date_time::Monday);
    }

    const date scheduler::second_tuesday() const {
        return second_day(boost::date_time::Tuesday);
    }
    const date scheduler::second_wednesday() const {
        return second_day(boost::date_time::Wednesday);
    }
    const date scheduler::second_thursday() const {
        return second_day(boost::date_time::Thursday);
    }
    const date scheduler::second_friday() const {
        return second_day(boost::date_time::Friday);
    }
    const date scheduler::second_saturday() const {
        return second_day(boost::date_time::Saturday);
    }
    const date scheduler::second_sunday() const {
        return second_day(boost::date_time::Sunday);
    }

    //third
    const date scheduler::third_monday() const {
        return third_day(boost::date_time::Monday);
    }

    const date scheduler::third_tuesday() const {
        return third_day(boost::date_time::Tuesday);
    }
    const date scheduler::third_wednesday() const {
        return third_day(boost::date_time::Wednesday);
    }
    const date scheduler::third_thursday() const {
        return third_day(boost::date_time::Thursday);
    }
    const date scheduler::third_friday() const {
        return third_day(boost::date_time::Friday);
    }
    const date scheduler::third_saturday() const {
        return third_day(boost::date_time::Saturday);
    }
    const date scheduler::third_sunday() const {
        return third_day(boost::date_time::Sunday);
    }

    // fourth
    const date scheduler::fourth_monday() const {
        return fourth_day(boost::date_time::Monday);
    }

    const date scheduler::fourth_tuesday() const {
        return fourth_day(boost::date_time::Tuesday);
    }
    const date scheduler::fourth_wednesday() const {
        return fourth_day(boost::date_time::Wednesday);
    }
    const date scheduler::fourth_thursday() const {
        return fourth_day(boost::date_time::Thursday);
    }
    const date scheduler::fourth_friday() const {
        return fourth_day(boost::date_time::Friday);
    }
    const date scheduler::fourth_saturday() const {
        return fourth_day(boost::date_time::Saturday);
    }
    const date scheduler::fourth_sunday() const {
        return fourth_day(boost::date_time::Sunday);
    }

    const date scheduler::last_monday() const {
        return last_day(boost::date_time::Monday);
    }
    const date scheduler::last_tuesday() const {
        return last_day(boost::date_time::Tuesday);
    }
    const date scheduler::last_wednesday() const {
        return last_day(boost::date_time::Wednesday);
    }
    const date scheduler::last_thursday() const {
        return last_day(boost::date_time::Thursday);
    }
    const date scheduler::last_friday() const {
        return last_day(boost::date_time::Friday);
    }
    const date scheduler::last_saturday() const {
        return last_day(boost::date_time::Saturday);
    }
    const date scheduler::last_sunday() const {
        return last_day(boost::date_time::Sunday);
    }

}  // namespace meetup
