module Board =
struct

  type case = O | X | None

  let empty : (case list) = List.init 9 (function x -> None)

  let caseToString c : string = match (c:case) with
    | O -> "O"
    | X -> "X"
    | _ -> "-"

    (* BOARD TEST *************************************************************)
    let boardXWins = [ X ; X ; X ;
                       O ; None ; O ;
                       None ; None ; None ]
    let boardOWins = [ X ; X ; O ;
                       O ; O ; None ;
                       O ; None ; None ]

    let boardNoWin = [ X ; X ; O ;
                       O ; O ; X ;
                       X ; O ; X ]

    let boardBasicX = [ X ; X ; O ;
                       O ; X ; X ;
                       X ; O ; None ]

    let boardBasicO = [ O ; X ; O ;
                       O ; X ; O ;
                       X ; O ; None ]

    let boardBasic = [ None ; X ; O ;
                      X ; None ; None ;
                      None ; None ; X ]


    (*All grids taken but draw game *)
    let bigBoardDraw1 = [ boardXWins ; boardXWins ; boardOWins ;
                         boardOWins ; boardOWins ; boardXWins ;
                         boardXWins ; boardOWins ; boardBasicO]

    (*No grid taken but all cases filled, so draw game *)
    let bigBoardDraw2 = [ boardNoWin ; boardNoWin ; boardNoWin ;
                         boardNoWin ; boardNoWin ; boardNoWin ;
                         boardNoWin ; boardNoWin ; boardBasicX]

    (* Mix draw game = some grid are taken and some not *)
    let bigBoardDraw3 = [ boardXWins ; boardXWins ; boardOWins ;
                         boardNoWin ; boardOWins ; boardNoWin ;
                         boardNoWin ; boardOWins ; boardBasicX]

    (* O can win *)
    let bigBoardForO = [ boardXWins ; boardOWins ; boardXWins ;
                         boardBasic ; boardOWins ; boardNoWin ;
                         empty ; boardBasicO ; boardBasic]

    (* X can win *)
    let bigBoardForX = [ boardOWins ; empty ; boardNoWin ;
                         boardXWins ; boardBasicX ; boardXWins ;
                         empty ; boardBasicO ; boardBasic]

    (* Basic *)
    let bigBoardBasic = [ empty ; boardXWins ; boardBasic ;
                          boardBasicO ; empty ; boardNoWin ;
                          boardOWins ; boardBasic ; empty ]
end

module Player =
struct

  type t = (Board.case * string)

  let next current all = match current with
    | (Board.O, _) -> List.nth all 1
    | _ -> List.nth all 0

  let rec getFirstName () =
    let n1 = String.trim (read_line ()) in
    match (String.length n1)  with
    | x when x < 1 -> print_endline "Incorrect name." ; getFirstName ()
    | _ -> n1

  let rec getSecondName j1_name =
    let n2 = String.trim (read_line ()) in
    match n2 with
    | x when x = j1_name -> print_endline "Player 1 and Player 2 can't have the same name." ; getSecondName j1_name
    | x when (String.length x) < 1 ->  print_endline "Incorrect name." ; getSecondName j1_name
    | _ -> n2

  let getPlayers () =
    print_string "First player name (O) : " ;
    let n1 = getFirstName () in
    print_string "Second player name (X) : " ;
    let n2 = getSecondName n1 in
    [(Board.O, n1) ; (Board.X, n2)]

end

let replaceInList l pos value =
   List.mapi (fun i x -> if i = pos then value else x) l

let replaceInBigBoard bb posA posB value =
  let miniBoard = List.nth bb posA in
  List.mapi (fun i x -> if i = posA then (replaceInList miniBoard posB value) else x) bb
