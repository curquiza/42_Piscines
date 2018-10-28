<?php

function	ft_get_index($tab, $login, $oldpw)
{
	$i = 0;
	foreach($tab as $elem)
	{
		if ($elem['login'] === $login)
		{
			if ($elem['passwd'] === $oldpw)
				return ($i);
			else
				return (-1);
		}
		$i++;
	}
	return (-1);
}

if ($_POST['submit'] === "OK" && $_POST['login'] != NULL && $_POST['oldpw'] != NULL && $_POST['newpw'] != NULL)
{
	$oldpw = hash("sha512", $_POST['oldpw']);
	$newpw = hash("sha512", $_POST['newpw']);
	$login = $_POST['login'];

	if (file_exists("../private/passwd") === FALSE)
	{
		echo "ERROR\n";
		return ;
	}

	$file = file_get_contents("../private/passwd");
	$tab = unserialize($file);
	if (($i = ft_get_index($tab, $login, $oldpw)) === -1)
	{
		echo "ERROR\n";
		return ;
	}
	$tab[$i]['passwd'] = $newpw;
	$file = serialize($tab);
	file_put_contents("../private/passwd", $file."\n");

	echo "OK\n";
}
else
	echo "ERROR\n";

?>
