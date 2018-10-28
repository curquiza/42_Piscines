<?php

Class Jaime extends Lannister {
	public function sleepWith($perso)
	{
		if (get_class($perso) == "Cersei")
			print ("With pleasure, but only in a tower in Winterfell, then.".PHP_EOL);
		else
			parent::sleepWith($perso);
	}
}

//Class Jaime extends Lannister {
//	function __construct() {
//		$this->isCersei = FALSE;
//	}	
//	public function sleepWith($perso)
//	{
//		if (isset($perso->isCersei) && $perso->isCersei == TRUE)
//			print ("With pleasure, but only in a tower in Winterfell, then.".PHP_EOL);
//		else
//			parent::sleepWith($perso);
//	}
//}

?>
