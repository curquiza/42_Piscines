
let ft_is_palindrome str =
    let len = (String.length str) in
    let rec loop i =
        if i < (len / 2) && ((String.get str i) = (String.get str (len - 1 -
        i)))
        then loop (i + 1)
        else i = len / 2
    in loop 0

let answer str =
    print_string str ;
    print_string " -> " ;
    print_endline (string_of_bool (ft_is_palindrome str))

let main () =
    answer "tttt";
    answer "ttatt";
    answer "atatt";
    answer "t0";
    answer "00";
    answer "0000";
    answer "0ata0";
    answer "";
    answer "t";
    answer "1"

let () = main ()
