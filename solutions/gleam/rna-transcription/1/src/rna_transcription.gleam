import gleam/string
import gleam/list
import gleam/result

pub fn to_rna(dna: String) -> Result(String, Nil) {
  let a = dna
    |> string.to_graphemes
    |> list.map(dna_char_to_rna)
    |> result.all
    |> result.map( fn(l) { string.join(l, with: "")}) 
  a
}

fn dna_char_to_rna(dna_char: String) -> Result(String, Nil) {
  case dna_char {
    "G" -> Ok("C")
    "C" -> Ok("G")
    "T" -> Ok("A")
    "A" -> Ok("U")
     _ -> Error(Nil)
  }
}
