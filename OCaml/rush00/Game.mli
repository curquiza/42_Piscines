module Board :
  sig

    type case = O | X | None

    val empty : case list

    val caseToString : case -> string

    (* TEST*)
    val boardXWins : case list
    val boardOWins : case list
    val boardNoWin : case list
    val boardBasicO : case list
    val boardBasicX : case list
    val boardBasic : case list
    val bigBoardDraw1 : case list list
    val bigBoardDraw2 : case list list
    val bigBoardDraw3 : case list list
    val bigBoardForO : case list list
    val bigBoardForX : case list list
    val bigBoardBasic : case list list

  end

module Player :
  sig

    type t = (Board.case * string)

    val next : t -> t list -> t
    val getPlayers : unit -> t list

  end

val replaceInBigBoard : (Board.case list list) -> int -> int -> Board.case -> (Board.case list list)
