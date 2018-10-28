let checkLines b : Game.Board.case =
  let rec loop i b =
    if i = 3 then Game.Board.None
    else if ((List.nth b (i * 3)) == (List.nth b (i * 3 + 1)) && (List.nth b (i * 3)) == (List.nth b (i * 3 + 2)) && (List.nth b (i * 3)) <> Game.Board.None)
    then List.nth b (i * 3)
    else loop (i + 1) b
  in loop 0 b

let checkColums b : Game.Board.case =
  let rec loop i b =
    if i = 3 then Game.Board.None
    else if ((List.nth b i) == (List.nth b (i + 3)) && (List.nth b i) == (List.nth b (i + 6)) && (List.nth b i) <> Game.Board.None)
    then List.nth b i
    else loop (i + 1) b
  in loop 0 b

let checkDiago b : Game.Board.case =
  if ((List.nth b 0) == (List.nth b 4) && (List.nth b 0) == (List.nth b 8) && (List.nth b 0) <> Game.Board.None)
  then List.nth b 0
  else Game.Board.None

let checkAntiDiago b : Game.Board.case =
  if ((List.nth b 2) == (List.nth b 4) && (List.nth b 2) == (List.nth b 6) && (List.nth b 2) <> Game.Board.None)
  then List.nth b 2
  else Game.Board.None

let eval b : Game.Board.case =
  let lines = checkLines b in
  if lines <> Game.Board.None then lines
  else let colums = checkColums b in
    if colums <> Game.Board.None then colums
    else let diago = checkDiago b in
      if diago <> Game.Board.None then diago
      else let antiDiago = checkAntiDiago b in
        if antiDiago <> Game.Board.None then antiDiago
        else Game.Board.None

let allCasesPlayed b =
  let f = List.filter (function x -> x = Game.Board.None) b in
  match List.length f with
  | 0 -> true
  | _ -> false

let boardIsEnded b =
  (eval b <> Game.Board.None) || allCasesPlayed b

let endBecauseOfDraw bb =
  let f = List.filter (function x -> boardIsEnded x) bb in
  match List.length f with
  | 9 -> true
  | _ -> false

let endBecauseOfWin bb =
  let bb_rslt = List.map (function x -> eval x) bb in
  match eval bb_rslt with
  | None -> false
  | _ -> true

let printRslt bb board_num (current_player : Game.Player.t) =
  match (eval (List.nth bb board_num)) with
    | Game.Board.None -> ()
    | _ -> print_endline ((snd current_player) ^ " wins grid " ^ (string_of_int (board_num + 1)) ^ "!")


