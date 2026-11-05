#include <string>

namespace targets {
    class Alien {
        public:
            int x_coordinate{};
            int y_coordinate{};

            Alien(int x, int y){
                x_coordinate = x;
                y_coordinate = y;
            }
                    
            int get_health() {
                return health;
            }
    
            bool hit(){
                if (health > 0) {
                    health--;
    
                }
                return true;
            }
    
            bool is_alive(){
                if (health >  0) {
                    return true;
                } else {
                    return false;
                }
            }
    
            bool teleport (int x_new, int y_new){
                x_coordinate = x_new;
                y_coordinate = y_new;
                return true;
            }
    
            bool collision_detection(Alien an_alien){
                if (an_alien.x_coordinate == x_coordinate
                && an_alien.y_coordinate ==  y_coordinate)
                {
                    return true;
                } else {
                    return false;  
                }
            }
    
        private:
            int health{3};
    };       
    

}  // namespace targets
