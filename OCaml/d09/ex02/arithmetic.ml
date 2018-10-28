module type MONOID =
  sig
    type element
    val zero1 : element
    val zero2 : element
    val mul : element -> element -> element
    val add : element -> element -> element
    val div : element -> element -> element
    val sub : element -> element -> element
  end

module INT : MONOID with type element = int =
  struct
    type element = int
    let zero1:element = 0
    let zero2:element = 1
    (*let add (a:element) (b:element) : element = a + b*)
    (*let mul (a:element) (b:element) : element = a * b*)
    (*let div (a:element) (b:element) : element = a / b*)
    (*let sub (a:element) (b:element) : element = a - b*)
    let add = ( + )
    let mul = ( * )
    let div = ( / )
    let sub = ( - )

  end

module FLOAT : MONOID with type element = float =
  struct
    type element = float
    let zero1:element = 0.0
    let zero2:element = 1.0
    (*let add (a:element) (b:element) : element = a +. b*)
    (*let mul (a:element) (b:element) : element = a *. b*)
    (*let div (a:element) (b:element) : element = a /. b*)
    (*let sub (a:element) (b:element) : element = a -. b*)
    let add = ( +. )
    let mul = ( *. )
    let div = ( /. )
    let sub = ( -. )
  end

module type Calc =
  functor (M : MONOID) ->
    sig
      val add : M.element -> M.element -> M.element
      val sub : M.element -> M.element -> M.element
      val mul : M.element -> M.element -> M.element
      val div : M.element -> M.element -> M.element
      val power : M.element -> int -> M.element
      val fact : M.element -> M.element
    end

module Calc =
  functor (M : MONOID) ->
  struct
    let add = M.add
    let sub = M.sub
    let mul = M.mul
    let div = M.div

    let power (a:M.element) (p:int) : M.element =
      let rec loop (i:int) : M.element = match i with
      | 0 -> M.zero2
      | _ -> M.mul a (loop(i - 1))
      in loop p

    let fact (a:M.element) : M.element =
      let rec loop (i:M.element) : M.element = match i with
      | x when x = M.zero1 -> M.zero2
      | _ -> M.mul i (loop (M.sub i M.zero2))
      in loop a
  end

module Calc_int = Calc(INT)
module Calc_float = Calc(FLOAT)

let () =
  print_endline "*** SUBJECT TESTS" ;
  print_endline (string_of_int (Calc_int.power 3 3));
  print_endline (string_of_float (Calc_float.power 3.0 3));
  print_endline (string_of_int (Calc_int.mul (Calc_int.add 20 1) 2));
  print_endline (string_of_float (Calc_float.mul (Calc_float.add 20.0 1.0) 2.0));

  print_newline () ; print_endline "*** MY TESTS" ;
  print_string "3^0 = " ; print_endline (string_of_int (Calc_int.power 3 0));
  print_string "0^0 = " ; print_endline (string_of_int (Calc_int.power 0 0));
  print_string "3.0^0 = " ; print_endline (string_of_float (Calc_float.power 3.0 0));
  print_string "0.0^0 = " ; print_endline (string_of_float (Calc_float.power 0.0 0));
  print_string "(20 - 1) / 2 = " ; print_endline (string_of_int (Calc_int.div (Calc_int.sub 20 1) 2));
  print_string "(20.0 -. 1.0) / 2.0 = " ; print_endline (string_of_float (Calc_float.div (Calc_float.sub 20.0 1.0) 2.0));
  print_string "3! = " ; print_endline (string_of_int (Calc_int.fact 3));
  print_string "0! = " ; print_endline (string_of_int (Calc_int.fact 0));
  print_string "1! = " ; print_endline (string_of_int (Calc_int.fact 1));
  print_string "4.0! = " ; print_endline (string_of_float (Calc_float.fact 4.0));
  print_string "0.0! = " ; print_endline (string_of_float (Calc_float.fact 0.0));
  print_string "1.0! = " ; print_endline (string_of_float (Calc_float.fact 1.0));
