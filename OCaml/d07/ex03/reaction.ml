class virtual reaction (start : (Molecule.molecule * int) list) (result : (Molecule.molecule * int) list) =
  object

    val _start : (Molecule.molecule * int) list = start
    val _result : (Molecule.molecule * int) list = result

    method get_start : (Molecule.molecule * int) list = _start
    method get_result : (Molecule.molecule * int) list = _result

    method virtual balance : reaction
    method virtual is_balanced : bool

  end
