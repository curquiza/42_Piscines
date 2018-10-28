let ft_string_all func str =
    let len = String.length str in
        let rec loop n =
            if n < len && func (String.get str n)
            then loop (n + 1)
            else len <> 0 && n = len
            (*else if len <> 0 && n = len
                then  true
                else false*)
        in loop 0

let is_digit c = c >= '0' && c <= '9'

let answer func str =
    print_endline (string_of_bool (ft_string_all func str))

let main () =
    answer is_digit "test";
    answer is_digit "t000";
    answer is_digit "0t00";
    answer is_digit "01t0";
    answer is_digit "014e";
    answer is_digit "0000";
    answer is_digit "";
    answer is_digit "t";
    answer is_digit "1"

let () = main ()

