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
  case days {
    []-> False
    [0]-> True
    [0, _rest] -> True
    [_, ..rest] -> has_day_without_birds(rest)
  }
}

pub fn total(days: List(Int)) -> Int {
  //list.fold(over: days,  from: 0, with: fn(x,y) {x+y}) 
  sum(days, 0)
}
fn sum(list: List(Int), acc: Int) -> Int {
  case list {
    [] -> 0
    [x ]-> acc+x
    [x, ..rest] -> sum(rest, acc+x)
  }
}

pub fn busy_days(days: List(Int)) -> Int {
  busy_days_helper(days, 0)
}
fn busy_days_helper(days: List(Int), acc: Int) {
  case days { 
    [x, ..rest] -> case x, rest  {
      x, _  if x >= 5 -> busy_days_helper(rest, acc+1)
      _ , _  -> busy_days_helper(rest, acc)  
    }
    [] -> acc
  }
}



