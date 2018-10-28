<?PHP

function	ft_is_sort($tab)
{
	$tab_sort = $tab;
	$tab_rsort = $tab;
	sort($tab_sort);
	rsort($tab_rsort);
	if ($tab == $tab_sort)
		return (TRUE);
	if ($tab == $tab_rsort)
		return (TRUE);
	return (FALSE);
}

?>
