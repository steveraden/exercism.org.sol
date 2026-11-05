import gleam/dict.{type Dict}
import gleam/result
import gleam/int

pub type ScoreBoard =
  Dict(String, Int)

pub fn create_score_board() -> ScoreBoard {
  let score_board = dict.new()
  dict.insert(score_board, "The Best Ever", 1_000_000)
}

pub fn add_player(
  score_board: ScoreBoard,
  player: String,
  score: Int,
) -> ScoreBoard {
    dict.insert(score_board, player, score)
}

pub fn remove_player(score_board: ScoreBoard, player: String) -> ScoreBoard {
  dict.delete(score_board, player)
}

pub fn update_score(
  score_board: ScoreBoard,
  player: String,
  points: Int
) -> ScoreBoard {
      case dict.get(score_board, player) {
        Ok(current_score) ->
          // update the player score in the scoreboard
          dict.insert(score_board, player,  points+current_score)
        //  return existing score_board if no player found   
        _ ->  score_board
      }
}

pub fn apply_monday_bonus(score_board: ScoreBoard) -> ScoreBoard {
  dict.map_values(score_board, fn(k,v){v + 100})
}
