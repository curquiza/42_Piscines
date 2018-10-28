type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y size =
  Graphics.moveto (x - (size / 2)) (y - (size / 2));
  Graphics.lineto (x - (size / 2)) (y + (size / 2));
  Graphics.lineto (x + (size / 2)) (y + (size / 2));
  Graphics.lineto (x + (size / 2)) (y - (size / 2));
  Graphics.lineto (x - (size / 2)) (y - (size / 2))

let rec size t = match t with
  | Nil -> 0
  | Node (_, left, right) -> 1 + size left + size right

let rec height t = match t with
  | Nil -> 0
  | Node (_, left, right) -> if (height left) > (height right)
                             then (height left) + 1
                             else (height right) + 1

let draw_tree t =
  let size = 50 in
  let rec loop t x y = match t with
  | Nil -> draw_square x y size; Graphics.moveto x y; Graphics.draw_string "Nil"
  | Node (v, left, right) -> draw_square x y size ; Graphics.moveto x y ; Graphics.draw_string v ;
                             Graphics.moveto (x + size / 2) y ; Graphics.lineto (x + size) (y + size);
                             Graphics.moveto (x + size / 2) y ; Graphics.lineto (x + size) (y - size);
                             loop left (x + size/2 + size) (y + size);
                             loop right (x + size/2 + size) (y - size);
  in loop t 300 300

let () =
  let node_s0_h0 = Nil in
  let node_s1_h1 = Node ("toto", Nil, Nil) in
  let node_s2_h2 = Node ("toto", Nil, Node ("tutu", Nil, Nil)) in
  print_string "size = " ; print_int (size node_s0_h0); print_string " height = " ; print_int (height node_s0_h0) ; print_endline "";
  print_string "size = " ; print_int (size node_s1_h1); print_string " height = " ; print_int (height node_s1_h1) ; print_endline "";
  print_string "size = " ; print_int (size node_s2_h2); print_string " height = " ; print_int (height node_s2_h2) ; print_endline "";

  Graphics.open_graph " 900x600";
  draw_tree node_s2_h2 ;
  ignore (Graphics.read_key ());
