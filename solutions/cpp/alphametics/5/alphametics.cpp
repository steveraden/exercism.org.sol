#include "alphametics.h"
#include <string>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>

namespace alphametics {
	struct Equation {
		std::vector<std::string> operands;
		std::string result;
	};

	std::string trim(std::string s) {
		const char* whitespace = " \t\n\r\f\v";

		// 1. Trim trailing whitespace first (prevents unnecessary memory shifts)
		size_t end = s.find_last_not_of(whitespace);
		if (end != std::string::npos) {
			s.erase(end + 1);
		} else {
			s.clear(); // String is entirely whitespace
			return s;
		}

		// 2. Trim leading whitespace
		size_t start = s.find_first_not_of(whitespace);
		if (start != std::string::npos) {
			s.erase(0, start);
		}
		return s;
	}

	// Google Gemini suggested this split function
	std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
		std::vector<std::string> tokens;
		size_t start = 0;
		size_t end = str.find(delimiter);    
		while (end != std::string::npos) {
			tokens.push_back(trim(str.substr(start, end - start)));
			start = end + delimiter.length();
			end = str.find(delimiter, start);
		}
		// Add the last remaining token
		tokens.push_back(trim(str.substr(start)));
		return tokens;
	}

	std::map<char, int> unique_characters(Equation equation) {
		std::map<char, int> uniq_chars;
		for (auto term : equation.operands) {
			for (char c : term) {
				uniq_chars.insert({c, 0});
			}
		}
		for (char c : equation.result) {
			uniq_chars.insert({c, 0});
		}
		return uniq_chars;
	}

	std::unordered_set<char> leading_characters(Equation equation) 
	{
		std::vector<char> leading_chars;
		for (auto term : equation.operands ) {
			leading_chars.insert(leading_chars.end(), term.at(0));
		}
		leading_chars.insert(leading_chars.end(), equation.result.at(0));
		return leading_chars;
	}

	long long word_to_number(std::string term_word, 
			std::map<char, int> uniq_chars) 
	{
		long long number{0};
		for (char c : term_word) {
			number =  (number * 10 ) + uniq_chars.at(c);  
		}
		return number;
	}

	std::vector<int> terms_to_number_list(
			std::vector<std::string> operands,
			std::map<char, int> uniq_chars)
	{
		std::vector<int> terms; 
		for (auto term : operands) {
			terms.insert(terms.begin(), word_to_number(term, uniq_chars));
		}
		return terms;
	}

	bool digits_satisfy(alphametics::Equation equation, 
			std::map<char, int> uniq_chars)
	{
		std::vector<int> terms = terms_to_number_list(equation.operands, uniq_chars);
		int sum_of_terms = std::accumulate(terms.begin(), terms.end(), 0); 
		int result = word_to_number(equation.result, uniq_chars);
		return (sum_of_terms == result);
	}

	std::optional<std::unordered_map<char, int>> 
		solve(std::string puzzle) 
		{
			std::vector<std::string> expressions = split(puzzle, "==");
			std::vector<std::string> operands = split(expressions.at(0), "+");
			std::string result_word = expressions.at(1);
			alphametics::Equation equation{operands, result_word}; 
			std::map uniq_chars = unique_characters(equation);	
			// identify the leading characters who can not be zero
			auto leading_chars = leading_characters(equation);
			std::unordered_map<char, int> result_map{};
			// explore permutations of digits {0-9} * uniq_chars
			std::vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
			while (std::next_permutation(digits.begin(), digits.end())) {
				size_t i{0};
				for (const auto& [c, n] : uniq_chars) {
					uniq_chars.at(c) = digits.at(i);
					++i;
				}
				// Reject maps with any leading char equal to zero
				bool leading_char_is_zero = std::any_of(
												uniq_chars.begin(), 
												uniq_chars.end(),
												[&leading_chars](const auto& pair) {
													return pair.second == 0 && 
													std::find(leading_chars.begin(), leading_chars.end(), pair.first) != leading_chars.end();
												});

				if (leading_char_is_zero){continue;}

				if (digits_satisfy(equation, uniq_chars)){
					result_map = {
						uniq_chars.begin(), 
						uniq_chars.end()
					};      
					return std::optional(result_map);
				}
				// reversing the remaining digits will cause next_permutation to pass over them
				// and give the next useful permutation
				std::sort(digits.begin() + i, digits.end(), std::greater<int>()); 
			}
			if (result_map.empty()) {
				return std::nullopt;
			} else {
				return std::make_optional(result_map);
			}
		}

}  // namespace alphametics
