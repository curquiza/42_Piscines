class galifrey (dalek_l:Dalek.dalek list) (doctor_l:Doctor.doctor list) (people_l:People.people list) =
  object (self)

    val _dalek_l : Dalek.dalek list = dalek_l
    val _doctor_l : Doctor.doctor list = doctor_l
    val _people_l : People.people list = people_l

    method discussions (dal : Dalek.dalek) (doc : Doctor.doctor) (p : People.people) =
      print_endline "The selected fighters are talking :" ;
      print_string "human : " ; p#talk () ; print_string "the Doctor : " ; doc#talk () ; print_string "dalek : " ; dal#talk ()

    method is_end_of_war (dal_army : Dalek.dalek Army.army) (doc_army : Doctor.doctor Army.army) (p_army : People.people Army.army) : bool =
      if dal_army#get_army () = [] && p_army#get_army () = [] then begin print_endline "Everyone is dead... -_-" ; true end
      else if dal_army#get_army () = [] then begin print_endline "Doctor Who and humans won the war !!! :D" ; true end
      else if p_army#get_army () = [] then begin print_endline "The Daleks won the war... :'(" ; true end
      else false

    method select_fighters (dal_a : Dalek.dalek Army.army) (doc_a : Doctor.doctor Army.army) (p_a : People.people Army.army) =
     (List.hd (dal_a#get_army ()), List.hd (doc_a#get_army ()), List.hd (p_a#get_army ()))

    method random_dalek_suppression (dal_f : Dalek.dalek) (dal_army : Dalek.dalek Army.army) : Dalek.dalek Army.army =
      Random.self_init () ;
      let name = dal_f#get_name () in
      match Random.int 2 with
      | 0 -> print_string ("The Dalek fighter " ^ name ^ " is dying and says : ") ; dal_f#die () ; dal_army#delete ()
      | _ -> print_endline ("The Dalek fighter " ^ name ^ " survives :(") ; dal_army

    method random_people_suppression (p_f : People.people) (p_army : People.people Army.army) : People.people Army.army =
      Random.self_init () ;
      let name = p_f#get_name () in
      match Random.int 2 with
      | 0 -> print_string ("The human fighter " ^ name ^ " is dying and says : ") ; p_f#die () ; p_army#delete ()
      | _ -> print_endline ("The human fighter " ^ name ^ " survives :D !!") ; p_army

    method do_time_war () =
      print_endline "BEGINNING OF WAR !!!!" ;
      print_endline "Creating all the armies.." ;
      let dal_army = new Army.army _dalek_l in
      let doc_army = new Army.army _doctor_l in
      let p_army   = new Army.army _people_l in
      (* LAUNCH THE ROUNDS *)
      print_endline "\nNow... Let's fight !!" ;
      let rec loop (i : int) (dal_a : Dalek.dalek Army.army) (doc_a : Doctor.doctor Army.army) (p_a : People.people Army.army) =
        print_endline ("\nROUND " ^ string_of_int i) ;
        let is_end = self#is_end_of_war dal_a doc_a p_a in
        match is_end with
        | false -> let (dal_f, doc_f, p_f) = self#select_fighters dal_a doc_a p_a in
                   self#discussions dal_f doc_f p_f ;
                   print_endline "The selected fighters are fighting :" ;
                   let (dal_tmp : Dalek.dalek Army.army) = self#random_dalek_suppression dal_f dal_a in
                   let (p_tmp : People.people Army.army) = self#random_people_suppression p_f p_a in
                   loop (i + 1) dal_tmp doc_a p_tmp
        | true -> ()
      in loop 1 dal_army doc_army p_army

  end
