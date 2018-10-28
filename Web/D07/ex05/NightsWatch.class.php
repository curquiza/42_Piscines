<?php
Class NightsWatch {
	public $fighters = array();

	public function recruit($perso) {
		//if (method_exists($perso, "fight") == TRUE)
			$this->fighters[] =  $perso;
	}

	public function fight() {
		if ($this->fighters)
		{
			foreach($this->fighters as $elem)
			{
				if (method_exists($elem, "fight") == TRUE)
					$elem->fight();
			}
		}
	}
}
?>
