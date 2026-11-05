//import gleam/int

pub fn is_leap_year(year: Int) -> Bool {
  case year {
    year if year % 4 != 0 -> False
    year if year % 100 == 0 && year % 400 != 0 -> False
    _ -> True
  }
}
