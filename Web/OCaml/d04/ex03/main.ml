let print_str_list l =
  List.iter (function x -> print_string x ; print_string " ") l ; print_endline ""

 let rec card_list_to_string f l = match l with
  | h::t -> (f h) ^ " " ^ (card_list_to_string f t)
  | _ -> ""

let check_best l =
  try Deck.Card.toStringVerbose (Deck.Card.best l) with invalid_args -> "Empty list"

let print_draw_card card =
  print_endline ("Drawing a card -> " ^ Deck.Card.toStringVerbose card)

let () =
  let allSpades = Deck.Card.allSpades in
  let allHearts = Deck.Card.allHearts in
  let allDiamonds = Deck.Card.allDiamonds in
  let allClubs = Deck.Card.allClubs in
  let all = Deck.Card.all in
  print_string "allSpades toStringVerbose -> " ; print_string (card_list_to_string Deck.Card.toStringVerbose allSpades); print_endline "";
  print_string "allSpades toString   -> " ; print_string (card_list_to_string Deck.Card.toString allSpades); print_endline "";
  print_string "allHearts toString   -> " ; print_string (card_list_to_string Deck.Card.toString allHearts); print_endline "";
  print_string "allDiamonds toString -> " ; print_string (card_list_to_string Deck.Card.toString allDiamonds); print_endline "";
  print_string "allClubs toString    -> " ; print_string (card_list_to_string Deck.Card.toString allClubs); print_endline "";
  print_string "all toString         -> " ; print_string (card_list_to_string Deck.Card.toString all); print_endline "";
  print_endline "";

  let c_2S = Deck.Card.newCard Deck.Card.Value.T2 Deck.Card.Color.Spade in
  let c_QC = Deck.Card.newCard Deck.Card.Value.Queen Deck.Card.Color.Club in
  let c_QH = Deck.Card.newCard Deck.Card.Value.Queen Deck.Card.Color.Heart in
  let c_9H = Deck.Card.newCard Deck.Card.Value.T9 Deck.Card.Color.Heart in
  let c_AD = Deck.Card.newCard Deck.Card.Value.As Deck.Card.Color.Diamond in
  let c_QS = Deck.Card.newCard Deck.Card.Value.Queen Deck.Card.Color.Spade in
  let c_QD = Deck.Card.newCard Deck.Card.Value.Queen Deck.Card.Color.Diamond in
  print_string "c_2S = "; print_string (Deck.Card.toStringVerbose c_2S) ; print_endline "";
  print_string "c_QC = "; print_string (Deck.Card.toStringVerbose c_QC) ; print_endline "";
  print_string "c_QH = "; print_string (Deck.Card.toStringVerbose c_QH) ; print_endline "";
  print_string "c_9H = "; print_string (Deck.Card.toStringVerbose c_9H) ; print_endline "";
  print_string "c_AD = "; print_string (Deck.Card.toStringVerbose c_AD) ; print_endline "";
  print_string "c_QS = "; print_string (Deck.Card.toStringVerbose c_QS) ; print_endline "";
  print_string "c_QD = "; print_string (Deck.Card.toStringVerbose c_QD) ; print_endline "";
  print_endline "";
  print_string "color c_QD -> " ; print_string (Deck.Card.Color.toStringVerbose (Deck.Card.getColor c_QD)); print_endline "";
  print_string "value c_QD -> " ; print_string (Deck.Card.Value.toStringVerbose (Deck.Card.getValue c_QD)); print_endline "";
  print_string "c_QD isOf Diamond -> " ; print_string (string_of_bool (Deck.Card.isOf c_QD Diamond)); print_endline "";
  print_string "c_QD isOf Heart -> " ; print_string (string_of_bool (Deck.Card.isOf c_QD Heart)); print_endline "";
  print_string "c_QD isSpade -> " ; print_string (string_of_bool (Deck.Card.isSpade c_QD)); print_endline "";
  print_string "c_QD isHeart -> " ; print_string (string_of_bool (Deck.Card.isHeart c_QD)); print_endline "";
  print_string "c_QD isDiamond -> " ; print_string (string_of_bool (Deck.Card.isDiamond c_QD)); print_endline "";
  print_string "c_QD isClub -> " ; print_string (string_of_bool (Deck.Card.isClub c_QD)); print_endline "";
  print_string "min(c_2S, c_QC) = "; print_string (Deck.Card.toStringVerbose (Deck.Card.min c_2S c_QC)) ; print_endline "";
  print_string "min(c_2S, c_QC) = "; print_string (Deck.Card.toStringVerbose (Deck.Card.min c_2S c_QC)) ; print_endline "";
  print_string "max(c_2S, c_QC) = "; print_string (Deck.Card.toStringVerbose (Deck.Card.max c_2S c_QC)) ; print_endline "";
  print_string "max(c_QS, c_QC) = "; print_string (Deck.Card.toStringVerbose (Deck.Card.max c_QS c_QC)) ; print_endline "";
  print_string "compare(c_2S, c_2S) = "; print_int (Deck.Card.compare c_2S c_2S) ; print_endline "";
  print_string "compare(c_QC, c_QD) = "; print_int (Deck.Card.compare c_QC c_QD) ; print_endline "";
  print_string "compare(c_QD, c_QH) = "; print_int (Deck.Card.compare c_QD c_QH) ; print_endline "";
  print_string "compare(c_QH, c_QS) = "; print_int (Deck.Card.compare c_QH c_QS) ; print_endline "";
  print_string "compare(c_9H, c_QS) = "; print_int (Deck.Card.compare c_9H c_QS) ; print_endline "";
  print_string "best of all -> "; print_string (check_best all) ; print_endline "";
  print_string "best of [] -> "; print_string (check_best []) ; print_endline "";

  print_endline "";

  let deck = Deck.newDeck () in

  print_string "Random deck -> ";
  print_str_list (Deck.toStringList deck);
  print_str_list (Deck.toStringListVerbose deck);
  print_endline "";
  print_endline "Check drawCard : ";
  let rec loop d = match (Deck.drawCard d) with
    | (f,s) -> print_draw_card f ; loop s
  in loop deck



