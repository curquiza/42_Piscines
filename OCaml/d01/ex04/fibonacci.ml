(*let rec fibonacci n =
    if n < 0 then (-1)
    else if n = 0 then 0
    else if n = 1 then 1
    else (fibonacci (n - 2)) + (fibonacci (n - 1))*)

let fibonacci n =
    if n < 0 then (-1)
    else
        let rec fibo_aux m acc1 acc2 =
            if m <= 0 then acc1
            else if m = 1 then acc2
            else fibo_aux (m - 1) acc2 (acc1 + acc2)
        in fibo_aux n 0 1

let () =
    print_string "f(-1) = " ; print_int (fibonacci (-1)) ; print_char '\n';
    print_string "f(0) = " ; print_int (fibonacci 0) ; print_char '\n';
    print_string "f(1) = " ; print_int (fibonacci 1) ; print_char '\n';
    print_string "f(3) = " ; print_int (fibonacci 3) ; print_char '\n';
    print_string "f(6) = " ; print_int (fibonacci 6) ; print_char '\n';
    print_string "f(12) = " ; print_int (fibonacci 12) ; print_char '\n'
