let () =
  print_endline (new Atom.hydrogen)#to_string ;
  print_endline (new Atom.carbon)#to_string ;
  print_endline (new Atom.oxygen)#to_string ;
  print_endline (new Atom.neon)#to_string ;
  print_endline (new Atom.calcium)#to_string ;
  print_endline (new Atom.sodium)#to_string ;
  print_endline (new Atom.potassium)#to_string ;
  print_endline (new Atom.lithium)#to_string ;
  print_endline (new Atom.helium)#to_string ;
  print_endline (new Atom.zinc)#to_string ;
  print_string "equals btw hydrogen and calcium -> " ; print_endline (string_of_bool ((new Atom.hydrogen)#equals (new Atom.calcium))) ;
  print_string "equals btw 2 hydrogens -> " ; print_endline (string_of_bool ((new Atom.hydrogen)#equals (new Atom.hydrogen)))
