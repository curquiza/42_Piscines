(* Ex04 *****************)
type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None
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

let nucleotide_to_string n =
    "{p = " ^ n.p ^ " ; d = " ^ n.d ^ " ; n = "
    ^ match n.n with
    | A -> "A"
    | T -> "T"
    | C -> "C"
    | G -> "G"
    | _ -> "?";
    ^ "}"

let rec helix_to_string l = match (l:helix) with
    | head::tail when tail = [] -> (nucleotide_to_string head)
    | head::tail -> (nucleotide_to_string head) ^ " " ^ (helix_to_string tail)
    | _ -> ""

let generate_complementary_nucleotide nucl = {
    p = nucl.p ;
    d = nucl.d ;
    n = match nucl.n with
    | A -> T
    | T -> A
    | C -> G
    | G -> C
    | _ -> None
}

let rec complementary_helix h : helix = match (h:helix) with
    | head::tail -> (generate_complementary_nucleotide head) :: (complementary_helix tail)
    | _ -> []

(* TEST *****************)

let print_nucleotide nucl =
    print_string (nucleotide_to_string nucl)

let print_list l =
    print_string "[" ;
    let rec loop i = match i with
    | head::tail when tail = [] -> print_nucleotide head ; loop tail
    | head::tail                -> print_nucleotide head ; print_string " ; " ; loop tail
    | _                         -> ()
    in loop l ;
    print_endline "]"

let () =
    let helix_1 = generate_helix 0 in
    let helix_2 = generate_helix 1 in
    let helix_3 = generate_helix 3 in
    print_string "Generating helix list of -1 nucleotide     -> " ; print_list (generate_helix (-1));
    print_string "Generating helix list of 0 nucleotide (1)  -> " ; print_list (helix_1);
    print_string "Generating helix list of 1 nucleotide (2)  -> " ; print_list (helix_2);
    print_string "Generating helix list of 3 nucleotides (3) -> " ; print_list (helix_3);
    print_endline "" ;
    print_string "Helix list to string with (1) -> " ; print_endline (helix_to_string helix_1) ;
    print_string "Helix list to string with (2) -> " ; print_endline (helix_to_string helix_2) ;
    print_string "Helix list to string with (3) -> " ; print_endline (helix_to_string helix_3) ;
    print_endline "" ;
    print_string "Generating complementary helix of (1) -> " ; print_endline (helix_to_string (complementary_helix helix_1)) ;
    print_string "Generating complementary helix of (2) -> " ; print_endline (helix_to_string (complementary_helix helix_2)) ;
    print_string "Generating complementary helix of (3) -> " ; print_endline (helix_to_string (complementary_helix helix_3)) ;
