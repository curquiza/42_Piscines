#!/usr/bin/php
<?PHP

if ($argc >= 2)
{
	$str = preg_replace("/[ \t]+/", " ", $argv[1]);
	$str = trim($str);
	echo $str."\n";
}

?>
