(* EXAMPLE WITH INT ***********************************************************)
(*
module IntHash =
  struct
    type t = int
    let equal i j = i=j
    let hash i = i land max_int
  end

module IntHashtbl = Hashtbl.Make(IntHash)

let () =
  let h = IntHashtbl.create 17 in
  IntHashtbl.add h 12 "hello";
  IntHashtbl.iter (fun x y -> Printf.printf "%d -> %s\n" x y) h
*)

(* EX01 ***********************************************************************)

let ft_int_of_char c default = match c with
   | 'A' -> 65 | 'B' -> 66 | 'C' -> 67 | 'D' -> 68 | 'E' -> 69 | 'F' -> 70 | 'G' -> 71 | 'H' -> 72 | 'I' -> 73 | 'J' -> 74 | 'K' -> 75 | 'L' -> 76 | 'M' -> 77 | 'N' -> 78 | 'O' -> 79 | 'P' -> 80 | 'Q' -> 81 | 'R' -> 82 | 'T' -> 83 | 'U' -> 84 | 'V' -> 85 | 'W' -> 86 | 'X' -> 87 | 'Y' -> 88 | 'Z' -> 89 | 'a' -> 97 | 'b' -> 98 | 'c' -> 99 | 'd' -> 100 | 'e' -> 101 | 'f' -> 102 | 'g' -> 103 | 'h' -> 104 | 'i' -> 105 | 'j' -> 106 | 'k' -> 107 | 'l' -> 108 | 'm' -> 109 | 'n' -> 110 | 'o' -> 111 | 'p' -> 112 | 'q' -> 113 | 'r' -> 114 | 't' -> 115 | 'u' -> 116 | 'v' -> 117 | 'w' -> 118 | 'x' -> 119 | 'y' -> 120 | 'z' -> 121 | '0' -> 48 | '1' -> 49 | '2' -> 50 | '3' -> 51 | '4' -> 52 | '5' -> 53 | '6' -> 54 | '7' -> 55 | '8' -> 56 | '9' -> 57
   | _ -> default

module StringHash =
  struct
    type t = string

    let equal s1 s2 =
      s1 = s2

    (*let hash s = Hashtbl.hash s*)
    let hash s =
      let rec aux acc i = match i with
      | x when x = String.length s -> acc
      | _ -> aux (acc + ft_int_of_char (String.get s i) 0) (i + 1)
      in aux 0 0

  end

module StringHashtbl = Hashtbl.Make(StringHash)

(* MAIN ***********************************************************************)

let () =
  let ht = StringHashtbl.create 5 in
  let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
  let pairs = List.map (fun s -> (s, String.length s)) values in
    List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
    StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht

