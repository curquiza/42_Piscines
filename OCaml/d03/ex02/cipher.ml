let rot_n_char c n =
  char_of_int (((int_of_char c) + n) mod 128)

let caesar n str =
  String.map (function x -> rot_n_char x n) str

let rot42 str =
  caesar 42 str

let xor_n_char c key =
  char_of_int ((lxor) (int_of_char c) key)

let xor n str =
  String.map (function x -> xor_n_char x n) str

let rec ft_crypt str l : string = match l with 
  | []          -> str
  | head::tail  -> ft_crypt (head str) tail