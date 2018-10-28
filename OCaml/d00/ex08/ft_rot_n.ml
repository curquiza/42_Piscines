let is_alpha c = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')

let map_func c =
    if is_alpha c
    then
        if c = 'z' || c = 'Z'
        then char_of_int ((int_of_char c) - 25)
        else char_of_int ((int_of_char c) + 1)
    else c

let rec ft_rot_n n str =
    if n > 0
       then
           let tmp = (String.map map_func str)
           in (ft_rot_n (n - 1) tmp)
       else str

let answer n str =
    print_int n;
    print_string " - ";
    print_string str;
    print_string " ---> ";
    print_endline (ft_rot_n n str)

let main () =
    answer 2 "abc";
    answer 2 "Zza";
    answer 1 "abcdefghijklmnopqrstuvwxyz";
    answer 13 "abcdefghijklmnopqrstuvwxyz";
    answer 42 "0123456789";
    answer 2 "OI2EAS67B9";
    answer 0 "Damned !";
    answer 42 "";
    answer 1 "NBzlk qnbjr !";
    answer 26 "t";
    answer (26 + 26) "tESt09"

let () = main ()
