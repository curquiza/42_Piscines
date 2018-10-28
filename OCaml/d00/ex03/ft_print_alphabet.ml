let ft_print_alphabet () =
    let a_ascii = int_of_char 'a' in
    let z_ascii = int_of_char 'z' in
    let rec alphabet_loop l =
        if l <= z_ascii
        then
            begin
                print_char (char_of_int l);
                alphabet_loop (l + 1)
            end
    in
    alphabet_loop a_ascii;
    print_char '\n'

let main () =
    ft_print_alphabet ()

let () = main ()
