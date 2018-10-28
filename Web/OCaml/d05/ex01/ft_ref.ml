type 'a ft_ref = { mutable contents : 'a }

let return r = { contents = r }

let get r = r.contents

let set r v = r.contents <- v

let bind r f:('b ft_ref) = f r.contents

let () =
  print_endline "Create ref with value 42" ;
  let r = return 42 in
  print_string "Print the value -> " ; print_int (get r); print_newline ();
  print_endline "Set a new value 1" ; set r 1 ;
  print_string "Print the value -> " ; print_int (get r) ; print_newline ();
  print_string "Apply function fun x -> x + 2 and print the value -> " ;
  print_int (get (bind r (function x -> return (x + 2)))) ; print_newline ()
