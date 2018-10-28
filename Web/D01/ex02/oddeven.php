#!/usr/bin/php
<?PHP

echo "Entrez un nombre: ";
while (($nbr = fgets(STDIN)) != FALSE)
{
	$nbr = trim($nbr);
	$numeric = is_numeric($nbr);
	if (strstr($nbr, "e") != FALSE || strstr($nbr, "E") != FALSE || strstr($nbr, ".") != FALSE)
		echo "'$nbr' n'est pas un chiffre\n";
	else if ($numeric == FALSE)
		echo "'$nbr' n'est pas un chiffre\n";
	else if (substr($nbr, -1) % 2 == 0)
		echo "Le chiffre $nbr est Pair\n";
	else
		echo "Le chiffre $nbr est Impair\n";
	echo "Entrez un nombre: ";
}
echo "\n";

?>
