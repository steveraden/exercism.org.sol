#pragma once
#include <string>
namespace date_independent {
    struct clock {
        clock(int total_minutes) : 
            total_minutes_{(total_minutes % (60*24) + 1440)%1440}
        {
            populate_from_total_minutes();
        }
        
        public: 
            static clock at(int hour, int minute);
            operator std::string() const;
            bool operator==(const clock &c) const;
            bool operator!=(const clock &c) const;
            clock plus(int minutes); 

        private:
            int total_minutes_;
            int hours_;
            int minutes_;
            void populate_from_total_minutes();
            int hour() const;
            int minutes() const;
    };
    
}  // namespace date_independent
