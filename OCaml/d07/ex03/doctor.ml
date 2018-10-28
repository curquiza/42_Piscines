class doctor ?(hp=100) name age sidekick =
  (*self and label only to test regenerate method*)
  object (self)
    val _name : string = name
    val _age : int = age
    val _sidekick : People.people = sidekick
    val _hp : int = hp

    initializer print_endline ("Doctor " ^ _name ^ " (hp = " ^ string_of_int _hp ^ ", age = " ^ string_of_int _age ^ ") created !")

    method to_string () : string = "Name = " ^ _name ^ " - age = " ^ string_of_int _age ^ " - hp = " ^ string_of_int _hp ^ " - Sidekick = { " ^ _sidekick#to_string () ^ " }"
    method talk () = print_endline "Hi! I’m the Doctor!"

    method travel_in_time start arrival = print_endline
"            ___
    _______(_@_)_______
    | POLICE      BOX |
    |_________________|
     | _____ | _____ |
     | |###| | |###| |
     | |###| | |###| |
     | _____ | _____ |
     | || || | || || |
     | ||_|| | ||_|| |
     | _____ |$_____ |
     | || || | || || |
     | ||_|| | ||_|| |
     | _____ | _____ |
     | || || | || || |
     | ||_|| | ||_|| |
     |       |       |
     *****************" ;
    begin
    match (arrival - start) with
    | x when x < 0 -> print_endline ("The Doctor travelled " ^ string_of_int (-1 * x) ^ " years in the past")
    | x -> print_endline ("The Doctor travelled " ^ string_of_int (x) ^ " years in the future")
    end ; print_endline "But his age did'nt change..."

    method use_sonic_screwdriver () = print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"

    method private regenerate () = new doctor _name _age _sidekick

    (*ONLY FOR TEST*)
    method test_regenerate () = print_endline ((self#regenerate ())#to_string ())
  end
