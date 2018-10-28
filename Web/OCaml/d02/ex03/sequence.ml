let encode l =
    if l = [] then []
    else
        let rec loop current_list count rslt_list = match current_list with
        | head::second::tail when head = second -> loop (second::tail) (count + 1) rslt_list
        | head::tail                            -> loop (tail) 1 (rslt_list @ [count;head])
        | _                                     -> rslt_list
        in loop l 1 []

let int_list_to_str liste =
    let rec loop l rslt = match l with
    | head::tail    -> loop tail (rslt ^ (string_of_int head))
    | _             -> rslt
    in loop liste ""

let sequence n =
    if n <= 0 then ""
    else let rec loop i = match i with
    | x when x = 1  -> [1]
    | _             -> let prev = loop (i - 1) in encode prev
    in int_list_to_str (loop n)

let () =
    print_string "S(-1) -> "; print_endline (sequence (-1));
    print_string "S(0)  -> "; print_endline (sequence 0);
    print_string "S(1)  -> "; print_endline (sequence 1);
    print_string "S(2)  -> "; print_endline (sequence 2);
    print_string "S(3)  -> "; print_endline (sequence 3);
    print_string "S(4)  -> "; print_endline (sequence 4);
    print_string "S(5)  -> "; print_endline (sequence 5);
    print_string "S(6)  -> "; print_endline (sequence 6);
    print_string "S(7)  -> "; print_endline (sequence 7);
    print_string "S(8)  -> "; print_endline (sequence 8);
    print_string "S(9)  -> "; print_endline (sequence 9)

