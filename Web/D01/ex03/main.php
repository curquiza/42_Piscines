#!/usr/bin/php
<?PHP

include("ft_split.php");

print_r(ft_split("* Hello  a  World A    AA  *** a  "));
echo "\n";
print_r(ft_split(" AA   "));
echo "\n";
print_r(ft_split(""));
echo "\n";
print_r(ft_split("    "));
echo "\n";
print_r(ft_split(NULL));

?>
