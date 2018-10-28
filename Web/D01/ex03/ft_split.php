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

?>
