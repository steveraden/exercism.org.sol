import gleam/list
import gleam/result
import gleam/string
import simplifile as sf

pub fn read_emails(path: String) -> Result(List(String), Nil) {
  case sf.read(path) {
    Ok(list_in_string) -> {
      let result_list =
        list_in_string
        |> string.trim
        |> string.split("\n")
      Ok(result_list)
    }
    Error(_) -> Error(Nil)
  }
}

pub fn create_log_file(path: String) -> Result(Nil, Nil) {
  case sf.write(path, "") {
    Ok(Nil) -> Ok(Nil)
    Error(_) -> Error(Nil)
  }
}

pub fn log_sent_email(path: String, email: String) -> Result(Nil, Nil) {
  case sf.append(path, email <> "\n") {
    Ok(Nil) -> Ok(Nil)
    Error(_) -> Error(Nil)
  }
}

pub fn send_newsletter(
  emails_path: String,
  log_path: String,
  send_email: fn(String) -> Result(Nil, Nil),
) -> Result(Nil, Nil) {
  use emails <- result.try(read_emails(emails_path))
  let _no_op = create_log_file(log_path)

  let _send_email_results =
    list.map(emails, fn(email) {
      use send_result <- result.try(send_email(email))
      use _log_result <- result.try(log_sent_email(log_path, email))
      Ok(send_result)
    })
  Ok(Nil)
}
