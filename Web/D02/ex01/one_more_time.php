#!/usr/bin/php
<?PHP

function	ft_get_month($str)
{
	$str = strtolower($str);
	$tab = array("janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre");
	$i = 0;
	foreach($tab as $elem)
	{
		if ($elem == $str)
			return ($i + 1);
		$i++;
	}
	return (0);;
}

if ($argc >= 2)
{
	$tab = explode(" ", $argv[1]);
	if (count($tab) != 5)
	{
		echo "Wrong Format\n";
		return ;
	}
	
	if (preg_match("/^([Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche)$/", $tab[0]) == 0)
	{
		echo "Wrong Format\n";
		return ;
	}
	if (preg_match("/^[0-9]{1,2}$/", $tab[1]) == 0)
	{
		echo "Wrong Format\n";
		return ;
	}
	if (preg_match("/^([Jj]anvier|[Ff]evrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]out|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd]ecembre)$/", $tab[2]) == 0)
	{
		echo "Wrong Format\n";
		return ;
	}
	if (preg_match("/^[0-9]{4}$/", $tab[3]) == 0)
	{
		echo "Wrong Format\n";
		return ;
	}
	if (preg_match("/^[0-9]{2}:[0-9]{2}:[0-9]{2}$/", $tab[4]) == 0)
	{
		echo "Wrong Format\n";
		return ;
	}

	$month = ft_get_month($tab[2]);
	if (checkdate($month, $tab[1], $tab[3]) === FALSE)
	{
		echo "Wrong Format\n";
		return ;
	}
	$str = $tab[3]."-".$month."-".$tab[1]." ".$tab[4];
	date_default_timezone_set("Europe/Paris");
	$rslt = strtotime($str);
	if ($rslt === FALSE)
		echo "Wrong Format\n";
	else
		echo $rslt."\n";
		
}

?>
