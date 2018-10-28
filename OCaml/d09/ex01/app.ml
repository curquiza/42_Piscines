module App =
  struct
    type project = (string * string * int)
    let zero : project = ("", "", 0)

    let combine (p1:project) (p2:project) : project =
      match (p1, p2) with
      | ((p1, s1, g1), (p2, s2, g2)) when ((g1 + g2) / 2) >= 80 -> (p1 ^ p2, "succeed", (g1 + g2) / 2)
      | ((p1, s1, g1), (p2, s2, g2)) -> (p1 ^ p2, "failed", (g1 + g2) / 2)

    let fail ((p, s, g):project) : project = (p, "failed", 0)
    let success ((p, s, g):project) : project = (p, "succeed", 80)

  end

let print_proj ((p, s, g):App.project) : unit =
  print_endline ("Product : " ^ p ^ " - Status : " ^ s ^ " - Grade : " ^ string_of_int g)

let () =
  let proj1:App.project = ("Toto", "none", 90)
  and proj2:App.project = ("Titi", "none", 40)
  and proj3:App.project = ("Tutu", "none", 100) in
  print_endline "All current project :" ; print_proj proj1 ; print_proj proj2 ; print_proj proj3 ;
  print_newline () ; print_endline "Combine Toto and Titi" ; print_proj (App.combine proj1 proj2) ;
  print_newline () ; print_endline "Combine Toto and Tutu" ; print_proj (App.combine proj1 proj3) ;
  print_newline () ; print_endline "Toto switch to failed" ; print_proj (App.fail proj1) ;
  print_newline () ; print_endline "Titi switch to succeed" ; print_proj (App.success proj2) ;
