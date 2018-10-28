<?php

abstract Class House {

	/*public function getHouseName() {
		return ("");
	}

	public function getHouseSeat(){
		return ("");
	}

	public function getHouseMotto() {
		return ("");
	}*/

	abstract function getHouseName();
	abstract function getHouseSeat();
	abstract function getHouseMotto();

	public function introduce() {
		print("House ".static::getHouseName()." of ".static::getHouseSeat()." : \"".static::getHouseMotto()."\"".PHP_EOL);
		return ("");
	}
}

?>
