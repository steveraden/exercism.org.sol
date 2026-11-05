import gleam/result

pub fn with_retry(experiment: fn() -> Result(t, e)) -> Result(t, e) {
 case experiment() {
  Ok(t) -> Ok(t)
  Error(e) -> experiment()
 }
}

pub fn record_timing(
  time_logger: fn() -> Nil,
  experiment: fn() -> Result(t, e),
) -> Result(t, e) {
  time_logger()
  let result = experiment()
  time_logger()
  result
}

pub fn run_experiment(
  name: String,
  setup: fn() -> Result(t, e),
  action: fn(t) -> Result(u, e),
  record: fn(t, u) -> Result(v, e),
) -> Result(#(String, v), e) {
  use config <- result.try(setup())
  use action_result <- result.try(action(config))
  use experiment_result <- result.try(record(config, action_result))
  Ok(#(name, experiment_result) )
}
