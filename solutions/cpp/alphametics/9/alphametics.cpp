#include "alphametics.h"
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

namespace alphametics {

    struct Puzzle {
        std::vector<std::string> terms{};
        std::string result{};
        size_t max_len{0};
        std::vector<std::string> padded_terms{};
        std::string padded_result{};
        std::array<bool, 256> is_leading{}; // Changed to fast lookup array
        std::array<int, 256> char_to_digit{};
        std::array<bool, 10> assigned_digits{}; 
    };

    std::string_view trim(std::string_view s) {
        const std::string_view whitespace = " \t\n\r\f\v";
        size_t start = s.find_first_not_of(whitespace);
        if (start == std::string_view::npos) return ""; 
        size_t end = s.find_last_not_of(whitespace);
        return s.substr(start, end - start + 1);
    }

    std::vector<std::string> split(std::string_view str, std::string_view delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end = str.find(delimiter);
        while (end != std::string::npos) {
            tokens.emplace_back(trim(str.substr(start, end - start)));
            start = end + delimiter.length();
            end = str.find(delimiter, start);
        }
        tokens.emplace_back(trim(str.substr(start)));
        return tokens;
    }

    std::string pad_string_to_len(std::string str, size_t max_len) 
    {
        if (str.length() < max_len) {
            str.insert(0, max_len - str.length(), '0');
        }
        return str;
    }

    size_t get_max_len(const std::vector<std::string> &terms, const std::string &result) 
    {
        auto longest = std::max_element(terms.begin(), terms.end(), 
                [](const std::string& a, const std::string& b) {
                return a.length() < b.length();
                }); 
        size_t max_len = (longest != terms.end()) ? longest->length() : 0;
        return std::max(max_len, result.length());
    }

    void populate_leading_characters(const std::vector<std::string>& terms, const std::string& result, std::array<bool, 256>& is_leading) 
    {
        is_leading.fill(false);
        for (const auto& term : terms) {
            if (!term.empty()) {
                is_leading[static_cast<unsigned char>(term.at(0))] = true;
            }
        }
        if (!result.empty()) {
            is_leading[static_cast<unsigned char>(result.at(0))] = true;
        }
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
        
        populate_leading_characters(puzzle.terms, puzzle.result, puzzle.is_leading);
        
        puzzle.padded_result = pad_string_to_len(result_word, puzzle.max_len);
        puzzle.char_to_digit.fill(-1);
        puzzle.assigned_digits.fill(false);
        
        for (std::string &term : puzzle.terms) {
            puzzle.padded_terms.push_back(pad_string_to_len(term, puzzle.max_len));
        }
        return puzzle;
    }

    bool backtrack(const size_t column, 
            const size_t word_idx, 
            const int current_sum,
            Puzzle& puzzle) 
    {
        if (column == puzzle.max_len) {
            return current_sum == 0;
        }

        auto& [terms, 
            result, 
            max_len, 
            padded_terms,
            padded_result,
            is_leading, 
            char_to_digit, 
            assigned_digits] = puzzle;

        // Finished summing all words in the current column
        if (word_idx == padded_terms.size()) {
            char target_char = padded_result[max_len - 1 - column];
            
            // Handle negative sums defensively, keeping result strictly between 0 and 9
            int expected_digit = (current_sum % 10 + 10) % 10;
            int carry = (current_sum - expected_digit) / 10;

            if (target_char == '0' && (max_len - 1 - column) < (max_len - result.length())) {
                if (expected_digit == 0) {
                    return backtrack(column + 1, 0, carry, puzzle);
                }
                return false;
            }

            unsigned char u_target = static_cast<unsigned char>(target_char);

            // Case 1: Target character is already assigned
            if (char_to_digit[u_target] != -1) {
                if (char_to_digit[u_target] == expected_digit) {
                    return backtrack(column + 1, 0, carry, puzzle);
                }
                return false; 
            }

            // Case 2: Target character is unassigned
            if (assigned_digits[expected_digit]) {
                return false;
            }

            // Reject zero assignment to a leading character
            if (expected_digit == 0 && is_leading[u_target]) {
                return false;
            }

            // Assign
            char_to_digit[u_target] = expected_digit;
            assigned_digits[expected_digit] = true;

            // Explore
            if (backtrack(column + 1, 0, carry, puzzle)) {
                return true;
            }

            // Backtrack
            char_to_digit[u_target] = -1;
            assigned_digits[expected_digit] = false;

            return false;
        }

        // Process current word in current column
        const auto& current_word = padded_terms[word_idx];
        auto char_pos = max_len - 1 - column;

        if (char_pos < max_len - terms[word_idx].length()) {
            return backtrack(column, word_idx + 1, current_sum, puzzle);
        }

        unsigned char c = static_cast<unsigned char>(current_word.at(char_pos));

        if (char_to_digit[c] != -1) {
            return backtrack(column, word_idx + 1, current_sum + char_to_digit[c], puzzle);
        } 

        // Case B: Character is unassigned; try available digits
        for (int digit = 0; digit <= 9; ++digit) {
            if (assigned_digits[digit]) continue;
            if (digit == 0 && is_leading[c]) continue;

            // Assign
            char_to_digit[c] = digit;
            assigned_digits[digit] = true;

            // Explore
            if (backtrack(column, word_idx + 1, current_sum + digit, puzzle)) {
                return true;
            }

            // Backtrack
            char_to_digit[c] = -1;
            assigned_digits[digit] = false;
        }

        return false;
    } // backtrack()

    std::optional<std::unordered_map<char, int>> 
    solve(const std::string puzzle_str)
    {
        Puzzle puzzle = init_puzzle(puzzle_str);
          
        if (backtrack(0, 0, 0, puzzle)) {
            std::unordered_map<char, int> result_map{};
            for (size_t i{0}; i < puzzle.char_to_digit.size(); ++i) {
                 int digit = puzzle.char_to_digit[i];
                 if (digit != -1) {
                    result_map[i] = digit;       
                 }
            }
            return std::make_optional(result_map);
        } else {
            return std::nullopt;
        }
    } // solve()
}

