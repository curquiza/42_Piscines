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

function	ft_print_array($tab)
{
	foreach ($tab as $tab)
		echo $tab."\n";
}

function	ft_index($c)
{
	$tab = array("a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
		"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "0", "1",
		"2", "3", "4", "5", "6", "7", "8", "9", " ", "!", "\"", "#", "$", "%",
		"&", "'", "(", ")", "*", "+", ",", "-", ".", "/", ":", ";", "<", "=", ">",
		"?", "[", "\\", "]", "^", "_", "`", "{", "|", "}", "~");
	$i = 0;
	foreach($tab as $tmp)
	{
		if ($tmp == $c)
			return ($i);
		$i++;
	}
}

function	ft_compare($elem1, $elem2)
{
	$tmp1 = strtolower($elem1);
	$tmp2 = strtolower($elem2);
	$i = 0;
	while ($tmp1[$i] != NULL && $tmp2[$i] != NULL && $tmp1[$i] == $tmp2[$i])
		$i++;
	return (ft_index($tmp1[$i]) - ft_index($tmp2[$i]));
}

if ($argv[1] != NULL)
{
	$i = 0;
	foreach ($argv as $argv)
	{
		if ($i != 0)
			$str = $str." ".$argv;
		$i++;
	}
	$tab = ft_split($str);
	usort($tab, "ft_compare");
	ft_print_array($tab);
}

?>
