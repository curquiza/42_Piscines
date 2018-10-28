let encode l =
    if l = [] then []
    else
        let rec loop current_list count rslt_list = match current_list with
        | head::second::tail when head = second -> loop (second::tail) (count + 1) rslt_list
        | head::tail                            -> loop (tail) 1 (rslt_list @ [(count, head)])
        | _                                     -> rslt_list
        in loop l 1 []


let rec ft_print_char_list l = match l with
    | head::tail -> print_char head ; ft_print_char_list tail
    | [] -> ()

let rec ft_print_tuples_list l = match l with
    | (count, elem)::tail   -> print_string "(" ; print_int count ; print_string "," ; print_char elem ; print_string ") " ; ft_print_tuples_list (tail)
    | _                     -> ()

let () =
    let l1 = ['a';'a';'a';'b';'b';'b';'c';'c';'c';'d';'a'] in
    let l2 = ['q';'w';'e';'e';'2';'2';'y'] in
    let l3 = [] in
    ft_print_char_list l1 ; print_string " ---> " ; ft_print_tuples_list (encode l1); print_char '\n' ;
    ft_print_char_list l2 ; print_string " ---> " ; ft_print_tuples_list (encode l2); print_char '\n' ;
    ft_print_char_list l3 ; print_string " ---> " ; ft_print_tuples_list (encode l3); print_char '\n'
