#!/usr/bin/php
<?PHP

if ($argc == 4)
{
	$elem1 = trim($argv[1]);
	$op = trim($argv[2]);
	$elem2 = trim($argv[3]);
	if ($op == "+")
		echo $elem1 + $elem2."\n";
	else if ($op == "-")
		echo $elem1 - $elem2."\n";
	else if ($op == "*")
		echo $elem1 * $elem2."\n";
	else if ($op == "/" && intval($elem2) != "0")
		echo $elem1 / $elem2."\n";
	else if ($op == "%" && intval($elem2) != "0")
		echo $elem1 % $elem2."\n";
}
else
	echo "Incorrect Parameters\n";

?>
