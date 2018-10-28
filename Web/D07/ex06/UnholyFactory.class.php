<?php

Class UnholyFactory {

	public	$fighters = array();

	public	function absorb($warrior) {
		if (array_key_exists($warrior->type, $this->fighters) == TRUE)
			print("(Factory already absorbed a fighter of type ".$warrior->type.")".PHP_EOL);
		else if (is_a($warrior, "Fighter") == FALSE)
			print("(Factory can't absorb this, it's not a fighter)".PHP_EOL);
		else
		{
			$this->fighters[$warrior->type] = $warrior;
			print("(Factory absorbed a fighter of type ".$warrior->type.")".PHP_EOL);
		}
	}

	public	function fabricate($rf) {
		print("(Factory fabricates a fighter of type ".$rf.")".PHP_EOL);
		$f = $this->fighters[$rf];
		return ($f);		
	}
}

?>
