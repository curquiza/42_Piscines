class ['a] army (l: 'a list) =
  object

    val _l = l

    method add elem = new army (elem :: _l)

    method delete () = new army (List.tl _l)

    method print_army () = List.iter (function x -> print_endline (x#to_string ())) _l

  end
