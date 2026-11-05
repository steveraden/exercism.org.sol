#include "bob.h"
#include <locale>
#include <algorithm>
#include <string_view>
#include <iostream>

namespace bob {
    //using namespace std::string; 
    bool is_a_question(std::string_view remark) {
       return (remark.at(remark.size()-1) == '?'); 
    }

    bool is_yelled(std::string_view remark) {   
        return 
           // yelling: any character is a letter and all characters are upper
           std::any_of(remark.begin(), 
                            remark.end(),
                            [](char c) { 
                                return std::isalpha(c); 
                            }) && 
            std::none_of(remark.begin(), 
                            remark.end(),
                            [](char c) { 
                                return std::islower(c); 
                            });

    }

    bool does_remark_have_silence(
            std::string_view remark , 
            std::string_view original_remark)
    {
        std::cout << "r.s vs or.s " << remark.size() << " : "  << original_remark.size() << "\n";
        return remark.size() != original_remark.size();             
    }
    
    std::string_view trim(std::string_view s) {
        // Remove leading spaces
        auto start = std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        });
        s.remove_prefix(std::distance(s.begin(), start));

        // Remove trailing spaces
        auto end = std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        });
        s.remove_suffix(std::distance(s.rbegin(), end));

        return s;
    }    

    std::string hey(std::string remark) {
        if (remark.empty()) return "Fine. Be that way!";
        std::string_view trimmed_remark = trim(remark);

        bool a_question = is_a_question(trimmed_remark);
        bool a_yelled_remark = is_yelled(trimmed_remark);
        bool a_silent_remark = does_remark_have_silence(trimmed_remark, remark);

        if (a_question && a_yelled_remark) {
            return "Calm down, I know what I'm doing!";
        } else if (a_question) {
            return "Sure.";
        } else if (a_yelled_remark) {
            return "Whoa, chill out!";
        } else if (a_silent_remark) {
            return "Fine. Be that way!";
        } else {
            return "Whatever.";
        }
    }
}  // namespace bob
