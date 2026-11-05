import gleam/bit_array
import gleam/int
import gleam/list
import gleam/result

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
    0 -> Ok(Adenine)
    1 -> Ok(Cytosine)
    2 -> Ok(Guanine)
    3 -> Ok(Thymine)
    _ -> Error(Nil)
  }
}

fn intcode_to_bitarray(b: Int) {
  b |> int.to_base2 |> bit_array.from_string
}

pub fn encode(dna: List(Nucleotide)) -> BitArray {
  dna
  |> list.fold(<<>>, fn(acc, bin) {
    let segment = encode_nucleotide(bin) |> intcode_to_bitarray
    <<acc:bits, segment:bits>>
  })
}

pub fn decode(dna: BitArray) -> Result(List(Nucleotide), Nil) {
  Ok(decode_helper(dna, []))
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
