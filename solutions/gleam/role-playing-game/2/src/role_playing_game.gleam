import gleam/option.{type Option, Some, None}

pub type Player {
  Player(
        name: Option(String), 
        level: Int, 
        health: Int, 
        mana: Option(Int)
)}

pub fn introduce(player: Player) -> String {
  option.unwrap(player.name, or: "Mighty Magician")
}

pub fn revive(player: Player) -> Option(Player) {
  case player.health, player.level {
    0, l if l < 10 
       -> Some(Player(..player, health: 100))
    0, l if l >= 10 
        -> Some(Player(..player, health: 100, mana: Some(100)))
    _, _  -> None
  }
}

pub fn cast_spell(player: Player, cost: Int) -> #(Player, Int) { 
  case player.mana  {
    None -> {
      let health_cost =   player.health - cost
      let new_health = case health_cost {
        n if n <= 0   -> 0
        _             -> health_cost
      }
      #(Player(..player, health: new_health, mana: None), 0)
    }
    Some(mana) -> 
        case mana - cost {
          new_mana if new_mana > 0 -> {
            let damage = 2 * cost 
            #(Player(..player, mana: Some(new_mana)), damage)
          } 
          new_mana if new_mana <= 0  -> #(player, 0)
          _ -> #(player, 0)
        }
  }

}