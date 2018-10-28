type t = Coord of (int * int) | None

let getBoardPos row col = (row / 3) * 3 + (col / 3)
let getElemPos row col = (3 * (row mod 3) + (col mod 3))
let translateToBoard row col : (int * int) = (getBoardPos (row - 1) (col - 1), getElemPos (row - 1) (col - 1))

let isCorrectFormat m = match m with
  | None -> false
  | _ -> true

let isLegalDigit x = x >= 1 && x <= 9

(* None = non gagné ou nul *)
let boardIsNotWon b = match (Eval.eval b) with
  | Game.Board.None -> true
  | _ -> false

let isFreeInBoard row col (bb : Game.Board.case list list) =
  let (board_num, elem_num) = translateToBoard row col in
  let b = (List.nth bb board_num) in
  let elem = List.nth b elem_num in
  match elem with
  | None -> (boardIsNotWon b)
  | _ -> false

let isIllegalMove m (bb : Game.Board.case list list) = match m with
  | None -> false
  | Coord (row, col) -> isLegalDigit row && isLegalDigit col && isFreeInBoard row col bb

let getRowValue m = match m with
  | Coord (row, _) -> row
  | _ -> 0

let getColValue m = match m with
  | Coord (_, col) -> col
  | _ -> 0

let parseInput str : t  =
  let lexer = String.split_on_char ' ' str in
  if List.length lexer <> 2 then None
  else
  begin
    match (lexer : string list) with
    | x::y::tail when ((int_of_string_opt x) <> None) && ((int_of_string_opt y) <> None) -> Coord (int_of_string x, int_of_string y)
    | _ -> None
  end

let rec askForMove bb =
  let input = String.trim (read_line ()) in
  let m = parseInput input in
  match m with
  | x when isCorrectFormat x = false -> print_endline "Incorrect format."  ; askForMove bb
  | x when isIllegalMove m bb = false -> print_endline "Illegal move." ; askForMove bb
  | _ -> m


