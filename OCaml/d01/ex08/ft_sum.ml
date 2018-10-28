(*non-tail*)
(*let rec ft_sum f i n =
    if i > n then nan
    else if i = n then f i
    else f i +. ft_sum f (i + 1) n*)

let ft_sum f i n =
    if i > n then nan
    else let rec loop i acc =
        if i = n then acc +. f i
        else loop (i + 1) (acc +. f i)
    in loop i 0.0

let () =
    print_float (ft_sum (fun i -> float_of_int (i * i)) 1 10) ; print_char '\n';
    print_float (ft_sum (fun i -> float_of_int (i * i)) 1 0) ; print_char '\n'
