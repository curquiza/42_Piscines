class dalek =
  object (self)

    val _name : string =
      Random.self_init () ;
      "Dalek" ^ String.init 3 (function i -> match i with
                                             | 0 -> char_of_int ((Random.int 26) + 65)
                                             | _ -> char_of_int ((Random.int 26) + 97) )
    val _hp : int = 100
    val mutable shield = true

    method to_string () = "Dalek -> name : " ^ _name ^ " - hp = " ^ string_of_int _hp ^ " - shield = " ^ string_of_bool shield

    method private get_random_talk () =
      Random.self_init () ;
      match (Random.int 4) with
        | 0 -> "Explain! Explain!"
        | 1 -> "Exterminate! Exterminate!"
        | 2 -> "I obey!"
        | 3 -> "You are the Doctor! You are the enemy of the Daleks!"
        | _ -> ""

    method talk () = print_endline (self#get_random_talk ())

    method exterminate (p : People.people) = p#die () ; match shield with
                                                        | false -> shield <- true
                                                        | true -> shield <- false

    method die () = print_endline "Emergency Temporal Shift!"
  end
