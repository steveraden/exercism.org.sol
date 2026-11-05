#include "alphametics.h"
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <type_traits>

namespace alphametics {
    typedef std::unordered_map<char, int> CharMap; 

    struct Puzzle {
        std::vector<std::string> terms{};
        std::string result{};
        size_t max_len{0};
        std::vector<std::string> padded_terms{};
        std::string padded_result{};
        std::unordered_set<char> leading_chars{};
        CharMap char_to_digit{};
        std::vector<int> assigned_digits{};
    };

    std::string_view trim(std::string_view s) {
        const std::string_view whitespace = " \t\n\r\f\v";
        size_t start = s.find_first_not_of(whitespace);
        if (start == std::string_view::npos) return ""; // All whitespace
        size_t end = s.find_last_not_of(whitespace);
        return s.substr(start, end - start + 1);
    }

    std::vector<std::string> split(std::string_view str, std::string_view delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end = str.find(delimiter);
        while (end != std::string::npos) {
            // Zero allocations happen during the trim step here
            tokens.emplace_back(trim(str.substr(start, end - start)));
            start = end + delimiter.length();
            end = str.find(delimiter, start);
        }
        tokens.emplace_back(trim(str.substr(start)));
        return tokens;
    }

    // use is_associative trait to create a contains method
    // 1. Primary trait defaults to false
    template <typename T> struct is_associative : std::false_type {};
    // 2. Simple one-line overrides for the standard sets and maps
    //template <typename... Args> struct is_associative<std::set<Args...>> : std::true_type {};
    template <typename... Args> struct is_associative<std::unordered_set<Args...>> : std::true_type {};
    template <typename... Args> struct is_associative<std::map<Args...>> : std::true_type {};
    template <typename... Args> struct is_associative<std::unordered_map<Args...>> : std::true_type {};

    template <typename Container, typename T>
    bool contains(const Container& container, const T& value) 
    {
        if constexpr (is_associative<Container>::value) { 
            return container.find(value) != container.end();
        } else {
            return std::find(std::begin(container), std::end(container), value) != std::end(container);
        }
    }

    std::string pad_string_to_len(std::string str, size_t max_len) 
    {
        if (str.length() < max_len) {
            str.insert(0, max_len - str.length(), '0');
        }
        return str;
    }

    size_t get_max_len(const std::vector<std::string> &terms, 
            const std::string &result) 
    {
        auto longest = std::max_element(terms.begin(), terms.end(), 
                [](const std::string& a, const std::string& b) {
                return a.length() < b.length();
                }); 

        size_t max_len = (longest != terms.end()) ? longest->length() : 0;

        return std::max(max_len, result.length());
    }


    std::unordered_set<char> leading_characters(Puzzle puzzle) 
    {
        std::unordered_set<char> leading_chars;
        for (auto term : puzzle.terms ) {
            leading_chars.insert(leading_chars.end(), term.at(0));
        }
        leading_chars.insert(leading_chars.end(), puzzle.result.at(0));
        return leading_chars;
    }

    Puzzle init_puzzle(std::string puzzle_str) 
    {
        std::vector<std::string> expressions = split(puzzle_str, "==");
        std::vector<std::string> terms = split(expressions.at(0), "+");
        const std::string &result_word = expressions.at(1);
        Puzzle puzzle{};
        puzzle.terms = terms;
        puzzle.result = result_word;
        puzzle.max_len = get_max_len(terms, result_word);
        //puzzle.uniq_chars = unique_characters(puzzle);	
        puzzle.leading_chars = leading_characters(puzzle);
        puzzle.padded_result = pad_string_to_len(result_word, puzzle.max_len);
        for (std::string &term : puzzle.terms) {
            puzzle.padded_terms.push_back(
                    pad_string_to_len(term, puzzle.max_len));
        }
        return puzzle;
    }

    bool backtrack(const size_t column, 
                   const size_t word_idx, 
                   const int current_sum,
                   Puzzle& puzzle) 
    {
        // Base case: all columns have been processed
        if (column == puzzle.max_len) {
            // The final carry must be 0 for the cryptarithm to balance
            return current_sum == 0;
        }
        
        auto& [terms, 
             result, 
             max_len, 
             padded_terms,
             padded_result,
             leading_chars, 
             char_to_digit, 
             assigned_digits] = puzzle;

        // Finished summing all words in the current column
        if (word_idx == padded_terms.size()) {
            char target_char = padded_result[max_len - 1 - column];
            int expected_digit = current_sum % 10;
            int carry = current_sum / 10;

            // If result position is just padding ('0'), it must match a zero carry
            if (target_char == '0' && (max_len - 1 - column) < (max_len - result.length())) {
                if (expected_digit == 0) {
                    return backtrack(column + 1, 0, carry, puzzle);
                }
                return false;
            }

            // Case 1: Target character is already assigned
            if (contains(char_to_digit, target_char)) {
                // Check if the assigned digit matches our column sum requirements
                if (char_to_digit.at(target_char) == expected_digit) {
                    return backtrack(column + 1, 0, carry, puzzle);
                }
                return false; // Mismatch
            }

            // Case 2: Target character is unassigned
            // Reject if the digit it needs is already taken by another letter
            if (contains(assigned_digits, expected_digit)) {
                return false;
            }

            // Reject zero assignment to a leading character
            if (expected_digit == 0 && contains(leading_chars, target_char)) {
                return false;
            }

            // Assign
            char_to_digit[target_char] = expected_digit;
            assigned_digits.push_back(expected_digit);

            // Explore
            if (backtrack(column + 1, 0, carry, puzzle)) {
                return true;
            }
                
            // Backtrack
            char_to_digit.erase(target_char);
            assigned_digits.erase(
                    std::remove(assigned_digits.begin(), assigned_digits.end(), expected_digit), 
                    assigned_digits.end());
                    
            return false;
        }
        
        // Process current word in current column
        auto current_word = padded_terms[word_idx];
        auto char_pos = max_len - 1 - column;
        
        // If this word doesn't extend to this column (it's padded), skip to next word
        if (char_pos < max_len - terms[word_idx].length()) {
            return backtrack(column, word_idx + 1, current_sum, puzzle);
        }
        
        auto c = current_word.at(char_pos);
        
        // Case A: Character is already assigned a digit
        if (contains(char_to_digit, c)) {
            return backtrack(column, word_idx + 1, current_sum + char_to_digit.at(c), puzzle);
        } 

        // Case B: Character is unassigned; try available digits
        for (int digit = 0; digit <= 9; ++digit) {
            if (contains(assigned_digits, digit)) continue;
            if (digit == 0 && contains(leading_chars, c)) continue;
                
            // Assign
            char_to_digit[c] = digit;
            assigned_digits.push_back(digit);

            // Explore
            if (backtrack(column, word_idx + 1, current_sum + digit, puzzle)) {
                return true;
            }

            // Backtrack
            char_to_digit.erase(c);
            assigned_digits.erase(
                    std::remove(assigned_digits.begin(), assigned_digits.end(), digit), 
                    assigned_digits.end());
        }

        return false;
    }



    /* solve() */
    std::optional<std::unordered_map<char, int>> 
    solve(const std::string puzzle_str)
    {
        Puzzle puzzle = init_puzzle(puzzle_str);

        if (backtrack(0, 0, 0, puzzle)) {
            return std::make_optional(puzzle.char_to_digit);
        } else {
            return std::nullopt;
        }
    } // solve()

}  // namespace alphametics
