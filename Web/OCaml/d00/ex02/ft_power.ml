let rec ft_power n p =
    if p <= 0
    then 1
    else n * ft_power n (p - 1)

let print_power_endline n p =
    print_int n;
    print_string "ˆ";
    print_int p;
    print_string " = ";
    print_int (ft_power n p);
    print_char '\n'

let main () =
    print_power_endline 2 3;
    print_power_endline 2 0;
    print_power_endline 0 0;
    print_power_endline 1 30;
    print_power_endline 1 1;
    print_power_endline 8 2

let () = main ()

