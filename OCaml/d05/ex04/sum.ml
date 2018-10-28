let sum f1 f2 = f1 +. f2

let () =
  print_string "1.1 + 1.2 = " ; print_float (sum 1.1 1.2) ; print_newline ();
  print_string "2.0 + 1.0 = " ; print_float (sum 2.0 1.0) ; print_newline ();
