import gleam/string

fn f() -> String {
  let level = ""
  let nebunk = "" 
  let f = "[" <> level  <> "]:" <> nebunk 
  f
}

pub fn message(log_line: String) -> String {
  case log_line { 
    "[INFO]:" <> message -> message
    "[ERROR]:" <> message -> message
    "[WARNING]:" <> message -> message
    _ -> ""
  } 
  |> string.trim
}

pub fn log_level(log_line: String) -> String {
  case log_line { 
    "[INFO]:" <> message -> "info"
    "[ERROR]:" <> message -> "error"
    "[WARNING]:" <> message -> "warning"
    _ -> ""  
  }
}

pub fn reformat(log_line: String) -> String {
   message(log_line ) <> " (" <> log_level(log_line) <> ")"
}

