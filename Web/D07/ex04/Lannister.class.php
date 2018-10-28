<?php

Class Lannister {
	public	$isLannister = TRUE;

	public function sleepWith($perso)
	{
		if (/*isset($perso->isLannister) == TRUE && */$perso->isLannister == TRUE)
			print ("Not even if I'm drunk !".PHP_EOL);
		else
			print ("Let's do this.".PHP_EOL);
	}

}

//Class Lannister {
//	public	$isLannister = TRUE;
//	public	$isCersei = TRUE;
//
//	public function sleepWith($perso)
//	{
//		if (/*isset($perso->isLannister) == TRUE && */$perso->isLannister == TRUE)
//			print ("Not even if I'm drunk !".PHP_EOL);
//		else
//			print ("Let's do this.".PHP_EOL);
//	}
//}

?>
