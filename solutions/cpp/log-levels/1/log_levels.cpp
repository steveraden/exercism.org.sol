#include <string>
#include <algorithm>
#include <iostream>

namespace log_line {
    int msg_start_idx(std::string line) {
        return line.find(":") + 2;
    }

    std::string message(std::string line) {
       return line.substr(msg_start_idx(line));
    }

    std::string log_level(std::string line) {
        std::string stars = "************************************************************";
        std::string label = line.substr(0, msg_start_idx(line)-2);
        std::erase(label, '[' );
        std::erase(label, ']');
        return label;    
    }

    std::string reformat(std::string line) {
        return  message(line) + " " + "(" + log_level(line) + ")";
    }

}  // namespace log_line
