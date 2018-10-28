let askForIA () =
  print_endline "Do you want the player 2 to be an IA ? (yes/no)" ;
  match (String.trim (read_line ())) with
  | "yes" -> print_endline "Ok, player 2 (X) will be an IA... BE READY !!!\n" ; true
  | _ -> print_endline "Ok, no IA. I understand, you are affraid of playing against our IA...\n" ; false
    
let transformToCoord (board_num, elem_num) : Move.t =
  let r = (board_num / 3) * 3 + elem_num / 3 in
  let c = (board_num mod 3) * 3 + elem_num mod 3 in
  Coord (r + 1, c + 1)

let checkTwoLines b sym : int =
  let rec loop i b =
    if i = 3 then -1
    else  let c1 = List.nth b (i * 3) in
          let c2 = List.nth b (i * 3 + 1) in
          let c3 = List.nth b (i * 3 + 2) in
          if (c2 = sym && c3 = sym && c1 = Game.Board.None) then i * 3
          else if (c1 = sym && c3 = sym && c2 = Game.Board.None) then i * 3 + 1
          else if (c1 = sym && c2 = sym && c3 = Game.Board.None) then i * 3 + 2
          else loop (i + 1) b
  in loop 0 b

let checkTwoColums b sym : int =
  let rec loop i b =
    if i = 3 then -1
    else  let c1 = List.nth b i in
          let c2 = List.nth b (i + 3) in
          let c3 = List.nth b (i + 6) in
          if (c2 = sym && c3 = sym && c1 = Game.Board.None) then i
          else if (c1 = sym && c3 = sym && c2 = Game.Board.None) then i + 3
          else if (c1 = sym && c2 = sym && c3 = Game.Board.None) then i + 6
          else loop (i + 1) b
  in loop 0 b

let checkTwoDiago b sym : int =
  let c1 = List.nth b 0 in
  let c2 = List.nth b 4 in
  let c3 = List.nth b 8 in
  if (c2 = sym && c3 = sym && c1 = Game.Board.None) then 0
  else if (c1 = sym && c3 = sym && c2 = Game.Board.None) then 4
  else if (c1 = sym && c2 = sym && c3 = Game.Board.None) then 8
  else -1 

let checkTwoAntiDiago b sym : int =
  let c1 = List.nth b 2 in
  let c2 = List.nth b 4 in
  let c3 = List.nth b 6 in
  if (c2 = sym && c3 = sym && c1 = Game.Board.None) then 2
  else if (c1 = sym && c3 = sym && c2 = Game.Board.None) then 4
  else if (c1 = sym && c2 = sym && c3 = Game.Board.None) then 6  
  else -1 

let checkTwoAligned b sym : int =
  let lines = checkTwoLines b sym in
  if lines <> -1 then lines
  else let colums = checkTwoColums b sym in
    if colums <> -1 then colums
    else let diago = checkTwoDiago b sym in
      if diago <> -1 then diago
      else let antiDiago = checkTwoAntiDiago b sym in
        if antiDiago <> -1 then antiDiago
        else -1

let rec genRandomMove bb : Move.t =
  let m = Move.Coord ((Random.int 9) + 1, (Random.int 9) + 1) in
    match m with 
    | x when Move.isIllegalMove m bb = false -> genRandomMove bb
    | _ -> m     

let isCaseFree b i : bool = match (List.nth b i) with
  | Game.Board.None -> true
  | _ -> false

let rec genPlayInBoard bb b i : Move.t =
  let (m : Move.t) = transformToCoord (i, Random.int 9) in
    match m with 
    | x when Move.isIllegalMove m bb = false -> genPlayInBoard bb b i
    | _ -> m 

let genCenterMove bb : Move.t =
  let rec nextBoard l i =
    match l with
    | head::tail when Eval.boardIsEnded head = true -> nextBoard tail (i + 1)
    | head::tail when isCaseFree head 4 -> transformToCoord (i, 4)
    | head::tail -> nextBoard tail (i + 1)
    | [] -> genRandomMove bb
  in nextBoard bb 0     

let isXinBoard b : bool =
  let f = List.filter (function x -> x = Game.Board.X) b in
  if List.length f > 0 then true
  else false

let genSimpleMove bb : Move.t =  
  let rec nextBoard l i =
    match l with
    | head::tail when Eval.boardIsEnded head = true -> nextBoard tail (i + 1)
    | head::tail when isXinBoard head = true -> genPlayInBoard bb head i
    | head::tail -> nextBoard tail (i + 1)
    | [] -> genCenterMove bb
  in nextBoard bb 0

let genDefenseMove bb : Move.t =
  let rec nextBoard l i =
    match l with
    | head::tail when Eval.boardIsEnded head = true -> nextBoard tail (i + 1)
    | head::tail when checkTwoAligned head Game.Board.O <> -1 -> transformToCoord (i, checkTwoAligned head Game.Board.O)
    | head::tail -> nextBoard tail (i + 1)
    | [] -> genSimpleMove bb
  in nextBoard bb 0

let genWinMove bb : Move.t =
  let rec nextBoard l i =
    match l with
    | head::tail when Eval.boardIsEnded head = true -> nextBoard tail (i + 1)
    | head::tail when checkTwoAligned head Game.Board.X <> -1 -> transformToCoord (i, checkTwoAligned head Game.Board.X) 
    | head::tail -> nextBoard tail (i + 1)
    | [] -> genDefenseMove bb
  in nextBoard bb 0  

let getMove bb : Move.t =
  Random.self_init ();
  let m : Move.t = genWinMove bb in match m with
    | Coord (x, y) -> print_int x; print_string " "; print_int y; print_newline (); m
    | None -> None
