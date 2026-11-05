import gleam/float
import gleam/int
import gleam/io
import gleam/list
import gleam/result
import gleam/string

pub fn is_armstrong_number(number: Int) -> Bool {
  // perform the work of the late great int.digits() function
  //io.debug("***********************************************************")
  //io.debug("Number: ")
  //io.debug(number)
  //io.debug("***********************************************************")

  let digits =
    number
    |> int.to_string
    |> string.to_graphemes
    |> list.map(fn(c) { int.parse(c) })
    |> list.map(fn(r) { result.unwrap(r, or: 0) })

  //  io.debug("***********************************************************")
  // io.debug("Digits: ")
  // io.debug(digits)
  //io.debug("***********************************************************")

  let power = list.length(digits)
  // get a list of the digits raised to the power the of the number of 
  // and take their sum
  let sum_of_digits =
    digits
    |> list.map(fn(x) { raise_number_by_power(x, power) })
    |> list.fold(0, fn(a, x) { a + x })

  // io.debug("***********************************************************")
  // io.debug("Sum of Digits: ")
  // io.debug(sum_of_digits)
  // io.debug("***********************************************************")

  case sum_of_digits {
    s if s == number -> True
    _ -> False
  }
}

fn raise_number_by_power(x: Int, power: Int) -> Int {
  let assert Ok(y) =
    power
    |> int.to_float
    |> int.power(x, _)
    |> result.map(float.round)
  y
}
