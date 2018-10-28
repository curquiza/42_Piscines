let () =

  print_endline (new Molecule.water)#to_string ;
  print_endline (new Molecule.carbon_dioxyde)#to_string;
  print_endline (new Molecule.ammoniac)#to_string;
  print_endline (new Molecule.hydrochloric_acid)#to_string;
  print_endline (new Molecule.trinitrotoluene)#to_string;
  print_endline (new Molecule.nitroglycerin)#to_string;
  print_string "equals btw 2 water -> " ; print_endline (string_of_bool ((new Molecule.water)#equals (new Molecule.water))) ;
  print_string "equals btw 1 water and 1 ammoniac -> " ; print_endline (string_of_bool ((new Molecule.water)#equals (new Molecule.ammoniac)))
  (*print_endline (new Molecule.test)#to_string;*)
