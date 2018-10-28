(** COLOR *********************************************************************)

module Color =
struct

  type t = Spade | Heart | Diamond | Club

  let all = [ Spade ; Heart ; Diamond ; Club ]

  let toString t = match t with
    | Spade -> "S"
    | Heart -> "H"
    | Diamond -> "D"
    | Club -> "C"

  let toStringVerbose t = match t with
    | Spade -> "Spade"
    | Heart -> "Heart"
    | Diamond -> "Diamond"
    | Club -> "Club"

end

(** VALUE *********************************************************************)

module Value =
struct

  type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As

  let all = [T2 ; T3 ; T4 ; T5 ; T6 ; T7 ; T8 ; T9 ; T10 ; Jack ; Queen ; King ; As]

  let toInt t = match t with
    | T2 -> 1
    | T3 -> 2
    | T4 -> 3
    | T5 -> 4
    | T6 -> 5
    | T7 -> 6
    | T8 -> 7
    | T9 -> 8
    | T10 -> 9
    | Jack -> 10
    | Queen -> 11
    | King -> 12
    | As -> 13

  let toString t = match t with
    | T2 -> "2"
    | T3 -> "3"
    | T4 -> "4"
    | T5 -> "5"
    | T6 -> "6"
    | T7 -> "7"
    | T8 -> "8"
    | T9 -> "9"
    | T10 -> "10"
    | Jack -> "J"
    | Queen -> "Q"
    | King -> "K"
    | As -> "A"

  let toStringVerbose t = match t with
    | T2 -> "2"
    | T3 -> "3"
    | T4 -> "4"
    | T5 -> "5"
    | T6 -> "6"
    | T7 -> "7"
    | T8 -> "8"
    | T9 -> "9"
    | T10 -> "10"
    | Jack -> "Jack"
    | Queen -> "Queen"
    | King -> "King"
    | As -> "As"

  let next t = match t with
    | T2 -> T3
    | T3 -> T4
    | T4 -> T5
    | T5 -> T6
    | T6 -> T7
    | T7 -> T8
    | T8 -> T9
    | T9 -> T10
    | T10 -> Jack
    | Jack -> Queen
    | Queen -> King
    | King -> As
    | As -> invalid_arg "No next value for As"

  let previous t = match t with
    | T2 -> invalid_arg "No previous value for T2"
    | T3 -> T2
    | T4 -> T3
    | T5 -> T4
    | T6 -> T5
    | T7 -> T6
    | T8 -> T7
    | T9 -> T8
    | T10 -> T9
    | Jack -> T10
    | Queen -> Jack
    | King -> Queen
    | As -> King

end

(** CARD **********************************************************************)

type t = (Value.t * Color.t)

let newCard v c : t = (v, c)

let allSpades : t list = List.map (function x -> (x, Color.Spade)) Value.all
let allHearts : t list = List.map (function x -> (x, Color.Heart)) Value.all
let allDiamonds : t list = List.map (function x -> (x, Color.Diamond)) Value.all
let allClubs : t list = List.map (function x -> (x, Color.Club)) Value.all
let all = allSpades @ allHearts @ allDiamonds @ allClubs

let getValue card : Value.t = match (card : t) with
  | (v,_) -> v

let getColor card : Color.t = match (card : t) with
  | (_,c) -> c

let toString card = match (card : t) with
  | (v, c) -> (Value.toString v) ^ (Color.toString c)

let toStringVerbose card = match (card : t) with
  | (v, c) -> "Card(" ^ (Value.toStringVerbose v) ^ ", " ^ (Color.toStringVerbose c) ^ ")"

let compare card1 card2 =
  if (card1 : t) = (card2 : t) then 0
  else if card1 < card2 then (-1)
  else 1

let min card1 card2 : t =
  if card1 <= card2 then card1
  else card2

let max card1 card2 : t =
  if card1 >= card2 then card1
  else card2

let best l = match l with
  | [] -> invalid_arg "Empty list"
  | h::t -> List.fold_left max h t


(*let isOf card color = match (card : t) with
  | (_,c) when c = color -> true
  | _ -> false*)
let isOf ((v,c) : t) (color : Color.t) =
  color = c

let isSpade card = isOf card Spade
let isHeart card = isOf card Heart
let isDiamond card = isOf card Diamond
let isClub card = isOf card Club
