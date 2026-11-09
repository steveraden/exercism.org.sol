#include "clock.h"
#include <cstdlib>

namespace date_independent {

    std::string pad_with_zero(int number) {
        char pad_char = '0';
        std::string digit_str = std::to_string(number); 
        if (number < 10) {
            digit_str.insert(0, 1, pad_char);     
         }
         return digit_str;       
    }

    void clock::populate_from_total_minutes() {
        auto [quot, rem] = std::div(total_minutes_, 60);      
        hours_ = quot % 24;
        minutes_ = rem;
    }
    
    int clock::hour() const {
        return hours_;
    }

    int clock::minutes() const {
        return minutes_;          
    }
    
    bool clock::operator==(const clock &c) const {
        return this->total_minutes_ == c.total_minutes_;
    }
        
    bool clock::operator!=(const clock &c) const {
        return this->total_minutes_ != c.total_minutes_;
    }
    
    clock clock::at(int hour, int minutes) {
        return clock(hour * 60 + minutes); 
    }

    clock clock::plus(int minutes){
        return clock(total_minutes_ + minutes);
    }

    clock::operator std::string() const {
        std::string result{};
        result += pad_with_zero(hour()); 
        result += ":"; 
        result += pad_with_zero(minutes());
        return result;
    }
}  // namespace date_independent
