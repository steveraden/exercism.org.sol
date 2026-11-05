import gleam/list

fn sum_of_range(n: Int) -> Int{
  let out = case n {
    1 -> 1
    _ -> sum_of_range(n-1) + n
  }
  out
}

pub fn square_of_sum(n: Int) -> Int {
  let sum = sum_of_range(n)
  sum * sum 
}


pub fn sum_of_squares(n: Int) -> Int {
  let squares = list.map( list.range(1, n), fn(x) { x * x })
  list.fold(squares, 0,  fn(acc, a) { acc + a })
}

pub fn difference(n: Int) -> Int {
  square_of_sum(n) - sum_of_squares(n)
}
