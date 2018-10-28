type t =  Coord of (int * int) | None

val translateToBoard : int -> int -> (int * int)

val getRowValue : t -> int
val getColValue : t -> int

val askForMove : (Game.Board.case list list) -> t
val isIllegalMove : t -> Game.Board.case list list -> bool