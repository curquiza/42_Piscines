val eval : (Game.Board.case list) -> Game.Board.case
val endBecauseOfDraw : (Game.Board.case list list) -> bool
val endBecauseOfWin : (Game.Board.case list list) -> bool
val printRslt : (Game.Board.case list list) -> int -> Game.Player.t -> unit
val boardIsEnded : (Game.Board.case list) -> bool
