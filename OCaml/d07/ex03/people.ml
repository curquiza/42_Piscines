class people name =
  object
    val _name : string = name
    val _hp : int = 100

    initializer print_endline ("People " ^ _name ^ " (hp = " ^ string_of_int _hp ^ ") created !")
    method to_string () : string = "Name : " ^ _name ^ " ; hp : " ^ string_of_int _hp
    method talk () = print_endline ("I’m " ^ _name ^ "! Do you know the Doctor?")
    method die () = print_endline "Aaaarghh!"
  end
