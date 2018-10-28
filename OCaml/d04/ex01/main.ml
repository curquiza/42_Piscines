let rec apply_f_string_on_list f l = match l with
  | h::t when t = [] -> print_string (f h) ; apply_f_string_on_list f t
  | h::t -> print_string (f h) ; print_string " ; " ; apply_f_string_on_list f t
  | [] -> print_endline ""

let rec apply_f_int_on_list f l = match l with
  | h::t when t = [] -> print_int (f h) ; apply_f_int_on_list f t
  | h::t -> print_int (f h) ; print_string " ; " ; apply_f_int_on_list f t
  | [] -> print_endline ""

let check_exception f h =
  try Value.toStringVerbose (f h) with invalid_arg -> "Invalid arg caught"

let rec apply_f_t_on_list f l = match l with
  | h::t when t = [] -> print_string (check_exception f h) ; apply_f_t_on_list f t
  | h::t -> print_string (check_exception f h) ; print_string " ; " ; apply_f_t_on_list f t
  | [] -> print_endline ""

let () =
  let all = Value.all in
  let test = [ Value.T4 ; Value.Queen ; Value.T2 ; Value.T2 ] in
  print_string "toInt on all -> " ; apply_f_int_on_list Value.toInt all;
  print_string "toString on all -> " ; apply_f_string_on_list Value.toString all;
  print_string "toStringVerbose on all -> " ; apply_f_string_on_list Value.toStringVerbose all;
  print_string "previous on all -> " ; apply_f_t_on_list (Value.previous) all;
  print_string "next on all -> " ; apply_f_t_on_list (Value.next) all;
  print_endline "";
  print_string "toInt on test -> " ; apply_f_int_on_list Value.toInt test;
  print_string "toString on test -> " ; apply_f_string_on_list Value.toString test;
  print_string "toStringVerbose on test -> " ; apply_f_string_on_list Value.toStringVerbose test;
  print_string "previous on test -> " ; apply_f_t_on_list (Value.previous) test;
  print_string "next on test -> " ; apply_f_t_on_list (Value.next) test
