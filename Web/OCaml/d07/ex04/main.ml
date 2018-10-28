let () =

  print_endline "Creating all the lists..." ;
  let p_l   = [ new People.people "toto" ; new People.people "titi" ; new People.people "tutu" ] in
  let doc_l = [ new Doctor.doctor "Who" 1000 (List.hd p_l) ] in
  let dal_l = [ new Dalek.dalek ; new Dalek.dalek ; new Dalek.dalek ] in
  print_newline  () ;
  let g = new Galifrey.galifrey dal_l doc_l p_l in
  g#do_time_war ()
