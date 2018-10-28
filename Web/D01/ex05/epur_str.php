#!/usr/bin/php
<?PHP

function	ft_split($str)
{
	$tab_vide = array("");
	$tab = explode(" ", $str);
	$tab = array_diff($tab, $tab_vide);
	$tab = array_values($tab);
	return ($tab);
}

if ($argc == 2)
{
	$split = ft_split($argv[1]);
	$str = implode(" ", $split);
	if ($str != NULL)
		echo $str."\n"; 
}

?>
