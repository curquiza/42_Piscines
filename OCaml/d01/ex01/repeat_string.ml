let rec repeat_string ?(str="x") n =
    if n < 0 then "Error"
    else if n = 0 then ""
    else str ^ (repeat_string ~str:str (n - 1))

let () =
    print_endline (repeat_string ~str:"titi" (-1));
    print_endline (repeat_string (-1));
    print_endline (repeat_string ~str:"titi" 0);
    print_endline (repeat_string 0);
    print_endline (repeat_string ~str:"hello" 2);
    print_endline (repeat_string 2);
    print_endline (repeat_string ~str:"ciao les nazes !" 4);
    print_endline (repeat_string ~str:"c" 3);
    print_endline (repeat_string 5)
