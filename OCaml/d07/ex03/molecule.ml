class virtual molecule (n:string) (atom_list : Atom.atom list) =
  object (self)

    val _name : string  = n
    val _atom_list : (Atom.atom list) = atom_list

    method name : string = _name

    method print_atom_list (l:Atom.atom list) =
      List.iter (function x -> print_endline x#to_string) l

    method private compare_symbols (a:Atom.atom) (b:Atom.atom) : int =
      match (a#symbol, b#symbol) with
      | ("C", _) -> -1
      | (_, "C") -> 1
      | ("H", _) -> -1
      | (_, "H") -> 1
      | (s1, s2) -> compare s1 s2

    method formula : string =
      let l_sorted = List.sort self#compare_symbols _atom_list in
      (*self#print_atom_list l_sorted ;*)
      let rec loop (l:Atom.atom list) (count:int) : string = match l with
      | h::snd::t when (h#equals snd) = true -> loop (snd::t) (count + 1)
      | h::t -> h#symbol ^ (if count <> 1 then (string_of_int count) else "") ^ loop t 1
      | _ -> ""
      in loop l_sorted 1

    method to_string : string = "name = " ^ _name ^ " - formula = " ^ self#formula
    method equals (mol:molecule) : bool = self#formula = mol#formula

  end

class water =
  object
    inherit molecule "Water" [new Atom.hydrogen; new Atom.hydrogen; new Atom.oxygen]
  end

class carbon_dioxyde =
  object
    inherit molecule "Carbon dioxyde" [new Atom.carbon; new Atom.oxygen ; new Atom.oxygen]
  end

class ammoniac =
  object
    inherit molecule "Ammoniac" [new Atom.nitrogene; new Atom.hydrogen; new Atom.hydrogen; new Atom.hydrogen]
  end

class hydrochloric_acid =
  object
    inherit molecule "Hydrochloric acid" [new Atom.chlore; new Atom.hydrogen]
  end

class trinitrotoluene =
  object
    inherit molecule "Trinitrotoluene" [new Atom.nitrogene; new Atom.nitrogene; new Atom.nitrogene;
                                        new Atom.hydrogen; new Atom.hydrogen; new Atom.hydrogen; new Atom.hydrogen; new Atom.hydrogen;
                                        new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen;
                                        new Atom.carbon; new Atom.carbon; new Atom.carbon; new Atom.carbon; new Atom.carbon; new Atom.carbon; new Atom.carbon]
  end

class nitroglycerin =
  object
    inherit molecule "Nitroglycerin" [new Atom.nitrogene; new Atom.nitrogene; new Atom.nitrogene;
                                        new Atom.hydrogen; new Atom.hydrogen; new Atom.hydrogen; new Atom.hydrogen; new Atom.hydrogen;
                                        new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen; new Atom.oxygen;
                                        new Atom.carbon; new Atom.carbon; new Atom.carbon]
  end


(*class test =*)
  (*object*)
    (*inherit molecule "Test" [new Atom.nitrogene ; new Atom.potassium; new Atom.potassium; new Atom.hydrogen; new Atom.hydrogen; new Atom.carbon]*)
  (*end*)
