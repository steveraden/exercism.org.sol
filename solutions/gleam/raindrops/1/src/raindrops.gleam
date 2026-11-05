import gleam/int
import gleam/string
import gleam/string_tree
import exercism/test_runner.{ debug }

pub fn convert(number: Int) -> String {
  let output = string_tree.new()
  let output = case number {
    number if number % 3 == 0 -> string_tree.append(output, "Pling")
    _ -> string_tree.append(output, "")
  } 
  let output = case number {
    number if number % 5 == 0 -> string_tree.append(output, "Plang")
    _ -> string_tree.append(output, "")
  }
  let output = case number {
    number if number % 7 == 0 -> string_tree.append(output, "Plong")
    _ -> string_tree.append(output, "")
  }
  debug(number % 5 )
  debug(output)
  debug(string_tree.is_empty(output))
  case string_tree.is_empty(output){
    True -> int.to_string(number)
    False -> string_tree.to_string(output)
  }
}
