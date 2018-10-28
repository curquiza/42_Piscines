module type FIXED = sig
  type t
  val of_float : float -> t
  val of_int : int -> t
  val to_float : t -> float
  val to_int : t -> int
  val to_string : t -> string
  val zero : t
  val one : t
  val succ : t -> t
  val pred : t -> t
  val min : t -> t -> t
  val max : t -> t -> t
  val gth : t -> t -> bool
  val lth : t -> t -> bool
  val gte : t -> t -> bool
  val lte : t -> t -> bool
  val eqp : t -> t -> bool (** physical equality *)
  val eqs : t -> t -> bool (** structural equality *)
  val add : t -> t -> t
  val sub : t -> t -> t
  val mul : t -> t -> t
  val div : t -> t -> t
  val foreach : t -> t -> (t -> unit) -> unit
end

(* EX03 **********************************************************************)

module type FRACTIONNAL_BITS =
  sig
    val bits : int
  end

module type MAKE =
  functor (FractionnalBits : FRACTIONNAL_BITS) -> FIXED

module Make =
  functor (FractionnalBits : FRACTIONNAL_BITS) ->
    struct
      type t = int

      let of_float (f : float) = int_of_float (floor(f *. float_of_int (1 lsl FractionnalBits.bits) +. 0.5))
      let of_int (i : int) = i lsl FractionnalBits.bits
      let to_float (fp : t) = float_of_int fp /. float_of_int (1 lsl FractionnalBits.bits)
      let to_int (fp : t) = fp lsr FractionnalBits.bits
      let to_string (fp : t) = string_of_float (to_float fp)

      let zero = 0
      let one = of_int 1

      let succ fp : t = fp + 1
      let pred fp : t = fp - 1
      let min fp1 fp2 : t = if fp1 <= fp2 then fp1 else fp2
      let max fp1 fp2 : t = if fp1 >= fp2 then fp1 else fp2

      let gth fp1 fp2 : bool = fp1 > fp2
      let lth fp1 fp2 : bool = fp1 < fp2
      let gte fp1 fp2 : bool = fp1 >= fp2
      let lte fp1 fp2 : bool = fp1 <= fp2
      let eqp fp1 fp2 : bool = fp1 == fp2
      let eqs fp1 fp2 : bool = fp1 = fp2

      let add fp1 fp2 : t = of_float (to_float fp1 +. to_float fp2)
      let sub fp1 fp2 : t = of_float (to_float fp1 -. to_float fp2)
      let mul fp1 fp2 : t = of_float (to_float fp1 *. to_float fp2)
      let div fp1 fp2 : t = of_float (to_float fp1 /. to_float fp2)

      let rec foreach fp1 fp2 f = match fp1 with
      | x when eqs x fp2 -> ()
      | _ -> f fp1 ; foreach (succ fp1) fp2 f

    end

(*****************************************************************************)

module Fixed4 : FIXED = Make (struct let bits = 4 end)

module Fixed8 : FIXED = Make (struct let bits = 8 end)

let () =
  print_endline ("** SUBJECT TESTS *******************************************") ;
  let x8 = Fixed8.of_float 21.10 in
  let y8 = Fixed8.of_float 21.32 in
  let r8 = Fixed8.add x8 y8 in
  print_endline (Fixed8.to_string r8);
  Fixed4.foreach (Fixed4.zero) (Fixed4.one) (fun f -> print_endline (Fixed4.to_string f));

  print_newline () ;

  print_endline ("** MY TESTS ************************************************") ;
  print_endline "** of_int / Fixed4:"; let x4 = Fixed4.of_int 21 in print_endline (Fixed4.to_string x4);
  print_endline "** of_float / Fixed4:"; let x4 = Fixed4.of_float 11.6 in print_endline (Fixed4.to_string x4);

  print_endline "** zero:"; print_endline (Fixed8.to_string Fixed8.zero);
  print_endline "** succ:"; print_endline (Fixed8.to_string (Fixed8.succ Fixed8.zero));
  print_endline "** one:"; print_endline (Fixed8.to_string Fixed8.one);
  print_endline "** pred:"; print_endline (Fixed8.to_string (Fixed8.pred Fixed8.one));

  let x8 = Fixed8.of_float 21.10 in
  let y8 = Fixed8.of_float 21.32 in
  print_endline "** greater than:"; print_endline (string_of_bool (Fixed8.gth x8 y8));
  print_endline "** lower than:"; print_endline (string_of_bool (Fixed8.lth x8 y8));
  print_endline "** greater or equal than:"; print_endline (string_of_bool (Fixed8.gte x8 y8));
  print_endline "** lower or equal than:"; print_endline (string_of_bool (Fixed8.lte x8 y8));

  let x8 = Fixed8.of_int 21 in
  let y8 = Fixed8.of_float 21.0 in
  print_endline "** physical equality:"; print_endline (string_of_bool (Fixed8.eqp x8 y8));
  print_endline "** structural equality:"; print_endline (string_of_bool (Fixed8.eqs x8 y8));

  let x8 = Fixed8.of_float 21.10 in
  let y8 = Fixed8.of_float 21.32 in
  print_endline "** add:"; let r8 = Fixed8.add x8 y8 in print_endline (Fixed8.to_string r8);
  print_endline "** sub:"; let r8 = Fixed8.sub x8 y8 in print_endline (Fixed8.to_string r8);
  print_endline "** mul:"; let r8 = Fixed8.mul x8 y8 in print_endline (Fixed8.to_string r8);
  print_endline "** div:"; let r8 = Fixed8.div x8 y8 in print_endline (Fixed8.to_string r8);
