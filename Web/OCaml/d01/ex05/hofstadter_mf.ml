let rec hfs_f n =
    if n < 0 then (-1)
    else if n = 0 then 1
    else n - (hfs_m (hfs_f (n - 1)))

and hfs_m n =
    if n < 0 then (-1)
    else if n = 0 then 0
    else n - (hfs_f (hfs_m (n - 1)))

let () =
    print_string "M(-1) = " ; print_int (hfs_m (-1)) ; print_char '\n';
    print_string "M(0) = " ; print_int (hfs_m 0) ; print_char '\n';
    print_string "M(1) = " ; print_int (hfs_m 1) ; print_char '\n';
    print_string "M(4) = " ; print_int (hfs_m 4) ; print_char '\n';
    print_string "F(-1) = " ; print_int (hfs_f (-1)) ; print_char '\n';
    print_string "F(0) = " ; print_int (hfs_f 0) ; print_char '\n';
    print_string "F(1) = " ; print_int (hfs_f 1) ; print_char '\n';
    print_string "F(4) = " ; print_int (hfs_f 4) ; print_char '\n'
