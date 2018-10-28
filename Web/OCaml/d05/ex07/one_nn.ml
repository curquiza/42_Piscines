(* EU DISTANCE ****************************************************************)

let squaredDistance a b = (a -. b) *. (a -.b)

let eu_dist a_array b_array =
  let rec aux rslt n = match n with
    | 0 -> rslt
    | _ -> aux (rslt +. (squaredDistance a_array.(n - 1) b_array.(n - 1))) (n - 1)
  in sqrt (aux 0.0 (Array.length a_array))

(* EXAMPLES_OF_FILE ***********************************************************)

let getOneLine data_s =
  let data_list =  String.split_on_char ',' (String.trim data_s) in
  let s = List.hd (List.rev data_list) in
  let float_list_string = List.rev (List.tl (List.rev data_list)) in
  let float_list = List.map (function x -> float_of_string x) float_list_string in
  let float_array = Array.of_list float_list in
  (float_array, s)

let getAllInput ic =
  let rec readLine () acc =
      try
      let data_s = input_line ic in
      readLine () (acc @ [getOneLine data_s])
      with
      | End_of_file -> acc
  in readLine () []

let examples_of_file path =
  let ic = open_in path in
  let input_list = getAllInput ic in
  close_in ic ; input_list

(* DISPLAY ********************************************************************)

let printEu r r_to_check =
  print_string ("EU distance of radar " ^ (snd r_to_check) ^ " -> ") ; print_float (eu_dist (fst r_to_check) (fst r)); print_newline ()

(* ONE NN *********************************************************************)

type radar = float array * string

let compareRadar current_nearest r r_to_check =
  (*printEu r r_to_check;*)
  match r_to_check with
  | (a, s) when (eu_dist a (fst r)) < (eu_dist (fst current_nearest) (fst r)) ->  r_to_check
  | _ -> current_nearest

let one_nn (r_l : radar list) (r : radar) : string =
  let rec aux l current_nearest = match l with
  | h::t -> aux t (compareRadar current_nearest r h)
  | _ -> current_nearest
  in snd (aux r_l (List.hd r_l))

(* MAIN ***********************************************************************)

let rec testRadars (training : radar list) (tests : radar list) = match tests with
  | (fl, str)::tail -> print_string ("Nearesrt of the radar " ^ str ^ " -> "); print_endline (one_nn training (fl, str)); testRadars training tail
  | [] -> ()

let () =
  print_endline "With hardcode radars :" ;
  let r_l = [ ([|1.; 1.; 1.; 1.; 1.|], "1"); ([|2.; 2.; 2.; 2.; 2.|], "2"); ([|3.; 3.; 3.; 3.; 3.|], "3"); ([|4.; 4.; 4.; 4.; 4.|], "4"); ([|5.; 5.; 5.; 5.; 5.|], "5") ] in
  let r = ([|1.; 2.; 3.; 4.; 5.|], "0") in
  print_endline ("The neriest is -> " ^ one_nn r_l r);
  print_newline () ;

  print_endline "On real files :";
  try
    let argv = Sys.argv in
    let train = examples_of_file argv.(1) in
    let tests = examples_of_file argv.(2) in
    testRadars train tests
  with
    | Sys_error err -> print_endline ("System error caught -> " ^ err)
    | Invalid_argument err -> print_endline "usage: ./a.out train.csv test.csv"
