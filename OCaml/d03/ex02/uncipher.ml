(* let unrot_n_char c n =
  char_of_int (((int_of_char c) + (128 - (n mod 128)) mod 128) *)

let unxor_n_char key c =
  char_of_int ((lor) (int_of_char c) key)

let unrot42 str =
  Cipher.caesar (128 - 42) str

let uncaesar n str =
  Cipher.caesar (128 - (n mod 128)) str

(* let rev_list l =
  let rec rev_aux acc = function
    | []          -> acc
    | head::tail  -> rev_aux (head::acc) tail
  in rev_aux [] l *)

let ft_uncrypt str f_l =
    let rec rev l1 l2 =
      match l1 with
      | head::tail -> rev tail (head::l2)
      | _ -> l2
    in Cipher.ft_crypt str (rev f_l [])

let () =
  let str0 = "" in
  let str1 = "TOTO" in
  let str2 = "toto" in
  let test1 = "abcdefghijklmnopqrstuvwxyz" in
  let crypt = Cipher.ft_crypt test1 [Cipher.xor 32; Cipher.caesar 1] in
    print_string "caesar 2 de chaine vide -> " ; print_endline (Cipher.caesar 2 str0);
    print_string "rot42 de chaine vide -> " ; print_endline (Cipher.rot42 str0);
    print_string "caesar 2 de TOTO -> " ; print_endline (Cipher.caesar 2 str1);
    print_string "rot42 de TOTO -> " ; print_endline (Cipher.rot42 str1);
    print_string "xor 32 de toto -> " ; print_endline (Cipher.xor 32 str2);
    print_string "xor 32 de TOTO -> " ; print_endline (Cipher.xor 32 str1);
    print_string "uncaesar 35 de ! -> " ; print_endline (uncaesar 35 "!");
    print_string "unrot42 de ! -> " ; print_endline (unrot42 "!");
    print_string "cipher avec chaine vide sur " ; print_string test1 ; print_string " -> " ; print_endline (Cipher.ft_crypt test1 []);
    print_string "cipher avec xor 32 + caesar 1 sur " ; print_string test1 ; print_string " -> " ; print_endline (Cipher.ft_crypt test1 [Cipher.xor 32; Cipher.caesar 1]);
    print_string "uncipher avec xor 31 + uncaesar 1 sur " ; print_string crypt ; print_string " -> " ; print_endline (ft_uncrypt crypt [Cipher.xor 32; uncaesar 1]);
