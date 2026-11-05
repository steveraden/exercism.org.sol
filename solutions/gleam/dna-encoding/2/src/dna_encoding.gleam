import gleam/bit_array
import gleam/int
import gleam/list

//import gleam/result
import gleam/io

pub type Nucleotide {
  Adenine
  Cytosine
  Guanine
  Thymine
}

pub fn encode_nucleotide(nucleotide: Nucleotide) -> Int {
  case nucleotide {
    Adenine -> 0b00
    Cytosine -> 0b01
    Guanine -> 0b010
    Thymine -> 0b011
  }
}

pub fn decode_nucleotide(nucleotide: Int) -> Result(Nucleotide, Nil) {
  case nucleotide {
    0b00 -> Ok(Adenine)
    0b01 -> Ok(Cytosine)
    0b010 -> Ok(Guanine)
    0b011 -> Ok(Thymine)
    _ -> Error(Nil)
  }
}

pub fn encode(dna: List(Nucleotide)) -> BitArray {
  list.fold(dna, <<>>, fn(acc, nucleotide) {
    <<acc:bits, encode_nucleotide(nucleotide):2>>
  })
}

pub fn decode(dna: BitArray) -> Result(List(Nucleotide), Nil) {
  case decode_helper(dna, []) {
    [head, ..tail] -> Ok([head, ..tail])
    _ -> Error(Nil)
  }
}

fn decode_helper(dna: BitArray, acc: List(Nucleotide)) -> List(Nucleotide) {
  case dna {
    <<>> -> acc
    <<value:2, rest:bits>> -> {
      case rest, decode_nucleotide(value) {
        rest, Ok(nucleotide) ->
          decode_helper(rest, list.append(acc, [nucleotide]))
        _, Error(Nil) -> []
      }
    }
    _ -> []
  }
}
