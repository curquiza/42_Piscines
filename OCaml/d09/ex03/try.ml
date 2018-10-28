module Try =
  struct
    type 'a t = Success of 'a | Failure of exn

    let return (value:'a) : 'a t = Success value

    let bind value f = match value with
    | Success (x) -> f x
    | _ -> Failure (Invalid_argument "failure")

    let recover value f = match value with
    | Failure (ex) -> f value
    | _ -> value

    let filter value f = match value with
    | Success x when f x -> value
    | Success x  -> Failure (Invalid_argument "failure")
    | Failure (ex) -> Failure ex

    let flatten value = match value with
      | Success (Success (x)) -> Success x
      | _ -> Failure (Invalid_argument "failure")

  end

let getInt value =
  match value with
  | Try.Success (x)   -> x
  | Try.Failure (ex)  -> 0

let () =
  let t = Try.return 12 in
  print_string "Bind 12 (function x -> Try.return (x - 2)) -> " ; print_int (getInt (Try.bind t (function x -> Try.return (x - 2)))); print_newline ();
  print_string "Recover Failure (function x -> Try.return (30)) -> " ; print_int (getInt (Try.recover (Failure (Invalid_argument "no arg")) (function x -> Try.return (30)))); print_char '\n';
  print_string "Recover (Try.return 5) (function x -> Try.return (30)) -> " ; print_int (getInt (Try.recover (Try.return (5)) (function x -> Try.return (30)))); print_char '\n';
  print_string "Filter (Try.return 5) (function x -> false) -> " ; print_int (getInt (Try.filter (Try.return (5)) (function x -> false))); print_char '\n';
  print_string "Filter (Try.return 5) (function x -> true) -> " ; print_int (getInt (Try.filter (Try.return (5)) (function x -> true))); print_char '\n';
  print_string "Flatten (Try.return (Try.return (42))) -> " ; print_int (getInt (Try.flatten (Try.return (Try.return (42))))); print_char '\n'
