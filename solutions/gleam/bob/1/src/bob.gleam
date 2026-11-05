import gleam/regexp 
import gleam/string

pub fn hey(remark: String) -> String {
  let trimmed_remark = string.trim(remark)
  case 
    is_question(trimmed_remark), 
    is_yelling(trimmed_remark), 
    is_silent(trimmed_remark) {

      //  a question
      True, False, False -> "Sure."
      // a question with white space
      True, False, True -> "Sure."
      // yelling
      False, True, False -> "Whoa, chill out!"
      // yelling question
      True, True, False -> "Calm down, I know what I'm doing!"
      // silence
      _, _, True -> "Fine. Be that way!"
      // other 
      _, _, False -> "Whatever."
    }
}

fn is_yelling(remark: String) -> Bool {
  remark == string.uppercase(remark) 
  && remark != string.lowercase(remark)
}

fn is_question(remark: String) -> Bool {
  string.ends_with(remark, "?")
}

fn is_silent(remark: String) -> Bool {
  string.is_empty(remark) 
}
