let rec repeat_x n =
    if n < 0 then "Error"
    else if n = 0 then ""
    else "x" ^ (repeat_x (n - 1))

let () =
    print_int 1 ; print_string " -> " ; print_endline (repeat_x 1) ;
    print_int 13 ; print_string " -> " ; print_endline (repeat_x 13) ;
    print_int 0 ; print_string " -> " ; print_endline (repeat_x 0) ;
    print_int (-128) ; print_string " -> " ; print_endline (repeat_x (-128)) ;
    print_int 42 ; print_string " -> " ; print_endline (repeat_x 42);
    print_int 4 ; print_string " -> " ; print_endline (repeat_x 4)
