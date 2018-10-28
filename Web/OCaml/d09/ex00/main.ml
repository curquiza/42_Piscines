module Watchtower =
  struct
    type hour = int
    let zero:hour = 12

    let add (a:hour) (b:hour) =
      match ((a + b) mod zero) with
      | x when x = 0 -> zero
      | x -> x

    let sub (a:hour) (b:hour) =
      match ((a - b) mod zero) with
      | x when x < 0 -> x + zero
      | x when x = 0 -> zero
      | x -> x
  end

let () =
  let h1:Watchtower.hour = 4 in
  let h2:Watchtower.hour = 15 in
  let h3:Watchtower.hour = 1 in
  print_endline "** ADD **" ;
  print_string "4 + 15 -> " ; print_int (Watchtower.add h1 h2) ; print_newline () ;
  print_string "4 + 1  -> " ; print_int (Watchtower.add h1 h3) ; print_newline () ;
  print_string "4 + 8  -> " ; print_int (Watchtower.add 4 8) ; print_newline () ;
  print_string "4 + 21 -> " ; print_int (Watchtower.add 4 21) ; print_newline () ;
  print_string "4 + 20 -> " ; print_int (Watchtower.add 4 20) ; print_newline () ;
  print_endline "** SUB **" ;
  print_string "4 - 15 -> " ; print_int (Watchtower.sub h1 h2) ; print_newline () ;
  print_string "4 - 1  -> " ; print_int (Watchtower.sub h1 h3) ; print_newline () ;
  print_string "7 - 10 -> " ; print_int (Watchtower.sub 7 10) ; print_newline () ;
  print_string "7 - 7  -> " ; print_int (Watchtower.sub 7 7) ; print_newline () ;
  print_string "7 - 21 -> " ; print_int (Watchtower.sub 7 21) ; print_newline () ;
  print_string "7 - 19 -> " ; print_int (Watchtower.sub 7 19) ; print_newline () ;
