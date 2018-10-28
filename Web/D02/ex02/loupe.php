#!/usr/bin/php
<?PHP
if ($argc >= 2)
{
	$str = file_get_contents($argv[1]);
	echo $str."\n\n";
	//$str = preg_replace("/<a.*\/a>/isU", "COCO", $str);
	//preg_match_all("/<a.*>(.*)<.*a>/isU", $str, $tab);
	//print_r($tab);
	//preg_match_all("/<a.*title=(.*)[ >].*a>/isU", $str, $tab);
	//print_r($tab);
	//$str = preg_replace("/<a(.*)a>/isU", "COCO", $str);


	preg_match_all("/<a.*>(.*)<.*a>/isU", $str, $tab);
	print_r($tab);

	preg_match_all("/<a.*title=\"(.*)\".*a>/isU", $str, $tab);
	print_r($tab);

//	echo $str."\n";

}
?>
