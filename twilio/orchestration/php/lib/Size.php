<?php
 
class Size {
	const SMALL = 'small';
	const MEDIUM = 'medium';
	const LARGE = 'large';

	/**
	 * Validate a size, if invalid throw an exception
	 * @param string $size The size to validate
	 * @throws SizeException If the provided size is invalid
	 */
	public static function validate($size) {
		if (!in_array($size, [self::SMALL, self::MEDIUM, self::LARGE])) {
			throw new SizeException("$size is not a valid size");
		}
	}
}
