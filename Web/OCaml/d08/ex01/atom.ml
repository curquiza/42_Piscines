class virtual atom n s a_n =
  object (self)

    val _name = n
    val _symbol = s
    val _atomic_number = a_n

    method name : string = _name
    method symbol : string = _symbol
    method atomic_number : int = _atomic_number

    method to_string : string =
      "name = " ^ self#name ^ " - symbol = " ^ self#symbol ^ " - atomic_number = " ^ string_of_int self#atomic_number

    method equals (a : atom) : bool =
      (a#name = self#name) && (a#symbol = self#symbol) && (a#atomic_number = self#atomic_number)

  end

class hydrogen =
  object
    inherit atom "Hydrogen" "H" 1
  end

class carbon =
  object
    inherit atom "Carbon" "C" 6
  end

class oxygen =
  object
    inherit atom "Oxygen" "O" 8
  end

class calcium =
  object
    inherit atom "Calcium" "Ca" 20
  end

class lithium =
  object
    inherit atom "Lithium" "Li" 3
  end

class neon =
  object
    inherit atom "Neon" "Ne" 10
  end

class potassium =
  object
    inherit atom "Potassium" "K" 19
  end

class sodium =
  object
    inherit atom "Sodium" "Na" 11
  end

class helium =
  object
    inherit atom "Helium" "He" 2
  end

class zinc =
  object
    inherit atom "Zinc" "Zn" 30
  end

class nitrogene =
  object
    inherit atom "Nitrogene" "N" 7
  end

class chlore =
  object
    inherit atom "Chlore" "Cl" 17
  end
