
pub type Approval{
  Yes
  No
  Maybe
}
pub type Cuisine{
   Korean
   Turkish
}
pub type Genre {
   Crime
   Horror
   Romance
   Thriller
}
pub type Activity {  
    BoardGame
    Chill
    Movie(Genre)
    Restaurant(Cuisine)
    Walk(Int)
}

pub fn rate_activity(activity: Activity) -> Approval {
  case activity{
    BoardGame -> No
    Chill -> No
    Movie(genre)-> case genre {
        genre if genre == Romance -> Yes
        _ -> No
    }
    Restaurant(cuisine)-> case cuisine {
        cuisine if cuisine == Korean -> Yes
        cuisine if cuisine == Turkish -> Maybe
        _ -> No
    }  
    Walk(length) -> case length {
        length if length > 11 -> Yes
        length if length > 6 -> Maybe
        _ -> No
     } 
  }
}