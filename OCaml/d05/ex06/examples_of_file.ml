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

let printArray a =
  print_string "[| " ;
  Array.iter (function x -> print_float x ; print_string " ") a;
  print_string "|]"

let printTuple t =
  print_char '(' ;
  printArray (fst t) ;
  print_string ", " ;
  print_string "\"" ; print_string (snd t) ; print_string "\"" ;
  print_endline ")"

let rec printListOfTuples l = match l with
  | h::t -> printTuple h ; printListOfTuples t
  | _ -> ()

(* MAIN ***********************************************************************)

let () =
  let argv = Sys.argv in
  let argc = Array.length argv in
  match argc with
  | 2 -> begin
           try (printListOfTuples (examples_of_file argv.(1))) with
           | Sys_error err -> print_endline ("System error caught -> " ^ err)
         end
  | _ -> print_endline "Error: bad number of argument"
