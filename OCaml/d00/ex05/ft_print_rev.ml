let ft_print_rev str =
    let rec loop str n =
        if n > 0 then
            begin
                print_char (String.get str (n - 1)) ;
                loop str (n - 1)
            end
    in loop str (String.length str) ; print_char '\n'


let print_answer str =
    print_string str ;
    print_string " -> " ;
    ft_print_rev str

let main () =
    print_answer "Hello les enfants !" ;
    print_answer "" ;
    print_answer "a"

let () = main ()
