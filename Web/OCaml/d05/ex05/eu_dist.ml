let squaredDistance a b = (a -. b) *. (a -.b)

let eu_dist a_array b_array =
  let rec aux rslt n = match n with
    | 0 -> rslt
    | _ -> aux (rslt +. (squaredDistance a_array.(n - 1) b_array.(n - 1))) (n - 1)
  in sqrt (aux 0.0 (Array.length a_array))

let () =
  let a_array = [| 1.0 ; 2.5 ; 3.0 |] in
  let b_array = [| 0.0 ; 2.0 ; 4.0 |] in
  print_float (eu_dist a_array b_array)
