#!/usr/bin/php
<?PHP

function	ft_split($str)
{
	$tab_vide = array("");
	$tab = explode(" ", $str);
	$tab = array_diff($tab, $tab_vide);
	$tab = array_values($tab);
	sort($tab);
	return ($tab);
}

function	ft_print_array($tab)
{
	foreach ($tab as $elem)
		echo $elem."\n";
}

$i = 0;
foreach ($argv as $argv)
{
	if ($i != 0)
		$str = $str." ".$argv;
	$i++;
}
$tab = ft_split($str);
ft_print_array($tab);

?>
