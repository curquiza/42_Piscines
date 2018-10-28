#!/usr/bin/php
<?PHP

if ($argc == 2)
{
	if (strstr($argv[1], "*") != FALSE)
	{
		$tab = explode("*", $argv[1]);
		$op = "*";
	}
	else if (strstr($argv[1], "/") != FALSE)
	{
		$tab = explode("/", $argv[1]);
		$op = "/";
	}
	else if (strstr($argv[1], "%") != FALSE)
	{
		$tab = explode("%", $argv[1]);
		$op = "%";
	}
	else if (strstr($argv[1], "+") != FALSE)
	{
		$tab = explode("+", $argv[1]);
		$op = "+";
	}
	else if (strstr($argv[1], "-") != FALSE)
	{
		$tab = explode("-", $argv[1]);
		$op = "-";
	}

	if (count($tab) != 2)
	{
		echo "Syntax Error\n";
		return ;
	}
	$elem1 = trim($tab[0]);
	$elem2 = trim($tab[1]);
	if (is_numeric($elem1) == TRUE && is_numeric($elem2) == TRUE)
	{
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
		echo "Syntax Error\n";
}
else
	echo "Incorrect Parameters\n";

?>
