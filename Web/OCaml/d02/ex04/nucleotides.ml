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
    | 'A'   -> A
    | 'T'   -> T
    | 'C'   -> C
    | 'G'   -> G
    | _     -> None
}

(* TEST ***************)

let print_nucleobase n = match n with
    | A -> print_char 'A'
    | T -> print_char 'T'
    | C -> print_char 'C'
    | G -> print_char 'G'
    | _ -> print_char '?'

let print_nucleotide nucl =
    print_string "{ p = " ; print_string nucl.p ; print_string "; d = " ;
    print_string nucl.d ; print_string "; n = " ; print_nucleobase nucl.n ;
    print_endline " }"

let () =
    print_endline "Generating nucleotides ..." ;
    print_string "with char 'A' -> " ; print_nucleotide (generate_nucleotide 'A') ;
    print_string "with char 'T' -> " ; print_nucleotide (generate_nucleotide 'T') ;
    print_string "with char 'C' -> " ; print_nucleotide (generate_nucleotide 'C') ;
    print_string "with char 'G' -> " ; print_nucleotide (generate_nucleotide 'G') ;
    print_string "with char 'w' -> " ; print_nucleotide (generate_nucleotide 'w')
