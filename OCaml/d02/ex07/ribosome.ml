(* Ex04 *****************)
type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None
type nucleotide = {
    p: phosphate;
    d: deoxyribose;
    n: nucleobase
}

let generate_nucleotide c = {
    p = "phosphate";
    d = "deoxyribose";
    n = match c with
    | 'A' -> A
    | 'T' -> T
    | 'C' -> C
    | 'G' -> G
    | 'U' -> U
    | _   -> None
}

(* Ex05 *****************)

type helix = nucleotide list

let random_char_nucleotide () =
    Random.self_init () ;
    let rand = Random.int 4 in
    match rand with
    | 0 -> 'A'
    | 1 -> 'T'
    | 2 -> 'C'
    | 3 -> 'G'
    | _ -> '?'

(* fonctionne aussi *)
(*let generate_helix n =
    let rec construct i rslt = match i with
        | x when x <= 0 -> rslt
        | _ -> construct (i - 1) ((generate_nucleotide (random_char_nucleotide ())) :: rslt)
    in construct n ([]:helix)*)

let rec generate_helix n : helix = match n with
    | x when x >= 1 -> (generate_nucleotide (random_char_nucleotide ())) :: (generate_helix (n - 1))
    | _ -> []

let nucleobase_to_string n = match n with
    | A -> "A"
    | T -> "T"
    | C -> "C"
    | G -> "G"
    | U -> "U"
    | _ -> "?"

let nucleotide_to_string n =
    "{p = " ^ n.p ^ " ; d = " ^ n.d ^ " ; n = " ^ (nucleobase_to_string n.n) ^ "}"

let rec helix_to_string l = match (l:helix) with
    | head::tail when tail = [] -> (nucleotide_to_string head)
    | head::tail -> (nucleotide_to_string head) ^ " " ^ (helix_to_string tail)
    | _ -> ""

let nucleobase_complementary n = match n with
    | A -> T
    | T -> A
    | C -> G
    | G -> C
    | _ -> None

let generate_complementary_nucleotide nucl = {
    p = nucl.p ;
    d = nucl.d ;
    n = nucleobase_complementary nucl.n
}

let rec complementary_helix h : helix = match (h:helix) with
    | head::tail -> (generate_complementary_nucleotide head) :: (complementary_helix tail)
    | _ -> []

(* Ex06 *****************)

type rna = nucleobase list

let nucleobase_complementary_rna n = match n with
    | T -> U
    | _ -> n

let rec generate_rna h = match h with
    | head::tail -> let compl = nucleobase_complementary head.n
                    in (nucleobase_complementary_rna compl) :: (generate_rna tail)
    | _ -> []


(* Ex07 *****************)

let rec generate_bases_triplets rna_lst = match (rna_lst:rna) with
    | head::second::third::tail -> [(head, second, third)] @ generate_bases_triplets tail
    | _ -> []

(* TEST *****************)

let print_nucleotide nucl =
    print_string (nucleotide_to_string nucl)

let nucleobase_list_to_string l =
    if l = [] then ""
    else
    "[" ^ let rec loop i = match i with
    | head::tail when tail = [] -> (nucleobase_to_string head) ^ "]"
    | head::tail -> (nucleobase_to_string head) ^ ";" ^ (loop tail)
    | _ -> ""
    in loop l

let triplet_to_string t = match t with
    | (x, y, z) -> "(" ^ (nucleobase_to_string x) ^ "," ^ (nucleobase_to_string y) ^ "," ^ (nucleobase_to_string z) ^ ")"

let triplet_list_to_string l =
    if l = [] then ""
    else
    "[" ^ let rec loop i = match i with
    | head::tail when tail = [] -> (triplet_to_string head) ^ "]"
    | head::tail -> (triplet_to_string  head) ^ ";" ^ (loop tail)
    | _ -> ""
    in loop l

let () =
    let helix_1 = generate_helix 0 in
    let helix_2 = generate_helix 1 in
    let helix_3 = generate_helix 3 in
    let helix_4 = generate_helix 7 in
    let rna_1 = generate_rna helix_1 in
    let rna_2 = generate_rna helix_2 in
    let rna_3 = generate_rna helix_3 in
    let rna_4 = generate_rna helix_4 in
    print_string "Helix (1) -> " ; print_endline (helix_to_string (helix_1)) ;
    print_string "Helix (2) -> " ; print_endline (helix_to_string (helix_2)) ;
    print_string "Helix (3) -> " ; print_endline (helix_to_string (helix_3)) ;
    print_string "Helix (4) -> " ; print_endline (helix_to_string (helix_4)) ;
    print_string "Generating rna of (1) -> " ; print_endline (nucleobase_list_to_string rna_1) ;
    print_string "Generating rna of (2) -> " ; print_endline (nucleobase_list_to_string rna_2) ;
    print_string "Generating rna of (3) -> " ; print_endline (nucleobase_list_to_string rna_3) ;
    print_string "Generating rna of (4) -> " ; print_endline (nucleobase_list_to_string rna_4) ;
    print_string "Generating base triplets from (1) -> " ; print_endline (triplet_list_to_string (generate_bases_triplets rna_1)) ;
    print_string "Generating base triplets from (2) -> " ; print_endline (triplet_list_to_string (generate_bases_triplets rna_2)) ;
    print_string "Generating base triplets from (3) -> " ; print_endline (triplet_list_to_string (generate_bases_triplets rna_3)) ;
    print_string "Generating base triplets from (4) -> " ; print_endline (triplet_list_to_string (generate_bases_triplets rna_4)) ;
