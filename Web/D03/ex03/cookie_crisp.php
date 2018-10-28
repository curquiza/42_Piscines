<?php

$action = $_GET['action'];
$name = $_GET['name'];
$value = $_GET['value'];

if ($action !== NULL)
{
	if ($action == "set" && $name !== NULL && $value !== NULL)
		setcookie($name, $value, time() + 3600);
	else if ($action == "del" && $name !== NULL)
		setcookie($name);
	else if ($action == "get" && $name !== NULL)
	{
		$val = $_COOKIE[$name];
		if ($val !== NULL)
			echo "$val\n";
	}
}

?>
