<?php

Class Color
{
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	static $verbose = FALSE;

	function __construct(array $tab)
	{
		if (isset($tab['rgb']))
		{
			$this->red = intval(($tab['rgb'] >> 16) & 0xFF);
			$this->green = intval(($tab['rgb'] >> 8) & 0xFF);
			$this->blue = intval($tab['rgb'] & 0xFF);
		}
		else
		{
			if (isset($tab['red']))
				$this->red = intval($tab['red']);
			else
				$this->red = 0;
			if (isset($tab['green']))
				$this->green = intval($tab['green']);
			else
				$this->green = 0;
			if (isset($tab['blue']))
				$this->blue = intval($tab['blue']);
			else
				$this->blue = 0;
		}
		if (self::$verbose == TRUE)
			print("Color( red: ".$this->red.", green: ".$this->green.", blue: ".$this->blue." ) constructed.".PHP_EOL);
	}

	function __toString()
	{
		return ("Color( red: ".$this->red.", green: ".$this->green.", blue: ".$this->blue." )");	
	}

	static function doc()
	{
		$file = file_get_contents("Color.doc.txt");
		return ($file);
	}

	function __clone()
	{
		return ;
	}

	function add($col)
	{
		$instance = clone $col;
		$instance->red = $col->red + $this->red;
		$instance->green = $col->green + $this->green;
		$instance->blue = $col->blue + $this->blue;
		return ($instance);
	}	

	function sub($col)
	{
		$instance = clone $col;
		$instance->red = $this->red - $col->red;
		$instance->green = $this->green - $col->green;
		$instance->blue = $this->blue - $col->blue;
		return ($instance);
	}	

	function mult($fact)
	{
		$instance = new Color(array('rgb' => 0));
		$instance->red = $this->red * $fact;
		$instance->green = $this->green * $fact;
		$instance->blue = $this->blue * $fact;
		return ($instance);
	}	

	function __destruct()
	{
		if (self::$verbose == TRUE)
			print("Color( red: ".$this->red.", green: ".$this->green.", blue: ".$this->blue." ) destructed.".PHP_EOL);
	}
}
?>
