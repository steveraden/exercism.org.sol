#include "matching_brackets.h"
#include <vector>
#include <iostream>

namespace matching_brackets {

	bool check(std::string str){
		if (str.empty()) return true;

		std::vector<char> seenSymbols; 
		for (char c : str) {
			if (leftSymbol(c)){
				seenSymbols.push_back(c);
			} else {
				if (rightSymbol(c)){
					if (!seenSymbols.empty() && 
							seenSymbols.back() == matchingLeftSymbol(c))
					{
						// delete the left symbol when matched
						seenSymbols.pop_back();
					} else {
						seenSymbols.push_back(c);
					}
				} 
			}
		}

		return seenSymbols.empty();
	}	

	bool leftSymbol(char c){
		if (c == '[' || c == '{' || c == '(') {
			return true;
		} else {
			return false;
		}
	}

	bool rightSymbol(char c){
		if (c == ']' || c == '}' || c == ')') {
			return true;
		} else {
			return false;
		}
	}

	char matchingLeftSymbol(char rightSymbol){
		switch (rightSymbol){
			case ']':
				return '[';
			case '}':
				return '{';
			case ')':
				return '(';
			default:
				return '*';
		}
	}


}  // namespace matching_brackets
