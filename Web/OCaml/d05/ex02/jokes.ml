let jokes = [| "Que dit une mère à son fils geek quand le diner est servi ? Alt Tab !!!" ;
               "Jai une blague sur les magasins mais elle a pas supermarché." ;
               "Pourquoi est ce qu'on met les crocos en prisons ? Parce que les crocos dealent." ;
               "On ne dit pas \"le ton monte\" mais \"la moche prend l'escalier\"." ;
               "Pourquoi Potter est triste ? Parce que personne Harry à sa vanne." |]

let () =
  Random.self_init ();
  let r = Random.int 5 in
  print_endline (jokes.(r))
