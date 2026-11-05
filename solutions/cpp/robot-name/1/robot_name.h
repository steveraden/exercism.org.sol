#pragma once
#include <string>
#include <unordered_set>

namespace robot_name {
    class robot {
         
        private:
            inline static std::unordered_set<std::string> names;
            std::string name_{};
            std::string make_name();
            std::string get_name();

        public:
            robot() {
                name_ = get_name();
            }
        
            void reset() {
                name_ = get_name();
            }

            std::string name() const {
                return name_;
            }

    };
}  // namespace robot_name
