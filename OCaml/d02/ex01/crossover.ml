(* marche mais moins élégant *)
(*let rec is_in_list l elem = match l with
    | head::tail when elem = head   -> true
    | head::tail                    -> is_in_list (tail) elem
    | _                             -> false*)

let rec is_in_list l elem = match l with
    | []         -> false
    | head::tail -> (head = elem) || is_in_list (tail) elem

let crossover l1 l2 =
    if l1 = [] || l2 = [] then []
    else
        let rec loop l1 l2 rslt =
            match l1 with
            | head::tail when (is_in_list l2 head) -> loop (tail) l2 (rslt @ [head])
            | head::tail    -> loop tail l2 rslt
            | _             -> rslt
        in loop l1 l2 []

let rec ft_print_int_list l =
    match l with
    | head::tail when tail = [] -> print_int head ; ft_print_int_list tail
    | head::tail -> print_int head ; print_string ";" ; ft_print_int_list tail
    | _             -> ()

let () =
    let l1 = [3;2;21;1] in
    let l2 = [1;4;(-1);12;21] in
    let l3 = [(-1)] in
    let l4 = [] in
    print_string "l1 = [" ; ft_print_int_list l1 ; print_endline "]" ;
    print_string "l2 = [" ; ft_print_int_list l2 ; print_endline "]" ;
    print_string "l3 = [" ; ft_print_int_list l3 ; print_endline "]" ;
    print_string "l4 = [" ; ft_print_int_list l4 ; print_endline "]" ;
    print_string "l1 && l2 --> [" ; ft_print_int_list (crossover l1 l2) ; print_endline "]" ;
    print_string "l1 && l3 --> [" ; ft_print_int_list (crossover l1 l3) ; print_endline "]" ;
    print_string "l2 && l3 --> [" ; ft_print_int_list (crossover l2 l3) ; print_endline "]" ;
    print_string "l1 && l1 --> [" ; ft_print_int_list (crossover l1 l1) ; print_endline "]" ;
    print_string "l1 && l4 --> [" ; ft_print_int_list (crossover l1 l4) ; print_endline "]";
    print_string "l4 && l4 --> [" ; ft_print_int_list (crossover l4 l4) ; print_endline "]"

