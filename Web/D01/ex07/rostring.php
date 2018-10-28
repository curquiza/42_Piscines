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

if ($argv[1] != NULL)
{
	$tab = ft_split($argv[1]);
	//$tmp = array($tab[0]);
	//$tab = array_diff($tab, $tmp);
	//$tab[] = $tmp[0];
	//array_push($tab, $tmp[0]);
	//$tab = array_values($tab);
	//$str = implode(" ", $tab);
	//if ($str != NULL)
	//	echo $str."\n";
	$i = 0;
	foreach ($tab as $elem)
	{
		if ($i != 0)
			echo $elem." ";
		$i++;
	}
	if ($tab[0] != NULL)
	echo $tab[0]."\n";
}
?>
