#include "alphametics.h"
#include "util.h"
#include <string>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>

namespace alphametics {
    typedef std::map<char, int> CharMap;

	struct Equation {
		std::vector<std::string> operands;
		std::string result;
	};

	CharMap unique_characters(Equation equation) {
		CharMap uniq_chars;
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
		std::unordered_set<char> leading_chars;
		for (auto term : equation.operands ) {
			leading_chars.insert(leading_chars.end(), term.at(0));
		}
		leading_chars.insert(leading_chars.end(), equation.result.at(0));
		return leading_chars;
	}

    long long ten_to_power(size_t exp) 
    {
        int ten_to_power{1}; 
        for (size_t i{0}; i < exp; ++i) { 
             ten_to_power *= 10;
        }	
        return ten_to_power;
    }

    CharMap calc_weight(std::string term_word, CharMap uniq_chars, int sign = 1) 
    {
       CharMap char_map{uniq_chars};
       int hi_pos = static_cast<int>(term_word.size()-1);
       for (int i{hi_pos}, j{0}; i >= 0; --i, ++j) {
           char c = term_word.at(j); 
           char_map.at(c) += (sign * ten_to_power(i)); 
       }
       return char_map;
    }

    CharMap combine_weights(Equation equation, CharMap uniq_chars) 
    {
        CharMap combined_map{uniq_chars};

        std::vector<std::map<char,int>> map_list;
        // get char weight map fo each left side term
        for (std::string term : equation.operands) {
            map_list.push_back(calc_weight(term, uniq_chars));
        }

        // the result char weights shouldbe substracted
        CharMap result_map = calc_weight(equation.result, uniq_chars, -1);
        map_list.push_back(result_map);
        // combine these maps 
        for (size_t i = 0; i < map_list.size(); ++i) {
            for (const auto& [key, value] : map_list[i]) {
                // Using operator[] safely accumulates values because keys are identical
                combined_map[key] += value;
            }
        }
        return combined_map;
    }

    bool digits_satisfy(CharMap digits_map, CharMap weights_map)
	{
        int total{0};
        for (const auto& [c, n] : digits_map) {
            auto w = weights_map[c];
            total += (w * n);
        }
        return total == 0;
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
        
        CharMap net_weights = combine_weights(equation, uniq_chars);

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
            
            if (digits_satisfy(uniq_chars, net_weights)){
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
    } // solve()

}  // namespace alphametics
