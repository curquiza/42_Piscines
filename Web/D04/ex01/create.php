<?php

function	ft_exists_in_tab($tab, $login)
{
	foreach ($tab as $elem)
	{
		if ($elem['login'] == $login)
			return (TRUE);
	}
	return (FALSE);

}

if ($_POST['submit'] === "OK" && $_POST['login'] != NULL && $_POST['passwd'] != NULL)
{
	$pwd = $_POST['passwd'];
	$pwd = hash("sha512", $pwd);
	$login = $_POST['login'];

	$account = array('login' => $login, 'passwd' => $pwd);
	if (file_exists("../private") === FALSE)
		mkdir("../private");
	if (file_exists("../private/passwd") === TRUE)
	{
		$file = file_get_contents("../private/passwd");
		$tab = unserialize($file);
		if (ft_exists_in_tab($tab, $login) === FALSE)
			$tab[] = $account;
		else
		{
			echo "ERROR\n";
			return ;
		}
	}
	else
		$tab = array($account);
	$file = serialize($tab);
	file_put_contents("../private/passwd", $file."\n");
	echo "OK\n";
}
else
	echo "ERROR\n";

?>
