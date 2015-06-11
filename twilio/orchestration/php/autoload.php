<?php

$lib = realpath(__DIR__ . '/lib');

spl_autoload_register(function($classname) use($lib) {
	$candidate = $lib . '/' . $classname . '.php';
	if (file_exists($candidate)) {
		require_once($candidate);
		return true;
	}
	return false;
}, false, true);
