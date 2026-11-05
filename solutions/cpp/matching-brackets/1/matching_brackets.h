#pragma once
#include <string>

namespace matching_brackets {
	bool check(std::string str);
    bool leftSymbol(char c);
	bool rightSymbol(char c);
	char matchingLeftSymbol(char rightSymbol);

}  // namespace matching_brackets
