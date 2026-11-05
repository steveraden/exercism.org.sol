// Please define the TreasureChest generic custom type
pub type TreasureChest(t) {
  TreasureChest( password: String, treasure: t)
}

// Please define the UnlockResult generic custom type
pub type UnlockResult(t) {
  Unlocked(treasure: t)
  WrongPassword
}

pub fn get_treasure(
  chest: TreasureChest(treasure),
  password: String,
) -> UnlockResult(treasure) {
  let password_check = chest.password == password
  let treasure = chest.treasure
  case password_check {
    True -> Unlocked(treasure)
    False -> WrongPassword
  }
}
