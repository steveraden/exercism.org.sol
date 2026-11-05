#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H
#include <string>
#include <optional>
#include <unordered_map>

namespace alphametics {
    
    std::optional<std::unordered_map<char, int>> solve(std::string puzzle);

}  // namespace alphametics

#endif  // ALPHAMETICS_H
