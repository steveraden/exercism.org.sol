import gleam/list
import gleam/string as s
import exercism/test_runner.{ debug }

pub fn today(days: List(Int)) -> Int {
  case days {
    [] -> 0
    [x] -> x
    [x, ..] -> x
  }  
}

pub fn increment_day_count(days: List(Int)) -> List(Int) {
  case days {
    [] -> [1]
    [x, ..rest] -> [x+1, ..rest]
  }
}

pub fn has_day_without_birds(days: List(Int)) -> Bool {
  let zero_days = list.filter(days, fn(x) {x == 0})
  ! list.is_empty(zero_days) 
}

pub fn total(days: List(Int)) -> Int {
  list.fold(over: days,  from: 0, with: fn(x,y) {x+y}) 
}

pub fn busy_days(days: List(Int)) -> Int {
  let busy_days = list.filter(days, fn(x) {x >= 5})
  list.length(busy_days)
}
