(*let ft_countdown n =
    if n < 0
    then 
        begin
            print_int 0 ;
            print_char '\n'
        end
    else let rec count_down a =
        if a < n
        then count_down (a + 1)
        else n
    in 
    begin
        print_int (count_down 0) ;
        print_char '\n'
    end*)

let rec ft_countdown n =
    if n <= 0
    then 
        begin 
            print_int 0 ;
            print_char '\n'
        end
    else 
        begin
            print_int n;
            print_char '\n';
            ft_countdown (n - 1);
        end

let main () = 
    ft_countdown 8;
    print_char '\n';
    ft_countdown (-12);
    print_char '\n';
    ft_countdown 0

let () = main ()
