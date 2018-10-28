let h_line = "    ---------------------"

let bigO = [ "/ - \\" ; "|   |" ; "\\ - /" ]
let bigX = [ "\\   /" ; "  X  " ; "/   \\" ]

let printSubLineNone l b = match l with
  | 0 -> print_string ( (Game.Board.caseToString (List.nth b 0)) ^ " " ^ (Game.Board.caseToString (List.nth b 1)) ^ " " ^ (Game.Board.caseToString (List.nth b 2)) )
  | 1 -> print_string ( (Game.Board.caseToString (List.nth b 3)) ^ " " ^ (Game.Board.caseToString (List.nth b 4)) ^ " " ^ (Game.Board.caseToString (List.nth b 5)) )
  | 2 -> print_string ( (Game.Board.caseToString (List.nth b 6)) ^ " " ^ (Game.Board.caseToString (List.nth b 7)) ^ " " ^ (Game.Board.caseToString (List.nth b 8)) )
  | _ -> ()

(* l = 0 1 ou 2 *)
(* b = un board *)
(* s = state *)
(* checkBMiniBoard : board -> case *)
(*let printSubLine l b s = match (checkBMiniBoard b) with*)
let printSubLine l b = match (Eval.eval b) with
  | Game.Board.X -> print_string (List.nth bigX l)
  | Game.Board.O -> print_string (List.nth bigO l)
  | None -> printSubLineNone l b

(* l = 0 1 2 3 4 5 6 7 ou 8 *)
(* bb = liste de board *)
let printLine l bb =
  let board_i = (l - (l mod 3))     in printSubLine (l mod 3) (List.nth bb board_i) ; print_string " | ";
  let board_i = (l - (l mod 3) + 1) in printSubLine (l mod 3) (List.nth bb board_i) ; print_string " | ";
  let board_i = (l - (l mod 3) + 2) in printSubLine (l mod 3) (List.nth bb board_i) ; print_newline ()

let printBigBoard bb =
  print_endline "    1 2 3   4 5 6   7 8 9\n";
  print_string "1   "; printLine 0 bb ;
  print_string "2   "; printLine 1 bb ;
  print_string "3   "; printLine 2 bb ;
  print_endline h_line;
  print_string "4   "; printLine 3 bb ;
  print_string "5   "; printLine 4 bb ;
  print_string "6   "; printLine 5 bb ;
  print_endline h_line;
  print_string "7   "; printLine 6 bb ;
  print_string "8   "; printLine 7 bb ;
  print_string "9   "; printLine 8 bb

let printBanner () =
  print_endline "*********************************************************" ;
  print_endline "***************** TIC TAC TOE DU TURFU ******************" ;
  print_endline "*********************************************************";
  print_newline ()

let printNewGameBanner () =
  print_newline () ;
  print_endline "********************* NEW GAME !!! **********************" ;
  print_newline ()
