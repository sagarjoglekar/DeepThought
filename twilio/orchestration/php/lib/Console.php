<?php
 
class Console {

	public static function out($message) {
		$timestamp = date('H:i:s');
		echo "[$timestamp] $message\n";
	}

}
