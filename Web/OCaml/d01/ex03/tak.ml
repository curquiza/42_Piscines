let rec tak x y z =
    if y < x then tak (tak (x - 1) y z) (tak (y - 1) z x) (tak (z - 1) x y)
    else z

let () =
    print_string "tak(0,0,0) = " ; print_int (tak 0 0 0); print_char '\n';
    print_string "tak(-1,1,0) = " ; print_int (tak (-1) 1 0); print_char '\n';
    print_string "tak(2,-1,4) = " ; print_int (tak 2 (-1) 4); print_char '\n';
    print_string "tak(2,1,-4) = " ; print_int (tak 2 1 (-4)); print_char '\n';
    print_string "tak(1,2,3) = " ; print_int (tak 1 2 3); print_char '\n';
    print_string "tak(5,23,7) = " ; print_int (tak 5 23 7); print_char '\n';
    print_string "tak(9,1,0) = " ; print_int (tak 9 1 0); print_char '\n';
    print_string "tak(1,1,1) = " ; print_int (tak 1 1 1); print_char '\n';
    print_string "tak(0,42,0) = " ; print_int (tak 0 42 0); print_char '\n';
    print_string "tak(23498,98734,98776) = " ; print_int (tak 23498 98734 98776); print_char '\n'
