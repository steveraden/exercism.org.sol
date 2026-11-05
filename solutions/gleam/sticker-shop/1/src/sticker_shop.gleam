import gleam/int
import gleam/list

pub type Usd

pub type Eur

pub type Jpy

pub opaque type Money(currency) {
  Money(amount: Int)
}

// Please define the Money type

pub fn dollar(amount: Int) -> Money(Usd) {
  Money(amount: amount)
}

pub fn euro(amount: Int) -> Money(Eur) {
  Money(amount: amount)
}

pub fn yen(amount: Int) -> Money(Jpy) {
  Money(amount: amount)
}

pub fn total(prices: List(Money(currency))) -> Money(currency) {
  let amounts = list.map(prices, fn(price) { price.amount })
  let total_amount = list.fold(amounts, 0, int.add)
  Money(amount: total_amount)
}
