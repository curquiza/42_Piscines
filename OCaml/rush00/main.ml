 let announcePlayer current_player = match current_player with
  | (v, name) -> print_endline (name ^ "\'s turn to play -> " ^ (Game.Board.caseToString v))

let getMove bb ia current_player = match ia with
  | x when x = true && (fst current_player) = Game.Board.X -> IA.getMove bb
  | _ -> Move.askForMove bb

let rec mainLoop players current_player bb ia =
  announcePlayer current_player ;
  (* Get move from IA or player *)
  let m = getMove bb ia current_player in
  (* Get the new big board *)
  let (board_num, elem_num) = Move.translateToBoard (Move.getRowValue m) (Move.getColValue m) in
  let new_bb = Game.replaceInBigBoard bb board_num elem_num (fst current_player) in
  (* Check if grid taken *)
  Eval.printRslt new_bb board_num current_player;
  (* Print board *)
  print_newline ();
  Draw.printBigBoard new_bb ;
  print_newline ();
  (* Final checks *)
  let win = Eval.endBecauseOfWin new_bb in
  match win with
  | true -> print_endline ((snd current_player) ^ " wins the game!\n")
  | _ -> let draw = Eval.endBecauseOfDraw new_bb in
         match draw with
         | true -> print_endline "Draw game :("
         | _ -> mainLoop players (Game.Player.next current_player players) new_bb ia

let rec startGame players =
  let current_player = List.nth players 0 in
  let ia = IA.askForIA () in
  (* Test part : *)
  (*Choose between : bigBoardDraw1 / bigBoardDraw2 / bigBoardDraw3
                     bigBoardForO / bigBoardForX / bigBoardBasic *)
  (* let bigBoard = Game.Board.bigBoardForX in *)
  let bigBoard = List.init 9 (function x -> Game.Board.empty) in
  Draw.printBigBoard bigBoard ; print_newline ();
  mainLoop players current_player bigBoard ia ;
  (* Ask for starting a new game *)
  print_endline "Play again ? (yes/no)" ;
  match (String.trim (read_line ())) with
  | "yes" -> Draw.printNewGameBanner () ; startGame players
  | _ -> print_endline "\nCiao les nazes !! ;)"

let main () =
  Draw.printBanner () ;
  let players = Game.Player.getPlayers () in
  print_newline () ;
  startGame players

let () = main ()
