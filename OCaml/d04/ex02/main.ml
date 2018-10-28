let rec card_list_to_string f l = match l with
  | h::t -> (f h) ^ " " ^ (card_list_to_string f t)
  | _ -> ""

let check_best l =
  try Card.toStringVerbose (Card.best l) with invalid_args -> "Empty list"

let () =
  let allSpades = Card.allSpades in
  let allHearts = Card.allHearts in
  let allDiamonds = Card.allDiamonds in
  let allClubs = Card.allClubs in
  let all = Card.all in
  print_string "allSpades toStringVerbose -> " ; print_string (card_list_to_string Card.toStringVerbose allSpades); print_endline "";
  print_string "allSpades toString   -> " ; print_string (card_list_to_string Card.toString allSpades); print_endline "";
  print_string "allHearts toString   -> " ; print_string (card_list_to_string Card.toString allHearts); print_endline "";
  print_string "allDiamonds toString -> " ; print_string (card_list_to_string Card.toString allDiamonds); print_endline "";
  print_string "allClubs toString    -> " ; print_string (card_list_to_string Card.toString allClubs); print_endline "";
  print_string "all toString         -> " ; print_string (card_list_to_string Card.toString all); print_endline "";
  print_endline "";

  let c_2S = Card.newCard Card.Value.T2 Card.Color.Spade in
  let c_QC = Card.newCard Card.Value.Queen Card.Color.Club in
  let c_QH = Card.newCard Card.Value.Queen Card.Color.Heart in
  let c_9H = Card.newCard Card.Value.T9 Card.Color.Heart in
  let c_AD = Card.newCard Card.Value.As Card.Color.Diamond in
  let c_QS = Card.newCard Card.Value.Queen Card.Color.Spade in
  let c_QD = Card.newCard Card.Value.Queen Card.Color.Diamond in
  print_string "c_2S = "; print_string (Card.toStringVerbose c_2S) ; print_endline "";
  print_string "c_QC = "; print_string (Card.toStringVerbose c_QC) ; print_endline "";
  print_string "c_QH = "; print_string (Card.toStringVerbose c_QH) ; print_endline "";
  print_string "c_9H = "; print_string (Card.toStringVerbose c_9H) ; print_endline "";
  print_string "c_AD = "; print_string (Card.toStringVerbose c_AD) ; print_endline "";
  print_string "c_QS = "; print_string (Card.toStringVerbose c_QS) ; print_endline "";
  print_string "c_QD = "; print_string (Card.toStringVerbose c_QD) ; print_endline "";
  print_endline "";
  print_string "color c_QD -> " ; print_string (Card.Color.toStringVerbose (Card.getColor c_QD)); print_endline "";
  print_string "value c_QD -> " ; print_string (Card.Value.toStringVerbose (Card.getValue c_QD)); print_endline "";
  print_string "c_QD isOf Diamond -> " ; print_string (string_of_bool (Card.isOf c_QD Diamond)); print_endline "";
  print_string "c_QD isOf Heart -> " ; print_string (string_of_bool (Card.isOf c_QD Heart)); print_endline "";
  print_string "c_QD isSpade -> " ; print_string (string_of_bool (Card.isSpade c_QD)); print_endline "";
  print_string "c_QD isHeart -> " ; print_string (string_of_bool (Card.isHeart c_QD)); print_endline "";
  print_string "c_QD isDiamond -> " ; print_string (string_of_bool (Card.isDiamond c_QD)); print_endline "";
  print_string "c_QD isClub -> " ; print_string (string_of_bool (Card.isClub c_QD)); print_endline "";
  print_string "min(c_2S, c_QC) = "; print_string (Card.toStringVerbose (Card.min c_2S c_QC)) ; print_endline "";
  print_string "min(c_2S, c_QC) = "; print_string (Card.toStringVerbose (Card.min c_2S c_QC)) ; print_endline "";
  print_string "max(c_2S, c_QC) = "; print_string (Card.toStringVerbose (Card.max c_2S c_QC)) ; print_endline "";
  print_string "max(c_QS, c_QC) = "; print_string (Card.toStringVerbose (Card.max c_QS c_QC)) ; print_endline "";
  print_string "compare(c_2S, c_2S) = "; print_int (Card.compare c_2S c_2S) ; print_endline "";
  print_string "compare(c_QC, c_QD) = "; print_int (Card.compare c_QC c_QD) ; print_endline "";
  print_string "compare(c_QD, c_QH) = "; print_int (Card.compare c_QD c_QH) ; print_endline "";
  print_string "compare(c_QH, c_QS) = "; print_int (Card.compare c_QH c_QS) ; print_endline "";
  print_string "compare(c_9H, c_QS) = "; print_int (Card.compare c_9H c_QS) ; print_endline "";
  print_string "best of all -> "; print_string (check_best all) ; print_endline "";
  print_string "best of [] -> "; print_string (check_best []) ; print_endline "";

