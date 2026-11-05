import gleam/list

pub type Pizza {
  Margherita
  Caprese
  Formaggio
  ExtraSauce(Pizza)
  ExtraToppings(Pizza)
}

pub fn pizza_price(pizza: Pizza) -> Int {
  pizza_price_helper(pizza, 0)
}

pub fn pizza_price_helper(pizza: Pizza, surcharge: Int) -> Int {
  case pizza {
    Margherita -> 7 + surcharge
    Caprese -> 9 + surcharge
    Formaggio -> 10 + surcharge
    ExtraSauce(pizza) -> pizza_price_helper(pizza, 1 + surcharge)
    ExtraToppings(pizza) -> pizza_price_helper(pizza, 2 + surcharge)
  }
}

pub fn order_price(order: List(Pizza)) -> Int {
  order_price_helper(order, 0) + calculate_surcharge(order)
}

fn calculate_surcharge(order: List(Pizza)) -> Int {
  case list.length(order) {
    x if x == 1 -> 3
    y if y == 2 -> 2
    _ -> 0
  }
}

fn order_price_helper(order: List(Pizza), acc: Int) {
  case order {
    [] -> acc
    [pizza, ..rest] -> {
      let acc = acc + pizza_price(pizza)
      order_price_helper(rest, acc)
    }
  }
}
