let ft_print_comb () =
    let rec loop1 a =
        if a <= 7 then
            let rec loop2 b =
                if b <= 8 then
                    let rec loop3 c =
                        if c <= 9 then
                            begin
                                print_int a ;
                                print_int b ;
                                print_int c ;
                                if a <> 7 then
                                    print_string ", " ;
                                loop3 (c + 1)
                            end
                    in loop3 (b + 1) ; loop2 (b + 1)
            in loop2 (a + 1) ; loop1 (a + 1)
    in loop1 (0) ; print_char '\n'


(*let ft_print_comb () =
    let rec loop1 a =
        if a <= 8 then
            let rec loop2 b =
                if b <= 9 then
                    begin
                        print_int a ;
                        print_int b ;
                        print_string ", ";
                        loop2 (b + 1) ;
                    end
            in loop2 (a + 1) ; loop1 (a + 1)
    in loop1 (0) ; print_char '\n'
*)

let main () =
    ft_print_comb ()

let () = main ()

