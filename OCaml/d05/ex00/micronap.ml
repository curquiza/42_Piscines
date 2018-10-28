(* Compile with ocamlopt unix.cmxa -cclib -lunix micronap.ml *)
let sleep () = Unix.sleep 1

let sleepCount arg =
  let second = int_of_string arg in
    for i = 1 to second do
      sleep ()
    done

let main argc argv =
  try (sleepCount argv.(1)) with
    | Failure err -> print_endline ("Error caught: failure " ^ err)
    | invalid_arg -> print_endline ("Error caught: invalid argument")

let () =
  let argv = Sys.argv in
  let argc = Array.length argv in
  match argc with
  | x when x < 3 -> main argc argv
  | _ -> print_endline "Too many arguments"
