import gleam/io
import gleam/list
import gleam/set.{type Set}
import gleam/string

pub fn new_collection(card: String) -> Set(String) {
  set.new() |> set.insert(card)
}

pub fn add_card(collection: Set(String), card: String) -> #(Bool, Set(String)) {
  case set.contains(collection, card) {
    True -> #(True, collection)
    False -> #(False, set.insert(collection, card))
  }
}

pub fn trade_card(
  my_card: String,
  their_card: String,
  collection: Set(String),
) -> #(Bool, Set(String)) {
  let is_good_trade =
    set.contains(collection, my_card) && !set.contains(collection, their_card)
  let collection_after_trade =
    collection
    |> set.delete(my_card)
    |> set.insert(their_card)
  #(is_good_trade, collection_after_trade)
}

pub fn boring_cards(collections: List(Set(String))) -> List(String) {
  collections
  |> list.fold(set.new(), accumulate_boring_cards)
  |> io.debug
  |> set.to_list
  |> list.sort(by: string.compare)
}

fn accumulate_boring_cards(
  accumulator: Set(String),
  collection: Set(String),
) -> Set(String) {
  case set.is_empty(accumulator) {
    True -> collection
    False -> {
      case set.is_disjoint(accumulator, collection) {
        True -> set.new()
        False -> set.intersection(accumulator, collection)
      }
    }
  }
}

pub fn total_cards(collections: List(Set(String))) -> Int {
  case collections {
    [] -> 0
    [first_set, ..rest] -> {
      collections
      |> list.fold(first_set, fn(a, s) { set.union(a, s) })
      |> set.size
      |> io.debug
    }
  }
}

pub fn shiny_cards(collection: Set(String)) -> Set(String) {
  collection
  |> set.filter(fn(card) { string.starts_with(card, "Shiny ") })
}
