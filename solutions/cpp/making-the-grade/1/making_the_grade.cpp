#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int>rounded_scores{};
    for ( double score : student_scores) {
       rounded_scores.push_back(static_cast<int>(score));
    }
    return rounded_scores;    
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int fail_count{0};
    for ( double score : student_scores) {
       if (score <= 40 ) {
           fail_count++;
       }
    }
    return fail_count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int window_size = highest_score - 40;
    int increment = (window_size/4);
    return std::array{41, 41+increment, 41+increment*2, 41+increment*3};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranked_scores{};
    std::string ranked_score{};
    for (int i{0};  i < student_scores.size(); i++ ){
        ranked_score = std::to_string(i +1)
                       + ". " 
                       + student_names.at(i)
                       + ": "
                       + std::to_string(student_scores.at(i));
        ranked_scores.push_back(ranked_score);
    }
    return ranked_scores;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (int i{0};  i < student_scores.size(); i++ ){
         if (student_scores.at(i)  == 100) {
             return student_names.at(i);
         }
     }       
     // there was no winner
     return "";        
}
