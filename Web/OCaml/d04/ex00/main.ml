let rec apply_f_on_list f l = match l with
  | h::t when t = [] -> print_string (f h) ; apply_f_on_list f t
  | h::t -> print_string (f h) ; print_string " " ; apply_f_on_list f t
  | [] -> print_endline ""

let () =
  let all = Color.all in
  let test = [Color.Heart ; Color.Spade ; Color.Heart] in
  let empty = [] in
  apply_f_on_list Color.toString all;
  apply_f_on_list Color.toStringVerbose all;
  apply_f_on_list Color.toString test;
  apply_f_on_list Color.toStringVerbose test;
  apply_f_on_list Color.toString empty;
  apply_f_on_list Color.toStringVerbose empty

