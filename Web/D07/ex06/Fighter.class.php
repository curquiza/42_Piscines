<?php

abstract Class Fighter {
	public $type = 0;

	function __construct($warrior) {
		$this->type = $warrior;
	}

	abstract function fight($target);
}

?>
