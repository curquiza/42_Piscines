<?php

function	auth($login, $passwd)
{
	if (file_exists("../private/passwd") === FALSE)
		return (FALSE);
	$file = file_get_contents("../private/passwd");
	$tab = unserialize($file);
	$pw_hash = hash("sha512", $passwd);
	foreach ($tab as $elem)
	{
		if ($elem['login'] == $login && $elem['passwd'] == $pw_hash)
			return (TRUE);
	}
	return (FALSE);
}

?>
