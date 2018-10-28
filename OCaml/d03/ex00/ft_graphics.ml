type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y size =
  Graphics.moveto (x - (size / 2)) (y - (size / 2));
  Graphics.lineto (x - (size / 2)) (y + (size / 2));
  Graphics.lineto (x + (size / 2)) (y + (size / 2));
  Graphics.lineto (x + (size / 2)) (y - (size / 2));
  Graphics.lineto (x - (size / 2)) (y - (size / 2))

let draw_tree_node node =
  let size = 100 in
  match node with
  | Nil -> draw_square 300 300 size ; Graphics.moveto 300 300 ; Graphics.draw_string "Nil"
  | Node (value, _, _) -> draw_square 300 300 size ; Graphics.moveto 300 300 ; Graphics.draw_string value;
                          draw_square 600 200 size ; Graphics.moveto 600 200 ; Graphics.draw_string "Nil";
                          draw_square 600 400 size ; Graphics.moveto 600 400 ; Graphics.draw_string "Nil";
                          Graphics.moveto (300 + size / 2) 300 ; Graphics.lineto (600 - size / 2) 400;
                          Graphics.moveto (300 + size / 2) 300 ; Graphics.lineto (600 - size / 2) 200

let () =
  Graphics.open_graph " 900x600";
  (*draw_square 400 200 100;*)
  draw_tree_node (Node ("titi", Nil, Nil));
  (*draw_tree_node (Nil);*)
  ignore (Graphics.read_key ())
