#include "secret_handshake.h"
#include <algorithm>
#include <map>
#include <array>


namespace secret_handshake {
    const std::array<std::string, 5> actions = {
          "wink",
          "double blink",
          "close your eyes",
          "jump",
          "reverse"
        };
        
    std::vector<std::string> commands(int bit_map) 
    {
        std::vector<std::string> result{};
        int bit{0};
        do  {
            int bit_mask = 1 << bit; 
            if ((bit_mask & bit_map) != 0)
            {
                if ((bit_mask) != 16) {
                    result.push_back(actions[bit]);
                } else {
                    std::reverse(result.begin(), result.end());        
                }
            }
            ++bit ; 
        } while (bit < 5);
        return result;    
    }

}  // namespace secret_handshake
