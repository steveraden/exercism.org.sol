import gleam/result
import gleam/string

//import gleam/string_tree
import exercism/test_runner.{debug}

pub fn first_letter(name: String) {
  let trimmed_name = string.trim(name)
  case string.pop_grapheme(trimmed_name) {
    Ok(#(head, _tail)) -> head
    Error(_) -> ""
  }
}

pub fn initial(name: String) {
  let initial =
    name
    |> first_letter
    |> string.uppercase
  initial <> "."
}

pub fn initials(full_name: String) {
  let #(first, last) =
    full_name
    |> string.split_once(" ")
    |> result.unwrap(#("", ""))
  debug(initial(first))
  debug(initial(last))
  initial(first) <> " " <> initial(last)
}

pub fn pair(full_name1: String, full_name2: String) {
  let before =
    "
     ******       ******
   **      **   **      **
 **         ** **         **
**            *            **
**                         **
**     "
  let after =
    "     **
 **                       **
   **                   **
     **               **
       **           **
         **       **
           **   **
             ***
              *
"
  before <> initials(full_name1) <> "  +  " <> initials(full_name2) <> after

}
