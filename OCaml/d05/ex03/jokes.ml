let jokesFromFileToArray file =
  let ic = open_in file in
  let data = input_line ic in
  close_in ic ;
  let l = String.split_on_char ';' data in
  let l_trim = List.map (function x -> String.trim x) l in
  Array.of_list l_trim

let printAJoke file =
  Random.self_init ();
  let jokes = jokesFromFileToArray file in
  let r = Random.int (Array.length jokes) in
  print_endline jokes.(r)

let () =
  let argv = Sys.argv in
  match Array.length argv with
  | x when x <= 2 -> begin
                       try printAJoke argv.(1) with
                       | Sys_error err -> print_endline ("System error caught -> " ^ err)
                       | invalid_arg -> print_endline "Standard error caugh -> invalid argument"
                     end
  | _ -> print_endline "Error : too many arguments"
