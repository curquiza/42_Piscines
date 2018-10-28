let rec converges f x n =
    if n < 0 then false
    else if x = f x then true
    else converges f (f x) (n - 1)

(*let converges f x n =
    if n < 0 then false
    else
        let loop f x n acc =
            if x = f x then acc
            else loop f  (n - 1) (f x)*)

let () =
    print_string (string_of_bool (converges (( * ) 2) 2 5)) ; print_char '\n';
    print_string (string_of_bool (converges (fun x -> x / 2) 2 3)) ; print_char
    '\n';
    print_string (string_of_bool (converges (fun x -> x / 2) 2 2)) ; print_char '\n'
