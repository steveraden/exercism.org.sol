import gleam/order.{type Order}
import gleam/float 
import gleam/list

pub type City {
  City(name: String, temperature: Temperature)
}

pub type Temperature {
  Celsius(Float)
  Fahrenheit(Float)
}

pub fn fahrenheit_to_celsius(f: Float) -> Float {
  { f -. 32.0 }  /. 1.8
}

pub fn compare_temperature(left: Temperature, right: Temperature) -> Order {
  let left_val = extract_celsius_val_from_temp(left)
  let right_val = extract_celsius_val_from_temp(right)
  float.compare(left_val, right_val)
}

fn compare_cities_by_temperature(city_left: City, city_right: City) -> Order {
  let City(left_name, left_temp) = city_left
  let City(right_name, right_temp) = city_right
  compare_temperature(left_temp, right_temp)
}

fn extract_celsius_val_from_temp(temp: Temperature) -> Float {
  case temp {
      Celsius(float) -> float
      Fahrenheit(float) -> fahrenheit_to_celsius(float)
  }
}

pub fn sort_cities_by_temperature(cities: List(City)) -> List(City) {
  list.sort(cities,  compare_cities_by_temperature)

}


