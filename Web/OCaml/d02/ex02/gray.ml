let rec print_str_list l = match l with
    | h::t when t = [] -> print_string h ; print_str_list t
    | h::t  -> print_string h ; print_string " " ; print_str_list t
    | _     -> print_endline ""

let reverse l =
    let rec loop i rslt = match i with
    | h::t  -> loop (t) (h :: rslt)
    | _     -> rslt
    in loop l []

let rec concat_list l1 l2 = match l1 with
    | [] -> l2
    | head::tail -> head :: (concat_list tail l2)

(*let add_number_to_lst l num =
    let rec loop i n rslt = match i with
    | h::t  -> loop t n (concat_list rslt [n ^ h])
    | _     -> rslt
    in loop l num []*)

let rec add_number_to_lst l num = match l with
    | head::tail -> (num ^ head) :: add_number_to_lst tail num
    | _ -> []

let gray n =
    if n <= 0 then (print_endline "")
    else
        let rec loop i = match i with
        | i when i <= 1 -> ["0";"1"]
        | _             -> let prev = loop (i - 1) in
                           let rev_prev = (reverse prev) in
                           concat_list (add_number_to_lst prev "0") (add_number_to_lst rev_prev "1")
        in print_str_list (loop n)

let () =
    (*let l1 = ["1";"2";"3"] in
    print_str_list l1 ;
    print_str_list (reverse l1 []);
    print_str_list (add_number_to_lst l1 0 [])*)
    print_string "gray -42 -> " ; gray (-42);
    print_string "gray 0 -> " ; gray 0 ;
    print_string "gray 1 -> " ; gray 1 ;
    print_string "gray 2 -> " ; gray 2 ;
    print_string "gray 3 -> " ; gray 3 ;
    print_string "gray 4 -> " ; gray 4 ;

    (*print_str_list (concat_list ["titi";"mimi"] ["toto";"tata";"yo"])*)

